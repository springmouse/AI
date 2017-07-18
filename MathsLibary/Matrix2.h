#pragma once
#include "Vector2.h"
#include "RealNumberType.h"
#include "DLLExport.h"

//realNum is the variable type that can be set by the user
//by default it should be set to being a realNum

/*
* Class: Matrix2
* --------------
*
* this is my Matrix2 class, 
* it is comprised of two Vector2
*
* Author: Callum Dunstone
*/
class DLL Matrix2
{
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor that sets
    * the Matrix2 to zero on all postions
    *
    */
    Matrix2();

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is a custom constructor that lets the user to set
    * the values of the Matrix2 manualy 
    *
    */
    Matrix2(realNum x1, realNum y1, realNum x2, realNum y2);

    /*
    * Function: DeConstructor
    * ---------------------
    *
    * this is the Default deconstructor
    *
    */
    ~Matrix2();


    const int SIZE = 4; /*how many positions are in the Matrix2*/
    const int ROW_SIZE = 2; /*the leangth of the Matrix2 along its width*/
    const int COLUM_SIZE = 2; /*the leangth of the height of the Matrix2*/

    Vector2 vec[2]; /*the array of Vector2s that makes up the internal array of the Matrix2*/

    /*
    * Function: SetRotate
    * -------------------
    *
    * this sets the values of the matrix to be eual to one of sin(r)/cos(r)/-sin(r)
    * giving the Matrix2 a rotation value
    *
    * Parameters: realNum r, represents the radions that we want to 
    * rotate the matrix by
    *
    * returns: Nothing as it is a void function.
    */
    void setRotate(realNum r); 

    /*
    * Function: Translate
    * -------------------
    *
    * takes in a vector2 to set the position of the matrix
    *
    * Parameters: a vector 2 holding the position of the matrix
    *
    * returns: Nothing as it is a void function.
    */
    void Translate(Vector2 pos);
    
    /*
    * Function: Inverse
    * -----------------
    *
    * this inverses the Matrix2 values and returns that in a new matrix
    *
    * Parameters: this takes no parameters
    *
    * returns: returns a matrix2 with the inverse values of the matrix that called this function
    */
    Matrix2 Inverse();

    /*
    * Function: Determiant
    * --------------------
    *
    * this fiunds the determint of the matrix and returns it as a realNum
    *
    * Parameters: this takes no parameters
    *
    * returns: returns a realNum holding the determiant of the matrix
    */
    realNum Determiant();

    /*
    * Function: SetIdentity
    * ---------------------
    *
    * this creats a new Matrix2 that is an identity Matrix2 and returns that
    *
    * Parameters: this takes no parameters
    *
    * returns: returns an identity Matrix2
    */
    Matrix2 SetIdentity();

    /*
    * Function: SetScale
    * ------------------
    *
    * this takes in a Vector2 and sets our scale by wiping the matrix and assinging the
    * identity locations to the vector passed in
    *
    * Parameters: this takes in a Vector2 to set our scale with
    *
    * returns: returns nothing
    */
    void SetScale(const Vector2 & scale);

    /*
    * Function: Scale
    * ---------------
    *
    * this takes in a Vector2 and changes ou scale by multiplying the matric
    * identity locations with the vector passed in
    *
    * Parameters: this takes in a Vector2 to change our scale with
    *
    * returns: returns nothing
    */
    void Scale(const Vector2 & scale);

    /*
    * Overload: *
    * -----------
    *
    * this creats a new Matrix2 using Matrix multiplication maths
    * so that Matrix2 can be apropritaly multiplyed 
    *
    * Parameters: this takes a refrence to a Matrix2 refA that we want to multiply with
    *
    * returns: returns an Matrix2
    */
    Matrix2 operator * (const Matrix2 & refA) const;

    /*
    * Overload: *=
    * ------------
    *
    * this multiplys the Matrix2 with the refrence matrix using proper Matrix multiplication
    * and set the Matrix2 to the new value
    *
    * Parameters: this takes a refrence to a Matrix2 refA that we want to multiply our selfes with
    *
    * returns: Nothing as it is a void function.
    */
    void operator *= (const Matrix2 & refA);

