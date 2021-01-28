//
//  SceneObject.cpp
//  
//
//  Created by HINGLI on 10/1/20.
//

#include "SceneObject.h"
SceneObject::SceneObject()
{
    this->_position = glm::vec3(0, 0, 0);
    this->_diffuseColor = ofColor::grey;
    this->_specularColor = ofColor::lightGray;
    this->_is_reflectable = false;
}
SceneObject::SceneObject(glm::vec3 pos,ofColor diffColor, ofColor speColor)
{
    this->_position = pos;
    this->_diffuseColor = diffColor;
    this->_specularColor = speColor;
    this->_is_reflectable = false;
}
bool SceneObject::intersect(const Ray &ray, glm::vec3 &point, glm::vec3 &normal)
{
    return false;
}
SceneObject::~SceneObject()
{
    
}
ofColor SceneObject::getDiffuseColor()
{
    return this->_diffuseColor;
}
glm::vec3 SceneObject::getPosition()
{
    return this->_position;
}
ofColor SceneObject::getSpecularColor()
{
    return this->_specularColor;
}
bool SceneObject::isFloorPlane()
{
    return false;
}
glm::vec2 SceneObject::getTexterPixel(glm::vec3 point)
{
    return glm::vec2(point.x,point.z);
}
ofImage* SceneObject::getFloorPlaneTexter()
{
    return nullptr;
}
bool SceneObject::getReflectable()
{
    return this->_is_reflectable;
}
bool SceneObject::isMeshObj()
{
    return false; 
}
