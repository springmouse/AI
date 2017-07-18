#include "Vector3.h"
#include "Vector4.h"

#include <math.h>

//sets all the possitions in the vector to 0
Vector3::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
}

//assigns all positions in the vector to the values requested by the user
Vector3::Vector3(realNum _x, realNum _y, realNum _z)
{
    x = _x;
    y = _y;
    z = _z;
}

Vector3::~Vector3()
{
}

//gets the magnitude of the vector
realNum Vector3::magnitude()
{
    return (realNum)sqrt((pow(x, 2) + pow(y, 2)) + pow(z, 2));
}

//this normalises the vector seting it to a unit leangth of 1 or less
void Vector3::normalise()
{
    realNum m = this->magnitude();

    if (m != 0)
    {
        this->x /= m;
        this->y /= m ;
        this->z /= m;
    }
    else
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

}

//this normalises the vector seting it to a unit leangth of 1 or less
Vector3 Vector3::normalised()
{
    realNum m = this->magnitude();
    Vector3 vec;

    if (m != 0)
    {
        vec = Vector3(this->x / m, this->y / m, this->z / m);
    }
    else
    {
        vec = Vector3();
    }

    return vec;
}

//finds the dot product of the vector
realNum Vector3::dot(Vector3 & refA)
{
    return ((this->x * refA.x) + (this->y * refA.y) + (this->z * refA.z));
}

//this gets the cross product of two vectors
Vector3 Vector3::cross(Vector3 & refA)
{
    Vector3 v;

    v.x = ((this->y * refA.z) - (this->z * refA.y));
    v.y = ((this->z * refA.x) - (this->x * refA.z));
    v.z = ((this->x * refA.y) - (this->y * refA.x));

    return v;
}

//returns a vector with only a positive x 
Vector3 Vector3::Right()
{
    return Vector3(1, 0, 0);
}

//returns a vector with only a Negative x
Vector3 Vector3::Leaft()
{
    return Vector3(-1, 0, 0);
}

//returns a vector with only a positive y
Vector3 Vector3::Up()
{
    return Vector3(0, 1, 0);
}

//returns a vector with only a Negative y
Vector3 Vector3::Down()
{
    return Vector3(0, -1, 0);
}

//returns a vector with only a positive z
Vector3 Vector3::Forward()
{
    return Vector3(0, 0, 1);
}

//returns a vector with only a Negative z
Vector3 Vector3::Backward()
{
    return Vector3(0, 0, -1);
}

//allows us to type cast from a vector 3 to a vector 4
Vector3::operator Vector4()
{
    return Vector4(x, y, z, (realNum)0.0f);
}

//allows us to type cast to a vector2
Vector3::operator Vector2()
{
    return Vector2(x, y);
}

//creates a new vector by adding to other vectors and returns that new vecotr
Vector3 Vector3::operator + (const Vector3 & refA) const
{
    Vector3 v;

    v.x = this->x + refA.x;
    v.y = this->y + refA.y;
    v.z = this->z + refA.z;

    return v;
}

//adds one vector to another
void Vector3::operator += (const Vector3 & refA)
{
    this->x += refA.x;
    this->y += refA.y;
    this->z += refA.z;
}

//creates a new vector by subtracting two other vectors then returns that
Vector3 Vector3::operator - (const Vector3 & refA) const
{
    Vector3 v;

    v.x = this->x - refA.x;
    v.y = this->y - refA.y;
    v.z = this->z - refA.z;

    return v;
}

//subtracts one vector from another
void Vector3::operator -= (const Vector3 & refA)
{
    this->x -= refA.x;
    this->y -= refA.y;
    this->z -= refA.z;
}

//makes the vector equal to another vector
void Vector3::operator = (const Vector3 & refA)
{
    this->x = refA.x;
    this->y = refA.y;
    this->z = refA.z;
}

