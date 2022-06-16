const auto& __XsEngineVertexShader__ = R"(
#version 400
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
out vec2 TexCoords;
out vec3 Normal;
out vec3 FragPos;
out vec4 FragPosLightSpace;
uniform mat4 lightSpaceMatrix;
void main(){
	FragPos = vec3(model * vec4(aPos, 1.0));
    TexCoords = vec2(aTexCoord.x, aTexCoord.y);
    Normal = mat3(transpose(inverse(model))) * aNormal;
    FragPosLightSpace = lightSpaceMatrix * vec4(FragPos, 1.0);
    gl_Position = proj * view * vec4(FragPos, 1.0);
}
)";
const auto& __XsEngineFragmentShader__ = R"(
#version 400
uniform vec4 color;
out vec4 FragColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
in vec4 FragPosLightSpace;
uniform sampler2D tex;
uniform sampler2D shadowMap;
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;    
    float shininess;
};
struct Light {
	vec3 pos;
	vec3 color;
	float power;
};
uniform Light light[256];
uniform Material material;
uniform int lightNum;
uniform vec3 viewPos;
float linearizeDepth(float depth) {
    float z = depth * 2.0 - 1.0;
    return (2.0 * 0.05 * 100.0) / (100.0 + 0.05 - z * (100.0 - 0.05));
};
/*
float ShadowCalculation(vec4 fragPosLightSpace, vec3 lightPos) {
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5;
    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;
    vec3 normal = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);
    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x) {
        for(int y = -1; y <= 1; ++y) {
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
        }    
    }
    shadow /= 9.0;
    if(projCoords.z > 1.0)
        shadow = 0.0;
        
    return shadow;
}
*/
void main() {
	vec3 result = vec3(0,0,0);
	for (int i = 0; i < lightNum; i++) {
		float power = light[i].power / (distance(FragPos, light[i].pos)*distance(FragPos, light[i].pos));
		if (power > 1)
			power = 1;
		vec3 ambient = material.ambient * power;
		vec3 norm = normalize(Normal);
		vec3 lightDir = normalize(light[i].pos - FragPos);
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = (diff * material.diffuse) * power;
		vec3 viewDir = normalize(viewPos - FragPos);
		vec3 reflectDir = reflect(-lightDir, norm);
		float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess) * power;
		vec3 specular = (spec * material.specular);
        //float shadow = ShadowCalculation(FragPosLightSpace,light[i].pos);
		result += (ambient + diffuse + specular) * light[i].color; // * (1.0 - shadow);
	};
	FragColor = texture(tex, TexCoord) * color * vec4(result, 1.0 - (linearizeDepth(gl_FragCoord.z) / 1000.0));
}
)";
const char* frag = R"(
#version 400 core
out vec4 FragColor;
in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;
uniform sampler2D tex;

// material parameters
uniform float alpha_color;
uniform vec3 albedo;
uniform float metallic;
uniform float roughness;
uniform float ao;

// lights
struct Light {
	vec3 pos;
	vec3 color;
	float power;
};
uniform Light lights[256];
uniform int lightNum;

uniform vec3 camPos;

