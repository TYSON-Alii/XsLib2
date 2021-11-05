## XsLib2
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "XsLib2/XsLib.hpp"

using namespace std;

int main() {
    sf::Window window;
    vex3f speed = 0.f;
    XsCamera kameram;
    kameram.fov = 45.0f;
    kameram.far_ = 1000;
    kameram.viewport = vex2f(1200, 750);
    kameram.near_ = 0.01;
    kameram.pos = vex3f(0, 0, 0);

    XsVerts magic;
    magic = Xs.LoadOBJ("data/cube.obj", Xs.Enum.VertexAndTexture);
    XsTexture tex("data/mavi_32x32.png");

    XsShape shape;
    shape.vert = &magic;
    shape.tex = &tex;

    XsStart(window, "HELLO WORLD !!") {
        if (Xs.KeyPressed(Xs.Key.Escape))
            break;

        if (Xs.KeyPressed(Xs.Key.W))
            speed += kameram.rot * 0.02f;
        else if (Xs.KeyPressed(Xs.Key.S))
            speed -= kameram.rot * 0.02f;
        else if (!Xs.KeyPressed(Xs.Key.S) && !Xs.KeyPressed(Xs.Key.W))
            speed *= 0.95;
        if (Xs.KeyPressed(Xs.Key.Space))
            speed *= 0.75f;
        kameram.pos += speed;

        XsFPSCamera(kameram, Xs.MousePos() - vex2f(0.f, 350.f), 0.3f);

        shape.draw();
    };
};
```
