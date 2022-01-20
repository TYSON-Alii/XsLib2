#define _XSLIB2_
#include <utility>
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <format>
#include <GL/glew.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <ImGui/imgui.h>
#include <ImGui/imgui-SFML.h>
#include <ImGui/imgui_stdlib.h>
#include <ImGui/ImGuiFileDialog.h>
#include <librarys/json.hpp>
#include <librarys/magic_enum.hpp>
#include <librarys/EasyGifReader.h>
#include <librarys/portable-file-dialogs.h>
#include <librarys/ofbx.h>
#include <GLM-Vex.hpp>
#include <ImGui-Vex.hpp>
#include <Vex.hpp>
#include <Random.hpp>
#include <Utilityx.hpp>
using namespace std::string_literals;
using json = nlohmann::json;
#define XS_PI 3.141592f
#define XS_HALF_PI 1.570796f
#define XS_TWO_PI 6.283185f
#define XS_FI 1.618033f
struct XsMesh;
struct XsVertex {
	std::vector<vex3f> pos, normal;
	std::vector<vex2f> tex;
};
typedef unsigned int XsTexData;
struct {
	float Fps = 1.0f;
	struct {
		std::string Text;
		struct {
			typedef unsigned char Color_t;
			Color_t Black = 0, White = 15;
			Color_t DarkBlue = 1, DarkGreen = 2, DarkCyan = 3, DarkRed = 4, DarkMagenta = 5, DarkYellow = 6, Dark_grey = 8;
			Color_t Grey = 7, Blue = 9, Green = 10, Cyan = 11, Red = 12, Purple = 13, Yellow = 14;
		} Color;
		void operator<<(const std::string& error) {
			Text += error;
			Text += '\n';
		};
	} Log;
	struct {
		vex3f Red			= vex3f(0.976f, 0.117f, 0.265f);
		vex3f DarkGreen		= vex3f(0.000f, 0.386f, 0.265f);
		vex3f Blue			= vex3f(0.000f, 0.703f, 0.917f);
		vex3f Pink			= vex3f(1.000f, 0.867f, 0.894f);
		vex3f DarkBlue		= vex3f(0.359f, 0.289f, 0.890f);
		vex3f Grey			= vex3f(0.230f, 0.226f, 0.289f);
		vex3f Purple		= vex3f(0.564f, 0.04f, 0.65f);
		vex3f LightPurple	= vex3f(0.576f, 0.439f, 0.858f);
		vex3f Orange		= vex3f(1.00f, 0.36f, 0.09f);
		vex3f Yellow		= vex3f(0.91f, 1.00f, 0.21f);
		vex3f Lime			= vex3f(0.55f, 0.90f, 0.06f);
		struct {
			vex3i Red			= vex3i(248, 29, 67);
			vex3i DarkGreen		= vex3i(0, 98, 67);
			vex3i Blue			= vex3i(0, 179, 233);
			vex3i Pink			= vex3i(255, 221, 227);
			vex3i DarkBlue		= vex3i(91, 73, 226);
			vex3i Grey			= vex3i(58, 57, 73);
			vex3i Purple		= vex3i(143, 10, 165);
			vex3i LightPurple	= vex3i(146, 112, 218);
			vex3i Orange		= vex3i(255, 91, 23);
			vex3i Yellow		= vex3i(232, 255, 53);
			vex3i Lime			= vex3i(140, 229, 15);
		} Rgb256;
		struct {
			int Red			= 0xf81d43;
			int DarkGreen	= 0x006243;
			int Blue		= 0x00b3e9;
			int Pink		= 0xffdde3;
			int DarkBlue	= 0x5b49e2;
			int Grey		= 0x3a3949;
			int Purple		= 0x8e0aa5;
			int LightPurple	= 0x9270da;
			int Orange		= 0xff5b17;
			int Yellow		= 0xe8ff35;
			int Lime		= 0x8ce50f;
			struct {
				std::string Red			= "f81d43";
				std::string DarkGreen	= "006243";
				std::string Blue		= "00b3e9";
				std::string Pink		= "ffdde3";
				std::string DarkBlue	= "5b49e2";
				std::string Grey		= "3a3949";
				std::string Purple		= "8e0aa5";
				std::string LightPurple	= "9270da";
				std::string Orange		= "ff5b17";
				std::string Yellow		= "e8ff35";
				std::string Lime		= "8ce50f";
			} Str;
		} Hex;
		struct {
			vex3f HexToRGB(int hex)		{ return vex3f(((hex >> 16) & 0xff) / 255.f, ((hex >> 8) & 0xff) / 255.f, ((hex) & 0xff) / 255.f); };
			vex3i HexToRGB256(int hex)	{ return vex3i(((hex >> 16) & 0xff), ((hex >> 8) & 0xff), ((hex) & 0xff)); };
		} Convert;
	} Color;
	struct {
		enum Key_t {
			A = 65, B = 66, C = 67, D = 68, E = 69, F = 70, G = 71, H = 72, I = 73, J = 74, K = 75, L = 76, M = 77, N = 78, O = 79, P = 80, Q = 81, R = 82, S = 83, T = 84, U = 85, V = 86, W = 87, X = 88, Y = 89, Z = 90,
			Num0 = 48, Num1 = 49, Num2 = 50, Num3 = 51, Num4 = 52, Num5 = 53, Num6 = 54, Num7 = 55, Num8 = 56, Num9 = 57,
			Space = 32,
			Escape = 27,
			Delete = 8,
			Tab = 9,
			Up = 38,
			Down = 40,
			Right = 39,
			Left = 37,
			Shift = 16,
			Enter = 13
		};
	} Key;
	struct {
		enum Enum_t {
			Point = GL_POINTS,
			Line = GL_LINES,
			Triangle = GL_TRIANGLES,
			Quad = GL_QUADS,
			Polygon = GL_POLYGON,
			Int = 0x05,
			Float = 0x06,
			Double = 0x07,
			Bool = 0x08,
			String = 0x09,
			Char = 0x0a,
			All = 0x0b,
			Vertex = 0x0c,
			Normal = 0x0d,
			Texture = 0x0e,
			VertexAndTexture = 0x0f,
			VertexAndNormal = 0x10,
			Ceil = 0x11,
			Trunc = 0x12,
			Floor = 0x13,
			Repeat = 0x14,
			Reverse = 0x15,
			Smooth = 0x16,
			Hard = 0x17,
		};
	} Enum;
	struct {
		enum Solid_t {
			Cube = 0x01,
			Prism = 0x02,
			Sphere = 0x03,
			Cylinder = 0x04,
			Cone = 0x05,
			Monke = 0x06,
			Icosphere = 0x07,
			Torus = 0x08,
			Square = 0x09,
			Teapot = 0x0a,
			Star = 0x0b,
			Polygone = 0x0c,
			Box = 0x0d
		};
	} Solid;
	bool KeyPressed(unsigned char key) { return (GetKeyState(key) & 0x800); };
	struct {
		vex2i Pos() {
			POINT p;
			GetCursorPos(&p);
			return vex2i(p.x, p.y);
		};
		template <typename T> void Pos(vex2<T>& v) {
			POINT p;
			GetCursorPos(&p);
			v = vex2<T>(p.x, p.y);
		};
		template <typename T> void Pos(vex3<T>& v) {
			POINT p;
			GetCursorPos(&p);
			v = vex2<T>(p.x, p.y);
		};
		template <typename T> void Pos(vex4<T>& v) {
			POINT p;
			GetCursorPos(&p);
			v = vex2<T>(p.x, p.y);
		};
		struct {
			enum Button_t {
				Left = 1,
				Right = 2,
				Middle = 16
			};
		} Button;
	} Mouse;
	struct {
		template <typename T1, typename T2>
		T1 Distance(vex2<T1> v1, vex2<T2> v2) { return std::sqrt(std::pow(v1.x-v2.x, 2) + std::pow(v1.y - v2.y, 2)); };
		template <typename T1, typename T2>
		T1 Distance(vex3<T1> v1, vex3<T2> v2) { return std::sqrt(std::pow(v1.x - v2.x, 2) + std::pow(v1.y - v2.y, 2) + std::pow(v1.z - v2.z, 2)); };
		inline void Limit(float& v, float min, float max, const bool& restart = false) { if (v > max) v = restart ? min : max; else if (v < min) v = restart ? max : min; };
	} Math;
	struct {
		const char* PolyNames[5]{ "Point", "Line", "Triangle", "Quad", "Polygon"};
	} Values;
	struct {
		struct {
			const std::vector<vex3f> __cube_pos = {
				{-1, -1, -1},{-1, 1, -1},{-1, -1, 1},{-1, -1, 1},{-1, 1, -1},{-1, 1, 1},
				{1, -1, -1 },{1, 1, -1 },{1, -1, 1 },{1, -1, 1 },{1, 1, -1 },{1, 1, 1 },
				{-1, -1, -1},{1, -1, -1},{-1, -1, 1},{-1, -1, 1},{1, -1, -1},{1, -1, 1},
				{-1, 1, -1 },{1, 1, -1 },{-1, 1, 1 },{-1, 1, 1 },{1, 1, -1 },{1, 1, 1 },
				{-1, -1, -1},{1, -1, -1},{-1, 1, -1},{-1, 1, -1},{1, -1, -1},{1, 1, -1},
				{-1, -1, 1 },{1, -1, 1 },{-1, 1, 1 },{-1, 1, 1 },{1, -1, 1 },{1, 1, 1 }
			};
			const std::vector<vex2f> __cube_tex = {
				{0, 0},{1, 0},{0, 1},{0, 1},{1, 0},{1, 1},
				{0, 0},{1, 0},{0, 1},{0, 1},{1, 0},{1, 1},
				{0, 0},{1, 0},{0, 1},{0, 1},{1, 0},{1, 1},
				{0, 0},{1, 0},{0, 1},{0, 1},{1, 0},{1, 1},
				{0, 0},{1, 0},{0, 1},{0, 1},{1, 0},{1, 1},
				{0, 0},{1, 0},{0, 1},{0, 1},{1, 0},{1, 1}
			};
			const std::vector<vex3f> __cube_normal = {
				{1, 0, 0 },{1, 0, 0 },{1, 0, 0 },{0, 0, -1 },{0, 0, -1 },{0, 0, -1 },
				{-1, 0, 0},{-1, 0, 0},{-1, 0, 0},{0, -0, 1 },{0, -0, 1 },{0, -0, 1 },
				{0, 1, 0 },{0, 1, 0 },{0, 1, 0 },{0, -1, -0},{0, -1, -0},{0, -1, -0},
				{1, 0, 0 },{1, 0, 0 },{1, 0, 0 },{0, 0, -1 },{0, 0, -1 },{0, 0, -1 },
				{-1, 0, 0},{-1, 0, 0},{-1, 0, 0},{0, -0, 1 },{0, -0, 1 },{0, -0, 1 },
				{0, 1, 0 },{0, 1, 0 },{0, 1, 0 },{0, -1, -0},{0, -1, -0},{0, -1, -0}
			};
			const std::vector<vex3f> __plane_pos = {
				{  1, 0,  1 },
				{ -1, 0, -1 },
				{ -1, 0,  1 },
				{  1, 0,  1 },
				{  1, 0, -1 },
				{ -1, 0, -1 }
			};
			const std::vector<vex2f> __plane_tex = {
				{ 1, 0 },
				{ 0, 1 },
				{ 0, 0 },
				{ 1, 0 },
				{ 1, 1 },
				{ 0, 1 }
			};
			const std::vector<vex3f> __plane_normal = {
				{ 0, 1, 0 },
				{ 0, 1, 0 },
				{ 0, 1, 0 },
				{ 0, 1, 0 },
				{ 0, 1, 0 },
				{ 0, 1, 0 }
			};
		} Meta;
		const XsVertex Cube = { Meta.__cube_pos, Meta.__cube_normal, Meta.__cube_tex };
		const XsVertex Plane = {Meta.__plane_pos, Meta.__plane_normal, Meta.__plane_tex };
	} Mesh;
	sf::Event Event;
	XsMesh LoadOBJ(const std::string& filename);
	struct {
		vex3f BackGround = 0.f;
		vex2ui WindowSize = vex2ui(1200, 700);
	} Sett;
	struct {
		struct {
			vex3f Speed = 0.f;
			vex3f Speed_v = 0.1f;
			vex2f Rot = 0.f;
			vex2f RotVel = 0.f;
		} Cam;
	} Editor;
} Xs;
typedef decltype(decltype(Xs)::Enum)::Enum_t XsEnum;
typedef decltype(decltype(Xs)::Key)::Key_t XsKey;
struct XsMesh : public XsVertex {
	XsMesh() = default;
	XsMesh(const XsMesh&) = default;
	XsMesh(XsVertex v) {
		pos = v.pos;
		tex = v.tex;
		normal = v.normal;
	};
	XsMesh(std::vector<vex3f> _pos_data, std::vector<vex2f> _tex_data, std::vector<vex3f> _normal_data) {
		pos = _pos_data;
		tex = _tex_data;
		normal = _normal_data;
	};
	inline void add(vex3f _pos = 0.f, vex2f _tex = 0.f, vex3f _normal = 0.f) { pos.push_back(_pos); tex.push_back(_tex); normal.push_back(_normal); };
	XsEnum poly = Xs.Enum.Triangle;
};
inline void glColor3f(vex3f v) { glColor3f(v.x, v.y, v.z); };
inline void glColor3f(vex4f v) { glColor3f(v.x, v.y, v.z); };
inline void glColor3i(vex3i v) { glColor3i(v.x, v.y, v.z); };
inline void glColor3f(vex2f v, float v1) { glColor3f(v.x, v.y, v1); };
inline void glColor3f(float v1, vex2f v) { glColor3f(v1, v.x, v.y); };
inline void glColor4f(vex3f v) { glColor4f(v.x, v.y, v.z, 1); };
inline void glColor4i(vex3i v) { glColor4i(float(v.x) / 256.f, float(v.y) / 256.f, float(v.z) / 256.f, 1.f); };
inline void glColor4f(vex4f v) { glColor4f(v.x, v.y, v.z, v.w); };
inline void glColor4i(vex4i v) { glColor4i(float(v.x) / 256.f, float(v.y) / 256.f, float(v.z) / 256.f, float(v.w) / 256.f); };
inline void glColor4f(vex3f v, float v1) { glColor4f(v.x, v.y, v.z, v1); };
inline void glColor4f(float v1, vex3f v) { glColor4f(v1, v.x, v.y, v.z); };
inline void glColor4f(vex2f v, float v1, float v2) { glColor4f(v.x, v.y, v1, v2); };
inline void glColor4f(float v1, vex2f v, float v2) { glColor4f(v1, v.x, v.y, v2); };
inline void glColor4f(float v1, float v2, vex2f v) { glColor4f(v1, v2, v.x, v.y); };

