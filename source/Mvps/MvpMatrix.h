#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

#include "ModelMatrix.h"
#include "ProjectionMatrix.h"
#include "../Camera/PerspectiveCamera.h"

class MvpMatrix
{
private:
    /* data */
    glm::mat4 m_Projection, m_View, m_Model;
    glm::mat4 u_MVP;

public:
    // model,view,projection mvp matrix
    MvpMatrix(ProjectionMatrix &, PerspectiveCamera &, ModelMatrix &);

    void setMvpMatrix(ProjectionMatrix &, PerspectiveCamera &, ModelMatrix &);

    glm::mat4 getMvpMatrix() { return u_MVP; };
};