#pragma once
#include "Vector4.h"
#include "RealNumberType.h"
#include "DLLExport.h"

//realNum is the variable type that can be set by the user
//by default it should be set to being a realNum

/*
* Class: Matrix4
* --------------
*
* this is my Matrix4 class,
* it is comprised of two Vector2
*
* Author: Callum Dunstone
*/
class DLL Matrix4
{
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor that sets
    * the Matrix4 to zero on all postions
    *
    */
    Matrix4();

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is a custom constructor that lets the user to set
    * the values of the Matrix2 manualy
    *
    */
    Matrix4(realNum x1, realNum x2, realNum x3, realNum x4, realNum y1, realNum y2, realNum y3, realNum y4, realNum z1, realNum z2, realNum z3, realNum z4, realNum w1, realNum w2, realNum w3, realNum w4);

    /*
    * Function: DeConstructor
    * ---------------------
    *
    * this is the Default deconstructor
    *
    */
    ~Matrix4();


    const int SIZE = 16; /*how many positions are in the Matrix4*/
    const int ROW_SIZE = 4; /*the leangth of the Matrix4 along its width*/
    const int COLUM_SIZE = 4; /*the leangth of the height of the Matrix4*/

    Vector4 vec[4]; /*the array of Vector4 that makes up the internal array of the Matrix4*/

    /*
    * Function: setRotateX
    * --------------------
    *
    * sets the rotation of the matrix on the xaxis by the radion passed into it
    * this also wipes out all the other variables in the matrix so you have been warned
    *
    * Parameters: this takes in a realNum (by default float) that is going to be interpreted as a radian 
    * and used to set the roatation of the matrix
    *
    * returns: nothing for it has a void in its heart
    */
    void setRotateX(realNum r);

    /*
    * Function: setRotateY
    * --------------------
    *
    * sets the rotation of the matrix on the yaxis by the radion passed into it
    * this also wipes out all the other variables in the matrix so you have been warned
    *
    * Parameters: this takes in a realNum (by default float) that is going to be interpreted as a radian
    * and used to set the roatation of the matrix
    *
    * returns: nothing for it has a void in its heart
    */
    void setRotateY(realNum r);

    /*
    * Function: setRotateZ
    * --------------------
    *
    * sets the rotation of the matrix on the zaxis by the radion passed into it
    * this also wipes out all the other variables in the matrix so you have been warned
    *
    * Parameters: this takes in a realNum (by default float) that is going to be interpreted as a radian
    * and used to set the roatation of the matrix
    *
    * returns: nothing for it has a void in its heart
    */
    void setRotateZ(realNum r);

    /*
    * Function: setRotateEuler
    * ------------------------
    *
    * sets the rotation of the matrix on all axis by the radion passed into it
    * this also wipes out all the other variables in the matrix so you have been warned
    *
    * Parameters: this takes in a Vector4 that we will use to rotate the matrix on all axis
    *
    * returns: nothing for it has a void in its heart
    */
    void setRotateEuler(const Vector4 & euler);

    /*
    * Function: RotateX
    * -----------------
    *
    * this rotates the matrix on the x axis using the value passed in
    *
    * Parameters: this takes in a realNum (by default float) that is going to be interpreted as a radian
    * and used to set the roatation of the matrix
    *
    * returns: nothing for it has a void in its heart
    */
    void RotateX(realNum r);

    /*
    * Function: RotateY
    * -----------------
    *
    * this rotates the matrix on the y axis using the value passed in
    *
    * Parameters: this takes in a realNum (by default float) that is going to be interpreted as a radian
    * and used to set the roatation of the matrix
    *
    * returns: nothing for it has a void in its heart
    */
    void RotateY(realNum r);

    /*
    * Function: RotateZ
    * -----------------
    *
    * this rotates the matrix on the z axis using the value passed in
    *
    * Parameters: this takes in a realNum (by default float) that is going to be interpreted as a radian
    * and used to set the roatation of the matrix
    *
    * returns: nothing for it has a void in its heart
    */
    void RotateZ(realNum r);
    

    /*
    * Function: RotateZ
    * -----------------
    *
    * this rotates the matrix on all axis by the values stored in the vector
    * in the order of x, y and z
    *
    * Parameters: this takes in a Vector3 that we will use to rotate the matrix with the values held inside the vector
    *
    * returns: nothing for it has a void in its heart
    */
    void RotateEuler(Vector4 euler);