inline void glTranslatef(vex2f v) { glTranslatef(v.x, v.y, 0); };
inline void glTranslatef(vex2f v, float v1) { glTranslatef(v.x, v.y, v1); };
inline void glTranslatef(vex3f v) { glTranslatef(v.x, v.y, v.z); };
inline void glTranslatef(vex4f v) { glTranslatef(v.x, v.y, v.z); };

inline void glRotatef(float v1, vex3f v) { glRotatef(v1, v.x, v.y, v.z); };
inline void glRotatef(vex3f v, float v1) { glRotatef(v1, v.x, v.y, v.z); };
inline void glRotatef(float v1, vex3d v) { glRotatef(v1, v.x, v.y, v.z); };
inline void glRotatef(vex3d v, float v1) { glRotatef(v1, v.x, v.y, v.z); };
inline void glRotatef(vex3f v) { glRotatef(v.x, 1, 0, 0); glRotatef(v.y, 0, 1, 0); glRotatef(v.z, 0, 0, 1); };
inline void glRotatef(vex4f v) { glRotatef(v.w, v.x, v.y, v.z); };
inline void glRotatef(vex4d v) { glRotatef(v.w, v.x, v.y, v.z); };

template <typename T> inline void glScalef(vex2<T> v) { glScalef(float(v.x), float(v.y), 1.f); };
template <typename T> inline void glScalef(vex3<T> v) { glScalef(float(v.x), float(v.y), float(v.z)); };
template <typename T> inline void glScalef(vex4<T> v) { glScalef(float(v.x), float(v.y), float(v.z)); };

