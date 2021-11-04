## XsLib2
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <XsLib.hpp>

int main() {
    sf::Window window;
    vex3f speed;
    XsCamera kameram;
    
    XsStart(window, "HELLO WORLD !!") {
        if (Xs.KeyPressed(Xs.Key.W))
            speed += kameram.rot * 0.1f;
        else if (Xs.KeyPressed(Xs.Key.S))
            speed -= kameram.rot * 0.1f;
        else if (!Xs.KeyPressed(Xs.Key.S) && !Xs.KeyPressed(Xs.Key.W))
            speed *= 0.98;
        if (Xs.KeyPressed(Xs.Key.Space))
            speed *= 0.75f;
        kameram.pos += speed;

        XsFPSCamera(kameram, Xs.MousePos() - vex2f(0.f, 350.f), 0.3f);

        if (Xs.KeyPressed(Xs.Key.Escape))
            break;
    };
};
```
