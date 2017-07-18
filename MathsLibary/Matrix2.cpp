#include "Matrix2.h"
#include <math.h>


//sets the matrix to zero
Matrix2::Matrix2()
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
Matrix2::Matrix2(realNum x1, realNum x2, realNum y1, realNum y2)
{
    vec[0].x = x1;
    vec[0].y = x2;
    
    vec[1].x = y1;
    vec[1].y = y2;
}


Matrix2::~Matrix2()
{
}

//this rotates the matrix depending on the value passed in
void Matrix2::setRotate(realNum r)
{
    vec[0].x = (realNum)cos((double)r);
    vec[0].y = (realNum)sin((double)r);

    vec[1].x = -(realNum)sin((double)r);
    vec[1].y = (realNum)cos((double)r);
}

//sets the translation of the matrix
void Matrix2::Translate(Vector2 pos)
{
    this->vec[1] += pos;
}

//this sets the scale of the matrix to the vecotr passed in
void Matrix2::SetScale(const Vector2 & scale)
{
    this->SetIdentity();
    this->vec[0].x = scale.x;
    this->vec[1].y = scale.y;
}

//this changes the scale of the matrixx by multplying it with the vector passed in
void Matrix2::Scale(const Vector2 & scale)
{
    this->vec[0].x *= scale.x;
    this->vec[1].y *= scale.y;
}

//multiplyes two matrix together and returns the resault in a new matrix
Matrix2 Matrix2::operator * (const Matrix2 & refA) const
{
    Matrix2 m;

    int inner = 2;

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
void Matrix2::operator *= (const Matrix2 & refA)
{
    Matrix2 m;

    int inner = 2;

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

    
    * this = m;
}

//multiplyes a matrix and vector together and returns the resault in a new vector
Vector2 Matrix2::operator * (const Vector2 & refA) const
{
    Vector2 v;

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
void Matrix2::operator = (const Matrix2 & refA)
{
    Matrix2 m;

    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
                this->vec[y][x] = refA.vec[y][x];
        }
    }
}

//checks if the two matrixs are equall or not
bool Matrix2::operator == (const Matrix2 & refA)
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
bool Matrix2::operator != (const Matrix2 & refA)
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
Vector2 & Matrix2::operator [] (int index)
{
    switch (index)
    {

    case 0:
        return vec[0];
    case 1:
        return vec[1];

    default: throw;
    }
}

//adds two matrix together and returns the resault in a new matrix
Matrix2 Matrix2::operator + (const Matrix2 & refA) const
{
    Matrix2 m;

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
void Matrix2::operator += (const Matrix2 & refA)
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
Matrix2 Matrix2::operator - (const Matrix2 & refA) const
{
    Matrix2 m;

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
void Matrix2::operator -= (const Matrix2 & refA)
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
Matrix2 Matrix2::Inverse ()
{
    Matrix2 m;

    realNum determinant = Determiant();

    if (determinant == 0)
    {
        m = *this;
        return m;
    }

    m[0][0] = this->vec[1][1];
    m[1][1] = this->vec[0][0];

    m[0][1] = this->vec[0][1] * -1;
    m[1][0] = this->vec[1][0] * -1;


    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            m[y][x] /= determinant;
        }
    }

    return m;
}

//returns the determiant of our matrix
realNum Matrix2::Determiant()
{
    realNum d = (this->vec[0][0] * this->vec[1][1]) - (this->vec[0][1] * this->vec[1][0]);
    return d;
}

//sets the matrix to be an Identity
Matrix2 Matrix2::SetIdentity()
{
    Matrix2 m;

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