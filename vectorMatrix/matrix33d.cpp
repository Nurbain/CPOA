#include "matrix33d.h"

Matrix33d::Matrix33d(){
    for(int i=0; i<DIM;i++){
        this->Tab[i] = Array<double,3>();
    }
}


Array<double,DIM> Matrix33d::operator[](const int index) const{
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
    Matrix33d matrix = {1,0,0,0,1,0,0,0,1};
    return matrix;
}

/*
Matrix33d Matrix33d::identity(){
    Matrix33d newMatrix = Matrix33d();
    newMatrix[2][2]= 1;
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM;j++){
            if(i==j){
                newMatrix[i][j]= 1;
            }
        }
    }
    return newMatrix;
}
*/

Matrix33d Matrix33d::inverse(){
    Matrix33d matrix;
    double det;
    std::cout << "Actuel \n" << (*this) << std::endl;
    det = (*this)[0][0]*(*this)[1][1]*(*this)[2][2]+
          (*this)[0][1]*(*this)[1][2]*(*this)[2][0]+
          (*this)[0][2]*(*this)[1][0]*(*this)[2][1]-
          (*this)[0][2]*(*this)[1][1]*(*this)[2][0]-
          (*this)[0][0]*(*this)[1][2]*(*this)[2][1]-
          (*this)[0][1]*(*this)[1][0]*(*this)[2][2];
    std::cout << det << std::endl;
    if(det == 0){
         std::cout << "ICI" << std::endl;
        return matrix;
    }


    matrix[0][0] = ((*this)[1][1]*(*this)[2][2] - (*this)[1][2]*(*this)[2][1]) / det;
    matrix[1][0] = ((*this)[1][0]*(*this)[2][2] - (*this)[2][0]*(*this)[1][2]) / det;
    matrix[2][0] = ((*this)[1][0]*(*this)[2][1] - (*this)[2][0]*(*this)[1][1]) / det;

    matrix[0][1] = ((*this)[0][1]*(*this)[2][2] - (*this)[2][1]*(*this)[0][2]) / det;
    matrix[1][1] = ((*this)[0][0]*(*this)[2][2] - (*this)[2][0]*(*this)[0][2]) / det;
    matrix[2][1] = ((*this)[0][0]*(*this)[2][1] - (*this)[2][0]*(*this)[0][1]) / det;

    matrix[0][2] = ((*this)[0][1]*(*this)[1][2] - (*this)[1][1]*(*this)[0][2]) / det;
    matrix[1][2] = ((*this)[0][0]*(*this)[1][2] - (*this)[1][0]*(*this)[0][2]) / det;
    matrix[2][2] = ((*this)[0][0]*(*this)[1][1] - (*this)[1][0]*(*this)[0][1]) / det;


    return matrix;
}



