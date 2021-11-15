## XsLib2
![dsfsf](https://cdn.discordapp.com/attachments/837068088473944104/909778067717763072/ezgif.com-gif-maker_2.gif)
```cpp
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

    XsShape shape("sahpe.json");
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

    XsInfoList info_list("list");
    info_list.Add("sdfdsf", tex);
    info_list.Add("sahpe", shape);
    info_list.Add("yre", floor);
    
    Xs.Editor.Cam.Speed_v = 0.03f;
    XsStart(window, "HELLO WORLD !!") {
        //if (Xs.KeyPressed(Xs.Key.Escape))
        //    break;
        Once(_change_them)
            im::StyleXsDark();

        kameram.viewport = { window.getSize().x, window.getSize().y };
        XsEditorCamera(kameram);

        floor.draw();
        shape.draw();

        ImBlock(window) {
            info_list.Draw();
            XsInfo(kameram, "kamerasd", true);
        };
    };
    shape.save("sahpe.json");
};
```
