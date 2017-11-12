/**
 * @author Nathan Urbain
 * @date 08/11
 * @file Matrix33d function implement
 */

#include "matrix33d.h"

// ---------------------------------------------------------------------
// All explications for functions are in the file matrix33d.h
// Matrix33d's test are in the file testMatrix.cpp
// ---------------------------------------------------------------------


Matrix33d::Matrix33d(){
    for(int i=0; i<DIM;i++){
        this->Tab[i] = Array<double,3>();
    }
}


Array<double,DIM> Matrix33d::operator[](const int index) const{
    return this->Tab[index];
}

Array<double,DIM>& Matrix33d::operator[](const int index){
    return this->Tab[index];
}

Matrix33d& Matrix33d::operator=(const Matrix33d& m){
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            (*this)[i][j] = m[i][j];
        }
    }
    return *this;
}

Matrix33d Matrix33d::identity(){
    Matrix33d newMatrix = Matrix33d();
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM;j++){
            if(i==j){
                newMatrix[i][j]= 1;
            }
        }
    }
    return newMatrix;
}


Vec3d Matrix33d::operator*(const Vec3d& v){
    Vec3d newVec;
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            newVec[i]+=(*this)[i][j] * v[j];
        }
    }
    return newVec;
}


Matrix33d Matrix33d::inverse(){
    Matrix33d matrix;
    double det;
    det = (*this)[0][0]*(*this)[1][1]*(*this)[2][2]+
          (*this)[0][1]*(*this)[1][2]*(*this)[2][0]+
          (*this)[0][2]*(*this)[1][0]*(*this)[2][1]-
          (*this)[0][2]*(*this)[1][1]*(*this)[2][0]-
          (*this)[0][0]*(*this)[1][2]*(*this)[2][1]-
          (*this)[0][1]*(*this)[1][0]*(*this)[2][2];
    if(det == 0){
        return matrix;
    }


    matrix[0][0] = ((*this)[1][1]*(*this)[2][2] - (*this)[1][2]*(*this)[2][1]) / det;
    matrix[1][0] = -((*this)[1][0]*(*this)[2][2] - (*this)[2][0]*(*this)[1][2]) / det;
    matrix[2][0] = ((*this)[1][0]*(*this)[2][1] - (*this)[2][0]*(*this)[1][1]) / det;

    matrix[0][1] = -((*this)[0][1]*(*this)[2][2] - (*this)[2][1]*(*this)[0][2]) / det;
    matrix[1][1] = ((*this)[0][0]*(*this)[2][2] - (*this)[2][0]*(*this)[0][2]) / det;
    matrix[2][1] = -((*this)[0][0]*(*this)[2][1] - (*this)[2][0]*(*this)[0][1]) / det;

    matrix[0][2] = ((*this)[0][1]*(*this)[1][2] - (*this)[1][1]*(*this)[0][2]) / det;
    matrix[1][2] = -((*this)[0][0]*(*this)[1][2] - (*this)[1][0]*(*this)[0][2]) / det;
    matrix[2][2] = ((*this)[0][0]*(*this)[1][1] - (*this)[1][0]*(*this)[0][1]) / det;

    return matrix;
}


Matrix33d Matrix33d::translation(const double dx,const double dy){
    Matrix33d newMatrix = Matrix33d::identity();
    newMatrix[0][2]=dx;
    newMatrix[1][2]=dy;
    return newMatrix;
}

Matrix33d Matrix33d::rotation(const double angle){
    Matrix33d newMatrix = Matrix33d::identity();
    newMatrix[0][0] = cos(angle);
    newMatrix[1][1] = cos(angle);

    newMatrix[0][1] = -sin(angle);
    newMatrix[1][0] = sin(angle);

    return newMatrix;
}

Matrix33d Matrix33d::scale(const double sx,const double sy){
    Matrix33d newMatrix = Matrix33d::identity();

    newMatrix[0][0] = sx;
    newMatrix[1][1] = sy;

    return newMatrix;
}

Matrix33d Matrix33d::operator*(const Matrix33d& m){
    Matrix33d newMatrix;
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            for(int l=0;l<DIM;l++){
                newMatrix[i][j]+=(*this)[i][l] * m[l][j];
            }
        }
    }
    return newMatrix;
}


Matrix33d Matrix33d::setRotation(double angle){
    (*this) = Matrix33d::rotation(angle);
    return (*this);
}

Matrix33d Matrix33d::applyRotation(double angle){
    Matrix33d m;
    m.setRotation(angle);
    (*this) = m*(*this);
    return (*this);
}

Matrix33d Matrix33d::setScale(double sx, double sy){
    (*this) = Matrix33d::scale(sx,sy);
    return (*this);
}

Matrix33d Matrix33d::applyScale(double sx, double sy){
    Matrix33d m;
    m.setScale(sx,sy);
    (*this) = m*(*this);
    return (*this);
}

Vec3d Matrix33d::operator*(const Vec2d& v){
    Vec3d newVec = {v[0],v[1],1};
    newVec = (*this)*newVec;
    return newVec;
}

bool Matrix33d::operator==(const Matrix33d& m){
    for(int i=0;i<DIM;i++){
        if((*this)[i]!=m[i])
            return false;
    }
    return true;
}
