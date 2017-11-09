/**
 * @author Nathan Urbain
 * @date 08/11
 * @file Matrix33d function header
 */

#ifndef __MATRIX33D_H__
#define __MATRIX33D_H__

#include "vector.h"
#include "../InterfaceCSG/Array.h"

class Matrix33d{
protected:
    Array<double,3> Tab[3];
public:
    Matrix33d();

    /*Matrix33d(std::initializer_list<double> list)
    {
        assert(list.size() == 9);
        int x = 0;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++){
                this->get_line(i)[j]=list.;
                x++;
            }
    }*/


    Array<double,3> get_line(const int index) const;
    Array<double,3> operator[](const int index) const;


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
