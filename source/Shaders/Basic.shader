#shader vertex
#version 330 core

layout (location = 0) in vec4 aPos;

void main()
{
  gl_Position = aPos;
};

#shader fragment
#version 330 core
 
layout (location = 0) out vec4 FragColor;

void main()
{
     FragColor = vec4(1.0, 0.5, 0.2, 1.0);
};