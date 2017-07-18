#include "Matrix3.h"
#include "Matrix2.h"
#include <math.h>


//sets the matrix to zero
Matrix3::Matrix3()
{
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int u = 0; u < COLUM_SIZE; u++)
        {
            vec[i][u] = 0;
        }
    }
}

//sets the matrix to the values entered by the user
Matrix3::Matrix3(realNum x1, realNum x2, realNum x3, realNum y1, realNum y2, realNum y3, realNum z1, realNum z2, realNum z3)
{
    vec[0].x = x1;
    vec[0].y = x2;
    vec[0].z = x3;

    vec[1].x = y1;
    vec[1].y = y2;
    vec[1].z = y3;

    vec[2].x = z1;
    vec[2].y = z2;
    vec[2].z = z3;
}


Matrix3::~Matrix3()
{
}

//this sets the rotation of the x axis and destroys all other values held in the matrix
void Matrix3::setRotateX(realNum r)
{
    this->SetIdentity();

    vec[1].y = (realNum)cos((double)r);
    vec[1].z = (realNum)sin((double)r);

    vec[2].y = -(realNum)sin((double)r);
    vec[2].z = (realNum)cos((double)r);
}

//this sets the rotation of the y axis and destroys all other values held in the matrix
void Matrix3::setRotateY(realNum r)
{
    this->SetIdentity();

    vec[0].x = (realNum)cos((double)r);
    vec[0].z = -(realNum)sin((double)r);

    vec[2].x = (realNum)sin((double)r);
    vec[2].z = (realNum)cos((double)r);
}

//this sets the rotation of the z axis and destroys all other values held in the matrix
void Matrix3::setRotateZ(realNum r)
{
    this->SetIdentity();

    vec[0].x = (realNum)cos((double)r);
    vec[0].y = (realNum)sin((double)r);

    vec[1].x = -(realNum)sin((double)r);
    vec[1].y = (realNum)cos((double)r);
}

//set the roatate of the matric on all axis
void Matrix3::setRotateEuler(const Vector3 & euler)
{
    Matrix3 rx;
    rx.SetIdentity();
    Matrix3 ry;
    ry.SetIdentity();
    Matrix3 rz;
    rz.SetIdentity();

    rx.RotateX(euler.x);
    ry.RotateY(euler.y);
    rz.RotateZ(euler.z);

    this->SetIdentity();

    *this = (rx * ry * rz * *this);
}

//this adds a rotation on the x axis
void Matrix3::RotateX(realNum r)
{
    Matrix3 rx;

    rx.setRotateX(r);

    *this *= rx;
}

//this adds a rotation on the x axis
void Matrix3::RotateY(realNum r)
{
    Matrix3 ry;

    ry.setRotateY(r);

    *this *= ry;
}

//this adds a rotation on the x axis
void Matrix3::RotateZ(realNum r)
{
    Matrix3 rz;

    rz.setRotateZ(r);

    *this *= rz;
}

//this adds a rotation on all the axis based on the vector passed in
void Matrix3::RotateEuler(Vector3 euler)
{
    Matrix3 rx;
    rx.SetIdentity();
    Matrix3 ry;
    ry.SetIdentity();
    Matrix3 rz;
    rz.SetIdentity();

    rx.RotateX(euler.x);
    ry.RotateY(euler.y);
    rz.RotateZ(euler.z);

    *this *= (rx * ry * rz * *this);
}

//this set the tranlation of the matrix by seting its bottum row to the vector3 passed in
void Matrix3::SetTranslate(const Vector3 & translate)
{
    this->vec[2] = translate;
}

//this increases or tranlation by adding the vecotr passed into our matrix
void Matrix3::Translate(const Vector3 & translate)
{
    this->vec[2] += translate;
}

//this sets the scale of the matrix to the vecotr passed in
void Matrix3::SetScale(const Vector3 & scale)
{
    this->SetIdentity();
    this->vec[0].x = scale.x;
    this->vec[1].y = scale.y;
    this->vec[2].z = scale.z;
}

