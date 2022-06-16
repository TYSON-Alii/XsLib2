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
var win = eng.Window;
var cam = eng.Cam;
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
        if(Xs.Key.Pressed(Xs.Key.Space))
            vel.y += 0.005f;
        if (eng.shapes.back().value->id == id and Xs.Key.Pressed(Xs.Mouse.Left))
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
        // if (life_time.getMilliSeconds() > 4.f) destroy();
    };
};
var yer = eng.create(new Shape());
var kayadam = eng.create(new Kayadam("first kayadam"));
var plane = eng.create(new Mesh(Xs.LoadOBJ("data/fena.obj")));
var anim = eng.create(new Anim());
var light0 = eng.create(new Light({ 15,15,15 }, 255));
var light1 = eng.create(new Light({ -15,15,-15 }, { 100,25,220 }, 1000.f));
Chrono spawn_timer;
int counter = 0;

void XsEngine::init() {
    cam.pos = vex3f(20.f, 20.f, 0.f);
    anim.loadFromGIF("data/fizbuz.gif");
    yer.scale = 75;
    yer.mesh = &plane;
    yer.tex = &anim.current();
    Xs.Editor.Cam.Speed_v = 0.03f;
}

void XsEngine::loop() {
    Once(im::StyleXsDark());
    cam.editor();
    light1.pos = cam.pos + cam.rot * 10;
    if (Xs.Limiter(spawn_timer, 0.3f) and Xs.Key.Pressed(Xs.Key.Q)) {
        eng.create(new Kayadam("kayadam "s + to_string(counter++)));
    };
    if (Xs.Key.Pressed(Xs.Key.Space))
        cout << eng.shapes.size() << '\n';
}

void XsEngine::shutdown() {
    echo "program end.\n";
}

void XsEngine::gui() {
    Xs.Info(yer, "floor");
    Xs.Info(light1, "light1");
}

auto main() -> int {
    str win_name;
    cout << "app name: ";
    std::cin >> win_name;
    eng.play(win_name);
};
```
