#define _XSLIB2_
#include <utility>
#include <Windows.h>
#include <GL/glew.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "math/Strinx.hpp"
#include "math/Vex.hpp"
#include "math/Random.hpp"
#define XS_PI 3.141592
#define XS_HALF_PI 1.570796
#define XS_TWO_PI 6.283185
#define XS_FI 1.618033
#define rep(v) for (decltype(v) i = 0; i < v; i +=1 )
#define rep(v, j) for (decltype(v) i = 0; i < v; i += j)
typedef std::vector<GLfloat> XsVertices;
typedef unsigned int XsTexture;
struct {
	strinx LogStx;
	struct {
		struct {
			typedef unsigned char Color_t;
			Color_t Black = 0, White = 15;
			Color_t DarkBlue = 1, DarkGreen = 2, DarkCyan = 3, DarkRed = 4, DarkMagenta = 5, DarkYellow = 6, Dark_grey = 8;
			Color_t Grey = 7, Blue = 9, Green = 10, Cyan = 11, Red = 12, Purple = 13, Yellow = 14;
		} Color;
		void operator<<(const char error) {
			Xs.LogStx += error;
			Xs.LogStx += '\n';
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
				strinx Red			= "f81d43";
				strinx DarkGreen	= "006243";
				strinx Blue			= "00b3e9";
				strinx Pink			= "ffdde3";
				strinx DarkBlue		= "5b49e2";
				strinx Grey			= "3a3949";
				strinx Purple		= "8e0aa5";
				strinx LightPurple	= "9270da";
				strinx Orange		= "ff5b17";
				strinx Yellow		= "e8ff35";
				strinx Lime			= "8ce50f";
			} Stx;
		} Hex;
		struct {
			vex3f HexToRGB(int hex) { return vex3f(((hex >> 16) & 0xff) / 255.f, ((hex >> 8) & 0xff) / 255.f, ((hex) & 0xff) / 255.f); };
			vex3i HexToRGB256(int hex) { return vex3i(((hex >> 16) & 0xff), ((hex >> 8) & 0xff), ((hex) & 0xff)); };
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
			Enter = 13,
			MouseLeft = 1,
			MouseRight = 2,
			MouseMiddle = 16
		};
	} Key;
	struct {
		enum Enum_t {
			Point = 0x01,
			Line = 0x02,
			Triangle = 0x03,
			Quad = 0x04,
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
	struct {
		struct {
			XsVertices Default{
				-1.f, -1.f, 0.f,
				-1.f, 1.f, 0.f,
				1.f, 1.f, 0.f,
				1.f, -1.f, 0.f
			};
			XsVertices Textured{
				-1.f, -1.f, 0.f,  0.f, 0.f,
				-1.f, 1.f, 0.f,  0.f, 1.f,
				1.f, 1.f, 0.f,  1.f, 1.f,
				1.f, -1.f, 0.f,  1.f, 0.f
			};
		} Square;
	} Vert;
	bool KeyPressed(unsigned char key) { return (GetKeyState(key) & 0x800); };
	vex2i MousePos() {
		POINT p;
		GetCursorPos(&p);
		return vex2i(p.x, p.y);
	};
	template <typename T> void XsGetMousePos(vex2<T>& v) {
		POINT p;
		GetCursorPos(&p);
		v = vex2<T>(p.x, p.y);
	};
	template <typename T> void XsGetMousePos(vex3<T>& v) {
		POINT p;
		GetCursorPos(&p);
		v = vex2<T>(p.x, p.y);
	};
	template <typename T> void XsGetMousePos(vex4<T>& v) {
		POINT p;
		GetCursorPos(&p);
		v = vex2<T>(p.x, p.y);
	};
	sf::Event Event;
} Xs;
void glColor3f(vex3f v) { glColor3f(v.x, v.y, v.z); };
void glColor3f(vex4f v) { glColor3f(v.x, v.y, v.z); };
void glColor3i(vex3i v) { glColor3i(v.x, v.y, v.z); };
void glColor3f(vex2f v, float v1) { glColor3f(v.x, v.y, v1); };
void glColor3f(float v1, vex2f v) { glColor3f(v1, v.x, v.y); };
void glColor4f(vex3f v) { glColor4f(v.x, v.y, v.z, 1); };
void glColor4i(vex3i v) { glColor4i(v.x, v.y, v.z, 1); };
void glColor4f(vex4f v) { glColor4f(v.x, v.y, v.z, v.w); };
void glColor4i(vex4i v) { glColor4i(v.x, v.y, v.z, v.w); };
void glColor4f(vex3f v, float v1) { glColor4f(v.x, v.y, v.z, v1); };
void glColor4f(float v1, vex3f v) { glColor4f(v1, v.x, v.y, v.z); };
void glColor4f(vex2f v, float v1, float v2) { glColor4f(v.x, v.y, v1, v2); };
void glColor4f(float v1, vex2f v, float v2) { glColor4f(v1, v.x, v.y, v2); };
void glColor4f(float v1, float v2, vex2f v) { glColor4f(v1, v2, v.x, v.y); };

void glTranslatef(vex2f v) { glTranslatef(v.x, v.y, 0); };
void glTranslatef(vex2f v, float v1) { glTranslatef(v.x, v.y, v1); };
void glTranslatef(vex3f v) { glTranslatef(v.x, v.y, v.z); };
void glTranslatef(vex4f v) { glTranslatef(v.x, v.y, v.z); };

void glRotatef(float v1, vex3f v) { glRotatef(v1, v.x, v.y, v.z); };
void glRotatef(vex3f v, float v1) { glRotatef(v1, v.x, v.y, v.z); };
void glRotatef(float v1, vex3d v) { glRotatef(v1, v.x, v.y, v.z); };
void glRotatef(vex3d v, float v1) { glRotatef(v1, v.x, v.y, v.z); };
void glRotatef(double v1, vex3f v) { glRotatef(v1, v.x, v.y, v.z); };
void glRotatef(vex3f v, double v1) { glRotatef(v1, v.x, v.y, v.z); };
void glRotatef(double v1, vex3d v) { glRotatef(v1, v.x, v.y, v.z); };
void glRotatef(vex3d v, double v1) { glRotatef(v1, v.x, v.y, v.z); };
void glRotatef(vex3f v) { glRotatef(v.x, 1, 0, 0); glRotatef(v.y, 0, 1, 0); glRotatef(v.z, 0, 0, 1); };
void glRotatef(vex4f v) { glRotatef(v.w, v.x, v.y, v.z); };
void glRotatef(vex4d v) { glRotatef(v.w, v.x, v.y, v.z); };

void glScalef(vex2f v) { glScalef(v.x, v.y, 1); };
void glScalef(vex3f v) { glScalef(v.x, v.y, v.z); };
void glScalef(vex4f v) { glScalef(v.x, v.y, v.z); };
void glScalef(vex2d v) { glScalef(v.x, v.y, 1); };
void glScalef(vex3d v) { glScalef(v.x, v.y, v.z); };
void glScalef(vex4d v) { glScalef(v.x, v.y, v.z); };
void glScalef(vex2i v) { glScalef(v.x, v.y, 1); };
void glScalef(vex3i v) { glScalef(v.x, v.y, v.z); };
void glScalef(vex4i v) { glScalef(v.x, v.y, v.z); };

void glVertex3f(float v) { glVertex3f(v, v, v); };
void glVertex3f(double v) { glVertex3f(float(v), float(v), float(v)); };
void glVertex3f(int v) { glVertex3f(float(v), float(v), float(v)); };
void glVertex3f(vex2f v) { glVertex3f(v.x, v.y, 0.f); };
void glVertex3f(vex3f v) { glVertex3f(v.x, v.y, v.z); };
void glVertex3f(vex4f v) { glVertex3f(v.x, v.y, v.z); };
void glVertex3f(vex2d v) { glVertex3f(float(v.x), float(v.y), 0.f); };
void glVertex3f(vex3d v) { glVertex3f(float(v.x), float(v.y), float(v.z)); };
void glVertex3f(vex4d v) { glVertex3f(float(v.x), float(v.y), float(v.z)); };
void glVertex3f(vex2i v) { glVertex3f(float(v.x), float(v.y), 0.f); };
void glVertex3f(vex3i v) { glVertex3f(float(v.x), float(v.y), float(v.z)); };
void glVertex3f(vex4i v) { glVertex3f(float(v.x), float(v.y), float(v.z)); };
void glVertex2f(vex2f v) { glVertex2f(v.x, v.y); };
void glVertex2f(vex3f v) { glVertex2f(v.x, v.y); };
void glVertex2f(vex4f v) { glVertex2f(v.x, v.y); };
void glVertex2f(vex2d v) { glVertex2f(float(v.x), float(v.y)); };
void glVertex2f(vex3d v) { glVertex2f(float(v.x), float(v.y)); };
void glVertex2f(vex4d v) { glVertex2f(float(v.x), float(v.y)); };
void glVertex2f(vex2i v) { glVertex2f(float(v.x), float(v.y)); };
void glVertex2f(vex3i v) { glVertex2f(float(v.x), float(v.y)); };
void glVertex2f(vex4i v) { glVertex2f(float(v.x), float(v.y)); };
#include "mesh/XsShape.hpp"
#include "system/XsCamera.hpp"
sf::ContextSettings contextSettings;

#define XsStart(_Window, _Name) for(([&]() -> void {										\
contextSettings.depthBits = 24;																\
contextSettings.stencilBits = 8;															\
contextSettings.antialiasingLevel = 0;														\
contextSettings.majorVersion = 3;															\
contextSettings.minorVersion = 3;															\
contextSettings.sRgbCapable = false;														\
_Window.create(sf::VideoMode(1500, 750), _Name, sf::Style::Default, contextSettings);		\
glewExperimental = GL_TRUE;																	\
glewInit();																					\
glEnable(GL_SCISSOR_TEST);																	\
glEnable(GL_DEPTH_TEST);																	\
glEnable(GL_NORMALIZE);																		\
glDepthFunc(GL_LESS);																		\
glShadeModel(GL_SMOOTH);																	\
glBlendFunc(GL_ZERO, GL_SRC_COLOR);															\
glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);					\
glBlendEquation(GL_FUNC_ADD);																\
glLoadIdentity();																			\
}());																						\
																							\
_Window.isOpen() || ([&]() -> bool {														\
glClearColor(0, 0, 0, 1.0);																	\
glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);											\
while (_Window.pollEvent(Xs.Event))															\
	if (Xs.Event.type == sf::Event::Closed)													\
		_Window.close();																	\
return false;																				\
}());																						\
																							\
([&]() -> void { _Window.display(); }()))
