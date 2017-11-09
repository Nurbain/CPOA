#include "matrix33d.h"


Matrix33d::Matrix33d(){
    for(int i=0; i<3;i++){
        this->Tab[i] = Array<double,3>();
    }
}


Array<double,3> Matrix33d::get_line(const int index) const{
    return this->Tab[index];
}

Array<double,3> Matrix33d::operator[](const int index) const{
    return this->get_line(index);
}


