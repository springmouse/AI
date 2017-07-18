#pragma once
#include "RealNumberType.h"
#include "DLLExport.h"
#include "VectorProperties.h"
#include "Vector2.h"

//forward Declarations
class Vector4;

//realNum is the variable type that can be set by the user
//by default it should be set to being a realNum

/*
* Class: Vector3
* --------------
*
* this is my Vector3 class
*
* Author: Callum Dunstone
*/
class DLL Vector3
{
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor that sets
    * the Vector3 to zero on all postions
    *
    */
    Vector3();

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is a custom constructor that lets the user to set
    * the values of the Vector3 manualy
    *
    */
    Vector3(realNum _x, realNum _y, realNum _z);

    /*
    * Function: DeConstructor
    * ---------------------
    *
    * this is the Default deconstructor
    *
    */
    ~Vector3();

    realNum x; /*the vectors x value*/
    realNum y; /*the vectors y value*/
    realNum z; /*the vectors z value*/

    /*
    * Function Right()
    * ----------------
    *
    * this returns a vector with the x = 1, y = 0 and z = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector3(1, 0, 0)
    */
    Vector3 Right();

    /*
    * Function Leaft()
    * ----------------
    *
    * this returns a vector with the x = -1, y = 0 and z = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector3(-1, 0, 0)
    */
    Vector3 Leaft();

    /*
    * Function Up()
    * -------------
    *
    * this returns a vector with the x = 0, y = 1 and z = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector3(0, 1, 0)
    */
    Vector3 Up();

    /*
    * Function Down()
    * ---------------
    *
    * this returns a vector with the x = 0, y = -1 and z = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector3(0, -1, 0)
    */
    Vector3 Down();

    /*
    * Function Forward()
    * ------------------
    *
    * this returns a vector with the x = 0, y = 0 and z = 1
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector3(0, 0, 1)
    */
    Vector3 Forward();

    /*
    * Function Backward()
    * -------------------
    *
    * this returns a vector with the x = 0, y = 0 and z = -1
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector3(0, 0, -1)
    */
    Vector3 Backward();

    /*
    * Function: Magnitude
    * -------------------
    *
    * this gets you the leangth of the vector
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a realNum holding the leangth of the vector
    */
    realNum magnitude();

    /*
    * Function: Normalise
    * -------------------
    *
    * this normalises your vector seting all its values to unit leangth
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns nothing as it is a void
    */
    void normalise();

    /*
    * Function: Normalised
    * --------------------
    *
    * this normalises your vector and returns it as a new vector
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a new vector with this vecotrs normalised value
    */
    Vector3 normalised();

    /*
    * Function: Dot
    * -------------
    *
    * this gets the dot product of two vectors
    *
    * Parameters: this takes in a refrence to a Vector3 that we will use to get the dot product
    *
    * returns: returns a realNum holding the dot product
    */
    realNum dot(Vector3 & refV);

    /*
    * Function: Cross
    * ---------------
    *
    * this gets the cross product of two vectors and assings that into a new vector
    *
    * Parameters: this takes in a refrence to a Vector3 that we will use to get the cross product
    *
    * returns: returns a Vector3 holding the cross product
    */
    Vector3 cross(Vector3 & refA);

    /*
    * Function: TypeCasting to Vector4
    * --------------------------------
    *
    * type casts the vector3 into a vector4 that will hold our vector3 x, y and z values and set w to 1.0f
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a Vector4 holding the vector3  x, y and z values and set w to 1.0f
    */
    operator Vector4();

    /*
    * Function: TypeCasting to Vector2
    * --------------------------------
    *
    * type casts the vector3 into a vector2 that will hold our vector3 x and y values
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a Vector2 holding the vector3  x and y values
    */
    operator Vector2();

