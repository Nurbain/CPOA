/**
 * @author Nathan Urbain
 * @date 08/11
 * @file Matrix33d function header
 */

#ifndef __MATRIX33D_H__
#define __MATRIX33D_H__

#include "vector.h"
#include "array.h"
#include "math.h"

const int DIM = 3;

class Matrix33d{
protected:
    Array<double,DIM> Tab[DIM];
public:
    Matrix33d();
    Matrix33d(std::initializer_list<double> list)
    {
        assert(list.size() == (DIM*DIM));
        int x = 0;
        for(int i=0; i<DIM; i++)
            for(int j=0; j<DIM; j++){
                this->Tab[i][j]= list.begin()[x];
                x++;
            }
    }
    Matrix33d& operator=(const Matrix33d& m);
    static Matrix33d identity();

    Array<double,DIM> operator[](const int index) const;
    Array<double,DIM>& operator[](const int index);

    Vec3d operator*(const Vec3d& v);
    Matrix33d inverse();

    static Matrix33d translation(const double dx,const double dy);
    static Matrix33d rotation(const double angle);
    static Matrix33d scale(const double sx,const double sy);




    inline friend std::ostream& operator<<(std::ostream& os, const Matrix33d& m){
       for(int i=0;i<3;i++){
           for(int j=0;j<3;j++){
            os << m[i][j] << " ";
           }
        os << " \n" ;
       }
       return os;
    }

};

#endif
