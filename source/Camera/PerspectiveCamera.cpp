#include "PerspectiveCamera.h"

void PerspectiveCamera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == Camera_Movement::FORWARD)
        Position += Front * velocity;
    if (direction == Camera_Movement::BACKWARD)
        Position -= Front * velocity;
    if (direction == Camera_Movement::LEFT)
        Position -= Right * velocity;
    if (direction == Camera_Movement::RIGHT)
        Position += Right * velocity;
    if (direction == Camera_Movement::UP)
        Position += Up * velocity;
    if (direction == Camera_Movement::DOWN)
        Position -= Up * velocity;
}

// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void PerspectiveCamera::ProcessMouseScroll(float yoffset)
{
    if (Zoom >= FOVMIN && Zoom <= FOVMAX)
        Zoom -= yoffset;
    if (Zoom <= FOVMIN)
        Zoom = FOVMIN;
    if (Zoom >= FOVMAX)
        Zoom = FOVMAX;
}

void PerspectiveCamera::updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // Also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front, WorldUp)); // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up = glm::normalize(glm::cross(Right, Front));
}