    /*
    * Overload: +
    * -----------
    *
    * this creates a new Vector3 of the combined values of two other Vector3
    *
    * Parameters: this takes a refrence to a Vector3 refA that we want to add to our selfes to creat a new Vector3
    *
    * returns: a new Vector3 of the combined values of ourselfes and the refA
    */
    Vector3 operator + (const Vector3 & refA) const;

    /*
    * Overload: +=
    * ------------
    *
    * this adds the values of refA to our selfes
    *
    * Parameters: this takes a refrence to a Vector3 refA that we want to add to our selfes
    *
    * returns: nothing as it is a void
    */
    void operator += (const Vector3 & refA);

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Vector3 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Vector3 refA that we want to subtract from our selfes to creat a new Vector3
    *
    * returns: a new Vector3 of the subtracted values of refa from our selfes
    */
    Vector3 operator - (const Vector3 & refA) const;

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Vector3 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Vector3 refA that we want to subtract from our selfes to creat a new Vector3
    *
    * returns: a new Vector3 of the subtracted values of refa from our selfes
    */
    void operator -= (const Vector3 & refA);

    /*
    * Overload: *
    * -----------
    *
    * this creates a new Vector3 by multiplying our self with a scaler
    *
    * Parameters: this takes a const realNum that we will times our selfes against
    *
    * returns: a new Vector3 of the multipliyed values from scaler and our selfes
    */
    Vector3 operator * (const realNum scaler) const;

    /*
    * Overload: *
    * -----------
    *
    * this times our self with a scaler
    *
    * Parameters: this takes a const realNum that we will times our selfes against
    *
    * returns: nothing as it is a filthy void function... we cry
    */
    void operator *= (const realNum scaler);

    /*
    * Overload: *
    * -----------
    *
    * in order for us to times our self against a scaler the order has to be V * s this gets used if
    * in code the order is s * v and then swaps them around and then dose the appropriate mutipilcation
    * and returns the new Vector3
    *
    * Parameters: realNum scaler, Vector3 & vec that we will use the scaler to times the vec against
    *
    * returns: a Vector3 with the new multipilcation value
    */
    friend Vector3 operator * (realNum scaler, Vector3 & vec) { return vec * scaler; }

    /*
    * Overload: =
    * -----------
    *
    * this takes in a refrence to another Vector3 that we want to set ourselfs to then goes through
    * a loop seting each position on the Vector3 to be equal to the refrence Vector3 we passed into it
    *
    * Parameters: this takes a refrence to a Vector3 refA that we want to set oourselfes to
    *
    * returns: Nothing as it is a void function.
    */
    void operator = (const Vector3 & refA);

    /*
    * Overload: ==
    * ------------
    *
    * this checks the values of two Vector3 to see if they have exactly the same values and returns true if they do
    *
    * Parameters: this takes a refrence to a Vector3 refA that we want to check our selfes against
    *
    * returns: true is the two Vector3 have the same value and false if they do not
    */
    bool operator == (const Vector3 & refA) const;

    /*
    * Overload: !=
    * ------------
    *
    * this checks the values of two Vector3 to see if they are not the same and returns true if that is the case
    *
    * Parameters: this takes a refrence to a Vector3 refA that we want to check our selfes against
    *
    * returns: true is the two Vector3 do not have the same value and false if they do
    */
    bool operator != (const Vector3 & refA) const;

    /*
    * Overload: []
    * ------------
    *
    * this allows us to easily and quickly call our x or y values
    *
    * Parameters: int index this is wich value we want acces to x = 0, y = 1 z = 2;
    *
    * returns: a refrence to a realNum in our Vector3
    */
    realNum & operator [] (int index);

    /*
    * Overload: []
    * ------------
    *
    * this dose the same except dose not allow you to change the values
    *
    * Parameters: int index this is wich value we want acces to x = 0, y = 1, z = 2;
    *
    * returns: a refrence to a realNum in our Vector3
    */
    const realNum & operator [] (int index) const;

