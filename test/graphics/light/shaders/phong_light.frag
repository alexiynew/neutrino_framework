#version 330 core

in vec4 fragColor;
in vec3 fragPosition;
in vec3 fragNormal;

in vec3 lightPosition;

out vec4 color;

vec3 lightColor = vec3(1.0, 1.0, 1.0);

float ambientStrength = 0.2f;
float diffuseStrength = 0.5f;
float specularStrength = 0.5f;

void main()
{
    vec3 ambient = ambientStrength * lightColor;

    vec3 lightDir = normalize(lightPosition - fragPosition);
    float diff = max(dot(fragNormal, lightDir), 0.0);
    vec3 diffuse = diffuseStrength * diff * lightColor;

    vec3 viewDir = normalize(-fragPosition);
    vec3 reflectDir = reflect(-lightDir, fragNormal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    color = vec4(ambient + diffuse + specular, 1.0) * fragColor;
}
