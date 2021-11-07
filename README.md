## XsLib2
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <XsLib.hpp>

using namespace std;
namespace im = ImGui;

int main() {
    sf::RenderWindow window;
    vex3f speed = 0.f;
    XsCamera kameram;
    kameram.fov = 45.0f;
    kameram.far_ = 1000.f;
    kameram.viewport = { 1200, 750 };
    kameram.near_ = 0.01f;
    kameram.pos = vex3f(20.f, 20.f, 0.f);

    XsTexture tex("data/mavi_32x32.png");
    XsVerts magic;
    magic = Xs.LoadOBJ("data/cube.obj", Xs.Enum.VertexAndTexture);

    XsShape shape;
    shape.mode = Xs.Enum.VertexAndTexture;
    shape.glmode = GL_QUADS;
    shape.vert = &magic;
    shape.tex = &tex;

    XsVerts floor_vert;
    floor_vert = Xs.LoadOBJ("data/plane.obj", Xs.Enum.VertexAndTexture);
    XsShape floor;
    floor.mode = Xs.Enum.VertexAndTexture;
    floor.vert = &floor_vert;
    floor.tex = &tex;

    XsStart(window, "HELLO WORLD !!") {
        if (Xs.KeyPressed(Xs.Key.Escape))
            break;

        if (Xs.KeyPressed(Xs.Key.W))
            speed += kameram.rot * 0.01f;
        else if (Xs.KeyPressed(Xs.Key.S))
            speed -= kameram.rot * 0.01f;
        else if (!Xs.KeyPressed(Xs.Key.S) && !Xs.KeyPressed(Xs.Key.W))
            speed *= 0.95f;
        if (Xs.KeyPressed(Xs.Key.Space))
            speed *= 0.75f;
        kameram.pos += speed;

        XsFPSCamera(kameram, Xs.Mouse.Pos() - vex2f(0.f, 350.f), 0.3f);

        floor.draw();
        shape.draw();

        ImBlock(window) {
            XsInfo(shape, "sahpe");
            XsInfo(floor, "yre");
        };
    };
};
```
