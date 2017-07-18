#pragma once
#include "RealNumberType.h"
#include "DLLExport.h"
#include "Vector2.h"
#include "Vector3.h"

//Forward Declarations
class Vector3;
class Vector2;

//realNum is the variable type that can be set by the user
//by default it should be set to being a realNum

/*
* Class: Vector4
* --------------
*
* this is my Vector4 class
*
* Author: Callum Dunstone
*/
class DLL Vector4
{
public:
    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor that sets
    * the Vector4 to zero on all postions
    *
    */
    Vector4();

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is a custom constructor that lets the user to set
    * the values of the Vector4 manualy
    *
    */
    Vector4(realNum _x, realNum _y, realNum _z, realNum _w);

    /*
    * Function: DeConstructor
    * ---------------------
    *
    * this is the Default deconstructor
    *
    */
    ~Vector4();

    realNum x; /*the vectors x value*/
    realNum y; /*the vectors y value*/
    realNum z; /*the vectors z value*/
    realNum w; /*the vectors w value*/

    /*
    * Function Right()
    * ----------------
    *
    * this returns a vector with the x = 1, y = 0, z = 0 and w = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector4(1, 0, 0, 0)
    */
    Vector4 Right();

    /*
    * Function Leaft()
    * ----------------
    *
    * this returns a vector with the x = -1, y = 0, z = 0 and w = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector4(-1, 0, 0, 0)
    */
    Vector4 Leaft();

    /*
    * Function Up()
    * -------------
    *
    * this returns a vector with the x = 0, y = 1, z = 0 and w = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector4(0, 1, 0, 0)
    */
    Vector4 Up();

    /*
    * Function Down()
    * ---------------
    *
    * this returns a vector with the x = 0, y = -1, z = 0 and w = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector4(0, -1, 0, 0)
    */
    Vector4 Down();

    /*
    * Function Forward()
    * ------------------
    *
    * this returns a vector with the x = 0, y = 0, z = 1 and w = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector4(0, 0, 1, 0)
    */
    Vector4 Forward();

    /*
    * Function Backward()
    * -------------------
    *
    * this returns a vector with the x = 0, y = 0, z = -1 and w = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector4(0, 0, -1, 0)
    */
    Vector4 Backward();

    /*
    * Function PositiveW()
    * --------------------
    *
    * this returns a vector with the x = 0, y = 0, z = 0 and w = 1
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector4(0, 0, 0, 1)
    */
    Vector4 PositiveW();

    /*
    * Function PositiveW()
    * --------------------
    *
    * this returns a vector with the x = 0, y = 0, z = 0 and w = -1
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector4(0, 0, 0, -1)
    */
    Vector4 NegativeW();

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
    * Function: Dot
    * -------------
    *
    * this gets the dot product of two vectors
    *
    * Parameters: this takes in a refrence to a Vector4 that we will use to get the dot product
    *
    * returns: returns a realNum holding the dot product
    */
    realNum dot(Vector4 & refV);

    /*
    * Function: Cross
    * ---------------
    *
    * this gets the cross product of two vectors and assings that into a new vector
    *
    * Parameters: this takes in a refrence to a Vector4 that we will use to get the cross product
    *
    * returns: returns a Vector4 holding the cross product
    */
    Vector4 cross(Vector4 & refA);

    /*
    * Function: TypeCasting to Vector2
    * --------------------------------
    *
    * type casts the vector4 into a vector2 that will hold our vector4 x and y values
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a Vector2 holding the vector4 x and y
    */
    operator Vector2();

    /*
    * Function: TypeCasting to Vector3
    * --------------------------------
    *
    * type casts the vector4 into a vector3 that will hold our vector4 x, y and z values
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a Vector2 holding the vector4 x, y and z
    */
    operator Vector3();

    /*
    * Overload: +
    * -----------
    *
    * this creates a new Vector4 of the combined values of two other Vector4
    *
    * Parameters: this takes a refrence to a Vector4 refA that we want to add to our selfes to creat a new Vector4
    *
    * returns: a new Vector4 of the combined values of ourselfes and the refA
    */
    Vector4 operator + (const Vector4 & refA) const;

    /*
    * Overload: +=
    * ------------
    *
    * this adds the values of refA to our selfes
    *
    * Parameters: this takes a refrence to a Vector4 refA that we want to add to our selfes
    *
    * returns: nothing as it is a void
    */
    void operator += (const Vector4 & refA);

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Vector4 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Vector4 refA that we want to subtract from our selfes to creat a new Vector4
    *
    * returns: a new Vector4 of the subtracted values of refa from our selfes
    */
    Vector4 operator - (const Vector4 & refA) const;

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Vector4 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Vector4 refA that we want to subtract from our selfes to creat a new Vector4
    *
    * returns: a new Vector4 of the subtracted values of refa from our selfes
    */
    void operator -= (const Vector4 & refA);

    /*
    * Overload: *
    * -----------
    *
    * this creates a new Vector4 by multiplying our self with a scaler
    *
    * Parameters: this takes a const realNum that we will times our selfes against
    *
    * returns: a new Vector4 of the multipliyed values from scaler and our selfes
    */
    Vector4 operator * (const realNum scaler) const;

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
    * and returns the new Vector4
    *
    * Parameters: realNum scaler, Vector4 & vec that we will use the scaler to times the vec against
    *
    * returns: a Vector4 with the new multipilcation value
    */
    friend Vector4 operator * (realNum scaler, Vector4 & vec) { return vec * scaler; }

    /*
    * Overload: =
    * -----------
    *
    * this takes in a refrence to another Vector4 that we want to set ourselfs to then goes through
    * a loop seting each position on the Vector4 to be equal to the refrence Vector4 we passed into it
    *
    * Parameters: this takes a refrence to a Vector4 refA that we want to set oourselfes to
    *
    * returns: Nothing as it is a void function.
    */
    void operator = (const Vector4 & refA);

    /*
    * Overload: ==
    * ------------
    *
    * this checks the values of two Vector4 to see if they have exactly the same values and returns true if they do
    *
    * Parameters: this takes a refrence to a Vector4 refA that we want to check our selfes against
    *
    * returns: true is the two Vector4 have the same value and false if they do not
    */
    bool operator == (const Vector4 & refA) const;

    /*
    * Overload: !=
    * ------------
    *
    * this checks the values of two Vector4 to see if they are not the same and returns true if that is the case
    *
    * Parameters: this takes a refrence to a Vector4 refA that we want to check our selfes against
    *
    * returns: true is the two Vector4 do not have the same value and false if they do
    */
    bool operator != (const Vector4 & refA) const;

    /*
    * Overload: []
    * ------------
    *
    * this allows us to easily and quickly call our x or y values
    *
    * Parameters: int index this is wich value we want acces to x = 0 y = 1, z = 2, w = 3;
    *
    * returns: a refrence to a realNum in our Vector4
    */
    realNum & operator [] (int index);

    /*
    * Overload: []
    * ------------
    *
    * this dose the same except dose not allow you to change the values
    *
    * Parameters: int index this is wich value we want acces to x = 0, y = 1, z = 2, z = 2, w = 3;
    *
    * returns: a refrence to a realNum in our Vector4
    */
    const realNum & operator [] (int index) const;

    /*
    * Overload: realNum *
    * -----------------
    *
    * this returns the memory address of the start of the variables held in this Vector4
    * allowing you to iterate through them like an array (this is ugly and unstable and i dont like it)
    *
    * Parameters: this takes no parameters
    *
    * returns: the memory address to our x value
    */
    operator realNum * () { return &x; }

#pragma region MySwizzling

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
            * Function: GetXW()
            * --------------------

            * swizzles vector to (x,w)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetXW();

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
            * Function: GetYW()
            * --------------------

            * swizzles vector to (y,w)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetYW();

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
            * Function: GetZW()
            * --------------------

            * swizzles vector to (z,w)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetZW();

            /*
            * Function: GetWX()
            * --------------------

            * swizzles vector to (w,x)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetWX();

            /*
            * Function: GetWY()
            * --------------------

            * swizzles vector to (w,y)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetWY();

            /*
            * Function: GetWZ()
            * --------------------

            * swizzles vector to (w,z)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetWZ();

            /*
            * Function: GetWW()
            * --------------------

            * swizzles vector to (w,w)
            *
            * returns: Vector2 - the swizzled vector
            */
            Vector2 GetWW();

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
            * Function: GetXXW()
            * --------------------

