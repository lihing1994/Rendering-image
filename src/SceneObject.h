//
//  SceneObject.hpp
//  
//
//  Created by HINGLI on 10/1/20.
//
#pragma once
#include "Ray.h"
class SceneObject {
    public:
        SceneObject();
        SceneObject(glm::vec3 pos,ofColor diffColor, ofColor speColor);
        virtual void draw() = 0;
        virtual ~SceneObject();
        virtual bool intersect(const Ray &ray, glm::vec3 &point, glm::vec3 &normal);
        virtual bool isFloorPlane();
        virtual bool isMeshObj();
        virtual glm::vec2 getTexterPixel(glm::vec3 point);
        virtual ofImage* getFloorPlaneTexter();
        virtual glm::vec3 getPosition();
        ofColor getDiffuseColor();
        ofColor getSpecularColor();
        bool getReflectable();
    protected:
        glm::vec3 _position;
        ofColor _diffuseColor;
        ofColor _specularColor;
        bool _is_reflectable;
};

