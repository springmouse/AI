#pragma once
#include "RealNumberType.h"
#include "DLLExport.h"
#include "VectorProperties.h"

//forward declarations
class Vector4;
class Vector3;

//realNum is the variable type that can be set by the user
//by default it should be set to being a realNum

/*
* Class: Vector2
* --------------
*
* this is my Vector2 class
*
* Author: Callum Dunstone
*/
class DLL Vector2
{
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor that sets
    * the Vector2 to zero on all postions
    *
    */
    Vector2();

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is a custom constructor that lets the user to set
    * the values of the Vector2 manualy
    *
    */
    Vector2(realNum _x, realNum _y);

    /*
    * Function: DeConstructor
    * ---------------------
    *
    * this is the Default deconstructor
    *
    */
    ~Vector2();

    realNum x; /*the vectors x value*/


    realNum y; /*the vectors y value*/

    /*
    * Function Right()
    * ----------------
    *
    * this returns a vector with the x = 1 and y = 0
    * 
    * Parameters: this takes no parameters
    *
    * Returns: a Vector2(1,0)
    */
    Vector2 Right();

    /*
    * Function Leaft()
    * ----------------
    *
    * this returns a vector with the x = -1 and y = 0
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector2(-1,0)
    */
    Vector2 Leaft();

    /*
    * Function Up()
    * -------------
    *
    * this returns a vector with the x = 0 and y = 1
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector2(0,1)
    */
    Vector2 Up();

    /*
    * Function Down()
    * ---------------
    *
    * this returns a vector with the x = 0 and y = -1
    *
    * Parameters: this takes no parameters
    *
    * Returns: a Vector2(0,-1)
    */
    Vector2 Down();

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
    * returns: this returns nothing as it is a void
    */
    void normalise();

    /*
    * Function: Dot
    * -------------
    *
    * this gets the dot product of two vectors
    *
    * Parameters: this takes in a refrence to a vector 2 that we will use to get the dot product
    *
    * returns: returns a realNum holding the dot product
    */
    realNum dot(Vector2 & refV);

    /*
    * Function: TypeCasting to Vector3
    * --------------------------------
    *
    * type casts the vector2 into a vector4 that will hold our vector2 x and y values and set z and w to 1.0f
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a Vector4 holding the vector2 x and y values and sets z and w to 1.0f
    */
    operator Vector4();

    /*
    * Function: TypeCasting to Vector3
    * --------------------------------
    *
    * type casts the vector2 into a vector3 that will hold our vector2 x and y values and set z to 1.0f
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a Vector3 holding the vector2 x and y values and set z to 1.0f
    */
    operator Vector3();

    /*
    * Overload: +
    * -----------
    *
    * this creates a new Vector2 of the combined values of two other Vector2
    *
    * Parameters: this takes a refrence to a Vector2 refA that we want to add to our selfes to creat a new Vector2
    *
    * returns: a new Vector2 of the combined values of ourselfes and the refA
    */
    Vector2 operator + (Vector2 & refA) ;

    /*
    * Overload: +=
    * ------------
    *
    * this adds the values of refA to our selfes
    *
    * Parameters: this takes a refrence to a Vector2 refA that we want to add to our selfes
    *
    * returns: nothing as it is a void
    */
    void operator += (Vector2 & refA);

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Vector2 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Vector2 refA that we want to subtract from our selfes to creat a new Vector2
    *
    * returns: a new Vector2 of the subtracted values of refa from our selfes
    */
    Vector2 operator - (Vector2 & refA);

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Vector2 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Vector2 refA that we want to subtract from our selfes to creat a new Vector2
    *
    * returns: a new Vector2 of the subtracted values of refa from our selfes
    */
    void operator -= (Vector2 & refA);

    /*
    * Overload: *
    * -----------
    *
    * this creates a new Vector2 by multiplying our self with a scaler
    *
    * Parameters: this takes a realNum that we will times our selfes against
    *
    * returns: a new Vector2 of the multipliyed values from scaler and our selfes
    */
    Vector2 operator * (realNum scaler);

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
    void operator *= (realNum scaler);

    /*
    * Overload: *
    * -----------
    *
    * in order for us to times our self against a scaler the order has to be V * s this gets used if
    * in code the order is s * v and then swaps them around and then dose the appropriate mutipilcation
    * and returns the new vector 2
    *
    * Parameters: realNum scaler, Vector2 & vec that we will use the scaler to times the vec against
    *
    * returns: a Vector2 with the new multipilcation value 
    */
    friend Vector2 operator * (realNum scaler, Vector2 & vec) { return vec * scaler; }

    /*
    * Overload: =
    * -----------
    *
    * this takes in a refrence to another Vector2 that we want to set ourselfs to then goes through
    * a loop seting each position on the Vector2 to be equal to the refrence Vector2 we passed into it
    *
    * Parameters: this takes a refrence to a Vector2 refA that we want to set oourselfes to
    *
    * returns: Nothing as it is a void function.
    */
    void operator = (const Vector2 & refA);

    /*
    * Overload: ==
    * ------------
    *
    * this checks the values of two Vector2 to see if they have exactly the same values and returns true if they do
    *
    * Parameters: this takes a refrence to a Vector2 refA that we want to check our selfes against
    *
    * returns: true is the two Vector2 have the same value and false if they do not
    */
    bool operator == (Vector2 & refA);

    /*
    * Overload: !=
    * ------------
    *
    * this checks the values of two Vector2 to see if they are not the same and returns true if that is the case
    *
    * Parameters: this takes a refrence to a Vector2 refA that we want to check our selfes against
    *
    * returns: true is the two Vector2 do not have the same value and false if they do
    */
    bool operator != (Vector2 & refA);

    /*
    * Overload: []
    * ------------
    *
    * this allows us to easily and quickly call our x or y values
    *
    * Parameters: int index this is wich value we want acces to x = 0 y = 1;
    *
    * returns: a refrence to a realNum in our Vector2
    */
    realNum & operator [] (int index);

    /*
    * Overload: []
    * ------------
    *
    * this dose the same except dose not allow you to change the values
    *
    * Parameters: int index this is wich value we want acces to x = 0 y = 1;
    *
    * returns: a refrence to a realNum in our Vector2
    */
    const realNum & operator [] (int index) const;

    /*
    * Overload: realNum *
    * -------------------
    *
    * this returns the memory address of the start of the variables held in this Vector2
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
    * GetXX
    *
    * swizzles vector to (x,x)
    *
    * @returns Vector2 - the swizzled vector
    */
    Vector2 GetXX();

    /*
    * GetYX
    *
    * swizzles vector to (y,x)
    *
    * @returns Vector2 - the swizzled vector
    */
    Vector2 GetYX();

    /*
    * GetYY
    *
    * swizzles vector to (y,y)
    *
    * @returns Vector2 - the swizzled vector
    */
    Vector2 GetYY();

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

#pragma endregion

#pragma endregion

};