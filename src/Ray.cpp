//
//  Ray.cpp
//  
//
//  Created by HINGLI on 10/1/20.
//

#include "Ray.h"
Ray::Ray(glm::vec3 point, glm::vec3 direction)
{
    this->_point = point;
    this->_direction = direction;
}
void Ray::draw(float t)
{
    ofDrawLine(this->_point, this->_point + this->_direction * t);
}
glm::vec3 Ray::evalPoint(float t)
{
    return this->_point+this->_direction*t;
}
glm::vec3 Ray::getPoint() const
{
    return this->_point;
}
glm::vec3 Ray::getDirecton() const
{
    return this->_direction;
}

