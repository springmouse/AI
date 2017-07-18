#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>

//sets all the possitions in the vector to 0
Vector2::Vector2()
{
    x = 0;
    y = 0;
}

//assigns all positions in the vector to the values requested by the user
Vector2::Vector2(realNum _x, realNum _y)
{
    x = _x;
    y = _y;
}

Vector2::~Vector2()
{
}

//gets the magnitude of the vector
realNum Vector2::magnitude()
{
    return (realNum)sqrt((pow(x, 2) + pow(y, 2)));
}

//this normalises the vector seting it to a unit leangth of 1 or less
void Vector2::normalise()
{
    realNum m = this->magnitude();

    if (m != 0)
    {
        this->x /= m;
        this->y /= m;
    }
    else
    {
        this->x = 0;
        this->y = 0;
    }
}

//finds the dot product of the vector
realNum Vector2::dot(Vector2 & refV)
{
    return ((this->x * refV.x) + (this->y * refV.y));
}

//returns a vector with only a positive x 
Vector2 Vector2::Right()
{
    return Vector2(1, 0);
}

//returns a vector with only a Negative x
Vector2 Vector2::Leaft()
{
    return Vector2(-1, 0);
}

//returns a vector with only a positive y
Vector2 Vector2::Up()
{
    return Vector2(0, 1);
}

//returns a vector with only a Negative y
Vector2 Vector2::Down()
{
    return Vector2(0, -1);
}

//allows us to type cast to a vector4
Vector2::operator Vector4()
{
    return Vector4(x, y, (realNum)0.0, (realNum)0.0);
}

//allows us to type cast to a vector3
Vector2::operator Vector3()
{
    return Vector3(x, y, (realNum)0.0f);
}

//creates a new vector by adding to other vectors and returns that new vecotr
Vector2 Vector2::operator + (Vector2 & refA) 
{
    Vector2 v;

    v.x = this->x + refA.x;
    v.y = this->y + refA.y;

    return v;
}

//adds one vector to another
void Vector2::operator += (Vector2 & refA)
{
    this->x += refA.x;
    this->y += refA.y;
}

//creates a new vector by subtracting two other vectors then returns that
Vector2 Vector2::operator - (Vector2 & refA) 
{
    Vector2 v;

    v.x = this->x - refA.x;
    v.y = this->y - refA.y;

    return v;
}

//subtracts one vector from another
void Vector2::operator -= (Vector2 & refA)
{
    this->x -= refA.x;
    this->y -= refA.y;
}

//makes the vector equal to another vector
void Vector2::operator = (const Vector2 & refA)
{
        this->x = refA.x;
        this->y = refA.y;
}

//checks if two vectors have the same values
bool Vector2::operator == (Vector2 & refA) 
{
    if (this->x == refA.x && this->y == refA.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//checks if the two vectors are diffrent
bool Vector2::operator != (Vector2 & refA) 
{
    if (this->x != refA.x || this->y != refA.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//multiplies the vector by a scaler/realNum and assigns that to a new vector that is passed back out
Vector2 Vector2::operator * (realNum scaler)
{
    return Vector2(this->x * scaler, this->y * scaler);
}

//multiplies the vector by a scaler/realNum 
void Vector2::operator *= (realNum scaler)
{
    this->x *= scaler;
    this->y *= scaler;
}

//allows you to easily and quickly acces the vectors positions of x and y
realNum & Vector2::operator [] (int index)
{
    switch (index)
    {

    case 0: 
        return x;
    case 1:
        return y;

    default: throw;
    }
}

//exactly the same but dose not allow you to change any of the variables(needed for some matrix stuff)
const realNum & Vector2::operator [] (int index) const{
    switch (index)
    {

    case 0:
        return x;
    case 1:
        return y;

    default: throw;
    }
}

#pragma region MySwizzleFunctions

    //swizzling the Vector2 to creat a new Vector2
    Vector2 Vector2::GetXX()
    {
        return Vector2{ x,x };
    }

    //swizzling the Vector2 to creat a new Vector2
    Vector2 Vector2::GetYX()
    {
        return Vector2{ y,x };
    }

    //swizzling the Vector2 to creat a new Vector2
    Vector2 Vector2::GetYY()
    {
        return Vector2{ y,y };
    }

#pragma endregion
