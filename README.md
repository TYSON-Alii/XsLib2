## XsLib2

```cpp
#include <XsLib.hpp>

class Kayadam : public XsShape {
private:
public:
    vex3f vel = 0.f;
    vex3f hitbox = 2.f;
    void controller() {
        if (Xs.KeyPressed(Xs.Key.Space))
            vel.y += 0.005f;
    };
    void physics() {
        vel.y -= 0.001f;
        pos += vel;
        const auto touch_axis = limit(pos, vex3f(-50, 0, -50) - hitbox / 2.f, vex3f(50, 50, 50) + hitbox / 2.f);
        vel(touch_axis, 0.f);
    };
    void loop() {
        controller();
        physics();
    };
};
#define win eng.Window
#define var auto&
auto main() -> int {
    XsEngine eng;
    var kameram = eng.Cam;
    kameram.pos = vex3f(20.f, 20.f, 0.f);
    var room = eng.New(new XsShape());
    var kayadam = eng.New(new Kayadam());
    var square_tex = eng.New(new XsTexture("data/mavi_32x32.png"));
    var kayatex = eng.New(new XsTexture("data/kayadam.png"));
    var cube = eng.New(new XsMesh());
    var kayavert = eng.New(new XsMesh());
    kayavert = Xs.LoadOBJ("data/kayadam.obj");
    kayadam.mesh = &kayavert;
    kayadam.tex = &kayatex;
    cube = Xs.LoadOBJ("data/magic.obj");
    room.pos.y = 25;
    room.scale = vex3f(75, 75, 75);
    room.mesh = &cube;
    var anim = eng.New(new XsAnim());
    anim.loadFromGIF("data/fizbuz.gif");
    room.tex = &anim.Current();
    Xs.Editor.Cam.Speed_v = 0.03f;
    XsStart(eng, "HELLO WORLD !!") {
        kameram.viewport << win.getSize();
        XsEditorCamera(kameram);
        eng();
        ImBlock(eng.Window) {
            XsInfo(room);
        }
    };
};
```
