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
    kameram.far = 1000.f;
    kameram.near = 0.01f;
    kameram.pos = vex3f(20.f, 20.f, 0.f);

    XsTexture tex("data/mavi_32x32.png");
    XsVerts magic;
    magic = Xs.LoadOBJ("data/cube.obj", Xs.Enum.VertexAndTexture);

    XsShape shape;
    shape.mode = Xs.Enum.VertexAndTexture;
    shape.glmode = GL_QUADS;
    shape.vert = &magic;
    std::cout << shape;

    XsVerts floor_vert;
    floor_vert = Xs.LoadOBJ("data/plane.obj", Xs.Enum.VertexAndTexture);
    XsShape floor;
    floor.mode = Xs.Enum.VertexAndTexture;
    floor.vert = &floor_vert;
    floor.tex = &tex;
    
    Xs.Editor.Cam.Speed_v = 0.03f;
    XsStart(window, "HELLO WORLD !!") {
        if (Xs.KeyPressed(Xs.Key.Escape))
            break;
        kameram.viewport = { window.getSize().x, window.getSize().y };
        XsEditorCamera(kameram);

        floor.draw();
        shape.draw();

        ImBlock(window) {
            XsInfo(shape, "sahpe");
            XsInfo(floor, "yre");
        };
    };
};
```