template <typename T> inline void glVertex3f(T v) { glVertex3f(float(v), float(v), float(v)); };
template <typename T> inline void glVertex3f(vex2<T> v) { glVertex3f(float(v.x), float(v.y), 0.f); };
template <typename T> inline void glVertex3f(vex3<T> v) { glVertex3f(float(v.x), float(v.y), float(v.z)); };
template <typename T> inline void glVertex3f(vex4<T> v) { glVertex3f(float(v.x), float(v.y), float(v.z)); };
template <typename T> inline void glVertex2f(vex2<T> v) { glVertex2f(float(v.x), float(v.y)); };
template <typename T> inline void glVertex2f(vex3<T> v) { glVertex2f(float(v.x), float(v.y)); };
template <typename T> inline void glVertex2f(vex4<T> v) { glVertex2f(float(v.x), float(v.y)); };

static sf::ContextSettings contextSettings = sf::ContextSettings(24,8,0,3,3,false);
sf::Context context;
static sf::Clock __IMCLOCK__;
static auto _XS_FPS_START = std::chrono::high_resolution_clock::now();
static const bool _xs_init = glewInit();

#include <system/XsClock.hpp>

#include <system/XsCamera.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <librarys/stb.h>
#include <librarys/stb_image.h>

#include <mesh/XsTexture.hpp>

