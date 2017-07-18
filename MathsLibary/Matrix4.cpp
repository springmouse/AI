#include "Matrix4.h"
#include "Matrix3.h"
#include "Matrix2.h"
#include <math.h>


//sets the matrix to zero
Matrix4::Matrix4()
{
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int u = 0; u < COLUM_SIZE; u++)
        {
                vec[i][u] = (realNum)0.0f;
        }
    }
}

//sets the matrix to the values entered by the user
Matrix4::Matrix4(realNum x1, realNum x2, realNum x3, realNum x4, realNum y1, realNum y2, realNum y3, realNum y4, realNum z1, realNum z2, realNum z3, realNum z4, realNum w1, realNum w2, realNum w3, realNum w4)
{
    vec[0].x = x1;
    vec[0].y = x2;
    vec[0].z = x3;
    vec[0].w = x4;

    vec[1].x = y1;
    vec[1].y = y2;
    vec[1].z = y3;
    vec[1].w = y4;

    vec[2].x = z1;
    vec[2].y = z2;
    vec[2].z = z3;
    vec[2].w = z4;

    vec[3].x = w1;
    vec[3].y = w2;
    vec[3].z = w3;
    vec[3].w = w4;
}


Matrix4::~Matrix4()
{
}

//this sets the rotation of the x axis and destroys all other values held in the matrix
void Matrix4::setRotateX(realNum r)
{
    this->SetIdentity();

    vec[1].y = (realNum)cos((double)r);
    vec[1].z = (realNum)sin((double)r);

    vec[2].y = -(realNum)sin((double)r);
    vec[2].z = (realNum)cos((double)r);
}

//this sets the rotation of the y axis and destroys all other values held in the matrix
void Matrix4::setRotateY(realNum r)
{
    this->SetIdentity();

    vec[0].x = (realNum)cos((double)r);
    vec[0].z = -(realNum)sin((double)r);

    vec[2].x = (realNum)sin((double)r);
    vec[2].z = (realNum)cos((double)r);
}

//this sets the rotation of the z axis and destroys all other values held in the matrix
void Matrix4::setRotateZ(realNum r)
{
    this->SetIdentity();

    vec[0].x = (realNum)cos((double)r);
    vec[0].y = (realNum)sin((double)r);

    vec[1].x = -(realNum)sin((double)r);
    vec[1].y = (realNum)cos((double)r);
}

//set the roatate of the matric on all axis
void Matrix4::setRotateEuler(const Vector4 & euler)
{
    Matrix4 rx;
    rx.SetIdentity();
    Matrix4 ry;
    ry.SetIdentity();
    Matrix4 rz;
    rz.SetIdentity();

    rx.RotateX(euler.x);
    ry.RotateY(euler.y);
    rz.RotateZ(euler.z);

    this->SetIdentity();

    *this = (rx * ry * rz * *this);
}

//this adds a rotation on the x axis
void Matrix4::RotateX(realNum r)
{
    Matrix4 rx;
    
    rx.setRotateX(r);

    *this *= rx;
}

//this adds a rotation on the x axis
void Matrix4::RotateY(realNum r)
{
    Matrix4 ry;

    ry.setRotateY(r);

    *this *= ry;
}

//this adds a rotation on the x axis
void Matrix4::RotateZ(realNum r)
{
    Matrix4 rz;

    rz.setRotateZ(r);

    *this *= rz;
}

//this adds a rotation on all the axis based on the vector passed in
void Matrix4::RotateEuler(Vector4 euler)
{
    Matrix4 rx;
    rx.SetIdentity();
    Matrix4 ry;
    ry.SetIdentity();
    Matrix4 rz;
    rz.SetIdentity();

    rx.RotateX(euler.x);
    ry.RotateY(euler.y);
    rz.RotateZ(euler.z);

    *this *= (rx * ry * rz * *this);
}



