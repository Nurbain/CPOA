/**
 * @author Nathan Urbain
 * @date 08/11
 * @file Matrix33d function header
 */

#ifndef __MATRIX33D_H__
#define __MATRIX33D_H__

#include "vector.h"
#include <iostream>
#include "array.h"
#include "math.h"

//Matrix dimension is 3 here
const int DIM = 3;

/**
 * @class Matrix33d
 * @brief Classe who define Matrix 3x3 double
 * @property {Array<double,3>}  tab , size of 3 of Array<double,3>
 */
class Matrix33d{
protected:
    Array<double,DIM> Tab[DIM];
public:

    /**
     * @brief Empty Constructor
     */
    Matrix33d();

    /**
     * @brief Constructor by list
     * @param list, list of valor
     */
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

    /**
     * @brief operator =, affectation
     * @param m, matrix to affecte
     * @return Matrix33d
     */
    Matrix33d& operator=(const Matrix33d& m);

    /**
     * @brief operator [], accessor operator to get
     * @param index, index to get
     * @return Array<double,DIM>
     */
    Array<double,DIM> operator[](const int index) const;

    /**
     * @brief operator [], accessor operator to set
     * @param index, index to set
     * @return Array<double,DIM>
     */
    Array<double,DIM>& operator[](const int index);

    /**
     * @brief compute the inverse of the matrix
     * @return new Inverse Matrix33d
     */
    Matrix33d inverse();

    /**
     * @brief identity, create a identity matrix
     * @return Matrix33d
     */
    static Matrix33d identity();

    /**
     * @brief translation, create a translation matrix
     * @param dx, coord. x
     * @param dy, coord. y
     * @return Matrix33d
     */
    static Matrix33d translation(const double dx,const double dy);

    /**
     * @brief rotation, create a rotation matrix
     * @param angle, in radian
     * @return Matrix33d
     */
    static Matrix33d rotation(const double angle);

    /**
     * @brief scale, create a scaling matrix
     * @param sx, x factor
     * @param sy, y factor
     * @return Matrix33d
     */
    static Matrix33d scale(const double sx,const double sy);

    /**
     * @brief operator *, composition of matrix
     * @param m
     * @return Matrix33d
     */
    Matrix33d operator*(const Matrix33d& m);

    /**
     * @brief operator *, multiplication by a Vec3d
     * @param v, Vec3d
     * @return Vec3d
     */
    Vec3d operator*(const Vec3d& v);

    /**
     * @brief operator *, apply transformation to a Vec2d
     * @param v, Vec2d
     * @return Vec3d, with 1 in the third coord.
     */
    Vec3d operator*(const Vec2d& v);

    /**
     * @brief operator ==, verifie if 2 matrix is equal
     * @param m, matrix to compare
     * @return true if equal
     */
    bool operator==(const Matrix33d& m);

    /**
     * @brief setRotation, transform the current matrix in a rotation one
     * @param angle, rotation angle
     * @return this
     */
    Matrix33d setRotation(double angle);

    /**
     * @brief applyRotation, compute a rotation with the current matrix
     * @param angle, rotation angle
     * @return
     */
    Matrix33d applyRotation(double angle);

    /**
     * @brief setScale, transform the current matrix in a scaling one
     * @param sx, x factor
     * @param sy, y factor
     * @return this
     */
    Matrix33d setScale(double sx, double sy);

    /**
     * @brief applyScale compute a scale with the current matrix
     * @param sx, x factor
     * @param sy, y factor
     * @return
     */
    Matrix33d applyScale(double sx, double sy);

    /**
     * @brief operator <<, display operator
     * @param os stream to return
     * @param m
     * @return stream with all data from matrix
     */
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
