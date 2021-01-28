//
//  Plane.hpp
//  
//
//  Created by HINGLI on 10/1/20.
//

#include "SceneObject.h"
class Plane: public SceneObject {
    public:
        Plane(glm::vec3 p, glm::vec3 n, ofColor diffuse, float w, float h,ofImage* floorPlaneTexter = nullptr, bool isReflectable = false);
        Plane();
        ~Plane();
        bool intersect(const Ray &ray, glm::vec3 & point, glm::vec3 & normal);
        void draw();
        float sdf(const glm::vec3 & p);
        glm::vec3 getNormal(const glm::vec3 &p);
        bool isFloorPlane();
        glm::vec2 getTexterPixel(glm::vec3 point);
        ofImage* getFloorPlaneTexter();
    private:
        ofPlanePrimitive plane;
        ofImage * _floor_plane_texter;
        float width = 20;
        float height = 20;
    protected:
        glm::vec3 normal = glm::vec3(0, 1, 0);
};
