struct XsMaterial {
	XsMaterial() = default;
	XsMaterial(const XsMaterial&) = default;
	vex3f ambient = 0.0f;
	vex3f diffuse = 1.f;
	vex3f specular = 0.25f;
	float shininess = 2.5f;
	vex4f color = 1.f;
};
class XsLight : public XsEntity {
public:
	XsLight() = default;
	XsLight(const XsLight&) = default;
	XsLight(const vex3f& _pos, const vex3f& _color, const float& _power = 1.f) { pos = _pos; color = _color; power = _power; };
	vex3f pos = 0.f, color = 1.f;
	float power = 1.f;
};
struct XsTransform {
	XsTransform() = default;
	typedef float scalar;
	vex3<scalar> pos = 0.f, rot = 0.f, scale = 1.f, origin = 0.f;
	inline vex3<scalar>& move(const vex3<scalar>& xyz) { return pos += xyz; };
	inline vex3<scalar>& move(const scalar& x, const scalar& y, const scalar& z) { return pos += vex3<scalar>(x, y, z); };
	//inline vex3<scalar>& lookAt(const vex3<scalar>& _at) { return (rot << glm::eulerAngles(glm::quat_cast(glm::lookAt(((glm::vec3)pos), ((glm::vec3)pos)+((glm::vec3)_at), glm::vec3(0, 1, 0))))) *= (180.f / 3.14); };
	auto& reset() { return (*this) = XsTransform(); };
	inline glm::mat4 matrix() const {
		return
			glm::translate(glm::mat4(1.f), (glm::vec3)pos)*
			glm::rotate(glm::mat4(1.f), rot.x/180.f*3.14f, glm::vec3(1, 0, 0))*
			glm::rotate(glm::mat4(1.f), rot.y/180.f*3.14f, glm::vec3(0, 1, 0))*
			glm::rotate(glm::mat4(1.f), rot.z/180.f*3.14f, glm::vec3(0, 0, 1))*
			glm::scale(glm::mat4(1.f), (glm::vec3)scale)*
			glm::translate(glm::mat4(1.f), (glm::vec3)origin);
	};
	/*
	struct {
		inline glm::mat4 operator()() const {
			return
				glm::translate(glm::mat4(1.f), (glm::vec3)pos)*
				glm::rotate(glm::mat4(1.f), rot.x/180.f*3.14f, glm::vec3(1, 0, 0))*
				glm::rotate(glm::mat4(1.f), rot.y/180.f*3.14f, glm::vec3(0, 1, 0))*
				glm::rotate(glm::mat4(1.f), rot.z/180.f*3.14f, glm::vec3(0, 0, 1))*
				glm::scale(glm::mat4(1.f), (glm::vec3)scale)*
				glm::translate(glm::mat4(1.f), (glm::vec3)origin);
		};
	} matrix;
	*/
};
class XsShape : public XsEntity, public XsMaterial, public XsTransform {
public:
	XsShape(const std::string&, XsEngine&);
	void Destroy();
	bool hide = false, froze = false;
	XsMesh* mesh = nullptr;
	XsTexture* tex = nullptr;
	//XsTransform& trans = this->XsTransform;
private:
	XsEngine& engine;
};
//static XsShape null_shape;
/*
//std::vector<XsShape> childs;
inline auto& Child(const std::string& tag) {
	const auto& i = std::find_if(childs.begin(), childs.end(), [&](const XsShape& v)-> bool { return v.tag == tag; });
	return (i==childs.end()) ? (null_shape) : (*i);
};
inline const auto& Child(const std::string& tag) const {
	const auto& i = std::find_if(childs.begin(), childs.end(), [&](const XsShape& v)-> bool { return v.tag==tag; });
	return (i==childs.end()) ? (null_shape) : (*i);
};
inline auto& operator[](const std::string& tag) {
	const auto& i = std::find_if(childs.begin(), childs.end(), [&](const XsShape& v)-> bool { return v.tag==tag; });
	return (i==childs.end()) ? (null_shape) : (*i);
};
inline const auto& operator[](const std::string& tag) const {
	const auto& i = std::find_if(childs.begin(), childs.end(), [&](const XsShape& v)-> bool { return v.tag==tag; });
	return (i==childs.end()) ? (null_shape) : (*i);
};
inline auto& Childs() { return childs; };
inline auto& Childs() const { return childs; };
*/
/*
enum XsEffectType {XsShake};
template <XsEffectType> class XsEffect;
template <> class XsEffect<XsShake> {
public:
	XsEffect(vex3f& _ref) : ref(&_ref) {};
	vex3f area = 1.f;
	float speed = 1.f;
	inline vex3f& Step() {
		return *ref;
	};
private:
	vex3f* ref = nullptr;
};
*/