//this changes the scale of the matrixx by multplying it with the vector passed in
void Matrix3::Scale(const Vector3 & scale)
{
    this->vec[0].x *= scale.x;
    this->vec[1].y *= scale.y;
    this->vec[2].z *= scale.z;
}

//gets roataion on the x axis
float Matrix3::GetX()
{
    return float(atan2(this->vec[1].z, this->vec[2].z));
}

//gets rotation on the y axis
float Matrix3::GetY()
{
    return float(atan2(-this->vec[0].z, sqrt((this->vec[1].z * this->vec[1].z) + (this->vec[2].z * this->vec[2].z))));
}

//gets rotation on the z axis
float Matrix3::GetZ()
{
    return float(atan2(this->vec[1].x, this->vec[1].y));
}

Vector2 Matrix3::GetTranslation()
{
	return this->vec[2];
}

//gets all the rotation values stored in a vector3
Vector3 Matrix3::GetRotationEuler()
{
    float x = this->GetX();
    float y = this->GetY();
    float z = this->GetZ();

    return Vector3(x, y, z);
}

//this gets the scale of the matrix
Vector2 Matrix3::GetScale()
{
    realNum xm = this->vec[0].x < 0 ? (realNum)1.0f : (realNum)-1.0f;
    xm = this->vec[0].x == 0 ? (realNum)0.0f : xm;

    realNum ym = this->vec[1].y < 0 ? (realNum)1.0f : (realNum)-1.0f;
    ym = this->vec[1].y == 0 ? (realNum)0.0f : ym;

    realNum xScale = xm * (realNum)sqrt((this->vec[0].x * this->vec[0].x) + (this->vec[1].x * this->vec[1].x) + (this->vec[2].x * this->vec[2].x));

    realNum yScale = ym * (realNum)sqrt((this->vec[0].y * this->vec[0].y) + (this->vec[1].y * this->vec[1].y) + (this->vec[2].y * this->vec[2].y));

    return Vector2(xScale, yScale);
}

//multiplyes two matrix together and returns the resault in a new matrix
Matrix3 Matrix3::operator * (const Matrix3 & refA) const
{
    Matrix3 m;

    int inner = 3;

    realNum sum = 0;

    //the fancy matrix multiplication or rows * colums
    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {

            for (int i = 0; i < inner; i++)
            {
                m[x][y] += this->vec[i][y] * refA.vec[x][i];
            }
        }
    }

    return m;
}

//multiplies the two matrix together assingin the new value to the matrix on the left of the argumeant
// m1 *= m2 new value goes into m1
void Matrix3::operator *= (const Matrix3 & refA)
{
    Matrix3 m;

    int inner = 3;

    //more fancy matrix multiplication or rows * colums
    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            for (int i = 0; i < inner; i++)
            {
                m[x][y] += this->vec[i][y] * refA.vec[x][i];
            }
        }
    }


    *this = m;
}

//multiplyes a matrix and vector together and returns the resault in a new vector
Vector3 Matrix3::operator * (const Vector3 & refA) const
{
    Vector3 v;

    //slightly less fancey matrix multiplication
    //as vectors are only 1 * n and not n * n like matrixs
    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int i = 0; i < COLUM_SIZE; i++)
        {
            v[y] += this->vec[i][y] * refA[i];
        }
    }

    return v;
}

//assigns left hand matrix to be equal to right hand matric
void Matrix3::operator = (const Matrix3 & refA)
{
    Matrix3 m;

    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            this->vec[y][x] = refA.vec[y][x];
        }
    }
}

//checks if the two matrixs are equall or not
bool Matrix3::operator == (const Matrix3 & refA)
{
    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            if (this->vec[y][x] != refA.vec[y][x])
            {
                return false;
            }
        }
    }

    return true;
}

//checks if the two matrixs are not quall
bool Matrix3::operator != (const Matrix3 & refA)
{
    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            if (this->vec[y][x] != refA.vec[y][x])
            {
                return true;
            }
        }
    }

    return false;
}

//returns a refrence to a vector in the internal array of vectors in the matric
Vector3 & Matrix3::operator [] (int index)
{
    switch (index)
    {

    case 0:
        return vec[0];
    case 1:
        return vec[1];
    case 2:
        return vec[2];

    default: throw;
    }
}