//checks if two vectors have the same values
bool Vector3::operator == (const Vector3 & refA) const
{
    if (this->x == refA.x && this->y == refA.y && this->z == refA.z)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//checks if the two vectors are diffrent
bool Vector3::operator != (const Vector3 & refA) const
{
    if (this->x != refA.x || this->y != refA.y || this->z != refA.z)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//multiplies the vector by a scaler/realNum and assigns that to a new vector that is passed back out
Vector3 Vector3::operator * (const realNum scaler) const
{
    return Vector3(this->x * scaler, this->y * scaler, this->z * scaler);
}

//multiplies the vector by a scaler/realNum 
void Vector3::operator *= (const realNum scaler)
{
    this->x *= scaler;
    this->y *= scaler;
    this->z *= scaler;
}

//allows you to easily and quickly acces the vectors positions of x and y
realNum & Vector3::operator [] (int index)
{
    switch (index)
    {

    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;

    default: throw;
    }
}

//exactly the same but dose not allow you to change any of the variables(needed for some matrix stuff)
const realNum & Vector3::operator [] (int index) const
{
    switch (index)
    {

    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;

    default: throw;
    }
}

#pragma region MySwizzleThings

    //swizzling the Vector3 to creat a new Vector2
    Vector2 Vector3::GetXX()
    {
        return Vector2{ x,x };
    }

    //swizzling the Vector3 to creat a new Vector2
    Vector2 Vector3::GetXY()
    {
        return Vector2{ x,y };
    }

    //swizzling the Vector3 to creat a new Vector2
    Vector2 Vector3::GetXZ()
    {
        return Vector2{ x,z };
    }

    //swizzling the Vector3 to creat a new Vector2
    Vector2 Vector3::GetYX()
    {
        return Vector2{ y,x };
    }

    //swizzling the Vector3 to creat a new Vector2
    Vector2 Vector3::GetYY()
    {
        return Vector2{ y,y };
    }

    //swizzling the Vector3 to creat a new Vector2
    Vector2 Vector3::GetYZ()
    {
        return Vector2{ y,z };
    }

    //swizzling the Vector3 to creat a new Vector2
    Vector2 Vector3::GetZX()
    {
        return Vector2{ z,x };
    }

    //swizzling the Vector3 to creat a new Vector2
    Vector2 Vector3::GetZY()
    {
        return Vector2{ z,y };
    }

    //swizzling the Vector3 to creat a new Vector2
    Vector2 Vector3::GetZZ()
    {
        return Vector2{ z,z };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetXXX()
    {
        return Vector3{ x,x,x };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetXXY()
    {
        return Vector3{ x,x,y };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetXXZ()
    {
        return Vector3{ x,x,z };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetXYX()
    {
        return Vector3{ x,y,x };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetXYY()
    {
        return Vector3{ x,y,y };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetXZX()
    {
        return Vector3{ x,z,x };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetXZY()
    {
        return Vector3{ x,z,y };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetXZZ()
    {
        return Vector3{ x,z,z };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetYXX()
    {
        return Vector3{ y,x,x };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetYXY()
    {
        return Vector3{ y,x,y };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetYXZ()
    {
        return Vector3{ y,x,z };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetYYX()
    {
        return Vector3{ y,y,x };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetYYY()
    {
        return Vector3{ y,y,y };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetYYZ()
    {
        return Vector3{ y,y,z };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetYZX()
    {
        return Vector3{ y,z,x };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetYZY()
    {
        return Vector3{ y,z,y };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetYZZ()
    {
        return Vector3{ y,z,z };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetZXX()
    {
        return Vector3{ z,x,x };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetZXY()
    {
        return Vector3{ z,x,y };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetZXZ()
    {
        return Vector3{ z,x,z };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetZYX()
    {
        return Vector3{ z,y,x };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetZYY()
    {
        return Vector3{ z,y,y };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetZYZ()
    {
        return Vector3{ z,y,z };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetZZX()
    {
        return Vector3{ z,z,x };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetZZY()
    {
        return Vector3{ z,z,y };
    }

    //swizzling the Vector3 to creat a new Vector3
    Vector3 Vector3::GetZZZ()
    {
        return Vector3{ z,z,z };
    }

#pragma endregion
