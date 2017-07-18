#pragma once
#include "Vector3.h"
#include "RealNumberType.h"
#include "DLLExport.h"

//realNum is the variable type that can be set by the user
//by default it should be set to being a realNum

/*
* Class: Matrix3
* --------------
*
* this is my Matrix3 class,
* it is comprised of two Vector2
*
* Author: Callum Dunstone
*/
class DLL Matrix3
{
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor that sets
    * the Matrix3 to zero on all postions
    *
    */
    Matrix3();

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is a custom constructor that lets the user to set
    * the values of the Matrix2 manualy
    *
    */
    Matrix3(realNum x1, realNum x2, realNum x3, realNum y1, realNum y2, realNum y3, realNum z1, realNum z2, realNum z3);

    /*
    * Function: DeConstructor
    * ---------------------
    *
    * this is the Default deconstructor
    *
    */
    ~Matrix3();


    const int SIZE = 9; /*how many positions are in the Matrix3*/
    const int ROW_SIZE = 3; /*the leangth of the Matrix3 along its width*/
    const int COLUM_SIZE = 3; /*the leangth of the height of the Matrix3*/

    Vector3 vec[3]; /*the array of Vector3s that makes up the internal array of the Matrix3*/

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
    * Parameters: this takes in a Vector3 that we will use to rotate the matrix on all axis
    *
    * returns: nothing for it has a void in its heart
    */
    void setRotateEuler(const Vector3 & euler);

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
    void RotateEuler(Vector3 euler);

    /*
    * Function: GetX
    * --------------
    *
    * this gets the x rotation value
    *
    * Parameters: this takes in no parameters
    *
    * returns: a float holding the x rotation values
    */
    float GetX();

    /*
    * Function: GetY
    * --------------
    *
    * this gets the y rotation value
    *
    * Parameters: this takes in no parameters
    *
    * returns: a float holding the y rotation values
    */
    float GetY();

    /*
    * Function: GetZ
    * --------------
    *
    * this gets the z rotation value
    *
    * Parameters: this takes in no parameters
    *
    * returns: a float holding the z rotation values
    */
    float GetZ();

	/*
	* Function: GetTranslation
	* ------------------------
	*
	* this gets the vector holding the translation of the matrix
	*
	* Parameters: this takes in no parameters
	*
	* returns: a vector2 from matrix pos[2]
	*/
	Vector2 GetTranslation();

    /*
    * Function: GetRotationEuler
    * --------------------------
    *
    * this gets all the rotation values
    *
    * Parameters: this takes in no parameters
    *
    * returns: a vector 3 holding all rotation values
    */
    Vector3 GetRotationEuler();

    /*
    * Function: Inverse
    * -----------------
    *
    * this inverses the Matrix3 values and returns that in a new matrix
    *
    * Parameters: this takes no parameters
    *
    * returns: returns a Matrix3 with the inverse values of the matrix that called this function
    */
    Matrix3 Inverse() const;

    /*
    * Function: CheckIFSetToIdentity
    * ------------------------------
    *
    * this checks to see if the Matrix3 that calls it is an identity Matrix or not
    *
    * Parameters: this takes no parameters
    *
    * returns: returns true if Matrix3 is identity and false if not
    */
    bool CheckIFSetToIdentity() const;

    /*
    * Function: SetIdentity
    * ---------------------
    *
    * this creats a new Matrix3 that is an identity Matrix3 and returns that
    *
    * Parameters: this takes no parameters
    *
    * returns: returns an identity Matrix3
    */
    Matrix3 SetIdentity();

    /*
    * Function: Determinant
    * ---------------------
    *
    * finds the Dterminant of the matrix
    *
    * Parameters: this takes no parameters
    *
    * returns: returns the determinant for the matrix
    */
    realNum Determinant() const;

    /*
    * Function: SetTranslate
    * ----------------------
    *
    * this takes in a vector3 and sets or translation to it by assiging the vector3 to vec[2]
    *
    * Parameters: this takes in a vector3 to set our translation to
    *
    * returns: returns nothing
    */
    void SetTranslate(const Vector3 & translate);

    /*
    * Function: Translate
    * -------------------
    *
    * this takes in a Vector3 and increases out translation by adding the Vector3 to vec[3]
    *
    * Parameters: this takes in a Vector3 to increase our translation by
    *
    * returns: returns nothing
    */
    void Translate(const Vector3 & translate);

    /*
    * Function: SetScale
    * ------------------
    *
    * this takes in a vector3 and sets our scale by wiping the matrix and assinging the
    * identity locations to the vector passed in
    *
    * Parameters: this takes in a vector3 to set our scale with
    *
    * returns: returns nothing
    */
    void SetScale(const Vector3 & scale);

    /*
    * Function: Scale
    * ---------------
    *
    * this takes in a vector3 and changes ou scale by multiplying the matric
    * identity locations with the vector passed in
    *
    * Parameters: this takes in a vector3 to change our scale with
    *
    * returns: returns nothing
    */
    void Scale(const Vector3 & scale);

