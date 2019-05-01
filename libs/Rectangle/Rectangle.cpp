//
// Created by insane on 01.05.19.
//

#include "Rectangle.h"

void raygauge::Rectangle::_setDefaultValues() {
    height = 100;
    x = 0;
    y = 0;
    minValue = 0;
    maxValue = 150;
}

raygauge::Rectangle::Rectangle() {
    _setDefaultValues();
}

raygauge::Rectangle::Rectangle(int height) {
    _setDefaultValues();
    this->height = height;
}

raygauge::Rectangle::Rectangle(int x, int y) {
    _setDefaultValues();
    this->x = x;
    this->y = y;
}

raygauge::Rectangle::Rectangle(int height, int x, int y) {
    _setDefaultValues();
    this->height = height;
    this->x = x;
    this->y = y;
}

raygauge::Rectangle::Rectangle(int x, int y, int minValue, int maxValue) {
    _setDefaultValues();
    this->x = x;
    this->y = y;
    this->minValue = minValue;
    this->maxValue = maxValue;
}

raygauge::Rectangle::Rectangle(int height, int x, int y, int minValue, int maxValue) {
    _setDefaultValues();
    this->height = height;
    this->x = x;
    this->y = y;
    this->minValue = minValue;
    this->maxValue = maxValue;
}

raygauge::Rectangle::~Rectangle() {}

void raygauge::Rectangle::setValue(const std::string &value) {this->value = value;}

void raygauge::Rectangle::setMaxValue(int value) {maxValue = value;}

void raygauge::Rectangle::setMinValue(int value) {minValue = value;}

void raygauge::Rectangle::setY(int value) {y = value;}

void raygauge::Rectangle::setX(int value) {x = value;}

void raygauge::Rectangle::setHeight(int value) {height = value;}

std::string raygauge::Rectangle::getValue() { return value;}