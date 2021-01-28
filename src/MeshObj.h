//
//  MeshObj.hpp
//  
//
//  Created by HINGLI on 12/24/20.
//

#pragma once
#include "SceneObject.h"
#include "ofxAssimpModelLoader.h"

class MeshObj : public SceneObject
{
    public:
    MeshObj(glm::vec3 pos,ofxAssimpModelLoader * mesh_obj, ofColor diffColor, ofColor speColor);
        bool intersect(const Ray &ray, glm::vec3 &point, glm::vec3 &normal);
        void draw();
        bool isMeshObj();
        void setRotationXAxis(float angle);
        void setRotationYAxis(float angle);
        void setRotationZAxis(float angle);
    private:
        ofxAssimpModelLoader * _mesh_obj = nullptr;
        
};

