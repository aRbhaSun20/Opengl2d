#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class MvpHandle
{
private:
    /* data */
    glm::mat4 projection, view, model;

public:
    // model,view,projection mvp matrix
    void MvpHandleProjection(float left, float right, float bottom, float top, float zNear, float zFar);
    void MvpHandleView(float, glm::vec3);
    void MvpHandleModel(float, glm::vec3);
    void MvpHandleCamera(glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp);
    glm::mat4 mvp();
};