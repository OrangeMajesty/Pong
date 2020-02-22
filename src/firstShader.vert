#version 330
layout(location = 0) in vec3 position;
uniform vec3 offsetPosition;

void main()
{
  gl_Position = vec4(position + offsetPosition, 1.0);
  //vColor = vec4(color, 1.0);
}
