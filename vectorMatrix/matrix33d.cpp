#include "matrix33d.h"

Matrix33d::Matrix33d(){
    for(int i=0; i<DIM;i++){
        this->Tab[i] = Array<double,3>();
    }
}


Array<double,DIM> Matrix33d::operator[](const int index) const{
    return this->Tab[index];
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

void Matrix33d::inverse(){

}



