#include <cmath>
#include <algorithm>

namespace liquid { namespace shape {
#ifndef _VECTOR2_H
#define _VECTOR2_H

#define PI 3.14159265359

class Vector2
{
public:
    Vector2();
    Vector2(float directionX, float directionY);
    ~Vector2();

    void setDirectionX(float directionX);
    void setDirectionY(float directionY);
    void setAngle(float angle);
    void setMagnitude(float magnitude);

    void invertX();
    void invertY();
    void scale(float magnitude);
    void polar(float magnitude, float angle);

    const float angle(Vector2& other);
    const float dotProduct(Vector2& other);
    const float lineProduct(Vector2& other);
    const float projection(Vector2& other);

    Vector2& rotate(float angle);
    Vector2& normalise();
    Vector2& lineNormal();

    const float getDirectionX();
    const float getDirectionY();
    const float getMagnitude();
    const float getAngle();

    Vector2& operator= (Vector2& vector);
    Vector2& operator- (Vector2& vector);
    Vector2& operator+ (Vector2& vector);
    Vector2& operator* (Vector2& vector);
    Vector2& operator/ (Vector2& vector);
    Vector2& operator+= (Vector2& vector);
    Vector2& operator-= (Vector2& vector);
    Vector2& operator*= (Vector2& vector);
    Vector2& operator/= (Vector2& vector);
    bool operator== (Vector2& vector);

protected:
    float mDirectionX;
    float mDirectionY;
};

#define VECTOR2X Vector2(1.0f, 0.0f);
#define VECTOR2Y Vector2(0.0f, 1.0f);
#define VECTOR20 Vector2(0.0f, 0.0f);

#endif // _VECTOR2_H
}}