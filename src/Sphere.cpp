//
//  Sphere.cpp
//  
//
//  Created by HINGLI on 10/1/20.
//

#include "Sphere.h"
Sphere::Sphere(glm::vec3 p, float r, ofColor diffuse,bool isReflectable)
{
    _position = p;
    _diffuseColor = diffuse;
    this->_radius = r;
    _specularColor = ofColor::white;
    _is_reflectable = isReflectable;
}
void Sphere::draw()
{
    ofSetColor(this->_diffuseColor);
    ofDrawSphere(_position, this->_radius);
    ofSetColor(ofColor::white);
    
}
Sphere::~Sphere()
{}
bool Sphere::intersect(const Ray &ray, glm::vec3 &point, glm::vec3 &normal)
{
    return glm::intersectRaySphere(ray.getPoint(), ray.getDirecton(), _position, this->_radius, point, normal);
}
float Sphere::getRadius()
{
    return this->_radius;
}
