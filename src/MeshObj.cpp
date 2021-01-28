//
//  MeshObj.cpp
//  
//
//  Created by HINGLI on 1/3/21.
//

#include "MeshObj.h"
#include <glm/gtx/euler_angles.hpp>
MeshObj::MeshObj(glm::vec3 pos,ofxAssimpModelLoader * mesh_obj, ofColor diffColor, ofColor speColor) : SceneObject(pos, diffColor, speColor)
{
    this->_mesh_obj = mesh_obj;
    _is_reflectable = false;
    if(this->_mesh_obj!=nullptr)
    {
        this->_mesh_obj->setPosition(_position.x, _position.y, _position.z);
    }
}
void MeshObj::draw()
{
    if(this->_mesh_obj != nullptr)
    {
        std::vector<ofMeshFace> mesh_list = this->_mesh_obj->getMesh(0).getUniqueFaces();
        //ofNoFill();
        glm::vec3 pos = this->_mesh_obj->getPosition();
        glm::mat4 m = glm::translate(glm::mat4(1.0f), pos);
        ofSetColor(getDiffuseColor());
        for(int i=0;i<mesh_list.size();i++)
        {
            
            glm::vec3 p1 = m * glm::vec4(mesh_list.at(i).getVertex(0),1.0f);
            glm::vec3 p2 = m * glm::vec4(mesh_list.at(i).getVertex(1),1.0f);
            glm::vec3 p3 = m * glm::vec4(mesh_list.at(i).getVertex(2),1.0f);
            ofDrawTriangle(p1, p2, p3);
        }
        ofSetColor(ofColor::white);
        //ofFill();
    }
}
bool MeshObj::isMeshObj()
{
    return true;
}
bool MeshObj::intersect(const Ray &ray, glm::vec3 &point, glm::vec3 &normal)
{
    if(this->_mesh_obj==nullptr) return false;
    else
    {
        bool is_intersect = false;
        glm::vec2 temp;
        glm::vec3 first_edge;
        glm::vec3 second_edge;
        glm::vec3 temp_normal;
        glm::vec3 the_shortest_normal;
        float temp_distance;
        float the_shortest_distance = std::numeric_limits<float>::infinity();
        std::vector<ofMeshFace> mesh_list = this->_mesh_obj->getMesh(0).getUniqueFaces();
        glm::vec3 pos = this->_mesh_obj->getPosition();
        glm::mat4 m = glm::translate(glm::mat4(1.0f), pos);
        for(int i =0;i<mesh_list.size();i++)
        {
            ofMeshFace temp_face = mesh_list.at(i);
            glm::vec3 p1 = m * glm::vec4(mesh_list.at(i).getVertex(0),1.0f);
            glm::vec3 p2 = m * glm::vec4(mesh_list.at(i).getVertex(1),1.0f);
            glm::vec3 p3 = m * glm::vec4(mesh_list.at(i).getVertex(2),1.0f);
            //Finding the face normal for a Trinagle Mesh.
            temp_normal = glm::normalize(glm::cross(p2-p1, p3-p1));
            if(glm::intersectRayTriangle(ray.getPoint(), ray.getDirecton(), p1, p2, p3, temp, temp_distance))
            {
                is_intersect = true;
                if(the_shortest_distance > temp_distance)
                {
                    the_shortest_distance = temp_distance;
                    the_shortest_normal = temp_normal;
                }
            }
        }
        normal = the_shortest_normal;
        point = ray.getPoint() + ray.getDirecton() * the_shortest_distance;
        return is_intersect;
    }
}
void MeshObj::setRotationXAxis(float angle)
{
    
}
void MeshObj::setRotationYAxis(float angle)
{
    
}
void MeshObj::setRotationZAxis(float angle)
{
    
}