    /*
    * Function: GetScale
    * -----------------
    *
    * this gets the scale of the matrix by finding the magnitued of each collum except for the
    * far right one and all values on the buttom row
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a Vector3 holding the scale of the matrix
    */
    Vector3 GetScale();

    /*
    * Function: GetTranlation
    * -----------------------
    *
    * this gets the translation of the matrix by retriving the values held on the buttom row of the matrix
    * vec[3] and returning it held in a vector3
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns a Vector3 holding the translation of the matrix
    */
    Vector3 GetTranlation();

    /*
    * Function: Inverse
    * -----------------
    *
    * this inverses the Matrix4 values and returns that in a new matrix
    *
    * Parameters: this takes no parameters
    *
    * returns: returns a Matrix4 with the inverse values of the matrix that called this function
    */
    Matrix4 Inverse();

    /*
    * Function: SetIdentity
    * ---------------------
    *
    * this creats a new Matrix4 that is an identity Matrix4 and returns that
    *
    * Parameters: this takes no parameters
    *
    * returns: returns an identity Matrix4
    */
    Matrix4 SetIdentity();

    /*
    * Function: Determinant
    * ---------------------
    *
    * this finds the determinant of the matrix
    *
    * Parameters: this takes no parameters
    *
    * returns: returns an identity Matrix4
    */
    realNum Determinant();

    /*
    * Function: SetTranslate
    * ----------------------
    *
    * this takes in a vector4 and sets or translation to it by assiging the vector4 to vec[3]
    *
    * Parameters: this takes in a vector4 to set our translation to
    *
    * returns: returns nothing
    */
    void SetTranslate(const Vector4 & translate);

    /*
    * Function: Translate
    * -------------------
    *
    * this takes in a vector4 and increases out translation by adding the vector4 to vec[3]
    *
    * Parameters: this takes in a vector4 to increase our translation by
    *
    * returns: returns nothing
    */
    void Translate(const Vector4 & translate);

    /*
    * Function: SetScale
    * ------------------
    *
    * this takes in a vector4 and sets our scale by wiping the matrix and assinging the
    * identity locations to the vector passed in
    *
    * Parameters: this takes in a vector4 to set our scale with
    *
    * returns: returns nothing
    */
    void SetScale(const Vector4 & scale);

    /*
    * Function: Scale
    * ---------------
    *
    * this takes in a vector4 and changes ou scale by multiplying the matric
    * identity locations with the vector passed in
    *
    * Parameters: this takes in a vector4 to change our scale with
    *
    * returns: returns nothing
    */
    void Scale(const Vector4 & scale);

    /*
    * Function: LookAt
    * ----------------
    *
    * this rotates the matrix to look at the matrix passed in
    *
    * Parameters: this takes in a matrix that we want to look at
    *
    * returns: returns an identity Matrix4
    */
    void LookAt(const Matrix4 & target);

    /*
    * Function: LookAt
    * ----------------
    *
    * this rotates the matrix to look at the vector passed in
    *
    * Parameters: this takes in a vector that we want to look at
    *
    * returns: returns an identity Matrix4
    */
    void LookAt(const Vector3 & target);

    /*
    * Overload: *
    * -----------
    *
    * this creats a new Matrix4 using Matrix multiplication maths
    * so that Matrix4 can be apropritaly multiplyed
    *
    * Parameters: this takes a refrence to a Matrix4 refA that we want to multiply with
    *
    * returns: returns an Matrix4
    */
    Matrix4 operator * (const Matrix4 & refA) const;

    /*
    * Overload: *=
    * ------------
    *
    * this multiplys the Matrix4 with the refrence matrix using proper Matrix multiplication
    * and set the Matrix4 to the new value
    *
    * Parameters: this takes a refrence to a Matrix4 refA that we want to multiply our selfes with
    *
    * returns: Nothing as it is a void function.
    */
    void operator *= (const Matrix4 & refA);

    /*
    * Overload: *
    * -----------
    *
    * this creats a new Vector4 and multiplys the Matrix4 with a refrence Vector4 using proper matrix multiplication
    * and set the Vector4 to the new value and returns it
    *
    * Parameters: this takes a refrence to a Vector4 refA that we want to multiply our selfes with
    *
    * returns: returns a Vector4 with the new value from multiplying the Matrix4 and refrence to a Vector4 together
    */
    Vector4 operator * (const Vector4 & refA) const;

