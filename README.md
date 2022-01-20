## XsLib2

```cpp
#include <XsLib.hpp>
namespace im = ImGui;
#define win eng.Window
#define cam eng.Cam
#define var auto&
XsEngine eng;

class Kayadam : public XsShape {
private:
public:
    vex3f vel = 0.f;
    vex3f hitbox = 2.f;
    void controller() {
        vel.y -= 0.001f;
        if (Xs.KeyPressed(Xs.Key.Space))
            vel.y += 0.005f;
        //if (Xs.KeyPressed(Xs.Mouse.Button.Right))
        //    vel = (pos - (eng.Cam.pos + eng.Cam.rot * 10.f)) * ((Xs.Math.Distance(pos, eng.Cam.pos) + 10) / -100.f);
    };
    void physics() {
        pos += vel;
        const auto& touch_axis = limit(pos, vex3f(-50, 0, -50) - hitbox / 2.f, vex3f(50) + hitbox / 2.f);
        vel(touch_axis, -(vel*0.8f));
    };
    void loop() {
        controller();
        physics();
    };
};
auto main() -> int {
    var kameram = eng.Cam;
    kameram.pos = vex3f(20.f, 20.f, 0.f);
    var floor = eng.New(new XsShape());
    var kayadam = eng.New(new Kayadam());
    var kayatex = eng.New(new XsTexture("data/kayadam.png"));
    var plane = eng.New(new XsMesh(Xs.LoadOBJ("data/fena.obj")));
    var kayavert = eng.New(new XsMesh(Xs.Mesh.Cube));
    kayavert = Xs.LoadOBJ("data/kayadam.obj");
    kayadam.mesh = &kayavert;
    kayadam.tex = &kayatex;
    floor.scale = vex3f(75, 75, 75);
    floor.mesh = &plane;
    var anim = eng.New(new XsAnim());
    anim.loadFromGIF("data/fizbuz.gif");
    floor.tex = &anim.Current();
    Xs.Editor.Cam.Speed_v = 0.03f;
    var light0 = eng.New(new XsLight({ 15,15,15 }, { 1,1,1 }));
    var light1 = eng.New(new XsLight({ -15,15,-15 }, { 0.4,0.1,0.8 }));
    XsStart(eng, "HELLO WORLD !!") {
        Once(once) {
            ImGui::StyleXsDark();
        };
        kameram.viewport << win.getSize();
        XsEditorCamera(kameram);
        light1.pos = cam.pos + cam.rot * 10;
        eng();
        ImBlock(win) {
            XsInfo(floor, "roomke");
            XsInfo(kayadam, "kayake");
            XsInfo(light0, "light0");
            XsInfo(light1, "light1");
        }
    };
};
```
