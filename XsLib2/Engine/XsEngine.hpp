using namespace std;
static const auto& __XsEngineVertexShader__ = R"(
#version 400
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;
out vec4 FragPosLightSpace;
uniform mat4 lightSpaceMatrix;
void main(){
	FragPos = vec3(model * vec4(aPos, 1.0));
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
    Normal = mat3(transpose(inverse(model))) * aNormal;
    FragPosLightSpace = lightSpaceMatrix * vec4(FragPos, 1.0);
    gl_Position = proj * view * vec4(FragPos, 1.0);
}
)";
static const auto& __XsEngineFragmentShader__ = R"(
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
    return (2.0 * 0.001 * 1000.0) / (1000.0 + 0.001 - z * (1000.0 - 0.001));
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
class XsEngine {
private:
    template <typename Key, typename Value>
    struct dict_pair {
        Key key;
        Value value;
    };
    template <typename Key, typename Value>
    class dict : public std::pmr::vector<dict_pair<Key, Value>> {
    public:
        using self_t = std::pmr::vector<dict_pair<Key, Value>>;
        using self_t::vector;
        using self_t::vector::push_back;
        inline Value& push_back(const Key& key, const Value& value) {
            self_t::push_back({ key,value });
            return self_t::back().value;
        };
        inline auto find(const Key& key) { return std::find_if(self_t::begin(), self_t::end(), [&](const dict_pair<Key, Value>& i) -> bool { return *i.key == *key; }); };
        inline Value& operator[](const Key& key) { return *find(key); };
        inline void remove(const Key& key) { self_t::erase(find(key)); };
    private:
    };
    XsShader shader = XsShader(__XsEngineVertexShader__, __XsEngineFragmentShader__);
    float _fps = 60.f;
    const std::chrono::steady_clock::time_point& fixed_t = std::chrono::high_resolution_clock::now();
public:
    XsEngine() = default;
    sf::RenderWindow Window;
    XsCamera Cam;
    inline void play() {
        XsPhysx();
        for (auto&& i : anims) {
            i.value->loop();
            i.value->Step();
        };
        //Sky(Cam);
        shader.use();
        shader("view", Cam.viewMatrix());
        shader("proj", Cam.projectionMatrix());
        shader("viewPos", Cam.pos);
        size_t n = 0u;
        shader("lightNum", int(lights.size()));
        for (auto& i : lights) {
            i.value->loop();
            const std::string& cstr = format("light[{}].", n);
            shader(cstr + "color", i.value->color);
            shader(cstr + "pos", i.value->pos);
            shader(cstr + "power", i.value->power);
            ++n;
        };
        const auto& _l = std::async([&] { for (auto& i : shapes) if (!i.value->froze) i.value->loop(); });
        for (auto& i : shapes) _draw(*i.value);
    };
    inline auto& create(XsShape* e) { auto& v = *shapes.push_back(&e->id,e); e->id = next_shape++; return v; };
    inline auto& create(XsMesh* e) { auto& v = *meshs.push_back(&e->id,e); e->id = next_mesh++; return v; };
    inline auto& create(XsTexture* e) { auto& v = *texs.push_back(&e->id,e); e->id = next_tex++; return v; };
    inline auto& create(XsAnim* e) { auto& v = *anims.push_back(&e->id,e); e->id = next_anim++; return v; };
    inline auto& create(XsLight* e) { auto& v = *lights.push_back(&e->id,e); e->id = next_light++; return v; };
    inline void destroy(const XsShape& e) { shapes.remove(new id_t(e.id)); };
    inline void destroy(const XsMesh& e) { meshs.remove(new id_t(e.id)); };
    inline void destroy(const XsTexture& e) { texs.remove(new id_t(e.id)); };
    inline void destroy(const XsAnim& e) { anims.remove(new id_t(e.id)); };
    inline void destroy(const XsLight& e) { lights.remove(new id_t(e.id)); };
    dict<id_t*, XsShape*> shapes;
    dict<id_t*, XsMesh*> meshs;
    dict<id_t*, XsTexture*> texs;
    dict<id_t*, XsAnim*> anims;
    dict<id_t*, XsLight*> lights;
private:
    id_t next_shape = 0, next_mesh = 0, next_tex = 0, next_anim = 0, next_light = 0;
    inline void render_mesh(XsMesh& mesh) {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, sizeof(vex3f), &mesh.pos[0]);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(vex3f), &mesh.pos[0]);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, sizeof(vex2f), &mesh.tex[0]);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(vex2f), &mesh.tex[0]);
        glEnableClientState(GL_NORMAL_ARRAY);
        glNormalPointer(GL_FLOAT, sizeof(vex3f), &mesh.normal[0]);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(vex3f), &mesh.normal[0]);
        glDrawArrays(mesh.poly, 0, mesh.pos.size());
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
    };
    inline void _draw(XsShape& v) {
        limit(v.rot, 0.f, 360.f, true);
        shader("model", v.matrix());
        shader("material.ambient", v.ambient);
        shader("material.diffuse", v.diffuse);
        shader("material.specular", v.specular);
        shader("material.shininess", v.shininess);
        shader("color", v.color);
        if (not v.hide and v.mesh != nullptr) {
            if (v.tex != nullptr)
                v.tex->bind();
            else
                glBindTexture(GL_TEXTURE_2D, 0);
            render_mesh(*v.mesh);
        };
    };
} eng;
inline XsShape::XsShape(const std::string& _tag = "", XsEngine&_eng = eng) : XsEntity(_tag), engine(_eng) { };
inline void XsShape::Destroy() { eng.destroy(*this); };