#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
private:
    /* data */
    glm::vec3 cameraPos(0.0f, 0.0f, 0.3f);
    glm::vec3 cameraFront(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);
    float speed = 10.0f;
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
// 
public:
    Camera(/* args */);
    ~Camera();
};


