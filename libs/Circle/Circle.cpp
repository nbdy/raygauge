//
// Created by insane on 01.05.19.
//

#include "Circle.h"
#include <raylib.h>
#include <iostream>


void raygauge::Circle::_setDefaultValues() {
    x = 0;
    y = 0;
    minValue = 0;
    maxValue = 420;
    radius = 64;
    borderThickness = 4;
    segments = maxValue / 10;
    textSize = 16;
    offset = 90;
    middleCircleRadius = 4;
    degreesOfCircleUsage = 300;
}

raygauge::Circle::Circle() {
    _setDefaultValues();
}

raygauge::Circle::Circle(int radius) {
    _setDefaultValues();
    this->radius = radius;
}

raygauge::Circle::Circle(int minValue, int maxValue) {
    _setDefaultValues();
    this->minValue = minValue;
    this->maxValue = maxValue;
}

raygauge::Circle::Circle(int minValue, int maxValue, int radius) {
    _setDefaultValues();
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->radius = radius;
}

raygauge::Circle::Circle(int minValue, int maxValue, int x, int y) {
    _setDefaultValues();
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->x = x;
    this->y = y;
}

raygauge::Circle::Circle(int minValue, int maxValue, int x, int y, int radius) {
    _setDefaultValues();
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->x = x;
    this->y = y;
    this->radius = radius;
}

raygauge::Circle::Circle(int minValue, int maxValue, int x, int y, int radius, int segments) {
    _setDefaultValues();
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->segments = segments;
}

raygauge::Circle::Circle(int minValue, int maxValue, int x, int y, int radius, int segments, int borderThickness) {
    _setDefaultValues();
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->segments = segments;
    this->borderThickness = borderThickness;
}

void raygauge::Circle::setValue(const std::string& value) {this->value = value;}

void raygauge::Circle::setY(int value) {y = value;}

void raygauge::Circle::setX(int value) {x = value;}

void raygauge::Circle::setMaxValue(int value) {maxValue = value;}

void raygauge::Circle::setMinValue(int value) {minValue = value;}

void raygauge::Circle::setRadius(int value) {radius = value;}

void raygauge::Circle::setSegments(int value) {segments = value;}

void raygauge::Circle::setBorderThickness(int value) {borderThickness = value;}

void raygauge::Circle::setTextSize(int value) {textSize = value;}

void raygauge::Circle::setOffset(int value) {offset = value;}

void raygauge::Circle::setMiddleCircleRadius(int value) {middleCircleRadius = value;}

void raygauge::Circle::setUnits(const std::string &value) {units = value;}

void raygauge::Circle::setDegreesOfCircleUsage(int value) {degreesOfCircleUsage = value;}

std::string raygauge::Circle::getValue() {return value;}

int raygauge::Circle::getMaxValue() {return maxValue;}

int raygauge::Circle::getMinValue() {return minValue;}

raygauge::Circle::~Circle() {}

void raygauge::Circle::drawCircle() {
    int xc = x + radius;
    int yc = y + radius;
    DrawCircle(xc, yc, radius - borderThickness / 2, GREEN);
    DrawCircle(xc, yc, radius - borderThickness - 16, BLACK); // todo indicator length setter
    for(int i = 0; i < segments; i++){
        int a = i * (degreesOfCircleUsage / segments);
        double d = ((a + offset) * PI / 180);
        double px = xc + radius * cos(d);
        double py = yc + radius * sin(d);
        DrawLine(xc, yc, (int) px, (int) py, GREEN);
    }
    DrawCircle(xc, yc, radius - borderThickness, BLACK);
    for(int i = 0; i < segments; i+=2){
        int a = i * (degreesOfCircleUsage / segments);
        double d = ((a + offset) * PI / 180);
        double px = xc + radius * cos(d);
        double py = yc + radius * sin(d);
        DrawLine(xc, yc, (int) px, (int) py, GREEN);
        double npx = px - xc;
        double npy = py - yc;
        if(npx >= 0 && npy >= 0) px += 8;
        if(npx <= 0 && npy <= 0) {
            py -= 16;
            px -= 20;
        }
        if(npx <= 0 && npy >= 0) px -= 16;
        if(npx >= 0 && npy <= 0) py -= 16; // todo fix
        DrawText(std::to_string((maxValue / segments) * i).c_str(), (int) px, (int) py, textSize, GREEN);
    }
    DrawCircle(xc, yc, radius - borderThickness - 8, BLACK);
    DrawCircle(xc, yc, middleCircleRadius, GREEN);
    double d = ((atof(value.c_str()) + offset) * PI / 180); // todo fix not on right value
    double px = xc + radius * cos(d);
    double py = yc + radius * sin(d);
    DrawLine(xc, yc, (int) px, (int) py, GREEN); // todo fix
    DrawText(units.c_str(), xc - MeasureText(units.c_str(), textSize) / 2, yc - 42, textSize, GREEN);
}

void raygauge::Circle::draw() {
    drawCircle();
}

raygauge::CircleWithExtraValue::CircleWithExtraValue() {

}

raygauge::CircleWithExtraValue::~CircleWithExtraValue() {

}

void raygauge::CircleWithExtraValue::setExtraValue(const std::string& value) {extraValue = value;}

std::string raygauge::CircleWithExtraValue::getExtraValue() {return extraValue;}

void raygauge::CircleWithExtraValue::draw() {
    drawCircle();
    drawCircleWithExtraValue();
}

void raygauge::CircleWithExtraValue::drawCircleWithExtraValue() {
    int cx = x + radius;
    int cy = y + radius;
    DrawText(extraValue.c_str(), cx - MeasureText(extraValue.c_str(), textSize) / 2, cy + 42, textSize, GREEN);
}