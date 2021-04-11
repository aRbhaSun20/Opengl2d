#include "MvpHandle.h"

void MvpHandle::MvpHandleProjection(float left, float right, float bottom, float top, float zNear, float zFar)
{
    MvpHandle::projection = glm::ortho(left, right, bottom, top, zNear, zFar);
}

void MvpHandle::MvpHandleView(float base, glm::vec3 transformation)
{
    MvpHandle::view = glm::translate(glm::mat4(base), transformation);
}

void MvpHandle::MvpHandleCamera(glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp)
{
    MvpHandle::view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void MvpHandle::MvpHandleModel(float base, glm::vec3 translation)
{
    MvpHandle::model = glm::translate(glm::mat4(base), translation);
}

glm::mat4 MvpHandle::mvp()
{
    return MvpHandle::projection * MvpHandle::view * MvpHandle::model;
}