//adds two matrix together and returns the resault in a new matrix
Matrix3 Matrix3::operator + (const Matrix3 & refA) const
{
    Matrix3 m;

    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            m[y][x] = this->vec[y][x] + refA.vec[y][x];
        }
    }

    return m;
}

//adds the value of the right hand matrix to the one on the left hand
void Matrix3::operator += (const Matrix3 & refA)
{
    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            this->vec[y][x] += refA.vec[y][x];
        }
    }
}

//subtracts the value of the right hand matrix from the left and returns the value in a new matrix
Matrix3 Matrix3::operator - (const Matrix3 & refA) const
{
    Matrix3 m;

    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            m[y][x] = this->vec[y][x] - refA.vec[y][x];
        }
    }

    return m;
}

//subtracts the value of the right hand matrix from the left
void Matrix3::operator -= (const Matrix3 & refA)
{
    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            this->vec[y][x] -= refA.vec[y][x];
        }
    }
}

//this inverses the matrix and assigns that to a new matrix and returns it leaving the original unchanged
Matrix3 Matrix3::Inverse() const
{
    Matrix3 m = * this;

    realNum determinant = Determinant();


    Matrix3 mb;
    Matrix2 mat[9] = {  Matrix2(this->vec[1].y, this->vec[1].z, this->vec[2].y, this->vec[2].z), Matrix2(this->vec[0].z, this->vec[0].y, this->vec[2].z, this->vec[2].y), Matrix2(this->vec[0].y, this->vec[0].z, this->vec[1].y, this->vec[1].z), 
                        Matrix2(this->vec[1].z, this->vec[1].x, this->vec[2].z, this->vec[2].x), Matrix2(this->vec[0].x, this->vec[0].z, this->vec[2].x, this->vec[2].z), Matrix2(this->vec[0].z, this->vec[0].x, this->vec[1].z, this->vec[1].x),
                        Matrix2(this->vec[1].x, this->vec[1].y, this->vec[2].x, this->vec[2].y), Matrix2(this->vec[0].y, this->vec[0].x, this->vec[2].y, this->vec[2].x) ,Matrix2(this->vec[0].x, this->vec[0].y, this->vec[1].x, this->vec[1].y)};

    int count = 0;

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            mb[y][x] = mat[count].Determiant();
            count++;
        }
    }

    mb[0].x *= 1;
    mb[0].y *= -1;
    mb[0].z *= 1;

    mb[1].x *= -1;
    mb[1].y *= 1;
    mb[1].z *= -1;

    mb[2].x *= 1;
    mb[2].y *= -1;
    mb[2].z *= 1;

    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            mb[x][y] /= determinant;
        }
    }

    mb[0].x *= 1;
    mb[0].y *= -1;
    mb[0].z *= 1;

    mb[1].x *= -1;
    mb[1].y *= 1;
    mb[1].z *= -1;

    mb[2].x *= 1;
    mb[2].y *= -1;
    mb[2].z *= 1;

    return mb;
}

//finds the determinat of this matric
realNum Matrix3::Determinant() const
{
    Matrix3 m = * this;
    return ((m[0].x * m[1].y * m[2].z) + (m[0].y * m[1].z * m[2].x) + (m[0].z * m[1].x * m[2].y)) - ((m[0].y * m[1].x * m[2].z) + (m[0].x * m[1].z * m[2].y) + (m[0].z * m[1].y * m[2].x));
}

//sets the matrix to be an Identity
Matrix3 Matrix3::SetIdentity()
{
    Matrix3 m;

    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int u = 0; u < COLUM_SIZE; u++)
        {
            if (i == u)
            {
                m[i][u] = vec[i][u] = 1;
            }
            else
            {
                m[i][u] = vec[i][u] = 0;
            }
        }
    }

    return m;
}

//checks to see if the matrix is set to an identity (probably uneeded)
bool Matrix3::CheckIFSetToIdentity() const
{
    Matrix3 m;

    if (m == this->Inverse())
    {
        return true;
    }
    else
    {
        return false;
    }
}