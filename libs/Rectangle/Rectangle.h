//
// Created by insane on 01.05.19.
//

#ifndef RAYGAUGE_RECTANGLE_H
#define RAYGAUGE_RECTANGLE_H


#include <string>

namespace raygauge {
    class Rectangle {
    public:
        Rectangle();
        explicit Rectangle(int height);
        Rectangle(int x, int y);
        Rectangle(int height, int x, int y);
        Rectangle(int x, int y, int minValue, int maxValue);
        Rectangle(int height, int x, int y, int minValue, int maxValue);
        ~Rectangle();

        void setHeight(int value);
        void setX(int value);
        void setY(int value);
        void setMinValue(int value);
        void setMaxValue(int value);
        void setValue(const std::string& value);

        std::string getValue();

    protected:
        void _setDefaultValues();

        int height;
        int x;
        int y;
        int minValue;
        int maxValue;

        std::string value;
    };
}


#endif //RAYGAUGE_RECTANGLE_H
