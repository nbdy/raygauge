//
// Created by insane on 01.05.19.
//

#ifndef RAYGAUGE_CIRCLE_H
#define RAYGAUGE_CIRCLE_H


#include <string>
#include <cmath>

namespace raygauge {
    class Circle {
    public:
        Circle();
        explicit Circle(int radius);
        Circle(int minValue, int maxValue);
        Circle(int minValue, int maxValue, int radius);
        Circle(int minValue, int maxValue, int x, int y);
        Circle(int minValue, int maxValue, int x, int y, int radius);
        Circle(int minValue, int maxValue, int x, int y, int radius, int segments);
        Circle(int minValue, int maxValue, int x, int y, int radius, int segments, int borderThickness);
        ~Circle();

        void setValue(const std::string& value);
        void setX(int value);
        void setY(int value);
        void setMinValue(int value);
        void setMaxValue(int value);
        void setRadius(int value);
        void setSegments(int value);
        void setBorderThickness(int value);
        void setTextSize(int value);
        void setOffset(int value);
        void setMiddleCircleRadius(int value);
        void setUnits(const std::string& value);
        void setDegreesOfCircleUsage(int value);

        std::string getValue();
        int getMaxValue();
        int getMinValue();

        virtual void draw();
    protected:
        void _setDefaultValues();
        void drawCircle();

        int degreesOfCircleUsage;
        int x;
        int y;
        int minValue;
        int maxValue;
        std::string value;
        std::string units;
        int radius;
        int segments;
        int borderThickness;
        int textSize;
        int offset;
        int middleCircleRadius;
    };

    class CircleWithExtraValue : public Circle {
    public:
        CircleWithExtraValue();
        ~CircleWithExtraValue();

        void draw() override;

        void setExtraValue(const std::string& value);

        std::string getExtraValue();
    protected:
        void drawCircleWithExtraValue();

    private:
        std::string extraValue;
    };
}

#endif //RAYGAUGE_CIRCLE_H
