## XsLib2
### Requirements
[SFML - 2.5.1](https://github.com/SFML/SFML)

[Physx - 4.1](https://github.com/NVIDIAGameWorks/PhysX)

[glm - latest](https://github.com/g-truc/glm)

[glew - latest](https://github.com/nigels-com/glew)

### Include Directorys
\XsLib2

\XsLib2\ImGui

\XsLib2\librarys

### Code View
```cpp
#include <XsLib.hpp>
#include <Utilityx.hpp>
namespace im = ImGui;
#define win ::eng.Window
#define cam ::eng.Cam
var kayatex = eng.create(new Texture("data/kayadam.png"));
var kayavert = eng.create(new Mesh(Xs.LoadOBJ("data/kayadam.obj")));
class Kayadam : public Shape {
public:
    Kayadam(const string& _tag) : Shape(_tag) {
        pos = cam.pos + cam.rot * 10.f;
        vel = cam.rot;
        tex = &kayatex;
        mesh = &kayavert;
    };
    vex3f vel = 0.f;
    vex3f hitbox = 2.f;
    Chrono life_time;
    void controller() {
        vel.y -= 0.001f;
        if(Xs.KeyPressed(Xs.Key.Space))
            vel.y += 0.005f;
        if (eng.shapes.back().value->id == id and Xs.KeyPressed(Xs.Mouse.Button.Left))
            vel = (pos - (cam.pos + cam.rot * 10.f)) * (Xs.Math.Distance(pos, cam.pos) / -100.f);
    };
    void physics() {
        pos += vel;
        const auto& touch_axis = limit(pos, vex3f(-50, 0, -50)-hitbox/2.f, vex3f(50)+hitbox/2.f);
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
    var floor = eng.create(new Shape());
    var kayadam = eng.create(new Kayadam("tasak"));
    var plane = eng.create(new Mesh(Xs.LoadOBJ("data/fena.obj")));
    floor.scale = 75;
    floor.mesh = &plane;
    var anim = eng.create(new Anim());
    anim.loadFromGIF("data/fizbuz.gif");
    floor.tex = &anim.Current();
    Xs.Editor.Cam.Speed_v = 0.03f;
    var light0 = eng.create(new Light({ 15,15,15 }, { 1,1,1 }));
    var light1 = eng.create(new Light({ -15,15,-15 }, { 0.4,0.1,0.8 }, 1000.f));
    Chrono spawn_timer;
    int counter = 0;
    XsStart(eng, "HELLO WORLD !!") {
        Once(im::StyleXsDark())
        kameram.viewport << win.getSize();
        XsEditorCamera(kameram);
        light1.pos = cam.pos+cam.rot*10;
        if (Xs.KeyPressed(Xs.Key.Q) and XsLimiter(spawn_timer, 1)) {
            eng.create(new Kayadam("tasak "s+to_string(counter++)));
        };
        eng.play();
        if (Xs.KeyPressed(Xs.Key.Space))
            echo eng.shapes.size() << '\n';
        ImBlock(win) {
            XsInfo(floor, "roomke");
            XsInfo(light0, "light0");
            XsInfo(light1, "light1");
        }
    };
};
```