    /*
    * Overload: *=
    * ------------
    *
    * technically this will look wrong as we are aloud to do Matrix4 * Vector4 and not Vector4 * Matrix4 wich this will look like
    * however i am lazy and would rather not do v = m * v; every songle time and would like to do v *= m;
    * this overload detects that we are calling v *= m; then rewords it to v = m * v; wich calls on the overload for m * v
    * allowing us to give it the appropriate value
    *
    * Parameters: this takes a refrence to a Vector4 vec and a Matrix4 mat that we want to multiply together
    *
    * returns: returns a Vector4 with the new value from multiplying the Matrix3 and refrence to a Vector4 together
    */
    friend void operator *= (Vector4 & vec, Matrix4 & mat) { vec = mat * vec; }

    /*
    * Overload: *
    * -----------
    *
    * this creats a new Vector3 and multiplys the Matrix4 with a refrence Vector3 by first creating a vector 4
    * and doing the appropriate matric multiplication the cangeing the vector4 into a vector 3 and retturning that
    *
    * Parameters: this takes a refrence to a Vector3 refA that we want to multiply our selfes with
    *
    * returns: returns a Vector3 with the new value from multiplying the Matrix4 with a Vector4 created from the passed in vector3
    */
    Vector3 operator * (const Vector3 & refA) const;

    /*
    * Overload: *=
    * ------------
    *
    * changes the Vector3 with the new value from multiplying the Matrix4 with a Vector4 created from the passed in vector3
    *
    * Parameters: this takes a refrence to a Vector4 vec and a Matrix4 mat that we want to multiply together
    *
    * returns: nothing as it is a void function
    */
    friend void operator *= (Vector3 & vec, Matrix4 & mat) { vec = mat * vec; }

    /*
    * Overload: =
    * -----------
    *
    * this takes in a refrence to another Matrix4 that we want to set ourselfs to then goes through
    * a loop seting each position on the Matrix4 to be equal to the refrence Matrix4 we passed into it
    *
    * Parameters: this takes a refrence to a Matrix4 refA that we want to set oourselfes to
    *
    * returns: Nothing as it is a void function.
    */
    void operator = (const Matrix4 & refA);

    /*
    * Overload: ==
    * ------------
    *
    * this checks the values of two matrixs to see if they have exactly the same values and returns true if they do
    *
    * Parameters: this takes a refrence to a Matrix4 refA that we want to check our selfes against
    *
    * returns: true is the two matrix have the same value and false if they do not
    */
    bool operator == (const Matrix4 & refA);

    /*
    * Overload: !=
    * ------------
    *
    * this checks the values of two matrixs to see if they are not the same and returns true if that is the case
    *
    * Parameters: this takes a refrence to a Matrix4 refA that we want to check our selfes against
    *
    * returns: true is the two matrix do not have the same value and false if they do
    */
    bool operator != (const Matrix4 & refA);

    /*
    * Overload: +
    * -----------
    *
    * this creates a new Matrix4 of the combined values of two other Matrix4
    *
    * Parameters: this takes a refrence to a Matrix4 refA that we want to add to our selfes to creat a new Matrix4
    *
    * returns: a new Matrix4 of the combined values of ourselfes and the refA
    */
    Matrix4 operator + (const Matrix4 & refA) const;

    /*
    * Overload: +=
    * ------------
    *
    * this adds the values of refA to our selfes
    *
    * Parameters: this takes a refrence to a Matrix4 refA that we want to add to our selfes
    *
    * returns: nothing as it is a void
    */
    void operator += (const Matrix4 & refA);

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Matrix4 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Matrix4 refA that we want to subtract from our selfes to creat a new Matrix4
    *
    * returns: a new Matrix4 of the subtracted values of refa from our selfes
    */
    Matrix4 operator - (const Matrix4 & refA) const;

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Matrix4 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Matrix4 refA that we want to subtract from our selfes to creat a new Matrix4
    *
    * returns: a new Matrix4 of the subtracted values of refa from our selfes
    */
    void operator -= (const Matrix4 & refA);

    /*
    * Overload: []
    * ------------
    *
    * this allows us to easily and quickly call apon a position in our Vector4 vec array
    * so that we can acces it
    *
    * Parameters: int index this is the position in the array we want to get
    *
    * returns: a refrence to a Vector3 in our internal array of Vector3
    */
    Vector4 & operator [] (int index);

    /*
    * Overload: realNum *
    * -----------------
    *
    * this returns the memory address of the start of our array of vectors and their x, y, z positions
    *
    * Parameters: this takes no parameters
    *
    * returns: the memory address to the start of our array
    */
    operator realNum * () { return &vec[0][0]; }

};