#include <system/XsShader.hpp>

#include <mesh/XsShape.hpp>

#include <mesh/XsOBJLoader.hpp>

#include <system/XsImGui.hpp>

#include <mesh/XsAnim.hpp>

#define XsStart(_Eng, _Name) for(([&]() -> void {										\
_Eng.Window.create(sf::VideoMode(Xs.Sett.WindowSize.x, Xs.Sett.WindowSize.y), _Name, sf::Style::Default, contextSettings);\
ImGui::SFML::Init(_Eng.Window);																	\
glEnable(GL_TEXTURE_2D);																	\
glEnable(GL_SCISSOR_TEST);																	\
glEnable(GL_DEPTH_TEST);																	\
glEnable(GL_NORMALIZE);																		\
glDepthFunc(GL_LESS);		\
glShadeModel(GL_SMOOTH);																	\
glBlendFunc(GL_ZERO, GL_SRC_COLOR);															\
glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);					\
glBlendEquation(GL_FUNC_ADD);																\
glLoadIdentity();																			\
}());																						\
																							\
([&]() -> bool {																			\
_XS_FPS_START = std::chrono::high_resolution_clock::now();									\
glClearColor(Xs.Sett.BackGround.x, Xs.Sett.BackGround.y, Xs.Sett.BackGround.z, 1.0);		\
glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);											\
while (_Eng.Window.pollEvent(Xs.Event)) {														\
	ImGui::SFML::ProcessEvent(Xs.Event);													\
	if (Xs.Event.type == sf::Event::Closed)													\
		_Eng.Window.close();																	\
};																							\
return false;																				\
}() || _Eng.Window.isOpen());																	\
																							\
