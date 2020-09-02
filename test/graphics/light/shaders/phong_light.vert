#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 3) in vec4 color;

uniform mat4 modelMatrix;
uniform mat4 lightMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat3 normalMatrix;

uniform vec3 lightPos;

out vec4 fragColor;
out vec3 fragPosition;
out vec3 fragNormal;

out vec3 lightPosition;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);

    lightPosition = vec3(viewMatrix * lightMatrix * vec4(lightPos, 1.0));

    fragPosition = vec3(viewMatrix * modelMatrix * vec4(position, 1.0));
    fragNormal = normalize(normalMatrix * normal);
    fragColor = color / 256.0;
}