            * swizzles vector to (x,x,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXXW();

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
            * Function: GetXYZ()
            * --------------------

            * swizzles vector to (x,y,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXYZ();

            /*
            * Function: GetXYW()
            * --------------------

            * swizzles vector to (x,y,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXYW();

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
            * Function: GetXZW()
            * --------------------

            * swizzles vector to (x,z,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXZW();

            /*
            * Function: GetXWX()
            * --------------------

            * swizzles vector to (x,w,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXWX();

            /*
            * Function: GetXWY()
            * --------------------

            * swizzles vector to (x,w,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXWY();

            /*
            * Function: GetXWZ()
            * --------------------

            * swizzles vector to (x,w,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXWZ();

            /*
            * Function: GetXWW()
            * --------------------

            * swizzles vector to (x,w,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetXWW();

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
            * Function: GetYXW()
            * --------------------

            * swizzles vector to (y,x,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYXW();

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
            * Function: GetYYW()
            * --------------------

            * swizzles vector to (y,y,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYYW();

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
            * Function: GetYZW()
            * --------------------

            * swizzles vector to (y,z,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYZW();

            /*
            * Function: GetYWX()
            * --------------------

            * swizzles vector to (y,w,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYWX();

            /*
            * Function: GetYWY()
            * --------------------

            * swizzles vector to (y,w,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYWY();

            /*
            * Function: GetYWZ()
            * --------------------

            * swizzles vector to (y,w,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYWZ();

            /*
            * Function: GetYWW()
            * --------------------

            * swizzles vector to (y,w,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetYWW();

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
            * Function: GetZXW()
            * --------------------

            * swizzles vector to (z,x,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZXW();

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
            * Function: GetZYW()
            * --------------------

            * swizzles vector to (z,y,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZYW();

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

            /*
            * Function: GetZZW()
            * --------------------

            * swizzles vector to (z,z,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZZW();

            /*
            * Function: GetZWX()
            * --------------------

            * swizzles vector to (z,w,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZWX();

            /*
            * Function: GetZWY()
            * --------------------

            * swizzles vector to (z,w,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZWY();

            /*
            * Function: GetZWZ()
            * --------------------

            * swizzles vector to (z,w,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZWZ();

            /*
            * Function: GetZWW()
            * --------------------

            * swizzles vector to (z,w,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetZWW();

            /*
            * Function: GetWXX()
            * --------------------

            * swizzles vector to (w,x,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWXX();

            /*
            * Function: GetWXY()
            * --------------------

            * swizzles vector to (w,x,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWXY();

            /*
            * Function: GetWXZ()
            * --------------------

            * swizzles vector to (w,x,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWXZ();

            /*
            * Function: GetWXW()
            * --------------------

            * swizzles vector to (w,x,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWXW();

            /*
            * Function: GetWYX()
            * --------------------

            * swizzles vector to (w,y,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWYX();

            /*
            * Function: GetWYY()
            * --------------------

            * swizzles vector to (w,y,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWYY();

            /*
            * Function: GetWYZ()
            * --------------------

            * swizzles vector to (w,y,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWYZ();

            /*
            * Function: GetWYW()
            * --------------------

            * swizzles vector to (w,y,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWYW();

            /*
            * Function: GetWZX()
            * --------------------

            * swizzles vector to (w,z,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWZX();

            /*
            * Function: GetWZY()
            * --------------------

            * swizzles vector to (w,z,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWZY();

            /*
            * Function: GetWZZ()
            * --------------------

            * swizzles vector to (w,z,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWZZ();

            /*
            * Function: GetWZW()
            * --------------------

            * swizzles vector to (w,z,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWZW();

            /*
            * Function: GetWWX()
            * --------------------

            * swizzles vector to (w,w,x)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWWX();

            /*
            * Function: GetWWY()
            * --------------------

            * swizzles vector to (w,w,y)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWWY();

            /*
            * Function: GetWWZ()
            * --------------------

            * swizzles vector to (w,w,z)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWWZ();

            /*
            * Function: GetWWW()
            * --------------------

            * swizzles vector to (w,w,w)
            *
            * returns: Vector3 - the swizzled vector
            */
            Vector3 GetWWW();

            /*
            * Function: GetXXXX()
            * --------------------

            * swizzles vector to (x,x,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXXX();

            /*
            * Function: GetXXXY()
            * --------------------

            * swizzles vector to (x,x,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXXY();

            /*
            * Function: GetXXXZ()
            * --------------------

            * swizzles vector to (x,x,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXXZ();

            /*
            * Function: GetXXXW()
            * --------------------

            * swizzles vector to (x,x,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXXW();

            /*
            * Function: GetXXYX()
            * --------------------

            * swizzles vector to (x,x,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXYX();

            /*
            * Function: GetXXYY()
            * --------------------

            * swizzles vector to (x,x,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXYY();

            /*
            * Function: GetXXYZ()
            * --------------------

            * swizzles vector to (x,x,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXYZ();

            /*
            * Function: GetXXYW()
            * --------------------

            * swizzles vector to (x,x,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXYW();

            /*
            * Function: GetXXZX()
            * --------------------

            * swizzles vector to (x,x,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXZX();

            /*
            * Function: GetXXZY()
            * --------------------

            * swizzles vector to (x,x,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXZY();

            /*
            * Function: GetXXZZ()
            * --------------------

            * swizzles vector to (x,x,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXZZ();

            /*
            * Function: GetXXZW()
            * --------------------

            * swizzles vector to (x,x,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXZW();

            /*
            * Function: GetXXWX()
            * --------------------

            * swizzles vector to (x,x,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXWX();

            /*
            * Function: GetXXWY()
            * --------------------

            * swizzles vector to (x,x,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXWY();

            /*
            * Function: GetXXWZ()
            * --------------------

            * swizzles vector to (x,x,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXWZ();

            /*
            * Function: GetXXWW()
            * --------------------

            * swizzles vector to (x,x,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXXWW();

            /*
            * Function: GetXYXX()
            * --------------------

            * swizzles vector to (x,y,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYXX();

            /*
            * Function: GetXYXY()
            * --------------------

            * swizzles vector to (x,y,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYXY();

            /*
            * Function: GetXYXZ()
            * --------------------

            * swizzles vector to (x,y,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYXZ();

            /*
            * Function: GetXYXW()
            * --------------------

            * swizzles vector to (x,y,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYXW();

            /*
            * Function: GetXYYX()
            * --------------------

            * swizzles vector to (x,y,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYYX();

            /*
            * Function: GetXYYY()
            * --------------------

            * swizzles vector to (x,y,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYYY();

            /*
            * Function: GetXYYZ()
            * --------------------

            * swizzles vector to (x,y,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYYZ();

            /*
            * Function: GetXYYW()
            * --------------------

            * swizzles vector to (x,y,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYYW();

            /*
            * Function: GetXYZX()
            * --------------------

            * swizzles vector to (x,y,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYZX();

            /*
            * Function: GetXYZY()
            * --------------------

            * swizzles vector to (x,y,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYZY();

            /*
            * Function: GetXYZZ()
            * --------------------

            * swizzles vector to (x,y,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYZZ();

            /*
            * Function: GetXYWX()
            * --------------------

            * swizzles vector to (x,y,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYWX();

            /*
            * Function: GetXYWY()
            * --------------------

            * swizzles vector to (x,y,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYWY();

            /*
            * Function: GetXYWZ()
            * --------------------

            * swizzles vector to (x,y,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYWZ();

            /*
            * Function: GetXYWW()
            * --------------------

            * swizzles vector to (x,y,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXYWW();

            /*
            * Function: GetXZXX()
            * --------------------

            * swizzles vector to (x,z,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZXX();

            /*
            * Function: GetXZXY()
            * --------------------

            * swizzles vector to (x,z,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZXY();

            /*
            * Function: GetXZXZ()
            * --------------------

            * swizzles vector to (x,z,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZXZ();

            /*
            * Function: GetXZXW()
            * --------------------

            * swizzles vector to (x,z,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZXW();

            /*
            * Function: GetXZYX()
            * --------------------

            * swizzles vector to (x,z,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZYX();

            /*
            * Function: GetXZYY()
            * --------------------

            * swizzles vector to (x,z,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZYY();

            /*
            * Function: GetXZYZ()
            * --------------------

            * swizzles vector to (x,z,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZYZ();

            /*
            * Function: GetXZYW()
            * --------------------

            * swizzles vector to (x,z,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZYW();

            /*
            * Function: GetXZZX()
            * --------------------

            * swizzles vector to (x,z,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZZX();

            /*
            * Function: GetXZZY()
            * --------------------

            * swizzles vector to (x,z,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZZY();

            /*
            * Function: GetXZZZ()
            * --------------------

            * swizzles vector to (x,z,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZZZ();

            /*
            * Function: GetXZZW()
            * --------------------

            * swizzles vector to (x,z,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZZW();

            /*
            * Function: GetXZWX()
            * --------------------

            * swizzles vector to (x,z,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZWX();

            /*
            * Function: GetXZWY()
            * --------------------

            * swizzles vector to (x,z,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZWY();

            /*
            * Function: GetXZWZ()
            * --------------------

            * swizzles vector to (x,z,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZWZ();

            /*
            * Function: GetXZWW()
            * --------------------

            * swizzles vector to (x,z,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXZWW();

            /*
            * Function: GetXWXX()
            * --------------------

            * swizzles vector to (x,w,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWXX();

            /*
            * Function: GetXWXY()
            * --------------------

            * swizzles vector to (x,w,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWXY();

            /*
            * Function: GetXWXZ()
            * --------------------

            * swizzles vector to (x,w,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWXZ();

            /*
            * Function: GetXWXW()
            * --------------------

            * swizzles vector to (x,w,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWXW();

            /*
            * Function: GetXWYX()
            * --------------------

            * swizzles vector to (x,w,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWYX();

            /*
            * Function: GetXWYY()
            * --------------------

            * swizzles vector to (x,w,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWYY();

            /*
            * Function: GetXWYZ()
            * --------------------

            * swizzles vector to (x,w,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWYZ();

            /*
            * Function: GetXWYW()
            * --------------------

            * swizzles vector to (x,w,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWYW();

            /*
            * Function: GetXWZX()
            * --------------------

            * swizzles vector to (x,w,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWZX();

            /*
            * Function: GetXWZY()
            * --------------------

            * swizzles vector to (x,w,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWZY();

            /*
            * Function: GetXWZZ()
            * --------------------

            * swizzles vector to (x,w,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWZZ();

            /*
            * Function: GetXWZW()
            * --------------------

            * swizzles vector to (x,w,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWZW();

            /*
            * Function: GetXWWX()
            * --------------------

            * swizzles vector to (x,w,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWWX();

            /*
            * Function: GetXWWY()
            * --------------------

            * swizzles vector to (x,w,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWWY();

            /*
            * Function: GetXWWZ()
            * --------------------

            * swizzles vector to (x,w,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWWZ();

            /*
            * Function: GetXWWW()
            * --------------------

            * swizzles vector to (x,w,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetXWWW();

            /*
            * Function: GetYXXX()
            * --------------------

            * swizzles vector to (y,x,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXXX();

            /*
            * Function: GetYXXY()
            * --------------------

            * swizzles vector to (y,x,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXXY();

            /*
            * Function: GetYXXZ()
            * --------------------

            * swizzles vector to (y,x,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXXZ();

            /*
            * Function: GetYXXW()
            * --------------------

            * swizzles vector to (y,x,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXXW();

            /*
            * Function: GetYXYX()
            * --------------------

            * swizzles vector to (y,x,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXYX();

            /*
            * Function: GetYXYY()
            * --------------------

            * swizzles vector to (y,x,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXYY();

            /*
            * Function: GetYXYZ()
            * --------------------

            * swizzles vector to (y,x,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXYZ();

            /*
            * Function: GetYXYW()
            * --------------------

            * swizzles vector to (y,x,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXYW();

            /*
            * Function: GetYXZX()
            * --------------------

            * swizzles vector to (y,x,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXZX();

            /*
            * Function: GetYXZY()
            * --------------------

            * swizzles vector to (y,x,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXZY();

            /*
            * Function: GetYXZZ()
            * --------------------

            * swizzles vector to (y,x,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXZZ();

            /*
            * Function: GetYXZW()
            * --------------------

            * swizzles vector to (y,x,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXZW();

            /*
            * Function: GetYXWX()
            * --------------------

            * swizzles vector to (y,x,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXWX();

            /*
            * Function: GetYXWY()
            * --------------------

            * swizzles vector to (y,x,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXWY();

            /*
            * Function: GetYXWZ()
            * --------------------

            * swizzles vector to (y,x,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXWZ();

            /*
            * Function: GetYXWW()
            * --------------------

            * swizzles vector to (y,x,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYXWW();

            /*
            * Function: GetYYXX()
            * --------------------

            * swizzles vector to (y,y,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYXX();

            /*
            * Function: GetYYXY()
            * --------------------

            * swizzles vector to (y,y,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYXY();

            /*
            * Function: GetYYXZ()
            * --------------------

            * swizzles vector to (y,y,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYXZ();

            /*
            * Function: GetYYXW()
            * --------------------

            * swizzles vector to (y,y,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYXW();

            /*
            * Function: GetYYYX()
            * --------------------

            * swizzles vector to (y,y,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYYX();

            /*
            * Function: GetYYYY()
            * --------------------

            * swizzles vector to (y,y,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYYY();

            /*
            * Function: GetYYYZ()
            * --------------------

            * swizzles vector to (y,y,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYYZ();

            /*
            * Function: GetYYYW()
            * --------------------

            * swizzles vector to (y,y,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYYW();

            /*
            * Function: GetYYZX()
            * --------------------

            * swizzles vector to (y,y,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYZX();

            /*
            * Function: GetYYZY()
            * --------------------

            * swizzles vector to (y,y,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYZY();

            /*
            * Function: GetYYZZ()
            * --------------------

            * swizzles vector to (y,y,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYZZ();

            /*
            * Function: GetYYZW()
            * --------------------

            * swizzles vector to (y,y,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYZW();

            /*
            * Function: GetYYWX()
            * --------------------

            * swizzles vector to (y,y,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYWX();

            /*
            * Function: GetYYWY()
            * --------------------

            * swizzles vector to (y,y,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYWY();

            /*
            * Function: GetYYWZ()
            * --------------------

            * swizzles vector to (y,y,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYWZ();

            /*
            * Function: GetYYWW()
            * --------------------

            * swizzles vector to (y,y,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYYWW();

            /*
            * Function: GetYZXX()
            * --------------------

            * swizzles vector to (y,z,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZXX();

            /*
            * Function: GetYZXY()
            * --------------------

            * swizzles vector to (y,z,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZXY();

            /*
            * Function: GetYZXZ()
            * --------------------

            * swizzles vector to (y,z,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZXZ();

            /*
            * Function: GetYZXW()
            * --------------------

            * swizzles vector to (y,z,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZXW();

            /*
            * Function: GetYZYX()
            * --------------------

            * swizzles vector to (y,z,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZYX();

            /*
            * Function: GetYZYY()
            * --------------------

            * swizzles vector to (y,z,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZYY();

            /*
            * Function: GetYZYZ()
            * --------------------

            * swizzles vector to (y,z,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZYZ();

            /*
            * Function: GetYZYW()
            * --------------------

            * swizzles vector to (y,z,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZYW();

            /*
            * Function: GetYZZX()
            * --------------------

            * swizzles vector to (y,z,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZZX();

            /*
            * Function: GetYZZY()
            * --------------------

            * swizzles vector to (y,z,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZZY();

            /*
            * Function: GetYZZZ()
            * --------------------

            * swizzles vector to (y,z,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZZZ();

            /*
            * Function: GetYZZW()
            * --------------------

            * swizzles vector to (y,z,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZZW();

            /*
            * Function: GetYZWX()
            * --------------------

            * swizzles vector to (y,z,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZWX();

            /*
            * Function: GetYZWY()
            * --------------------

            * swizzles vector to (y,z,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZWY();

            /*
            * Function: GetYZWZ()
            * --------------------

            * swizzles vector to (y,z,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZWZ();

            /*
            * Function: GetYZWW()
            * --------------------

            * swizzles vector to (y,z,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYZWW();

            /*
            * Function: GetYWXX()
            * --------------------

            * swizzles vector to (y,w,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWXX();

            /*
            * Function: GetYWXY()
            * --------------------

            * swizzles vector to (y,w,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWXY();

            /*
            * Function: GetYWXZ()
            * --------------------

            * swizzles vector to (y,w,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWXZ();

            /*
            * Function: GetYWXW()
            * --------------------

            * swizzles vector to (y,w,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWXW();

            /*
            * Function: GetYWYX()
            * --------------------

            * swizzles vector to (y,w,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWYX();

            /*
            * Function: GetYWYY()
            * --------------------

            * swizzles vector to (y,w,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWYY();

            /*
            * Function: GetYWYZ()
            * --------------------

            * swizzles vector to (y,w,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWYZ();

            /*
            * Function: GetYWYW()
            * --------------------

            * swizzles vector to (y,w,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWYW();

            /*
            * Function: GetYWZX()
            * --------------------

            * swizzles vector to (y,w,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWZX();

            /*
            * Function: GetYWZY()
            * --------------------

            * swizzles vector to (y,w,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWZY();

            /*
            * Function: GetYWZZ()
            * --------------------

            * swizzles vector to (y,w,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWZZ();

            /*
            * Function: GetYWZW()
            * --------------------

            * swizzles vector to (y,w,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWZW();

            /*
            * Function: GetYWWX()
            * --------------------

            * swizzles vector to (y,w,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWWX();

            /*
            * Function: GetYWWY()
            * --------------------

            * swizzles vector to (y,w,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWWY();

            /*
            * Function: GetYWWZ()
            * --------------------

            * swizzles vector to (y,w,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWWZ();

            /*
            * Function: GetYWWW()
            * --------------------

            * swizzles vector to (y,w,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetYWWW();

            /*
            * Function: GetZXXX()
            * --------------------

            * swizzles vector to (z,x,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXXX();

            /*
            * Function: GetZXXY()
            * --------------------

            * swizzles vector to (z,x,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXXY();

            /*
            * Function: GetZXXZ()
            * --------------------

            * swizzles vector to (z,x,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXXZ();

            /*
            * Function: GetZXXW()
            * --------------------

            * swizzles vector to (z,x,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXXW();

            /*
            * Function: GetZXYX()
            * --------------------

            * swizzles vector to (z,x,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXYX();

            /*
            * Function: GetZXYY()
            * --------------------

            * swizzles vector to (z,x,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXYY();

            /*
            * Function: GetZXYZ()
            * --------------------

            * swizzles vector to (z,x,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXYZ();

            /*
            * Function: GetZXYW()
            * --------------------

            * swizzles vector to (z,x,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXYW();

            /*
            * Function: GetZXZX()
            * --------------------

            * swizzles vector to (z,x,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXZX();

            /*
            * Function: GetZXZY()
            * --------------------

            * swizzles vector to (z,x,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXZY();

            /*
            * Function: GetZXZZ()
            * --------------------

            * swizzles vector to (z,x,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXZZ();

            /*
            * Function: GetZXZW()
            * --------------------

            * swizzles vector to (z,x,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXZW();

            /*
            * Function: GetZXWX()
            * --------------------

            * swizzles vector to (z,x,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXWX();

            /*
            * Function: GetZXWY()
            * --------------------

            * swizzles vector to (z,x,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXWY();

            /*
            * Function: GetZXWZ()
            * --------------------

            * swizzles vector to (z,x,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXWZ();

            /*
            * Function: GetZXWW()
            * --------------------

            * swizzles vector to (z,x,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZXWW();

            /*
            * Function: GetZYXX()
            * --------------------

            * swizzles vector to (z,y,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYXX();

            /*
            * Function: GetZYXY()
            * --------------------

            * swizzles vector to (z,y,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYXY();

            /*
            * Function: GetZYXZ()
            * --------------------

            * swizzles vector to (z,y,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYXZ();

            /*
            * Function: GetZYXW()
            * --------------------

            * swizzles vector to (z,y,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYXW();

            /*
            * Function: GetZYYX()
            * --------------------

            * swizzles vector to (z,y,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYYX();

            /*
            * Function: GetZYYY()
            * --------------------

            * swizzles vector to (z,y,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYYY();

            /*
            * Function: GetZYYZ()
            * --------------------

            * swizzles vector to (z,y,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYYZ();

            /*
            * Function: GetZYYW()
            * --------------------

            * swizzles vector to (z,y,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYYW();

            /*
            * Function: GetZYZX()
            * --------------------

            * swizzles vector to (z,y,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYZX();

            /*
            * Function: GetZYZY()
            * --------------------

            * swizzles vector to (z,y,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYZY();

            /*
            * Function: GetZYZZ()
            * --------------------

            * swizzles vector to (z,y,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYZZ();

            /*
            * Function: GetZYZW()
            * --------------------

            * swizzles vector to (z,y,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYZW();

            /*
            * Function: GetZYWX()
            * --------------------

            * swizzles vector to (z,y,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYWX();

            /*
            * Function: GetZYWY()
            * --------------------

            * swizzles vector to (z,y,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYWY();

            /*
            * Function: GetZYWZ()
            * --------------------

            * swizzles vector to (z,y,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYWZ();

            /*
            * Function: GetZYWW()
            * --------------------

            * swizzles vector to (z,y,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZYWW();

            /*
            * Function: GetZZXX()
            * --------------------

            * swizzles vector to (z,z,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZXX();

            /*
            * Function: GetZZXY()
            * --------------------

            * swizzles vector to (z,z,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZXY();

            /*
            * Function: GetZZXZ()
            * --------------------

            * swizzles vector to (z,z,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZXZ();

            /*
            * Function: GetZZXW()
            * --------------------

            * swizzles vector to (z,z,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZXW();

            /*
            * Function: GetZZYX()
            * --------------------

            * swizzles vector to (z,z,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZYX();

            /*
            * Function: GetZZYY()
            * --------------------

            * swizzles vector to (z,z,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZYY();

            /*
            * Function: GetZZYZ()
            * --------------------

            * swizzles vector to (z,z,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZYZ();

            /*
            * Function: GetZZYW()
            * --------------------

            * swizzles vector to (z,z,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZYW();

            /*
            * Function: GetZZZX()
            * --------------------

            * swizzles vector to (z,z,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZZX();

            /*
            * Function: GetZZZY()
            * --------------------

            * swizzles vector to (z,z,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZZY();

            /*
            * Function: GetZZZZ()
            * --------------------

            * swizzles vector to (z,z,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZZZ();

            /*
            * Function: GetZZZW()
            * --------------------

            * swizzles vector to (z,z,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZZW();

            /*
            * Function: GetZZWX()
            * --------------------

            * swizzles vector to (z,z,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZWX();

            /*
            * Function: GetZZWY()
            * --------------------

            * swizzles vector to (z,z,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZWY();

            /*
            * Function: GetZZWZ()
            * --------------------

            * swizzles vector to (z,z,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZWZ();

            /*
            * Function: GetZZWW()
            * --------------------

            * swizzles vector to (z,z,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZZWW();

            /*
            * Function: GetZWXX()
            * --------------------

            * swizzles vector to (z,w,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWXX();

            /*
            * Function: GetZWXY()
            * --------------------

            * swizzles vector to (z,w,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWXY();

            /*
            * Function: GetZWXZ()
            * --------------------

            * swizzles vector to (z,w,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWXZ();

            /*
            * Function: GetZWXW()
            * --------------------

            * swizzles vector to (z,w,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWXW();

            /*
            * Function: GetZWYX()
            * --------------------

            * swizzles vector to (z,w,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWYX();

            /*
            * Function: GetZWYY()
            * --------------------

            * swizzles vector to (z,w,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWYY();

            /*
            * Function: GetZWYZ()
            * --------------------

            * swizzles vector to (z,w,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWYZ();

            /*
            * Function: GetZWYW()
            * --------------------

            * swizzles vector to (z,w,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWYW();

            /*
            * Function: GetZWZX()
            * --------------------

            * swizzles vector to (z,w,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWZX();

            /*
            * Function: GetZWZY()
            * --------------------

            * swizzles vector to (z,w,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWZY();

            /*
            * Function: GetZWZZ()
            * --------------------

            * swizzles vector to (z,w,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWZZ();

            /*
            * Function: GetZWZW()
            * --------------------

            * swizzles vector to (z,w,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWZW();

            /*
            * Function: GetZWWX()
            * --------------------

            * swizzles vector to (z,w,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWWX();

            /*
            * Function: GetZWWY()
            * --------------------

            * swizzles vector to (z,w,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWWY();

            /*
            * Function: GetZWWZ()
            * --------------------

            * swizzles vector to (z,w,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWWZ();

            /*
            * Function: GetZWWW()
            * --------------------

            * swizzles vector to (z,w,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetZWWW();

            /*
            * Function: GetWXXX()
            * --------------------

            * swizzles vector to (w,x,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXXX();

            /*
            * Function: GetWXXY()
            * --------------------

            * swizzles vector to (w,x,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXXY();

            /*
            * Function: GetWXXZ()
            * --------------------

            * swizzles vector to (w,x,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXXZ();

            /*
            * Function: GetWXXW()
            * --------------------

            * swizzles vector to (w,x,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXXW();

            /*
            * Function: GetWXYX()
            * --------------------

            * swizzles vector to (w,x,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXYX();

            /*
            * Function: GetWXYY()
            * --------------------

            * swizzles vector to (w,x,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXYY();

            /*
            * Function: GetWXYZ()
            * --------------------

            * swizzles vector to (w,x,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXYZ();

            /*
            * Function: GetWXYW()
            * --------------------

            * swizzles vector to (w,x,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXYW();

            /*
            * Function: GetWXZX()
            * --------------------

            * swizzles vector to (w,x,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXZX();

            /*
            * Function: GetWXZY()
            * --------------------

            * swizzles vector to (w,x,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXZY();

            /*
            * Function: GetWXZZ()
            * --------------------

            * swizzles vector to (w,x,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXZZ();

            /*
            * Function: GetWXZW()
            * --------------------

            * swizzles vector to (w,x,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXZW();

            /*
            * Function: GetWXWX()
            * --------------------

            * swizzles vector to (w,x,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXWX();

            /*
            * Function: GetWXWY()
            * --------------------

            * swizzles vector to (w,x,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXWY();

            /*
            * Function: GetWXWZ()
            * --------------------

            * swizzles vector to (w,x,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXWZ();

            /*
            * Function: GetWXWW()
            * --------------------

            * swizzles vector to (w,x,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWXWW();

            /*
            * Function: GetWYXX()
            * --------------------

            * swizzles vector to (w,y,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYXX();

            /*
            * Function: GetWYXY()
            * --------------------

            * swizzles vector to (w,y,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYXY();

            /*
            * Function: GetWYXZ()
            * --------------------

            * swizzles vector to (w,y,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYXZ();

            /*
            * Function: GetWYXW()
            * --------------------

            * swizzles vector to (w,y,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYXW();

            /*
            * Function: GetWYYX()
            * --------------------

            * swizzles vector to (w,y,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYYX();

            /*
            * Function: GetWYYY()
            * --------------------

            * swizzles vector to (w,y,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYYY();

            /*
            * Function: GetWYYZ()
            * --------------------

            * swizzles vector to (w,y,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYYZ();

            /*
            * Function: GetWYYW()
            * --------------------

            * swizzles vector to (w,y,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYYW();

            /*
            * Function: GetWYZX()
            * --------------------

            * swizzles vector to (w,y,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYZX();

            /*
            * Function: GetWYZY()
            * --------------------

            * swizzles vector to (w,y,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYZY();

            /*
            * Function: GetWYZZ()
            * --------------------

            * swizzles vector to (w,y,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYZZ();

            /*
            * Function: GetWYZW()
            * --------------------

            * swizzles vector to (w,y,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYZW();

            /*
            * Function: GetWYWX()
            * --------------------

            * swizzles vector to (w,y,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYWX();

            /*
            * Function: GetWYWY()
            * --------------------

            * swizzles vector to (w,y,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYWY();

            /*
            * Function: GetWYWZ()
            * --------------------

            * swizzles vector to (w,y,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYWZ();

            /*
            * Function: GetWYWW()
            * --------------------

            * swizzles vector to (w,y,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWYWW();

            /*
            * Function: GetWZXX()
            * --------------------

            * swizzles vector to (w,z,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZXX();

            /*
            * Function: GetWZXY()
            * --------------------

            * swizzles vector to (w,z,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZXY();

            /*
            * Function: GetWZXZ()
            * --------------------

            * swizzles vector to (w,z,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZXZ();

            /*
            * Function: GetWZXW()
            * --------------------

            * swizzles vector to (w,z,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZXW();

            /*
            * Function: GetWZYX()
            * --------------------

            * swizzles vector to (w,z,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZYX();

            /*
            * Function: GetWZYY()
            * --------------------

            * swizzles vector to (w,z,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZYY();

            /*
            * Function: GetWZYZ()
            * --------------------

            * swizzles vector to (w,z,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZYZ();

            /*
            * Function: GetWZYW()
            * --------------------

            * swizzles vector to (w,z,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZYW();

            /*
            * Function: GetWZZX()
            * --------------------

            * swizzles vector to (w,z,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZZX();

            /*
            * Function: GetWZZY()
            * --------------------

            * swizzles vector to (w,z,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZZY();

            /*
            * Function: GetWZZZ()
            * --------------------

            * swizzles vector to (w,z,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZZZ();

            /*
            * Function: GetWZZW()
            * --------------------

            * swizzles vector to (w,z,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZZW();

            /*
            * Function: GetWZWX()
            * --------------------

            * swizzles vector to (w,z,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZWX();

            /*
            * Function: GetWZWY()
            * --------------------

            * swizzles vector to (w,z,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZWY();

            /*
            * Function: GetWZWZ()
            * --------------------

            * swizzles vector to (w,z,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZWZ();

            /*
            * Function: GetWZWW()
            * --------------------

            * swizzles vector to (w,z,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWZWW();

            /*
            * Function: GetWWXX()
            * --------------------

            * swizzles vector to (w,w,x,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWXX();

            /*
            * Function: GetWWXY()
            * --------------------

            * swizzles vector to (w,w,x,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWXY();

            /*
            * Function: GetWWXZ()
            * --------------------

            * swizzles vector to (w,w,x,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWXZ();

            /*
            * Function: GetWWXW()
            * --------------------

            * swizzles vector to (w,w,x,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWXW();

            /*
            * Function: GetWWYX()
            * --------------------

            * swizzles vector to (w,w,y,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWYX();

            /*
            * Function: GetWWYY()
            * --------------------

            * swizzles vector to (w,w,y,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWYY();

            /*
            * Function: GetWWYZ()
            * --------------------

            * swizzles vector to (w,w,y,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWYZ();

            /*
            * Function: GetWWYW()
            * --------------------

            * swizzles vector to (w,w,y,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWYW();

            /*
            * Function: GetWWZX()
            * --------------------

            * swizzles vector to (w,w,z,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWZX();

            /*
            * Function: GetWWZY()
            * --------------------

            * swizzles vector to (w,w,z,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWZY();

            /*
            * Function: GetWWZZ()
            * --------------------

            * swizzles vector to (w,w,z,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWZZ();

            /*
            * Function: GetWWZW()
            * --------------------

            * swizzles vector to (w,w,z,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWZW();

            /*
            * Function: GetWWWX()
            * --------------------

            * swizzles vector to (w,w,w,x)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWWX();

            /*
            * Function: GetWWWY()
            * --------------------

            * swizzles vector to (w,w,w,y)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWWY();

            /*
            * Function: GetWWWZ()
            * --------------------

            * swizzles vector to (w,w,w,z)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWWZ();

            /*
            * Function: GetWWWW()
            * --------------------

            * swizzles vector to (w,w,w,w)
            *
            * returns: Vector4 - the swizzled vector
            */
            Vector4 GetWWWW();

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

                //this returns the values of xw in a new Vector2
                //so that it can be accessed by doing something like Vector2.xw
                PROPERTY(Vector2, xw);
                GET(xw)
                {
                    return GetXW();
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

                //this returns the values of yw in a new Vector2
                //so that it can be accessed by doing something like Vector2.yw
                PROPERTY(Vector2, yw);
                GET(yw)
                {
                    return GetYW();
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

                //this returns the values of zw in a new Vector2
                //so that it can be accessed by doing something like Vector2.zw
                PROPERTY(Vector2, zw);
                GET(zw)
                {
                    return GetZW();
                }

                //this returns the values of wx in a new Vector2
                //so that it can be accessed by doing something like Vector2.wx
                PROPERTY(Vector2, wx);
                GET(wx)
                {
                    return GetWX();
                }

                //this returns the values of wy in a new Vector2
                //so that it can be accessed by doing something like Vector2.wy
                PROPERTY(Vector2, wy);
                GET(wy)
                {
                    return GetWY();
                }

                //this returns the values of wz in a new Vector2
                //so that it can be accessed by doing something like Vector2.wz
                PROPERTY(Vector2, wz);
                GET(wz)
                {
                    return GetWZ();
                }

                //this returns the values of ww in a new Vector2
                //so that it can be accessed by doing something like Vector2.ww
                PROPERTY(Vector2, ww);
                GET(ww)
                {
                    return GetWW();
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

                //this returns the values of xxw in a new Vector3
                //so that it can be accessed by doing something like Vector3.xxw
                PROPERTY(Vector3, xxw);
                GET(xxw)
                {
                    return GetXXW();
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

                //this returns the values of xyz in a new Vector3
                //so that it can be accessed by doing something like Vector3.xyz
                PROPERTY(Vector3, xyz);
                GET(xyz)
                {
                    return GetXYZ();
                }

                //this returns the values of xyw in a new Vector3
                //so that it can be accessed by doing something like Vector3.xyw
                PROPERTY(Vector3, xyw);
                GET(xyw)
                {
                    return GetXYW();
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

                //this returns the values of xzw in a new Vector3
                //so that it can be accessed by doing something like Vector3.xzw
                PROPERTY(Vector3, xzw);
                GET(xzw)
                {
                    return GetXZW();
                }

                //this returns the values of xwx in a new Vector3
                //so that it can be accessed by doing something like Vector3.xwx
                PROPERTY(Vector3, xwx);
                GET(xwx)
                {
                    return GetXWX();
                }

                //this returns the values of xwy in a new Vector3
                //so that it can be accessed by doing something like Vector3.xwy
                PROPERTY(Vector3, xwy);
                GET(xwy)
                {
                    return GetXWY();
                }

                //this returns the values of xwz in a new Vector3
                //so that it can be accessed by doing something like Vector3.xwz
                PROPERTY(Vector3, xwz);
                GET(xwz)
                {
                    return GetXWZ();
                }

                //this returns the values of xww in a new Vector3
                //so that it can be accessed by doing something like Vector3.xww
                PROPERTY(Vector3, xww);
                GET(xww)
                {
                    return GetXWW();
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

                //this returns the values of yxw in a new Vector3
                //so that it can be accessed by doing something like Vector3.yxw
                PROPERTY(Vector3, yxw);
                GET(yxw)
                {
                    return GetYXW();
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

                //this returns the values of yyw in a new Vector3
                //so that it can be accessed by doing something like Vector3.yyw
                PROPERTY(Vector3, yyw);
                GET(yyw)
                {
                    return GetYYW();
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

                //this returns the values of yzw in a new Vector3
                //so that it can be accessed by doing something like Vector3.yzw
                PROPERTY(Vector3, yzw);
                GET(yzw)
                {
                    return GetYZW();
                }

                //this returns the values of ywx in a new Vector3
                //so that it can be accessed by doing something like Vector3.ywx
                PROPERTY(Vector3, ywx);
                GET(ywx)
                {
                    return GetYWX();
                }

                //this returns the values of ywy in a new Vector3
                //so that it can be accessed by doing something like Vector3.ywy
                PROPERTY(Vector3, ywy);
                GET(ywy)
                {
                    return GetYWY();
                }

                //this returns the values of ywz in a new Vector3
                //so that it can be accessed by doing something like Vector3.ywz
                PROPERTY(Vector3, ywz);
                GET(ywz)
                {
                    return GetYWZ();
                }

                //this returns the values of yww in a new Vector3
                //so that it can be accessed by doing something like Vector3.yww
                PROPERTY(Vector3, yww);
                GET(yww)
                {
                    return GetYWW();
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

                //this returns the values of zxw in a new Vector3
                //so that it can be accessed by doing something like Vector3.zxw
                PROPERTY(Vector3, zxw);
                GET(zxw)
                {
                    return GetZXW();
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

                //this returns the values of zyw in a new Vector3
                //so that it can be accessed by doing something like Vector3.zyw
                PROPERTY(Vector3, zyw);
                GET(zyw)
                {
                    return GetZYW();
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

                //this returns the values of zzw in a new Vector3
                //so that it can be accessed by doing something like Vector3.zzw
                PROPERTY(Vector3, zzw);
                GET(zzw)
                {
                    return GetZZW();
                }

                //this returns the values of zwx in a new Vector3
                //so that it can be accessed by doing something like Vector3.zwx
                PROPERTY(Vector3, zwx);
                GET(zwx)
                {
                    return GetZWX();
                }

                //this returns the values of zwy in a new Vector3
                //so that it can be accessed by doing something like Vector3.zwy
                PROPERTY(Vector3, zwy);
                GET(zwy)
                {
                    return GetZWY();
                }

                //this returns the values of zwz in a new Vector3
                //so that it can be accessed by doing something like Vector3.zwz
                PROPERTY(Vector3, zwz);
                GET(zwz)
                {
                    return GetZWZ();
                }

                //this returns the values of zww in a new Vector3
                //so that it can be accessed by doing something like Vector3.zww
                PROPERTY(Vector3, zww);
                GET(zww)
                {
                    return GetZWW();
                }

                //this returns the values of wxx in a new Vector3
                //so that it can be accessed by doing something like Vector3.wxx
                PROPERTY(Vector3, wxx);
                GET(wxx)
                {
                    return GetWXX();
                }

                //this returns the values of wxy in a new Vector3
                //so that it can be accessed by doing something like Vector3.wxy
                PROPERTY(Vector3, wxy);
                GET(wxy)
                {
                    return GetWXY();
                }

                //this returns the values of wxz in a new Vector3
                //so that it can be accessed by doing something like Vector3.wxz
                PROPERTY(Vector3, wxz);
                GET(wxz)
                {
                    return GetWXZ();
                }

                //this returns the values of wxw in a new Vector3
                //so that it can be accessed by doing something like Vector3.wxw
                PROPERTY(Vector3, wxw);
                GET(wxw)
                {
                    return GetWXW();
                }

                //this returns the values of wyx in a new Vector3
                //so that it can be accessed by doing something like Vector3.wyx
                PROPERTY(Vector3, wyx);
                GET(wyx)
                {
                    return GetWYX();
                }

                //this returns the values of wyy in a new Vector3
                //so that it can be accessed by doing something like Vector3.wyy
                PROPERTY(Vector3, wyy);
                GET(wyy)
                {
                    return GetWYY();
                }

                //this returns the values of wyz in a new Vector3
                //so that it can be accessed by doing something like Vector3.wyz
                PROPERTY(Vector3, wyz);
                GET(wyz)
                {
                    return GetWYZ();
                }

                //this returns the values of wyw in a new Vector3
                //so that it can be accessed by doing something like Vector3.wyw
                PROPERTY(Vector3, wyw);
                GET(wyw)
                {
                    return GetWYW();
                }

                //this returns the values of wzx in a new Vector3
                //so that it can be accessed by doing something like Vector3.wzx
                PROPERTY(Vector3, wzx);
                GET(wzx)
                {
                    return GetWZX();
                }

                //this returns the values of wzy in a new Vector3
                //so that it can be accessed by doing something like Vector3.wzy
                PROPERTY(Vector3, wzy);
                GET(wzy)
                {
                    return GetWZY();
                }

                //this returns the values of wzz in a new Vector3
                //so that it can be accessed by doing something like Vector3.wzz
                PROPERTY(Vector3, wzz);
                GET(wzz)
                {
                    return GetWZZ();
                }

                //this returns the values of wzw in a new Vector3
                //so that it can be accessed by doing something like Vector3.wzw
                PROPERTY(Vector3, wzw);
                GET(wzw)
                {
                    return GetWZW();
                }

                //this returns the values of wwx in a new Vector3
                //so that it can be accessed by doing something like Vector3.wwx
                PROPERTY(Vector3, wwx);
                GET(wwx)
                {
                    return GetWWX();
                }

                //this returns the values of wwy in a new Vector3
                //so that it can be accessed by doing something like Vector3.wwy
                PROPERTY(Vector3, wwy);
                GET(wwy)
                {
                    return GetWWY();
                }

                //this returns the values of wwz in a new Vector3
                //so that it can be accessed by doing something like Vector3.wwz
                PROPERTY(Vector3, wwz);
                GET(wwz)
                {
                    return GetWWZ();
                }

                //this returns the values of www in a new Vector3
                //so that it can be accessed by doing something like Vector3.www
                PROPERTY(Vector3, www);
                GET(www)
                {
                    return GetWWW();
                }

                //this returns the values of xxxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxxx
                PROPERTY(Vector4, xxxx);
                GET(xxxx)
                {
                    return GetXXXX();
                }

                //this returns the values of xxxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxxy
                PROPERTY(Vector4, xxxy);
                GET(xxxy)
                {
                    return GetXXXY();
                }

                //this returns the values of xxxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxxz
                PROPERTY(Vector4, xxxz);
                GET(xxxz)
                {
                    return GetXXXZ();
                }

                //this returns the values of xxxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxxw
                PROPERTY(Vector4, xxxw);
                GET(xxxw)
                {
                    return GetXXXW();
                }

                //this returns the values of xxyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxyx
                PROPERTY(Vector4, xxyx);
                GET(xxyx)
                {
                    return GetXXYX();
                }

                //this returns the values of xxyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxyy
                PROPERTY(Vector4, xxyy);
                GET(xxyy)
                {
                    return GetXXYY();
                }

                //this returns the values of xxyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxyz
                PROPERTY(Vector4, xxyz);
                GET(xxyz)
                {
                    return GetXXYZ();
                }

                //this returns the values of xxyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxyw
                PROPERTY(Vector4, xxyw);
                GET(xxyw)
                {
                    return GetXXYW();
                }

                //this returns the values of xxzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxzx
                PROPERTY(Vector4, xxzx);
                GET(xxzx)
                {
                    return GetXXZX();
                }

                //this returns the values of xxzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxzy
                PROPERTY(Vector4, xxzy);
                GET(xxzy)
                {
                    return GetXXZY();
                }

                //this returns the values of xxzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxzz
                PROPERTY(Vector4, xxzz);
                GET(xxzz)
                {
                    return GetXXZZ();
                }

                //this returns the values of xxzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxzw
                PROPERTY(Vector4, xxzw);
                GET(xxzw)
                {
                    return GetXXZW();
                }

                //this returns the values of xxwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxwx
                PROPERTY(Vector4, xxwx);
                GET(xxwx)
                {
                    return GetXXWX();
                }

                //this returns the values of xxwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxwy
                PROPERTY(Vector4, xxwy);
                GET(xxwy)
                {
                    return GetXXWY();
                }

                //this returns the values of xxwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxwz
                PROPERTY(Vector4, xxwz);
                GET(xxwz)
                {
                    return GetXXWZ();
                }

                //this returns the values of xxww in a new Vector4
                //so that it can be accessed by doing something like Vector4.xxww
                PROPERTY(Vector4, xxww);
                GET(xxww)
                {
                    return GetXXWW();
                }

                //this returns the values of xyxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyxx
                PROPERTY(Vector4, xyxx);
                GET(xyxx)
                {
                    return GetXYXX();
                }

                //this returns the values of xyxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyxy
                PROPERTY(Vector4, xyxy);
                GET(xyxy)
                {
                    return GetXYXY();
                }

                //this returns the values of xyxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyxz
                PROPERTY(Vector4, xyxz);
                GET(xyxz)
                {
                    return GetXYXZ();
                }

                //this returns the values of xyxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyxw
                PROPERTY(Vector4, xyxw);
                GET(xyxw)
                {
                    return GetXYXW();
                }

                //this returns the values of xyyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyyx
                PROPERTY(Vector4, xyyx);
                GET(xyyx)
                {
                    return GetXYYX();
                }

                //this returns the values of xyyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyyy
                PROPERTY(Vector4, xyyy);
                GET(xyyy)
                {
                    return GetXYYY();
                }

                //this returns the values of xyyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyyz
                PROPERTY(Vector4, xyyz);
                GET(xyyz)
                {
                    return GetXYYZ();
                }

                //this returns the values of xyyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyyw
                PROPERTY(Vector4, xyyw);
                GET(xyyw)
                {
                    return GetXYYW();
                }

                //this returns the values of xyzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyzx
                PROPERTY(Vector4, xyzx);
                GET(xyzx)
                {
                    return GetXYZX();
                }

                //this returns the values of xyzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyzy
                PROPERTY(Vector4, xyzy);
                GET(xyzy)
                {
                    return GetXYZY();
                }

                //this returns the values of xyzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyzz
                PROPERTY(Vector4, xyzz);
                GET(xyzz)
                {
                    return GetXYZZ();
                }

                //this returns the values of xywx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xywx
                PROPERTY(Vector4, xywx);
                GET(xywx)
                {
                    return GetXYWX();
                }

                //this returns the values of xywy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xywy
                PROPERTY(Vector4, xywy);
                GET(xywy)
                {
                    return GetXYWY();
                }

                //this returns the values of xywz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xywz
                PROPERTY(Vector4, xywz);
                GET(xywz)
                {
                    return GetXYWZ();
                }

                //this returns the values of xyww in a new Vector4
                //so that it can be accessed by doing something like Vector4.xyww
                PROPERTY(Vector4, xyww);
                GET(xyww)
                {
                    return GetXYWW();
                }

                //this returns the values of xzxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzxx
                PROPERTY(Vector4, xzxx);
                GET(xzxx)
                {
                    return GetXZXX();
                }

                //this returns the values of xzxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzxy
                PROPERTY(Vector4, xzxy);
                GET(xzxy)
                {
                    return GetXZXY();
                }

                //this returns the values of xzxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzxz
                PROPERTY(Vector4, xzxz);
                GET(xzxz)
                {
                    return GetXZXZ();
                }

                //this returns the values of xzxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzxw
                PROPERTY(Vector4, xzxw);
                GET(xzxw)
                {
                    return GetXZXW();
                }

                //this returns the values of xzyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzyx
                PROPERTY(Vector4, xzyx);
                GET(xzyx)
                {
                    return GetXZYX();
                }

                //this returns the values of xzyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzyy
                PROPERTY(Vector4, xzyy);
                GET(xzyy)
                {
                    return GetXZYY();
                }

                //this returns the values of xzyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzyz
                PROPERTY(Vector4, xzyz);
                GET(xzyz)
                {
                    return GetXZYZ();
                }

                //this returns the values of xzyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzyw
                PROPERTY(Vector4, xzyw);
                GET(xzyw)
                {
                    return GetXZYW();
                }

                //this returns the values of xzzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzzx
                PROPERTY(Vector4, xzzx);
                GET(xzzx)
                {
                    return GetXZZX();
                }

                //this returns the values of xzzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzzy
                PROPERTY(Vector4, xzzy);
                GET(xzzy)
                {
                    return GetXZZY();
                }

                //this returns the values of xzzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzzz
                PROPERTY(Vector4, xzzz);
                GET(xzzz)
                {
                    return GetXZZZ();
                }

                //this returns the values of xzzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzzw
                PROPERTY(Vector4, xzzw);
                GET(xzzw)
                {
                    return GetXZZW();
                }

                //this returns the values of xzwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzwx
                PROPERTY(Vector4, xzwx);
                GET(xzwx)
                {
                    return GetXZWX();
                }

                //this returns the values of xzwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzwy
                PROPERTY(Vector4, xzwy);
                GET(xzwy)
                {
                    return GetXZWY();
                }

                //this returns the values of xzwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzwz
                PROPERTY(Vector4, xzwz);
                GET(xzwz)
                {
                    return GetXZWZ();
                }

                //this returns the values of xzww in a new Vector4
                //so that it can be accessed by doing something like Vector4.xzww
                PROPERTY(Vector4, xzww);
                GET(xzww)
                {
                    return GetXZWW();
                }

                //this returns the values of xwxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwxx
                PROPERTY(Vector4, xwxx);
                GET(xwxx)
                {
                    return GetXWXX();
                }

                //this returns the values of xwxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwxy
                PROPERTY(Vector4, xwxy);
                GET(xwxy)
                {
                    return GetXWXY();
                }

                //this returns the values of xwxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwxz
                PROPERTY(Vector4, xwxz);
                GET(xwxz)
                {
                    return GetXWXZ();
                }

                //this returns the values of xwxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwxw
                PROPERTY(Vector4, xwxw);
                GET(xwxw)
                {
                    return GetXWXW();
                }

                //this returns the values of xwyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwyx
                PROPERTY(Vector4, xwyx);
                GET(xwyx)
                {
                    return GetXWYX();
                }

                //this returns the values of xwyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwyy
                PROPERTY(Vector4, xwyy);
                GET(xwyy)
                {
                    return GetXWYY();
                }

                //this returns the values of xwyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwyz
                PROPERTY(Vector4, xwyz);
                GET(xwyz)
                {
                    return GetXWYZ();
                }

                //this returns the values of xwyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwyw
                PROPERTY(Vector4, xwyw);
                GET(xwyw)
                {
                    return GetXWYW();
                }

                //this returns the values of xwzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwzx
                PROPERTY(Vector4, xwzx);
                GET(xwzx)
                {
                    return GetXWZX();
                }

                //this returns the values of xwzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwzy
                PROPERTY(Vector4, xwzy);
                GET(xwzy)
                {
                    return GetXWZY();
                }

                //this returns the values of xwzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwzz
                PROPERTY(Vector4, xwzz);
                GET(xwzz)
                {
                    return GetXWZZ();
                }

                //this returns the values of xwzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwzw
                PROPERTY(Vector4, xwzw);
                GET(xwzw)
                {
                    return GetXWZW();
                }

                //this returns the values of xwwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwwx
                PROPERTY(Vector4, xwwx);
                GET(xwwx)
                {
                    return GetXWWX();
                }

                //this returns the values of xwwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwwy
                PROPERTY(Vector4, xwwy);
                GET(xwwy)
                {
                    return GetXWWY();
                }

                //this returns the values of xwwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwwz
                PROPERTY(Vector4, xwwz);
                GET(xwwz)
                {
                    return GetXWWZ();
                }

                //this returns the values of xwww in a new Vector4
                //so that it can be accessed by doing something like Vector4.xwww
                PROPERTY(Vector4, xwww);
                GET(xwww)
                {
                    return GetXWWW();
                }

                //this returns the values of yxxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxxx
                PROPERTY(Vector4, yxxx);
                GET(yxxx)
                {
                    return GetYXXX();
                }

                //this returns the values of yxxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxxy
                PROPERTY(Vector4, yxxy);
                GET(yxxy)
                {
                    return GetYXXY();
                }

                //this returns the values of yxxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxxz
                PROPERTY(Vector4, yxxz);
                GET(yxxz)
                {
                    return GetYXXZ();
                }

                //this returns the values of yxxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxxw
                PROPERTY(Vector4, yxxw);
                GET(yxxw)
                {
                    return GetYXXW();
                }

                //this returns the values of yxyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxyx
                PROPERTY(Vector4, yxyx);
                GET(yxyx)
                {
                    return GetYXYX();
                }

                //this returns the values of yxyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxyy
                PROPERTY(Vector4, yxyy);
                GET(yxyy)
                {
                    return GetYXYY();
                }

                //this returns the values of yxyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxyz
                PROPERTY(Vector4, yxyz);
                GET(yxyz)
                {
                    return GetYXYZ();
                }

                //this returns the values of yxyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxyw
                PROPERTY(Vector4, yxyw);
                GET(yxyw)
                {
                    return GetYXYW();
                }

                //this returns the values of yxzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxzx
                PROPERTY(Vector4, yxzx);
                GET(yxzx)
                {
                    return GetYXZX();
                }

                //this returns the values of yxzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxzy
                PROPERTY(Vector4, yxzy);
                GET(yxzy)
                {
                    return GetYXZY();
                }

                //this returns the values of yxzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxzz
                PROPERTY(Vector4, yxzz);
                GET(yxzz)
                {
                    return GetYXZZ();
                }

                //this returns the values of yxzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxzw
                PROPERTY(Vector4, yxzw);
                GET(yxzw)
                {
                    return GetYXZW();
                }

                //this returns the values of yxwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxwx
                PROPERTY(Vector4, yxwx);
                GET(yxwx)
                {
                    return GetYXWX();
                }

                //this returns the values of yxwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxwy
                PROPERTY(Vector4, yxwy);
                GET(yxwy)
                {
                    return GetYXWY();
                }

                //this returns the values of yxwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxwz
                PROPERTY(Vector4, yxwz);
                GET(yxwz)
                {
                    return GetYXWZ();
                }

                //this returns the values of yxww in a new Vector4
                //so that it can be accessed by doing something like Vector4.yxww
                PROPERTY(Vector4, yxww);
                GET(yxww)
                {
                    return GetYXWW();
                }

                //this returns the values of yyxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyxx
                PROPERTY(Vector4, yyxx);
                GET(yyxx)
                {
                    return GetYYXX();
                }

                //this returns the values of yyxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyxy
                PROPERTY(Vector4, yyxy);
                GET(yyxy)
                {
                    return GetYYXY();
                }

                //this returns the values of yyxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyxz
                PROPERTY(Vector4, yyxz);
                GET(yyxz)
                {
                    return GetYYXZ();
                }

                //this returns the values of yyxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyxw
                PROPERTY(Vector4, yyxw);
                GET(yyxw)
                {
                    return GetYYXW();
                }

                //this returns the values of yyyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyyx
                PROPERTY(Vector4, yyyx);
                GET(yyyx)
                {
                    return GetYYYX();
                }

                //this returns the values of yyyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyyy
                PROPERTY(Vector4, yyyy);
                GET(yyyy)
                {
                    return GetYYYY();
                }

                //this returns the values of yyyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyyz
                PROPERTY(Vector4, yyyz);
                GET(yyyz)
                {
                    return GetYYYZ();
                }

                //this returns the values of yyyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyyw
                PROPERTY(Vector4, yyyw);
                GET(yyyw)
                {
                    return GetYYYW();
                }

                //this returns the values of yyzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyzx
                PROPERTY(Vector4, yyzx);
                GET(yyzx)
                {
                    return GetYYZX();
                }

                //this returns the values of yyzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyzy
                PROPERTY(Vector4, yyzy);
                GET(yyzy)
                {
                    return GetYYZY();
                }

                //this returns the values of yyzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyzz
                PROPERTY(Vector4, yyzz);
                GET(yyzz)
                {
                    return GetYYZZ();
                }

                //this returns the values of yyzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyzw
                PROPERTY(Vector4, yyzw);
                GET(yyzw)
                {
                    return GetYYZW();
                }

                //this returns the values of yywx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yywx
                PROPERTY(Vector4, yywx);
                GET(yywx)
                {
                    return GetYYWX();
                }

                //this returns the values of yywy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yywy
                PROPERTY(Vector4, yywy);
                GET(yywy)
                {
                    return GetYYWY();
                }

                //this returns the values of yywz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yywz
                PROPERTY(Vector4, yywz);
                GET(yywz)
                {
                    return GetYYWZ();
                }

                //this returns the values of yyww in a new Vector4
                //so that it can be accessed by doing something like Vector4.yyww
                PROPERTY(Vector4, yyww);
                GET(yyww)
                {
                    return GetYYWW();
                }

                //this returns the values of yzxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzxx
                PROPERTY(Vector4, yzxx);
                GET(yzxx)
                {
                    return GetYZXX();
                }

                //this returns the values of yzxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzxy
                PROPERTY(Vector4, yzxy);
                GET(yzxy)
                {
                    return GetYZXY();
                }

                //this returns the values of yzxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzxz
                PROPERTY(Vector4, yzxz);
                GET(yzxz)
                {
                    return GetYZXZ();
                }

                //this returns the values of yzxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzxw
                PROPERTY(Vector4, yzxw);
                GET(yzxw)
                {
                    return GetYZXW();
                }

                //this returns the values of yzyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzyx
                PROPERTY(Vector4, yzyx);
                GET(yzyx)
                {
                    return GetYZYX();
                }

                //this returns the values of yzyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzyy
                PROPERTY(Vector4, yzyy);
                GET(yzyy)
                {
                    return GetYZYY();
                }

                //this returns the values of yzyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzyz
                PROPERTY(Vector4, yzyz);
                GET(yzyz)
                {
                    return GetYZYZ();
                }

                //this returns the values of yzyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzyw
                PROPERTY(Vector4, yzyw);
                GET(yzyw)
                {
                    return GetYZYW();
                }

                //this returns the values of yzzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzzx
                PROPERTY(Vector4, yzzx);
                GET(yzzx)
                {
                    return GetYZZX();
                }

                //this returns the values of yzzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzzy
                PROPERTY(Vector4, yzzy);
                GET(yzzy)
                {
                    return GetYZZY();
                }

                //this returns the values of yzzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzzz
                PROPERTY(Vector4, yzzz);
                GET(yzzz)
                {
                    return GetYZZZ();
                }

                //this returns the values of yzzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzzw
                PROPERTY(Vector4, yzzw);
                GET(yzzw)
                {
                    return GetYZZW();
                }

                //this returns the values of yzwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzwx
                PROPERTY(Vector4, yzwx);
                GET(yzwx)
                {
                    return GetYZWX();
                }

                //this returns the values of yzwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzwy
                PROPERTY(Vector4, yzwy);
                GET(yzwy)
                {
                    return GetYZWY();
                }

                //this returns the values of yzwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzwz
                PROPERTY(Vector4, yzwz);
                GET(yzwz)
                {
                    return GetYZWZ();
                }

                //this returns the values of yzww in a new Vector4
                //so that it can be accessed by doing something like Vector4.yzww
                PROPERTY(Vector4, yzww);
                GET(yzww)
                {
                    return GetYZWW();
                }

                //this returns the values of ywxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywxx
                PROPERTY(Vector4, ywxx);
                GET(ywxx)
                {
                    return GetYWXX();
                }

                //this returns the values of ywxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywxy
                PROPERTY(Vector4, ywxy);
                GET(ywxy)
                {
                    return GetYWXY();
                }

                //this returns the values of ywxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywxz
                PROPERTY(Vector4, ywxz);
                GET(ywxz)
                {
                    return GetYWXZ();
                }

                //this returns the values of ywxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywxw
                PROPERTY(Vector4, ywxw);
                GET(ywxw)
                {
                    return GetYWXW();
                }

                //this returns the values of ywyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywyx
                PROPERTY(Vector4, ywyx);
                GET(ywyx)
                {
                    return GetYWYX();
                }

                //this returns the values of ywyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywyy
                PROPERTY(Vector4, ywyy);
                GET(ywyy)
                {
                    return GetYWYY();
                }

                //this returns the values of ywyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywyz
                PROPERTY(Vector4, ywyz);
                GET(ywyz)
                {
                    return GetYWYZ();
                }

                //this returns the values of ywyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywyw
                PROPERTY(Vector4, ywyw);
                GET(ywyw)
                {
                    return GetYWYW();
                }

                //this returns the values of ywzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywzx
                PROPERTY(Vector4, ywzx);
                GET(ywzx)
                {
                    return GetYWZX();
                }

                //this returns the values of ywzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywzy
                PROPERTY(Vector4, ywzy);
                GET(ywzy)
                {
                    return GetYWZY();
                }

                //this returns the values of ywzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywzz
                PROPERTY(Vector4, ywzz);
                GET(ywzz)
                {
                    return GetYWZZ();
                }

                //this returns the values of ywzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywzw
                PROPERTY(Vector4, ywzw);
                GET(ywzw)
                {
                    return GetYWZW();
                }

                //this returns the values of ywwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywwx
                PROPERTY(Vector4, ywwx);
                GET(ywwx)
                {
                    return GetYWWX();
                }

                //this returns the values of ywwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywwy
                PROPERTY(Vector4, ywwy);
                GET(ywwy)
                {
                    return GetYWWY();
                }

                //this returns the values of ywwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywwz
                PROPERTY(Vector4, ywwz);
                GET(ywwz)
                {
                    return GetYWWZ();
                }

                //this returns the values of ywww in a new Vector4
                //so that it can be accessed by doing something like Vector4.ywww
                PROPERTY(Vector4, ywww);
                GET(ywww)
                {
                    return GetYWWW();
                }

                //this returns the values of zxxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxxx
                PROPERTY(Vector4, zxxx);
                GET(zxxx)
                {
                    return GetZXXX();
                }

                //this returns the values of zxxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxxy
                PROPERTY(Vector4, zxxy);
                GET(zxxy)
                {
                    return GetZXXY();
                }

                //this returns the values of zxxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxxz
                PROPERTY(Vector4, zxxz);
                GET(zxxz)
                {
                    return GetZXXZ();
                }

                //this returns the values of zxxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxxw
                PROPERTY(Vector4, zxxw);
                GET(zxxw)
                {
                    return GetZXXW();
                }

                //this returns the values of zxyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxyx
                PROPERTY(Vector4, zxyx);
                GET(zxyx)
                {
                    return GetZXYX();
                }

                //this returns the values of zxyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxyy
                PROPERTY(Vector4, zxyy);
                GET(zxyy)
                {
                    return GetZXYY();
                }

                //this returns the values of zxyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxyz
                PROPERTY(Vector4, zxyz);
                GET(zxyz)
                {
                    return GetZXYZ();
                }

                //this returns the values of zxyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxyw
                PROPERTY(Vector4, zxyw);
                GET(zxyw)
                {
                    return GetZXYW();
                }

                //this returns the values of zxzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxzx
                PROPERTY(Vector4, zxzx);
                GET(zxzx)
                {
                    return GetZXZX();
                }

                //this returns the values of zxzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxzy
                PROPERTY(Vector4, zxzy);
                GET(zxzy)
                {
                    return GetZXZY();
                }

                //this returns the values of zxzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxzz
                PROPERTY(Vector4, zxzz);
                GET(zxzz)
                {
                    return GetZXZZ();
                }

                //this returns the values of zxzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxzw
                PROPERTY(Vector4, zxzw);
                GET(zxzw)
                {
                    return GetZXZW();
                }

                //this returns the values of zxwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxwx
                PROPERTY(Vector4, zxwx);
                GET(zxwx)
                {
                    return GetZXWX();
                }

                //this returns the values of zxwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxwy
                PROPERTY(Vector4, zxwy);
                GET(zxwy)
                {
                    return GetZXWY();
                }

                //this returns the values of zxwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxwz
                PROPERTY(Vector4, zxwz);
                GET(zxwz)
                {
                    return GetZXWZ();
                }

                //this returns the values of zxww in a new Vector4
                //so that it can be accessed by doing something like Vector4.zxww
                PROPERTY(Vector4, zxww);
                GET(zxww)
                {
                    return GetZXWW();
                }

                //this returns the values of zyxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyxx
                PROPERTY(Vector4, zyxx);
                GET(zyxx)
                {
                    return GetZYXX();
                }

                //this returns the values of zyxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyxy
                PROPERTY(Vector4, zyxy);
                GET(zyxy)
                {
                    return GetZYXY();
                }

                //this returns the values of zyxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyxz
                PROPERTY(Vector4, zyxz);
                GET(zyxz)
                {
                    return GetZYXZ();
                }

                //this returns the values of zyxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyxw
                PROPERTY(Vector4, zyxw);
                GET(zyxw)
                {
                    return GetZYXW();
                }

                //this returns the values of zyyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyyx
                PROPERTY(Vector4, zyyx);
                GET(zyyx)
                {
                    return GetZYYX();
                }

                //this returns the values of zyyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyyy
                PROPERTY(Vector4, zyyy);
                GET(zyyy)
                {
                    return GetZYYY();
                }

                //this returns the values of zyyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyyz
                PROPERTY(Vector4, zyyz);
                GET(zyyz)
                {
                    return GetZYYZ();
                }

                //this returns the values of zyyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyyw
                PROPERTY(Vector4, zyyw);
                GET(zyyw)
                {
                    return GetZYYW();
                }

                //this returns the values of zyzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyzx
                PROPERTY(Vector4, zyzx);
                GET(zyzx)
                {
                    return GetZYZX();
                }

                //this returns the values of zyzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyzy
                PROPERTY(Vector4, zyzy);
                GET(zyzy)
                {
                    return GetZYZY();
                }

                //this returns the values of zyzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyzz
                PROPERTY(Vector4, zyzz);
                GET(zyzz)
                {
                    return GetZYZZ();
                }

                //this returns the values of zyzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyzw
                PROPERTY(Vector4, zyzw);
                GET(zyzw)
                {
                    return GetZYZW();
                }

                //this returns the values of zywx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zywx
                PROPERTY(Vector4, zywx);
                GET(zywx)
                {
                    return GetZYWX();
                }

                //this returns the values of zywy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zywy
                PROPERTY(Vector4, zywy);
                GET(zywy)
                {
                    return GetZYWY();
                }

                //this returns the values of zywz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zywz
                PROPERTY(Vector4, zywz);
                GET(zywz)
                {
                    return GetZYWZ();
                }

                //this returns the values of zyww in a new Vector4
                //so that it can be accessed by doing something like Vector4.zyww
                PROPERTY(Vector4, zyww);
                GET(zyww)
                {
                    return GetZYWW();
                }

                //this returns the values of zzxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzxx
                PROPERTY(Vector4, zzxx);
                GET(zzxx)
                {
                    return GetZZXX();
                }

                //this returns the values of zzxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzxy
                PROPERTY(Vector4, zzxy);
                GET(zzxy)
                {
                    return GetZZXY();
                }

                //this returns the values of zzxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzxz
                PROPERTY(Vector4, zzxz);
                GET(zzxz)
                {
                    return GetZZXZ();
                }

                //this returns the values of zzxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzxw
                PROPERTY(Vector4, zzxw);
                GET(zzxw)
                {
                    return GetZZXW();
                }

                //this returns the values of zzyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzyx
                PROPERTY(Vector4, zzyx);
                GET(zzyx)
                {
                    return GetZZYX();
                }

                //this returns the values of zzyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzyy
                PROPERTY(Vector4, zzyy);
                GET(zzyy)
                {
                    return GetZZYY();
                }

                //this returns the values of zzyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzyz
                PROPERTY(Vector4, zzyz);
                GET(zzyz)
                {
                    return GetZZYZ();
                }

                //this returns the values of zzyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzyw
                PROPERTY(Vector4, zzyw);
                GET(zzyw)
                {
                    return GetZZYW();
                }

                //this returns the values of zzzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzzx
                PROPERTY(Vector4, zzzx);
                GET(zzzx)
                {
                    return GetZZZX();
                }

                //this returns the values of zzzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzzy
                PROPERTY(Vector4, zzzy);
                GET(zzzy)
                {
                    return GetZZZY();
                }

                //this returns the values of zzzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzzz
                PROPERTY(Vector4, zzzz);
                GET(zzzz)
                {
                    return GetZZZZ();
                }

                //this returns the values of zzzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzzw
                PROPERTY(Vector4, zzzw);
                GET(zzzw)
                {
                    return GetZZZW();
                }

                //this returns the values of zzwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzwx
                PROPERTY(Vector4, zzwx);
                GET(zzwx)
                {
                    return GetZZWX();
                }

                //this returns the values of zzwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzwy
                PROPERTY(Vector4, zzwy);
                GET(zzwy)
                {
                    return GetZZWY();
                }

                //this returns the values of zzwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzwz
                PROPERTY(Vector4, zzwz);
                GET(zzwz)
                {
                    return GetZZWZ();
                }

                //this returns the values of zzww in a new Vector4
                //so that it can be accessed by doing something like Vector4.zzww
                PROPERTY(Vector4, zzww);
                GET(zzww)
                {
                    return GetZZWW();
                }

                //this returns the values of zwxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwxx
                PROPERTY(Vector4, zwxx);
                GET(zwxx)
                {
                    return GetZWXX();
                }

                //this returns the values of zwxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwxy
                PROPERTY(Vector4, zwxy);
                GET(zwxy)
                {
                    return GetZWXY();
                }

                //this returns the values of zwxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwxz
                PROPERTY(Vector4, zwxz);
                GET(zwxz)
                {
                    return GetZWXZ();
                }

                //this returns the values of zwxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwxw
                PROPERTY(Vector4, zwxw);
                GET(zwxw)
                {
                    return GetZWXW();
                }

                //this returns the values of zwyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwyx
                PROPERTY(Vector4, zwyx);
                GET(zwyx)
                {
                    return GetZWYX();
                }

                //this returns the values of zwyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwyy
                PROPERTY(Vector4, zwyy);
                GET(zwyy)
                {
                    return GetZWYY();
                }

                //this returns the values of zwyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwyz
                PROPERTY(Vector4, zwyz);
                GET(zwyz)
                {
                    return GetZWYZ();
                }

                //this returns the values of zwyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwyw
                PROPERTY(Vector4, zwyw);
                GET(zwyw)
                {
                    return GetZWYW();
                }

                //this returns the values of zwzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwzx
                PROPERTY(Vector4, zwzx);
                GET(zwzx)
                {
                    return GetZWZX();
                }

                //this returns the values of zwzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwzy
                PROPERTY(Vector4, zwzy);
                GET(zwzy)
                {
                    return GetZWZY();
                }

                //this returns the values of zwzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwzz
                PROPERTY(Vector4, zwzz);
                GET(zwzz)
                {
                    return GetZWZZ();
                }

                //this returns the values of zwzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwzw
                PROPERTY(Vector4, zwzw);
                GET(zwzw)
                {
                    return GetZWZW();
                }

                //this returns the values of zwwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwwx
                PROPERTY(Vector4, zwwx);
                GET(zwwx)
                {
                    return GetZWWX();
                }

                //this returns the values of zwwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwwy
                PROPERTY(Vector4, zwwy);
                GET(zwwy)
                {
                    return GetZWWY();
                }

                //this returns the values of zwwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwwz
                PROPERTY(Vector4, zwwz);
                GET(zwwz)
                {
                    return GetZWWZ();
                }

                //this returns the values of zwww in a new Vector4
                //so that it can be accessed by doing something like Vector4.zwww
                PROPERTY(Vector4, zwww);
                GET(zwww)
                {
                    return GetZWWW();
                }

                //this returns the values of wxxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxxx
                PROPERTY(Vector4, wxxx);
                GET(wxxx)
                {
                    return GetWXXX();
                }

                //this returns the values of wxxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxxy
                PROPERTY(Vector4, wxxy);
                GET(wxxy)
                {
                    return GetWXXY();
                }

                //this returns the values of wxxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxxz
                PROPERTY(Vector4, wxxz);
                GET(wxxz)
                {
                    return GetWXXZ();
                }

                //this returns the values of wxxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxxw
                PROPERTY(Vector4, wxxw);
                GET(wxxw)
                {
                    return GetWXXW();
                }

                //this returns the values of wxyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxyx
                PROPERTY(Vector4, wxyx);
                GET(wxyx)
                {
                    return GetWXYX();
                }

                //this returns the values of wxyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxyy
                PROPERTY(Vector4, wxyy);
                GET(wxyy)
                {
                    return GetWXYY();
                }

                //this returns the values of wxyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxyz
                PROPERTY(Vector4, wxyz);
                GET(wxyz)
                {
                    return GetWXYZ();
                }

                //this returns the values of wxyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxyw
                PROPERTY(Vector4, wxyw);
                GET(wxyw)
                {
                    return GetWXYW();
                }

                //this returns the values of wxzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxzx
                PROPERTY(Vector4, wxzx);
                GET(wxzx)
                {
                    return GetWXZX();
                }

                //this returns the values of wxzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxzy
                PROPERTY(Vector4, wxzy);
                GET(wxzy)
                {
                    return GetWXZY();
                }

                //this returns the values of wxzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxzz
                PROPERTY(Vector4, wxzz);
                GET(wxzz)
                {
                    return GetWXZZ();
                }

                //this returns the values of wxzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxzw
                PROPERTY(Vector4, wxzw);
                GET(wxzw)
                {
                    return GetWXZW();
                }

                //this returns the values of wxwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxwx
                PROPERTY(Vector4, wxwx);
                GET(wxwx)
                {
                    return GetWXWX();
                }

                //this returns the values of wxwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxwy
                PROPERTY(Vector4, wxwy);
                GET(wxwy)
                {
                    return GetWXWY();
                }

                //this returns the values of wxwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxwz
                PROPERTY(Vector4, wxwz);
                GET(wxwz)
                {
                    return GetWXWZ();
                }

                //this returns the values of wxww in a new Vector4
                //so that it can be accessed by doing something like Vector4.wxww
                PROPERTY(Vector4, wxww);
                GET(wxww)
                {
                    return GetWXWW();
                }

                //this returns the values of wyxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyxx
                PROPERTY(Vector4, wyxx);
                GET(wyxx)
                {
                    return GetWYXX();
                }

                //this returns the values of wyxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyxy
                PROPERTY(Vector4, wyxy);
                GET(wyxy)
                {
                    return GetWYXY();
                }

                //this returns the values of wyxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyxz
                PROPERTY(Vector4, wyxz);
                GET(wyxz)
                {
                    return GetWYXZ();
                }

                //this returns the values of wyxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyxw
                PROPERTY(Vector4, wyxw);
                GET(wyxw)
                {
                    return GetWYXW();
                }

                //this returns the values of wyyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyyx
                PROPERTY(Vector4, wyyx);
                GET(wyyx)
                {
                    return GetWYYX();
                }

                //this returns the values of wyyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyyy
                PROPERTY(Vector4, wyyy);
                GET(wyyy)
                {
                    return GetWYYY();
                }

                //this returns the values of wyyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyyz
                PROPERTY(Vector4, wyyz);
                GET(wyyz)
                {
                    return GetWYYZ();
                }

                //this returns the values of wyyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyyw
                PROPERTY(Vector4, wyyw);
                GET(wyyw)
                {
                    return GetWYYW();
                }

                //this returns the values of wyzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyzx
                PROPERTY(Vector4, wyzx);
                GET(wyzx)
                {
                    return GetWYZX();
                }

                //this returns the values of wyzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyzy
                PROPERTY(Vector4, wyzy);
                GET(wyzy)
                {
                    return GetWYZY();
                }

                //this returns the values of wyzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyzz
                PROPERTY(Vector4, wyzz);
                GET(wyzz)
                {
                    return GetWYZZ();
                }

                //this returns the values of wyzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyzw
                PROPERTY(Vector4, wyzw);
                GET(wyzw)
                {
                    return GetWYZW();
                }

                //this returns the values of wywx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wywx
                PROPERTY(Vector4, wywx);
                GET(wywx)
                {
                    return GetWYWX();
                }

                //this returns the values of wywy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wywy
                PROPERTY(Vector4, wywy);
                GET(wywy)
                {
                    return GetWYWY();
                }

                //this returns the values of wywz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wywz
                PROPERTY(Vector4, wywz);
                GET(wywz)
                {
                    return GetWYWZ();
                }

                //this returns the values of wyww in a new Vector4
                //so that it can be accessed by doing something like Vector4.wyww
                PROPERTY(Vector4, wyww);
                GET(wyww)
                {
                    return GetWYWW();
                }

                //this returns the values of wzxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzxx
                PROPERTY(Vector4, wzxx);
                GET(wzxx)
                {
                    return GetWZXX();
                }

                //this returns the values of wzxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzxy
                PROPERTY(Vector4, wzxy);
                GET(wzxy)
                {
                    return GetWZXY();
                }

                //this returns the values of wzxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzxz
                PROPERTY(Vector4, wzxz);
                GET(wzxz)
                {
                    return GetWZXZ();
                }

                //this returns the values of wzxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzxw
                PROPERTY(Vector4, wzxw);
                GET(wzxw)
                {
                    return GetWZXW();
                }

                //this returns the values of wzyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzyx
                PROPERTY(Vector4, wzyx);
                GET(wzyx)
                {
                    return GetWZYX();
                }

                //this returns the values of wzyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzyy
                PROPERTY(Vector4, wzyy);
                GET(wzyy)
                {
                    return GetWZYY();
                }

                //this returns the values of wzyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzyz
                PROPERTY(Vector4, wzyz);
                GET(wzyz)
                {
                    return GetWZYZ();
                }

                //this returns the values of wzyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzyw
                PROPERTY(Vector4, wzyw);
                GET(wzyw)
                {
                    return GetWZYW();
                }

                //this returns the values of wzzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzzx
                PROPERTY(Vector4, wzzx);
                GET(wzzx)
                {
                    return GetWZZX();
                }

                //this returns the values of wzzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzzy
                PROPERTY(Vector4, wzzy);
                GET(wzzy)
                {
                    return GetWZZY();
                }

                //this returns the values of wzzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzzz
                PROPERTY(Vector4, wzzz);
                GET(wzzz)
                {
                    return GetWZZZ();
                }

                //this returns the values of wzzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzzw
                PROPERTY(Vector4, wzzw);
                GET(wzzw)
                {
                    return GetWZZW();
                }

                //this returns the values of wzwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzwx
                PROPERTY(Vector4, wzwx);
                GET(wzwx)
                {
                    return GetWZWX();
                }

                //this returns the values of wzwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzwy
                PROPERTY(Vector4, wzwy);
                GET(wzwy)
                {
                    return GetWZWY();
                }

                //this returns the values of wzwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzwz
                PROPERTY(Vector4, wzwz);
                GET(wzwz)
                {
                    return GetWZWZ();
                }

                //this returns the values of wzww in a new Vector4
                //so that it can be accessed by doing something like Vector4.wzww
                PROPERTY(Vector4, wzww);
                GET(wzww)
                {
                    return GetWZWW();
                }

                //this returns the values of wwxx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwxx
                PROPERTY(Vector4, wwxx);
                GET(wwxx)
                {
                    return GetWWXX();
                }

                //this returns the values of wwxy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwxy
                PROPERTY(Vector4, wwxy);
                GET(wwxy)
                {
                    return GetWWXY();
                }

                //this returns the values of wwxz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwxz
                PROPERTY(Vector4, wwxz);
                GET(wwxz)
                {
                    return GetWWXZ();
                }

                //this returns the values of wwxw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwxw
                PROPERTY(Vector4, wwxw);
                GET(wwxw)
                {
                    return GetWWXW();
                }

                //this returns the values of wwyx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwyx
                PROPERTY(Vector4, wwyx);
                GET(wwyx)
                {
                    return GetWWYX();
                }

                //this returns the values of wwyy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwyy
                PROPERTY(Vector4, wwyy);
                GET(wwyy)
                {
                    return GetWWYY();
                }

                //this returns the values of wwyz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwyz
                PROPERTY(Vector4, wwyz);
                GET(wwyz)
                {
                    return GetWWYZ();
                }

                //this returns the values of wwyw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwyw
                PROPERTY(Vector4, wwyw);
                GET(wwyw)
                {
                    return GetWWYW();
                }

                //this returns the values of wwzx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwzx
                PROPERTY(Vector4, wwzx);
                GET(wwzx)
                {
                    return GetWWZX();
                }

                //this returns the values of wwzy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwzy
                PROPERTY(Vector4, wwzy);
                GET(wwzy)
                {
                    return GetWWZY();
                }

                //this returns the values of wwzz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwzz
                PROPERTY(Vector4, wwzz);
                GET(wwzz)
                {
                    return GetWWZZ();
                }

                //this returns the values of wwzw in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwzw
                PROPERTY(Vector4, wwzw);
                GET(wwzw)
                {
                    return GetWWZW();
                }

                //this returns the values of wwwx in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwwx
                PROPERTY(Vector4, wwwx);
                GET(wwwx)
                {
                    return GetWWWX();
                }

                //this returns the values of wwwy in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwwy
                PROPERTY(Vector4, wwwy);
                GET(wwwy)
                {
                    return GetWWWY();
                }

                //this returns the values of wwwz in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwwz
                PROPERTY(Vector4, wwwz);
                GET(wwwz)
                {
                    return GetWWWZ();
                }

                //this returns the values of wwww in a new Vector4
                //so that it can be accessed by doing something like Vector4.wwww
                PROPERTY(Vector4, wwww);
                GET(wwww)
                {
                    return GetWWWW();
                }


    #pragma endregion

#pragma endregion

};