    Vector2 GetScale();

    /*
    * Overload: *
    * -----------
    *
    * this creats a new Matrix3 using Matrix multiplication maths
    * so that Matrix3 can be apropritaly multiplyed
    *
    * Parameters: this takes a refrence to a Matrix3 refA that we want to multiply with
    *
    * returns: returns an Matrix3
    */
    Matrix3 operator * (const Matrix3 & refA) const;

    /*
    * Overload: *=
    * ------------
    *
    * this multiplys the Matrix3 with the refrence matrix using proper Matrix multiplication
    * and set the Matrix3 to the new value
    *
    * Parameters: this takes a refrence to a Matrix3 refA that we want to multiply our selfes with
    *
    * returns: Nothing as it is a void function.
    */
    void operator *= (const Matrix3 & refA);

    /*
    * Overload: *
    * -----------
    *
    * this creats a new Vector3 and multiplys the Matrix3 with a refrence Vector3 using proper matrix multiplication
    * and set the Vector3 to the new value and returns it
    *
    * Parameters: this takes a refrence to a Vector3 refA that we want to multiply our selfes with
    *
    * returns: returns a Vector3 with the new value from multiplying the Matrix3 and refrence to a Vector3 together
    */
    Vector3 operator * (const Vector3 & refA) const;

    /*
    * Overload: *
    * -----------
    *
    * technically this will look wrong as we are aloud to do Matrix3 * Vector3 and not Vector3 * Matrix3 wich this will look like
    * however i am lazy and would rather not do v = m * v; every songle time and would like to do v *= m;
    * this overload detects that we are calling v *= m; then rewords it to v = m * v; wich calls on the overload for m * v
    * allowing us to give it the appropriate value
    *
    * Parameters: this takes a refrence to a Vector3 vec and a Matrix3 mat that we want to multiply together
    *
    * returns: returns a Vector3 with the new value from multiplying the Matrix3 and refrence to a Vector3 together
    */
    friend void operator *= (Vector3 & vec, Matrix3 & mat) { vec = mat * vec; }

    /*
    * Overload: =
    * -----------
    *
    * this takes in a refrence to another Matrix3 that we want to set ourselfs to then goes through
    * a loop seting each position on the Matrix3 to be equal to the refrence Matrix3 we passed into it
    *
    * Parameters: this takes a refrence to a Matrix3 refA that we want to set oourselfes to
    *
    * returns: Nothing as it is a void function.
    */
    void operator = (const Matrix3 & refA);

    /*
    * Overload: ==
    * ------------
    *
    * this checks the values of two matrixs to see if they have exactly the same values and returns true if they do
    *
    * Parameters: this takes a refrence to a Matrix3 refA that we want to check our selfes against
    *
    * returns: true is the two matrix have the same value and false if they do not
    */
    bool operator == (const Matrix3 & refA);

    /*
    * Overload: !=
    * ------------
    *
    * this checks the values of two matrixs to see if they are not the same and returns true if that is the case
    *
    * Parameters: this takes a refrence to a Matrix3 refA that we want to check our selfes against
    *
    * returns: true is the two matrix do not have the same value and false if they do
    */
    bool operator != (const Matrix3 & refA);

    /*
    * Overload: +
    * -----------
    *
    * this creates a new Matrix3 of the combined values of two other Matrix3
    *
    * Parameters: this takes a refrence to a Matrix3 refA that we want to add to our selfes to creat a new Matrix3
    *
    * returns: a new Matrix3 of the combined values of ourselfes and the refA
    */
    Matrix3 operator + (const Matrix3 & refA) const;

    /*
    * Overload: +=
    * ------------
    *
    * this adds the values of refA to our selfes
    *
    * Parameters: this takes a refrence to a Matrix3 refA that we want to add to our selfes
    *
    * returns: nothing as it is a void
    */
    void operator += (const Matrix3 & refA);

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Matrix3 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Matrix3 refA that we want to subtract from our selfes to creat a new Matrix3
    *
    * returns: a new Matrix3 of the subtracted values of refa from our selfes
    */
    Matrix3 operator - (const Matrix3 & refA) const;

    /*
    * Overload: -
    * -----------
    *
    * this creates a new Matrix3 of the subtracted values of refa from our selfes
    *
    * Parameters: this takes a refrence to a Matrix3 refA that we want to subtract from our selfes to creat a new Matrix3
    *
    * returns: a new Matrix3 of the subtracted values of refa from our selfes
    */
    void operator -= (const Matrix3 & refA);

    /*
    * Overload: []
    * ------------
    *
    * this allows us to easily and quickly call apon a position in our Vector3 vec array
    * so that we can acces it
    *
    * Parameters: int index this is the position in the array we want to get
    *
    * returns: a refrence to a Vector3 in our internal array of Vector3
    */
    Vector3 & operator [] (int index);

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

