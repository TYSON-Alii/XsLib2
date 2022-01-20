class XsEngine;
const auto& __XsShapeVertexShader__ = R"(
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
const auto& __XsShapeFragmentShader__ = R"(
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
void main() {
	vec3 result = vec3(0,0,0);
	for (int i = 0; i < lightNum; i++) {
		float power = light[i].power / (distance(FragPos, light[i].pos)*distance(FragPos, light[i].pos));
		vec3 ambient = material.ambient;
		vec3 norm = normalize(Normal);
		vec3 lightDir = normalize(light[i].pos - FragPos);
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = (diff * material.diffuse) * power;
		vec3 viewDir = normalize(viewPos - FragPos);
		vec3 reflectDir = reflect(-lightDir, norm);
		float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess) * light[i].power;
		vec3 specular = (spec * material.specular);
		result += (ambient + diffuse + specular) * light[i].color;
	};
    FragColor = texture(tex, TexCoord) * color * vec4(result, 1.0);
}
)";
struct XsMaterial {
	XsMaterial() = default;
	XsMaterial(const XsMaterial&) = default;
	vex3f ambient = 0.0f;
	vex3f diffuse = 1.f;
	vex3f specular = 0.25f;
	float shininess = 2.5f;
};
struct XsLight {
	XsLight() = default;
	XsLight(const XsLight&) = default;
	XsLight(const vex3f& _pos, const vex3f& _color, const float& _power = 1.f) { pos = _pos; color = _color; power = _power; };
	vex3f pos = 0.f, color = 1.f;
	float power = 1.f;
};
class XsShape {
private:
	XsShader shader = XsShader(__XsShapeVertexShader__, __XsShapeFragmentShader__);
public:
	XsShape() = default;
	XsShape(const XsShape&) = default;
	XsShape(const std::string& loadfrom) {
		std::ifstream i(loadfrom);
		if (i.is_open()) {
			json loadfile;
			i >> loadfile;
			pos    = vex3f(float(loadfile["pos"][0]), float(loadfile["pos"][1]), float(loadfile["pos"][2]));
			rot    = vex3f(float(loadfile["rot"][0]), float(loadfile["rot"][1]), float(loadfile["rot"][2]));
			scale  = vex3f(float(loadfile["scale"][0]), float(loadfile["scale"][1]), float(loadfile["scale"][2]));
			origin = vex3f(float(loadfile["origin"][0]), float(loadfile["origin"][1]), float(loadfile["origin"][2]));
			color  = vex4f(float(loadfile["color"][0]), float(loadfile["color"][1]), float(loadfile["color"][2]), float(loadfile["color"][3]));
		}
		else {
			std::cerr << "Shape Cannot Load.";
			Xs.Log << "Shape Cannot Load.";
		};
	};
	inline operator glm::mat4() const { return model_matrix; };
	XsMaterial material;
	glm::mat4 model_matrix = glm::mat4(1.f);
	bool update_matrix = true;
	vex3f pos = 0.f, rot = 0.f, scale = 1.f, origin = 0.f;
	vex4f color = 1.f;
	XsMesh* mesh = nullptr;
	XsTexture* tex = nullptr;
	XsShape* operator*() { return this; };
	inline glm::mat4 matrix() const {
		return
			glm::translate(glm::mat4(1.f), (glm::vec3)pos) *
			glm::rotate(glm::mat4(1.f), rot.x / 180.f * 3.14f, glm::vec3(1, 0, 0)) *
			glm::rotate(glm::mat4(1.f), rot.y / 180.f * 3.14f, glm::vec3(0, 1, 0)) *
			glm::rotate(glm::mat4(1.f), rot.z / 180.f * 3.14f, glm::vec3(0, 0, 1)) *
			glm::scale(glm::mat4(1.f), (glm::vec3)scale) *
			glm::translate(glm::mat4(1.f), (glm::vec3)origin);
	};
	virtual void loop() { };
	void save(const std::string& filename) const {
		json savefile{
			{"pos",   {pos.x, pos.y, pos.z}					},
			{"rot",	  {rot.x, rot.y, rot.z}					},
			{"scale", {scale.x, scale.y, scale.z}			},
			{"origin",{origin.x, origin.y, origin.z}		},
			{"color", {color.x, color.y, color.z, color.w}	}
		};
		std::ofstream o(filename);
		o << savefile;
		o.close();
	};
	operator std::string() const {
		std::string t;
		(t += "[Pos   ]: ") += pos.str  (", ", "\n");
		(t += "[Rot   ]: ") += rot.str  (", ", "\n");
		(t += "[Scale ]: ") += scale.str(", ", "\n");
		(t += "[Color ]: ") += color.str(", ", "\n");
		return t;
	};
	friend std::ostream& operator<<(std::ostream& os, const XsShape& v) { return os << (std::string)v; };
	void draw(const XsCamera& cam, const bool& _reset_matrix = true, XsEngine* eng = nullptr);
};