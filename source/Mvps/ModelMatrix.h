#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ModelMatrix
{
private:
    glm::vec3 m_Translation;
    glm::vec3 m_RotationAxis;
    float m_RotationAngle = 0.0f;
    glm::mat4 m_Model = glm::mat4(1.0f);

public:
    ModelMatrix(glm::vec3 Translation, float Angle, glm::vec3 Axis)
        : m_Translation(Translation), m_RotationAxis(Axis), m_RotationAngle(Angle)
    {
        m_Model = glm::translate(glm::mat4(1.0f), m_Translation) *
                  glm::rotate(glm::mat4(1.0f), glm::radians(m_RotationAngle), m_RotationAxis);
    };

    void setModelMatrix(glm::vec3 Translation, float Angle, glm::vec3 Axis)
    {
        m_Translation = Translation;
        m_RotationAngle = Angle;
        m_RotationAxis = Axis;
        m_Model = glm::translate(glm::mat4(1.0f), m_Translation) *
                  glm::rotate(glm::mat4(1.0f), glm::radians(m_RotationAngle), m_RotationAxis);
    }

    glm::mat4 getModelMatrix() { return m_Model; };

};
