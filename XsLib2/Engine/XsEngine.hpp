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
void main(){
	FragPos = vec3(model * vec4(aPos, 1.0));
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
    Normal = mat3(transpose(inverse(model))) * aNormal;
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
uniform sampler2D tex;
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
		result += (ambient + diffuse + specular) * light[i].color;
	};
	FragColor = texture(tex, TexCoord) * color * vec4(result, 1.0 - (linearizeDepth(gl_FragCoord.z) / 1000.0));
}
)";
class XsEngine {
private:
public:
    XsEngine() = default;
    XsShader shader = XsShader(__XsEngineVertexShader__, __XsEngineFragmentShader__);
    sf::RenderWindow Window;
    XsCamera Cam;
    //XsSky Sky;
    template <typename T>
    class Mem_t {
    private:
        vector<T*> _data;
    public:
        inline auto& Data() { return _data; };
        inline auto Data() const { return _data; };
        T& New(T* msh = new T()) {
            _data.emplace_back(msh);
            return *_data.back();
        };
        void Del(XsShape& shp) {
            const auto& a = find_if(_data.begin(), _data.end(), [&](auto& i) -> bool { return (&*i == &shp); });
            if (a != _data.end())
                _data.erase(a);
        };
    };
    Mem_t<XsMesh> Meshs;
    Mem_t<XsShape> Shapes;
    Mem_t<XsTexture> Textures;
    Mem_t<XsAnim> Anims;
    Mem_t<XsLight> Lights;
    Mem_t<XsRigid<XsDynamic>> DynamicRigids;
    Mem_t<XsRigid<XsStatic>> StaticRigids;
    inline void operator()() {
        XsPhysx();
        for (auto& i : Anims.Data()) i->Step();
        //Sky(Cam);
        shader.use();
        shader("view", Cam.viewMatrix());
        shader("proj", Cam.projectionMatrix());
        shader("viewPos", Cam.pos);
        size_t n = 0u;
        shader("lightNum", int(Lights.Data().size()));
        for (const auto& i : Lights.Data()) {
            const std::string& cstr = format("light[{}].", n);
            shader(cstr + "color", i->color);
            shader(cstr + "pos", i->pos);
            shader(cstr + "power", i->power);
            ++n;
        };
        for (auto& i : Shapes.Data()) i->draw(this);
        for (auto& i : DynamicRigids.Data()) i->draw(this);
        for (auto& i : StaticRigids.Data()) i->draw(this);
    };
#define __extra_funcs__(type,name)                                                                                      \
    type& New(type* v) {                                                                                                \
    name.Data().emplace_back(v);                                                                                        \
    return *name.Data().back();                                                                                         \
    };                                                                                                                  \
    void Del(type& v) {                                                                                                 \
        const auto& a = find_if(name.Data().begin(), name.Data().end(), [&](auto& i) -> bool { return (&*i == &v); });  \
        if (a != name.Data().end()) name.Data().erase(a);                                                               \
    };
    __extra_funcs__(XsShape, Shapes);
    __extra_funcs__(XsMesh, Meshs);
    __extra_funcs__(XsTexture, Textures);
    __extra_funcs__(XsAnim, Anims);
    __extra_funcs__(XsLight, Lights);
    __extra_funcs__(XsRigid<XsDynamic>, DynamicRigids);
    __extra_funcs__(XsRigid<XsStatic>, StaticRigids);
#undef __extra_funcs__
};