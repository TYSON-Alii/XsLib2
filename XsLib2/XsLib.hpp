#include <utility>
#include <Windows.h>
#include <GL/glew.h>
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
		vex3f Red = vex3f(0.976f, 0.117f, 0.265f);
		vex3f DarkGreen = (0.000f, 0.386f, 0.265f);
		vex3f Blue = (0.000f, 0.703f, 0.917f);
		vex3f Pink = (1.000f, 0.867f, 0.894f);
		vex3f DarkBlue = (0.359f, 0.289f, 0.890f);
		vex3f Grey = (0.230f, 0.226f, 0.289f);
		vex3f Purple = (0.564f, 0.04f, 0.65f);
		vex3f MediumPurple = (0.576f, 0.439f, 0.858f);
		vex3f Orange = (1.00f, 0.36f, 0.09f);
		vex3f Yellow = (0.91f, 1.00f, 0.21f);
		vex3f Lime = (0.55f, 0.90f, 0.06f);
	} Color;
	struct {
		typedef unsigned char Key_t;
		Key_t A = 65, B = 66, C = 67, D = 68, E = 69, F = 70, G = 71, H = 72, I = 73, J = 74, K = 75, L = 76, M = 77, N = 78, O = 79, P = 80, Q = 81, R = 82, S = 83, T = 84, U = 85, V = 86, W = 87, X = 88, Y = 89, Z = 90;
		Key_t num0 = 48, num1 = 49, num2 = 50, num3 = 51, num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57;
		Key_t Space = 32;
		Key_t Escape = 27;
		Key_t Delete = 8;
		Key_t Tab = 9;
		Key_t Up = 38;
		Key_t Down = 40;
		Key_t Right = 39;
		Key_t Left = 37;
		Key_t Shift = 16;
		Key_t Enter = 13;
		Key_t MouseLeft = 1;
		Key_t MouseRight = 2;
		Key_t MouseMiddle = 16;
	} Key;
	struct {
		typedef unsigned char Enum_t;
		Enum_t Point = 0x01;
		Enum_t Line = 0x02;
		Enum_t Triangle = 0x03;
		Enum_t Quad = 0x04;
		Enum_t Int = 0x05;
		Enum_t Float = 0x06;
		Enum_t Double = 0x07;
		Enum_t Bool = 0x08;
		Enum_t String = 0x09;
		Enum_t Char = 0x0a;
		Enum_t All = 0x0b;
		Enum_t Vertex = 0x0c;
		Enum_t Normal = 0x0d;
		Enum_t Texture = 0x0e;
		Enum_t VertexAndTexture = 0x0f;
		Enum_t VertexAndNormal = 0x10;
		Enum_t Ceil = 0x11;
		Enum_t Trunc = 0x12;
		Enum_t Floor = 0x13;
		Enum_t Repeat = 0x14;
		Enum_t Reverse = 0x15;
		Enum_t Smooth = 0x16;
		Enum_t Hard = 0x17;
	} Enum;
	struct {
		typedef unsigned char Type_t;
		Type_t Cube = 0x01;
		Type_t Prism = 0x02;
		Type_t Sphere = 0x03;
		Type_t Cylinder = 0x04;
		Type_t Cone = 0x05;
		Type_t Monke = 0x06;
		Type_t Icosphere = 0x07;
		Type_t Torus = 0x08;
		Type_t Square = 0x09;
		Type_t Teapot = 0x0a;
		Type_t Star = 0x0b;
		Type_t Polygone = 0x0c;
		Type_t Box = 0x0d;
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
} Xs;