const float PI = 3.14159265359;
// ----------------------------------------------------------------------------
float linearizeDepth(float depth) {
    float z = depth * 2.0 - 1.0;
    return (2.0 * 0.05 * 100.0) / (100.0 + 0.05 - z * (100.0 - 0.05));
};
// ----------------------------------------------------------------------------
float DistributionGGX(vec3 N, vec3 H, float roughness)
{
    float a = roughness*roughness;
    float a2 = a*a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH*NdotH;

    float nom   = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return nom / denom;
}
// ----------------------------------------------------------------------------
float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float nom   = NdotV;
    float denom = NdotV * (1.0 - k) + k;

    return nom / denom;
}
// ----------------------------------------------------------------------------
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);

    return ggx1 * ggx2;
}
// ----------------------------------------------------------------------------
vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}
// ----------------------------------------------------------------------------
void main()
{
    vec3 N = normalize(Normal);
    vec3 V = normalize(camPos - FragPos);

    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);

    vec3 Lo = vec3(0.0);
    for(int i = 0; i < lightNum; ++i)
    {
        vec3 L = normalize(lights[i].pos - FragPos);
        vec3 H = normalize(V + L);
        float distance = length(lights[i].pos - FragPos) / lights[i].power;
        float attenuation = 1.0 / (distance * distance);
        vec3 radiance = lights[i].color * attenuation;

        float NDF = DistributionGGX(N, H, roughness);
        float G   = GeometrySmith(N, V, L, roughness);
        vec3 F    = fresnelSchlick(clamp(dot(H, V), 0.0, 1.0), F0);

        vec3 numerator    = NDF * G * F;
        float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0) + 0.0001;
        vec3 specular = numerator / denominator;

        vec3 kS = F;
        vec3 kD = vec3(1.0) - kS;
        kD *= 1.0 - metallic;

        float NdotL = max(dot(N, L), 0.0);

        Lo += (kD * albedo / PI + specular) * radiance * NdotL;
    }
    vec3 ambient = vec3(0.03) * albedo * ao;
    vec3 color = ambient + Lo;
    vec4 result = texture(tex, TexCoords) * vec4(pow(color / (color + vec3(1.0)), vec3(1.0/2.2)), 1.0);
    result.w = alpha_color * (1.0 - (linearizeDepth(gl_FragCoord.z) / 1000.0));
    FragColor = result;
}
)";
sf::Context context;
bool _xs_init = []() -> bool { GLenum v = glewInit(); const bool its_ok = (v == GLEW_OK); if (!its_ok) std::cerr << "glew error: " << v << '\n'; return its_ok; }();
class XsEngine {
public:
    sf::RenderWindow Window;
    sf::Event Event;
    XsCamera Cam;
    vex3f BgColor = 0.f;
    void play(const str& win_name) {
        _init(win_name);
        while (Window.isOpen()) {
            Window.clear();
            gl.Clear.Color(BgColor.x, BgColor.y, BgColor.z);
            gl.Clear(glEnum::DepthBufferBit | glEnum::ColorBufferBit);
            while (Window.pollEvent(Event)) {
                ImGui::SFML::ProcessEvent(Event);
                if (Event.type == sf::Event::Closed)
                    Window.close();
            }
            _play();
            Window.display();
        }
        this->shutdown();
    };
    void init();
    void loop();
    void shutdown();
    void gui();
    inline auto& create(XsShape* e, const str& tag = "") { auto& v = *shapes.push_back(&e->id, e); e->id = next_shape++; if (!tag.empty()) e->tag = tag; return v; };
    inline auto& create(XsMesh* e, const str& tag = "") { auto& v = *meshs.push_back(&e->id,e); e->id = next_mesh++; if (!tag.empty()) e->tag = tag; return v; };
    inline auto& create(XsTexture* e, const str& tag = "") { auto& v = *texs.push_back(&e->id,e); e->id = next_tex++; if (!tag.empty()) e->tag = tag; return v; };
    inline auto& create(XsAnim* e, const str& tag = "") { auto& v = *anims.push_back(&e->id,e); e->id = next_anim++; if (!tag.empty()) e->tag = tag; return v; };
    inline auto& create(XsLight* e, const str& tag = "") { auto& v = *lights.push_back(&e->id,e); e->id = next_light++; if (!tag.empty()) e->tag = tag; return v; };
    inline void destroy(XsShape& e) { shapes.remove(&e.id); };
    inline void destroy(XsMesh& e) { meshs.remove(&e.id); };
    inline void destroy(XsTexture& e) { texs.remove(&e.id); };
    inline void destroy(XsAnim& e) { anims.remove(&e.id); };
    inline void destroy(XsLight& e) { lights.remove(&e.id); };
    _Dict<XsId*, XsShape*> shapes;
    _Dict<XsId*, XsMesh*> meshs;
    _Dict<XsId*, XsTexture*> texs;
    _Dict<XsId*, XsAnim*> anims;
    _Dict<XsId*, XsLight*> lights;
private:
    XsShader shader = XsShader(__XsEngineVertexShader__, frag);
    f32 _fps = 60.f;
    XsChrono fixed_t;
    XsTexture no_tex = XsTexture().create(1, 1, { 1,1,1,1 });
    uint next_shape=0, next_mesh=0, next_tex=0, next_anim=0, next_light=0;
    sf::Clock imclk;
    void _init(const str& win_name) {
        Window.create(sf::VideoMode(Xs.Sett.WindowSize.x, Xs.Sett.WindowSize.y), win_name, sf::Style::Default,  sf::ContextSettings(24,8,0,3,3,false));
        ImGui::SFML::Init(Window);
        gl.Enable((glEnum)gl.Texture2D);
        gl.Enable(glEnum::ScissorTest);
        gl.Enable(glEnum::DepthTest);
        gl.Enable(glEnum::Normalize);
        gl.Depth(gl.Depth.Less);
        glShadeModel(GL_SMOOTH);
        gl.Enable(glEnum::Blend); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
        glBlendEquation(GL_FUNC_ADD);
        gl.Ident();
        init();
    }
    void _play() {
        const auto& execut = std::execution::par;
        _cam();
        loop();
        static bool Once = [&]() {
            for (auto&& i : anims) i.value->start();
            for (auto&& i : lights) i.value->start();
            for (auto&& i : texs) i.value->start();
            for (auto&& i : meshs) i.value->start();
            for (auto&& i : shapes) i.value->start();
            return true;
        }();
        std::for_each(execut, anims.begin(), anims.end(), [](auto&& i)  {
            if (!i.value->froze) {
                i.value->loop();
                i.value->step();
            };
        });
        shader.use();
        shader("view", Cam.viewMatrix());
        shader("proj", Cam.projectionMatrix());
        shader("viewPos", Cam.pos);
        byte n = 0;
        shader("lightNum", int(lights.size()));
        for (auto&& i : lights) {
            if (!i.value->froze) i.value->loop();
            const string& cstr = std::format("lights[{}].", n++);
            shader(cstr + "color", vex3f(vex4f() << i.value->color) / 255.f);
            shader(cstr + "pos", i.value->pos);
            shader(cstr + "power", i.value->power);
        };
        std::for_each(execut, shapes.begin(), shapes.end(), [](auto&& i) { if (!i.value->froze) i.value->loop(); });
        for (auto& i : shapes) _draw(*i.value);
        _gui();
    };
    void _gui() {
        ImGui::SFML::Update(Window, imclk.restart());
        gui();
        Window.pushGLStates();
        ImGui::SFML::Render(Window);
        Window.popGLStates();
    }
    void _cam() {
        Cam.viewport << Window.getSize();
        glScissor(0, 0, Cam.viewport.x, Cam.viewport.y);
        gl.Viewport(0, 0, Cam.viewport.x, Cam.viewport.y);
        glMatrixMode(GL_PROJECTION);
        gl.Ident();
        const glm::mat4 _ftransform = Cam.projectionMatrix() * Cam.viewMatrix();
        glLoadMatrixf(&_ftransform[0][0]);
        glMatrixMode(GL_MODELVIEW);
    }
    void render_mesh(XsMesh& mesh) {
        gl.Enable.ClientState(glEnum::VertexArray);
        gl.VertexPointer(3, gl.Float, sizeof(vex3f), &mesh.pos[0]);
        gl.Enable.VertexAttribArray(0);
        gl.VertexAttribPointer(0, 3, gl.Float, false, sizeof(vex3f), &mesh.pos[0]);
        gl.Enable.ClientState(glEnum::TextureCoordArray);
        gl.TexCoordPointer(2, gl.Float, sizeof(vex2f), &mesh.tex[0]);
        gl.Enable.VertexAttribArray(1);
        gl.VertexAttribPointer(1, 2, gl.Float, false, sizeof(vex2f), &mesh.tex[0]);
        gl.Enable.ClientState(glEnum::NormalArray);
        gl.NormalPointer(gl.Float, sizeof(vex3f), &mesh.normal[0]);
        gl.Enable.VertexAttribArray(2);
        gl.VertexAttribPointer(2, 3, gl.Float, false, sizeof(vex3f), &mesh.normal[0]);
        gl.DrawArrays(mesh.poly, mesh.pos.size());
        gl.Disable.ClientState(glEnum::VertexArray);
        gl.Disable.ClientState(glEnum::TextureCoordArray);
        gl.Disable.ClientState(glEnum::NormalArray);
        gl.Disable.VertexAttribArray(0);
        gl.Disable.VertexAttribArray(1);
        gl.Disable.VertexAttribArray(2);
    };
    void _draw(XsShape& v) {
        limit(v.rot, 0.f, 360.f, true);
        shader("model", v.matrix());
        shader("metallic", v.metallic);
        shader("roughness", v.roughness);
        shader("ao", v.ao);
        shader("albedo", (vex3f() << v.color) / 255.f);
        shader("alpha_color", (f32)v.color.w / 255.f);
        if (not v.hide and v.mesh != nullptr) {
            if (v.tex != nullptr)
                v.tex->bind();
            else
                no_tex.bind();
            render_mesh(*v.mesh);
        };
    };
} eng;
void XsShape::destroy() { eng.destroy(*this); };