    /*
    * Overload: *
    * -----------
    *
    * this creats a new Vector2 and multiplys the Matrix2 with a refrence Vector2 using proper matrix multiplication
    * and set the Vector2 to the new value and returns it
    *
    * Parameters: this takes a refrence to a Vector2 refA that we want to multiply our selfes with
    *
    * returns: returns a Vector2 with the new value from multiplying the Matrix2 and refrence to a Vector2 together
    */
    Vector2 operator * (const Vector2 & refA) const;

    /*
    * Overload: *
    * -----------
    *
    * technically this will look wrong as we are aloud to do Matrix2 * Vector2 and not Vector2 * Matrix2 wich this will look like
    * however i am lazy and would rather not do v = m * v; every songle time and would like to do v *= m;
    * this overload detects that we are calling v *= m; then rewords it to v = m * v; wich calls on the overload for m * v
    * allowing us to give it the appropriate value
    *
    * Parameters: this takes a refrence to a Vector2 vec and a Matrix2 mat that we want to multiply together
    *
    * returns: returns a Vector2 with the new value from multiplying the Matrix2 and refrence to a Vector2 together
    */
    friend void operator *= (Vector2 & vec, Matrix2 & mat) {vec = mat * vec;}

    /*
    * Overload: =
    * -----------
    *
    * this takes in a refrence to another Matrix2 that we want to set ourselfs to then goes through 
    * a loop seting each position on the Matrix2 to be equal to the refrence Matrix2 we passed into it
    *
    * Parameters: this takes a refrence to a Matrix2 refA that we want to set oourselfes to
    *
    * returns: Nothing as it is a void function.
    */
    void operator = (const Matrix2 & refA);

    /*
    * Overload: ==
    * ------------
    *
    * this checks the values of two matrixs to see if they have exactly the same values and returns true if they do
    *
    * Parameters: this takes a refrence to a Matrix2 refA that we want to check our selfes against
    *
    * returns: true is the two matrix have the same value and false if they do not
    */
    bool operator == (const Matrix2 & refA);

    /*
    * Overload: !=
    * ------------
    *
    * this checks the values of two matrixs to see if they are not the same and returns true if that is the case
    *
    * Parameters: this takes a refrence to a Matrix2 refA that we want to check our selfes against
    *
    * returns: true is the two matrix do not have the same value and false if they do
    */
    bool operator != (const Matrix2 & refA);

    /*
    * Overload: +
    * -----------
    *
    * this creates a new Matrix2 of the combined values of two other Matrix2
    *
    * Parameters: this takes a refrence to a Matrix2 refA that we want to add to our selfes to creat a new Matrix2
    *
    * returns: a new Matrix2 of the combined values of ourselfes and the refA
    */
    Matrix2 operator + (const Matrix2 & refA) const;

    /*
    * Overload: +=
    * ------------
    *
    * this adds the values of refA to our selfes
    *
    * Parameters: this takes a refrence to a Matrix2 refA that we want to add to our selfes
    *
    * returns: nothing as it is a void
    */
    void operator += (const Matrix2 & refA);

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Matrix2 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Matrix2 refA that we want to subtract from our selfes to creat a new Matrix2
    *
    * returns: a new Matrix2 of the subtracted values of refa from our selfes
    */
    Matrix2 operator - (const Matrix2 & refA) const;

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Matrix2 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Matrix2 refA that we want to subtract from our selfes to creat a new Matrix2
    *
    * returns: a new Matrix2 of the subtracted values of refa from our selfes
    */
    void operator -= (const Matrix2 & refA);

    /*
    * Overload: []
    * ------------
    *
    * this allows us to easily and quickly call apon a position in our Vector2 vec array
    * so that we can acces it
    *
    * Parameters: int index this is the position in the array we want to get
    *
    * returns: a refrence to a Vector2 in our internal array of Vector2
    */
    Vector2 & operator [] (int index);

    /*
    * Overload: realNum *
    * -----------------
    *
    * this returns the memory address of the start of our array of vectors and their x, y positions
    *
    * Parameters: this takes no parameters
    *
    * returns: the memory address to the start of our array
    */
    operator realNum * () { return &vec[0][0]; }
};

