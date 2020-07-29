#version 330 core

in vec4 fragColor;
in vec3 fragPosition;
in vec3 fragNormal;

in vec3 lightPosition;

out vec4 color;

float ambientStrength = 0.2f;
vec3 lightColor = vec3(1.0, 1.0, 1.0);

float specularStrength = 0.05f;

void main()
{
    vec3 ambient = ambientStrength * lightColor;

    vec3 lightDir = normalize(lightPosition - fragPosition);
    float diff = max(dot(normalize(fragNormal), lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 viewDir = -fragPosition;
    vec3 reflectDir = reflect(-lightDir, fragNormal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 2);
    vec3 specular = specularStrength * spec * lightColor;

    color = vec4(ambient + diffuse + specular, 1.0) * fragColor;
}