//this set the tranlation of the matrix by seting its bottum row to the vector3 passed in
void Matrix4::SetTranslate(const Vector4 & translate)
{
    this->vec[3] = translate;
}

//this increases or tranlation by adding the vecotr passed into our matrix
void Matrix4::Translate(const Vector4 & translate)
{
    this->vec[3] += translate;
}

//this gets the matrix translation and returns it as a vector 3
Vector3 Matrix4::GetTranlation()
{
    return this->vec[3];
}

//this sets the scale of the matrix to the vecotr passed in
void Matrix4::SetScale(const Vector4 & scale)
{
    this->SetIdentity();
    this->vec[0].x = scale.x;
    this->vec[1].y = scale.y;
    this->vec[2].z = scale.z;
    this->vec[3].w = scale.w;
}

//this is meant to return the scale of the matrix
Vector3 Matrix4::GetScale()
{
    realNum xm = this->vec[0].x < 0 ? (realNum)1.0f : (realNum)-1.0f;
    xm = this->vec[0].x == 0 ? (realNum)0.0f : xm;

    realNum ym = this->vec[1].y < 0 ? (realNum)1.0f : (realNum)-1.0f;
    ym = this->vec[1].y == 0 ? (realNum)0.0f : ym;

    realNum zm = this->vec[2].z < 0 ? (realNum)1.0f : (realNum)-1.0f;
    zm = this->vec[2].z == 0 ? (realNum)0.0f : zm;

    realNum xScale = xm * (realNum)sqrt((this->vec[0].x * this->vec[0].x) + (this->vec[1].x * this->vec[1].x) + (this->vec[2].x * this->vec[2].x));

    realNum yScale = ym * (realNum)sqrt((this->vec[0].y * this->vec[0].y) + (this->vec[1].y * this->vec[1].y) + (this->vec[2].y * this->vec[2].y));

    realNum zScale = zm * (realNum)sqrt((this->vec[0].z * this->vec[0].z) + (this->vec[1].z * this->vec[1].z) + (this->vec[2].z * this->vec[2].z));

    return Vector3(xScale, yScale, zScale);
}

//this changes the scale of the matrixx by multplying it with the vector passed in
void Matrix4::Scale(const Vector4 & scale)
{
    this->vec[0].x *= scale.x;
    this->vec[1].y *= scale.y;
    this->vec[2].z *= scale.z;
    this->vec[3].w *= scale.w;
}

//this makes the matrix rotate to look at the passed in matrix
void Matrix4::LookAt(const Matrix4 & target)
{
    Vector3 at = target * Vector3();
    Vector3 eye = *this * Vector3();
    Vector3 up = Vector3().Forward();

    Vector3 zaxis = (at - eye).normalised();
    Vector3 xaxis = (up.cross(zaxis)).normalised();
    Vector3 yaxis = zaxis.cross(xaxis);

    Matrix4 lookAtMat = Matrix4().SetIdentity();

    lookAtMat[0].x = xaxis.x;
    lookAtMat[0].y = xaxis.y;
    lookAtMat[0].z = xaxis.z;
    lookAtMat[0].w = -xaxis.dot(eye);

    lookAtMat[1].x = yaxis.x;
    lookAtMat[1].y = yaxis.y;
    lookAtMat[1].z = yaxis.z;
    lookAtMat[1].w = -yaxis.dot(eye);

    lookAtMat[2].x = zaxis.x;
    lookAtMat[2].y = zaxis.y;
    lookAtMat[2].z = zaxis.z;
    lookAtMat[2].w = -zaxis.dot(eye);

    lookAtMat[3].x = 0;
    lookAtMat[3].y = 0;
    lookAtMat[3].z = 0;
    lookAtMat[3].w = 1;

    * this = lookAtMat;
}

