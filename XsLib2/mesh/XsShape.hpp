class XsEngine;
struct XsMaterial {
	XsMaterial(const XsMaterial&) = default;
	inline XsMaterial(const vex3f& _ambient = 0.f, const vex3f& _diffuse = 1.f, const vex3f& _specular = 0.25f, const float& _shininess = 2.5f) : ambient(_ambient), diffuse(_diffuse), specular(_specular), shininess(_shininess) {};
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
struct XsTransform {
	vex3f pos = 0.f, rot = 0.f, scale = 1.f, origin = 0.f;
};
class XsShape : public XsTransform {
private:
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
	inline operator glm::mat4() const { return matrix(); };
	inline auto& operator<<(XsMaterial _material) { material = _material; return *this; };
	inline auto& operator<<(XsMesh _mesh) { mesh = new XsMesh(_mesh); return *this; };
	inline auto& operator<<(XsMesh* _mesh) { mesh = _mesh; return *this; };
	inline auto& operator<<(XsTexture _tex) { tex = new XsTexture(_tex); return *this; };
	inline auto& operator<<(XsTexture* _tex) { tex = _tex; return *this; };
	vex4f color = 1.f;
	XsMaterial material;
	XsMesh* mesh = nullptr;
	XsTexture* tex = nullptr;
	auto operator*() { return this; };
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
	void draw(XsEngine* eng);
};
enum XsEffectType {XsShake};
template <XsEffectType> class XsEffect;
template <> class XsEffect<XsShake> {
private:
	vex3f* ref = nullptr;
public:
	XsEffect(vex3f& _ref) : ref(&_ref) {};
	vex3f area = 1.f;
	float speed = 1.f;
	inline vex3f& Step() {
		return *ref;
	};
};
/*
static const auto& __XsSkyVertexShader__ = R"(
#version 400
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
out vec2 TexCoord;
uniform mat4 model;
void main(){
	FragPos = vec3(model * vec4(aPos, 1.0));
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
	gl_Position = vec4(FragPos, 1.0); 
}
)";
static const auto& __XsSkyFragmentShader__ = R"(
#version 400
out vec4 FragColor;
in vec2 TexCoord;
uniform vec4 color;
uniform sampler2D tex;
void main() {
	FragColor = texture(tex, TexCoord) * color;
}
)";
#include <system/XsTrash.hpp>
class XsSky {
private:
	XsShader shader = XsShader(__XsSkyVertexShader__, __XsSkyFragmentShader__);
public:
	XsTexture* tex;
	vex3f rot = 0.f;
	vex4f color = 1.f;
	XsEnum type = Xs.Enum.Sphere;
	inline void operator()(const XsCamera& cam) {
		shader.use();
		shader("model",
			glm::rotate(glm::mat4(1.f), rot.x / 180.f * 3.14f, glm::vec3(1, 0, 0)) *
			glm::rotate(glm::mat4(1.f), rot.y / 180.f * 3.14f, glm::vec3(0, 1, 0)) *
			glm::rotate(glm::mat4(1.f), rot.z / 180.f * 3.14f, glm::vec3(0, 0, 1)));
		shader("color", color);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		if (tex != nullptr) shader("tex", (int)tex->data);
		glColor4f(color.x, color.y, color.z, color.w);
		if (type == Xs.Enum.Sphere) {
			glVertexPointer(3, GL_FLOAT, sizeof(vex3f), __sphere_pos.data());
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(vex3f), __sphere_pos.data());
			glTexCoordPointer(2, GL_FLOAT, sizeof(vex2f), __sphere_tex.data());
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(vex2f), __sphere_tex.data());
			glDrawArrays(GL_TRIANGLES, 0, __sphere_pos.size());
		};
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	};
};
*/