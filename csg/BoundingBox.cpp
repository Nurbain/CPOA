#include "BoundingBox.h"
#include "math.h"

// ---------------------------------------------------------------------
// All explications for functions are in the file BoundingBox.h
// ---------------------------------------------------------------------

BoundingBox::BoundingBox(){

}

Vec2d BoundingBox::getMin() const{
    return (*this).pointMin;
}

Vec2d BoundingBox::getMax() const{
    return (*this).pointMax;
}

void BoundingBox::setMin(Vec2d& point){
    (*this).pointMin = point;
}

void BoundingBox::setMax(Vec2d& point){
    (*this).pointMax = point;
}


BoundingBox BoundingBox::operator=(const BoundingBox& box){
    (*this).pointMin = box.pointMin;
    (*this).pointMax = box.pointMax;
    return *this;
}

BoundingBox BoundingBox::operator+(const BoundingBox& box){
    BoundingBox result;
    if((*this).pointMin[0]<=box.pointMin[0]){
        result.pointMin[0]=(*this).pointMin[0];}
    else
        result.pointMin[0]=box.pointMin[0];

    if((*this).pointMin[1]<=box.pointMin[1])
        result.pointMin[1]=(*this).pointMin[1];
    else
        result.pointMin[1]=box.pointMin[1];


    if((*this).pointMax[0]>=box.pointMax[0]){
        result.pointMax[0]=(*this).pointMax[0];}
    else
        result.pointMax[0]=box.pointMax[0];

    if((*this).pointMax[1]>=box.pointMax[1])
        result.pointMax[1]=(*this).pointMax[1];
    else
        result.pointMax[1]=box.pointMax[1];

    return result;
}

//difference
BoundingBox BoundingBox::operator-(const BoundingBox& box){
    return *this;
}

BoundingBox BoundingBox::operator^(const BoundingBox& box){
    BoundingBox result;

    result.pointMin[0] = std::max(std::min((*this).pointMin[0],(*this).pointMax[0]),std::min(box.pointMin[0],box.pointMax[0]));
    result.pointMin[1] = std::max(std::min((*this).pointMin[1],(*this).pointMax[1]),std::min(box.pointMin[1],box.pointMax[1]));
    result.pointMax[0] = std::min(std::max((*this).pointMin[1],(*this).pointMax[1]),std::max(box.pointMin[1],box.pointMax[1]));
    result.pointMax[1] = std::min(std::max((*this).pointMin[1],(*this).pointMax[1]),std::max(box.pointMin[1],box.pointMax[1]));

    if (result.pointMin[0] < result.pointMax[0] && result.pointMin[1] < result.pointMax[1])
        return result;
    else{
        BoundingBox null;
        return null;
    }

}


bool BoundingBox::isEmpty(){
    if(this->pointMax == this->pointMin)
        return true;
    else
        return false ;
}

Vec2d BoundingBox::center(){
    Vec2d center;
    center[0] = this->getMin()[0]+this->largeur/2;
    center[1] = this->getMin()[1]+this->hauteur/2;
    return center;
}

bool BoundingBox::isInBox(const Vec2d& point){
    if(point[0] <= this->pointMax[0] && point[0]>=this->pointMin[0]){
        if(point[1]<= this->pointMax[1]&& point[1]>=this->pointMin[1]){
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

BoundingBox BoundingBox::addPoint(const Vec2d& point){
    Vec2d newMinPoint = this->pointMin;
    Vec2d newMaxPoint = this->pointMax;

    if(point[0]>this->pointMax[0]){
        newMaxPoint[0]=point[0];
    }

    if(point[1]>this->pointMax[1]){
        newMaxPoint[1]=point[1];
    }

    if(point[0]<this->pointMin[0]){
        newMinPoint[0]=point[0];
    }

    if(point[1]<this->pointMin[1]){
        newMinPoint[1]=point[1];
    }

    BoundingBox newBoundingBox = BoundingBox(newMinPoint,newMaxPoint);

    return newBoundingBox;
}
