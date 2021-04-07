#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class MvpHandle
{
private:
    /* data */
    glm::mat4 projection, view, model;

public: 
// model,view,projection mvp matrix
    void MvpHandleProjection(float left, float right, float bottom, float top, float zNear, float zFar);
    void MvpHandleView(float,  glm::vec3);
    void MvpHandleModel(float,  glm::vec3);

    glm::mat4 mvp();
};