([&]() -> void { _Eng.Window.display(); Xs.Fps = (float)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - _XS_FPS_START).count(); }()))

static bool __FxsIm = true;
#define ImBlock(_Window) for([&](){ ImGui::SFML::Update(_Window, __IMCLOCK__.restart()); __FxsIm = true; }();__FxsIm;[&](){ _Window.pushGLStates(); ImGui::SFML::Render(_Window); _Window.popGLStates(); __FxsIm = false;}())

#include <Engine/XsEngine.hpp>

void XsShape::draw(const XsCamera& cam, const bool& _reset_matrix, XsEngine* eng) {
	loop();
	if (_reset_matrix) glLoadIdentity();
	limit(rot, 0.f, 360.f, true);
	if (update_matrix) model_matrix = matrix();
	shader.use();
	shader("model", model_matrix);
	shader("view", cam.viewMatrix());
	shader("proj", cam.projectionMatrix());
	shader("viewPos", cam.pos);
	shader("material.ambient", material.ambient);
	shader("material.diffuse", material.diffuse);
	shader("material.specular", material.specular);
	shader("material.shininess", material.shininess);
	if (eng != nullptr) {
		size_t n = 0u;
		shader("lightNum", int(eng->Lights.Data().size()));
		for (const auto& i : eng->Lights.Data()) {
			const std::string& cstr = format("light[{}].", n);
			shader(cstr + "color", i->color);
			shader(cstr + "pos", i->pos);
			shader(cstr + "power", i->power);
			n++;
		};
	};
	shader("color", color);
	if (mesh != nullptr) {
		if (tex != nullptr)
			tex->bind();
		else
			glBindTexture(GL_TEXTURE_2D, 0);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, sizeof(vex3f), &mesh->pos[0]);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(vex3f), &mesh->pos[0]);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, sizeof(vex2f), &mesh->tex[0]);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(vex2f), &mesh->tex[0]);
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, sizeof(vex3f), &mesh->normal[0]);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(vex3f), &mesh->normal[0]);
		glDrawArrays(mesh->poly, 0, mesh->pos.size());
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
	};
};