//this makes the matrix rotate to look at the passed in vector
void Matrix4::LookAt(const Vector3 & target)
{
    Vector3 at = target;
    Vector3 eye = *this * Vector3();
    Vector3 up = Vector3().Forward();

    Vector3 zaxis = (at - eye).normalised();
    Vector3 xaxis = (up.cross(zaxis)).normalised();
    Vector3 yaxis = zaxis.cross(xaxis);

    Matrix4 lookAtMat;

    lookAtMat[0].x = xaxis.x;
    lookAtMat[0].y = xaxis.y;
    lookAtMat[0].z = xaxis.z;
    lookAtMat[0].w = -xaxis.dot(eye);

    lookAtMat[1].x = yaxis.x;
    lookAtMat[1].y = yaxis.y;
    lookAtMat[1].z = yaxis.z;
    lookAtMat[1].w = -yaxis.dot(eye);

    lookAtMat[2].x = zaxis.x;
    lookAtMat[2].y = zaxis.y;
    lookAtMat[2].z = zaxis.z;
    lookAtMat[2].w = -zaxis.dot(eye);

    lookAtMat[3].x = 0;
    lookAtMat[3].y = 0;
    lookAtMat[3].z = 0;
    lookAtMat[3].w = 1;

    *this = lookAtMat;
}

