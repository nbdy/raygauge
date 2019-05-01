#include <iostream>
#include <raylib.h>
#include "libs/Circle/Circle.h"
#include "libs/Rectangle/Rectangle.h"


int main() {
    auto *c = new raygauge::CircleWithExtraValue();
    c->setRadius(100);
    c->setX(50);
    c->setY(50);
    c->setOffset(135);
    c->setMaxValue(260);
    c->setSegments(13);
    c->setValue("200");
    c->setUnits("km/h");
    c->setColor(RED);
    c->setExtraValue("420666");
    c->setDegreesOfCircleUsage(280);

    auto* r = new raygauge::Rectangle();
    r->setX(300);
    r->setY(100);
    r->setValue("42");

    int w = 1000;
    int h = 1000;
    InitWindow(w, h, "gauge test");
    SetTargetFPS(30);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        c->draw();
        EndDrawing();
    }
    return 0;
}