    /*
    * Overload: realNum *
    * -----------------
    *
    * this returns the memory address of the start of the variables held in this Vector3
    * allowing you to iterate through them like an array (this is ugly and unstable and i dont like it)
    *
    * Parameters: this takes no parameters
    *
    * returns: the memory address to our x value
    */
    operator realNum * () { return &x; }

#pragma region MySwizziling

    #pragma region MyPrivateRegion
        private:
            /*
            * Function: GetXX()
            * --------------------

            * swizzles vector to (x,x)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetXX();

            /*
            * Function: GetXY()
            * --------------------

            * swizzles vector to (x,y)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetXY();

            /*
            * Function: GetXZ()
            * --------------------

            * swizzles vector to (x,z)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetXZ();

            /*
            * Function: GetYX()
            * --------------------

            * swizzles vector to (y,x)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetYX();

            /*
            * Function: GetYY()
            * --------------------

            * swizzles vector to (y,y)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetYY();

            /*
            * Function: GetYZ()
            * --------------------

            * swizzles vector to (y,z)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetYZ();

            /*
            * Function: GetZX()
            * --------------------

            * swizzles vector to (z,x)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetZX();

            /*
            * Function: GetZY()
            * --------------------

            * swizzles vector to (z,y)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetZY();

            /*
            * Function: GetZZ()
            * --------------------

            * swizzles vector to (z,z)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetZZ();

            /*
            * Function: GetXXX()
            * --------------------

            * swizzles vector to (x,x,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXXX();

            /*
            * Function: GetXXY()
            * --------------------

            * swizzles vector to (x,x,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXXY();

            /*
            * Function: GetXXZ()
            * --------------------

            * swizzles vector to (x,x,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXXZ();

            /*
            * Function: GetXYX()
            * --------------------

            * swizzles vector to (x,y,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXYX();

            /*
            * Function: GetXYY()
            * --------------------

            * swizzles vector to (x,y,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXYY();

            /*
            * Function: GetXZX()
            * --------------------

            * swizzles vector to (x,z,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXZX();

            /*
            * Function: GetXZY()
            * --------------------

            * swizzles vector to (x,z,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXZY();

            /*
            * Function: GetXZZ()
            * --------------------

            * swizzles vector to (x,z,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXZZ();

            /*
            * Function: GetYXX()
            * --------------------

            * swizzles vector to (y,x,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYXX();

            /*
            * Function: GetYXY()
            * --------------------

            * swizzles vector to (y,x,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYXY();

            /*
            * Function: GetYXZ()
            * --------------------

            * swizzles vector to (y,x,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYXZ();

            /*
            * Function: GetYYX()
            * --------------------

            * swizzles vector to (y,y,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYYX();

            /*
            * Function: GetYYY()
            * --------------------

            * swizzles vector to (y,y,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYYY();

            /*
            * Function: GetYYZ()
            * --------------------

            * swizzles vector to (y,y,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYYZ();

            /*
            * Function: GetYZX()
            * --------------------

            * swizzles vector to (y,z,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYZX();

            /*
            * Function: GetYZY()
            * --------------------

            * swizzles vector to (y,z,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYZY();

            /*
            * Function: GetYZZ()
            * --------------------

            * swizzles vector to (y,z,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYZZ();

            /*
            * Function: GetZXX()
            * --------------------

            * swizzles vector to (z,x,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZXX();

            /*
            * Function: GetZXY()
            * --------------------

            * swizzles vector to (z,x,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZXY();

            /*
            * Function: GetZXZ()
            * --------------------

            * swizzles vector to (z,x,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZXZ();

            /*
            * Function: GetZYX()
            * --------------------

            * swizzles vector to (z,y,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZYX();

            /*
            * Function: GetZYY()
            * --------------------

            * swizzles vector to (z,y,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZYY();

            /*
            * Function: GetZYZ()
            * --------------------

            * swizzles vector to (z,y,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZYZ();

            /*
            * Function: GetZZX()
            * --------------------

            * swizzles vector to (z,z,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZZX();

            /*
            * Function: GetZZY()
            * --------------------

            * swizzles vector to (z,z,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZZY();

            /*
            * Function: GetZZZ()
            * --------------------

            * swizzles vector to (z,z,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZZZ();

    #pragma endregion

    #pragma region MyPublicRegion
        public:
            //this returns the values of xx in a new Vector2
            //so that it can be accessed by doing something like Vector2.xx
            PROPERTY(Vector2, xx);
            GET(xx)
            {
                return GetXX();
            }

            //this returns the values of xy in a new Vector2
            //so that it can be accessed by doing something like Vector2.xy
            PROPERTY(Vector2, xy);
            GET(xy)
            {
                return GetXY();
            }

            //this returns the values of xz in a new Vector2
            //so that it can be accessed by doing something like Vector2.xz
            PROPERTY(Vector2, xz);
            GET(xz)
            {
                return GetXZ();
            }

            //this returns the values of yx in a new Vector2
            //so that it can be accessed by doing something like Vector2.yx
            PROPERTY(Vector2, yx);
            GET(yx)
            {
                return GetYX();
            }

            //this returns the values of yy in a new Vector2
            //so that it can be accessed by doing something like Vector2.yy
            PROPERTY(Vector2, yy);
            GET(yy)
            {
                return GetYY();
            }

            //this returns the values of yz in a new Vector2
            //so that it can be accessed by doing something like Vector2.yz
            PROPERTY(Vector2, yz);
            GET(yz)
            {
                return GetYZ();
            }

            //this returns the values of zx in a new Vector2
            //so that it can be accessed by doing something like Vector2.zx
            PROPERTY(Vector2, zx);
            GET(zx)
            {
                return GetZX();
            }

            //this returns the values of zy in a new Vector2
            //so that it can be accessed by doing something like Vector2.zy
            PROPERTY(Vector2, zy);
            GET(zy)
            {
                return GetZY();
            }

            //this returns the values of zz in a new Vector2
            //so that it can be accessed by doing something like Vector2.zz
            PROPERTY(Vector2, zz);
            GET(zz)
            {
                return GetZZ();
            }

            //this returns the values of xxx in a new Vector3
            //so that it can be accessed by doing something like Vector3.xxx
            PROPERTY(Vector3, xxx);
            GET(xxx)
            {
                return GetXXX();
            }

            //this returns the values of xxy in a new Vector3
            //so that it can be accessed by doing something like Vector3.xxy
            PROPERTY(Vector3, xxy);
            GET(xxy)
            {
                return GetXXY();
            }

            //this returns the values of xxz in a new Vector3
            //so that it can be accessed by doing something like Vector3.xxz
            PROPERTY(Vector3, xxz);
            GET(xxz)
            {
                return GetXXZ();
            }

            //this returns the values of xyx in a new Vector3
            //so that it can be accessed by doing something like Vector3.xyx
            PROPERTY(Vector3, xyx);
            GET(xyx)
            {
                return GetXYX();
            }

            //this returns the values of xyy in a new Vector3
            //so that it can be accessed by doing something like Vector3.xyy
            PROPERTY(Vector3, xyy);
            GET(xyy)
            {
                return GetXYY();
            }

            //this returns the values of xzx in a new Vector3
            //so that it can be accessed by doing something like Vector3.xzx
            PROPERTY(Vector3, xzx);
            GET(xzx)
            {
                return GetXZX();
            }

            //this returns the values of xzy in a new Vector3
            //so that it can be accessed by doing something like Vector3.xzy
            PROPERTY(Vector3, xzy);
            GET(xzy)
            {
                return GetXZY();
            }

            //this returns the values of xzz in a new Vector3
            //so that it can be accessed by doing something like Vector3.xzz
            PROPERTY(Vector3, xzz);
            GET(xzz)
            {
                return GetXZZ();
            }

            //this returns the values of yxx in a new Vector3
            //so that it can be accessed by doing something like Vector3.yxx
            PROPERTY(Vector3, yxx);
            GET(yxx)
            {
                return GetYXX();
            }

            //this returns the values of yxy in a new Vector3
            //so that it can be accessed by doing something like Vector3.yxy
            PROPERTY(Vector3, yxy);
            GET(yxy)
            {
                return GetYXY();
            }

            //this returns the values of yxz in a new Vector3
            //so that it can be accessed by doing something like Vector3.yxz
            PROPERTY(Vector3, yxz);
            GET(yxz)
            {
                return GetYXZ();
            }

            //this returns the values of yyx in a new Vector3
            //so that it can be accessed by doing something like Vector3.yyx
            PROPERTY(Vector3, yyx);
            GET(yyx)
            {
                return GetYYX();
            }

            //this returns the values of yyy in a new Vector3
            //so that it can be accessed by doing something like Vector3.yyy
            PROPERTY(Vector3, yyy);
            GET(yyy)
            {
                return GetYYY();
            }

            //this returns the values of yyz in a new Vector3
            //so that it can be accessed by doing something like Vector3.yyz
            PROPERTY(Vector3, yyz);
            GET(yyz)
            {
                return GetYYZ();
            }

            //this returns the values of yzx in a new Vector3
            //so that it can be accessed by doing something like Vector3.yzx
            PROPERTY(Vector3, yzx);
            GET(yzx)
            {
                return GetYZX();
            }

            //this returns the values of yzy in a new Vector3
            //so that it can be accessed by doing something like Vector3.yzy
            PROPERTY(Vector3, yzy);
            GET(yzy)
            {
                return GetYZY();
            }

            //this returns the values of yzz in a new Vector3
            //so that it can be accessed by doing something like Vector3.yzz
            PROPERTY(Vector3, yzz);
            GET(yzz)
            {
                return GetYZZ();
            }

            //this returns the values of zxx in a new Vector3
            //so that it can be accessed by doing something like Vector3.zxx
            PROPERTY(Vector3, zxx);
            GET(zxx)
            {
                return GetZXX();
            }

            //this returns the values of zxy in a new Vector3
            //so that it can be accessed by doing something like Vector3.zxy
            PROPERTY(Vector3, zxy);
            GET(zxy)
            {
                return GetZXY();
            }

            //this returns the values of zxz in a new Vector3
            //so that it can be accessed by doing something like Vector3.zxz
            PROPERTY(Vector3, zxz);
            GET(zxz)
            {
                return GetZXZ();
            }

            //this returns the values of zyx in a new Vector3
            //so that it can be accessed by doing something like Vector3.zyx
            PROPERTY(Vector3, zyx);
            GET(zyx)
            {
                return GetZYX();
            }

            //this returns the values of zyy in a new Vector3
            //so that it can be accessed by doing something like Vector3.zyy
            PROPERTY(Vector3, zyy);
            GET(zyy)
            {
                return GetZYY();
            }

            //this returns the values of zyz in a new Vector3
            //so that it can be accessed by doing something like Vector3.zyz
            PROPERTY(Vector3, zyz);
            GET(zyz)
            {
                return GetZYZ();
            }

            //this returns the values of zzx in a new Vector3
            //so that it can be accessed by doing something like Vector3.zzx
            PROPERTY(Vector3, zzx);
            GET(zzx)
            {
                return GetZZX();
            }

            //this returns the values of zzy in a new Vector3
            //so that it can be accessed by doing something like Vector3.zzy
            PROPERTY(Vector3, zzy);
            GET(zzy)
            {
                return GetZZY();
            }

            //this returns the values of zzz in a new Vector3
            //so that it can be accessed by doing something like Vector3.zzz
            PROPERTY(Vector3, zzz);
            GET(zzz)
            {
                return GetZZZ();
            }

    #pragma endregion

#pragma endregion

};