//multiplyes two matrix together and returns the resault in a new matrix
Matrix4 Matrix4::operator * (const Matrix4 & refA) const
{
    Matrix4 m;

    int inner = 4;

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
void Matrix4::operator *= (const Matrix4 & refA)
{
    Matrix4 m;

    int inner = 4;

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
Vector4 Matrix4::operator * (const Vector4 & refA) const
{
    Vector4 v;

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

Vector3 Matrix4::operator * (const Vector3 & refA) const
{
    Vector4 newVec = Vector4(refA.x, refA.y, refA.z, (realNum)1.0f);

    Vector3 holder = (Vector3)(*this * newVec);

    return holder;
}

//assigns left hand matrix to be equal to right hand matric
void Matrix4::operator = (const Matrix4 & refA)
{
    Matrix4 m;

    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            this->vec[y][x] = refA.vec[y][x];
        }
    }
}

//checks if the two matrixs are equall or not
bool Matrix4::operator == (const Matrix4 & refA)
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
bool Matrix4::operator != (const Matrix4 & refA)
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
Vector4 & Matrix4::operator [] (int index)
{
    switch (index)
    {

    case 0:
        return vec[0];
    case 1:
        return vec[1];
    case 2:
        return vec[2];
    case 3:
        return vec[3];

    default: throw;
    }
}

//adds two matrix together and returns the resault in a new matrix
Matrix4 Matrix4::operator + (const Matrix4 & refA) const
{
    Matrix4 m;

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
void Matrix4::operator += (const Matrix4 & refA)
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
Matrix4 Matrix4::operator - (const Matrix4 & refA) const
{
    Matrix4 m;

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
void Matrix4::operator -= (const Matrix4 & refA)
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
//////////////////////////////
////REWORK THIS SHIT!!!///////
//////////////////////////////
Matrix4 Matrix4::Inverse() 
{
    Matrix4 m4a;

    realNum determinant = Determinant();

    realNum a = Matrix3(vec[1].y, vec[1].z, vec[1].w, vec[2].y, vec[2].z, vec[2].w, vec[3].y, vec[3].z, vec[3].w).Determinant();
    realNum b = Matrix3(vec[1].x, vec[1].z, vec[1].w, vec[2].x, vec[2].z, vec[2].w, vec[3].x, vec[3].z, vec[3].w).Determinant();
    realNum c = Matrix3(vec[1].x, vec[1].y, vec[1].w, vec[2].x, vec[2].y, vec[2].w, vec[3].x, vec[3].y, vec[3].w).Determinant();
    realNum d = Matrix3(vec[1].x, vec[1].y, vec[1].z, vec[2].x, vec[2].y, vec[2].z, vec[3].x, vec[3].y, vec[3].z).Determinant();

    realNum e = Matrix3(vec[0].y, vec[0].z, vec[0].w, vec[2].y, vec[2].z, vec[2].w, vec[3].y, vec[3].z, vec[3].w).Determinant();
    realNum f = Matrix3(vec[0].x, vec[0].z, vec[0].w, vec[2].x, vec[2].z, vec[2].w, vec[3].x, vec[3].z, vec[3].w).Determinant();
    realNum g = Matrix3(vec[0].x, vec[0].y, vec[0].w, vec[2].x, vec[2].y, vec[2].w, vec[3].x, vec[3].y, vec[3].w).Determinant();
    realNum h = Matrix3(vec[0].x, vec[0].y, vec[0].z, vec[2].x, vec[2].y, vec[2].z, vec[3].x, vec[3].y, vec[3].z).Determinant();

    realNum i = Matrix3(vec[0].y, vec[0].z, vec[0].w, vec[1].y, vec[1].z, vec[1].w, vec[3].y, vec[3].z, vec[3].w).Determinant();
    realNum j = Matrix3(vec[0].x, vec[0].z, vec[0].w, vec[1].x, vec[1].z, vec[1].w, vec[3].x, vec[3].z, vec[3].w).Determinant();
    realNum k = Matrix3(vec[0].x, vec[0].y, vec[0].w, vec[1].x, vec[1].y, vec[1].w, vec[3].x, vec[3].y, vec[3].w).Determinant();
    realNum l = Matrix3(vec[0].x, vec[0].y, vec[0].z, vec[1].x, vec[1].y, vec[1].z, vec[3].x, vec[3].y, vec[3].z).Determinant();

    realNum m = Matrix3(vec[0].y, vec[0].z, vec[0].w, vec[1].y, vec[1].z, vec[1].w, vec[2].y, vec[2].z, vec[2].w).Determinant();
    realNum n = Matrix3(vec[0].x, vec[0].z, vec[0].w, vec[1].x, vec[1].z, vec[1].w, vec[2].x, vec[2].z, vec[2].w).Determinant();
    realNum o = Matrix3(vec[0].x, vec[0].y, vec[0].w, vec[1].x, vec[1].y, vec[1].w, vec[2].x, vec[2].y, vec[2].w).Determinant();
    realNum p = Matrix3(vec[0].x, vec[0].y, vec[0].z, vec[1].x, vec[1].y, vec[1].z, vec[2].x, vec[2].y, vec[2].z).Determinant();

    b *= -1;
    d *= -1;

    e *= -1;
    g *= -1;

    j *= -1;
    l *= -1;

    m *= -1;
    o *= -1;

    m4a = Matrix4(a,e,i,m,b,f,j,n,c,g,k,o,d,h,l,p);

    for (int y = 0; y < ROW_SIZE; y++)
    {
        for (int x = 0; x < COLUM_SIZE; x++)
        {
            m4a[y][x] *= 1/determinant;
        }
    }

    return m4a;
}

//finds us the determinant of the matrix
realNum Matrix4::Determinant()
{
    realNum e = vec[1].x;
    realNum f = vec[1].y;
    realNum g = vec[1].z;
    realNum h = vec[1].w;

    realNum i = vec[2].x;
    realNum j = vec[2].y;
    realNum k = vec[2].z;
    realNum l = vec[2].w;

    realNum m = vec[3].x;
    realNum n = vec[3].y;
    realNum o = vec[3].z;
    realNum p = vec[3].w;

    realNum det1 = vec[0].x * (Matrix3(f, g, h, j, k, l, n, o, p).Determinant());
    realNum det2 = vec[0].y * (Matrix3(e, g, h, i, k, l, m, o, p).Determinant());
    realNum det3 = vec[0].z * (Matrix3(e, f, h, i, j, l, m, n, p).Determinant());
    realNum det4 = vec[0].w * (Matrix3(e, f, g, i, j, k, m, n, o).Determinant());
    return (det1 - det2 + det3 - det4);
}

//sets the matrix to be an Identity
Matrix4 Matrix4::SetIdentity()
{
    Matrix4 m;

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