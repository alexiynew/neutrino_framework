#version 330 core

in vec3 fragPosition;
in vec3 fragNormal;

in vec3 lightPosition;

out vec4 color;

vec3 lightColor = vec3(1.0, 1.0, 1.0);

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

struct Light {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light; 
  
uniform Material material;

void main()
{
    vec3 ambient = material.ambient * light.ambient;

    vec3 lightDir = normalize(lightPosition - fragPosition);
    float diff = max(dot(fragNormal, lightDir), 0.0);
    vec3 diffuse = material.diffuse * light.diffuse * diff;

    vec3 viewDir = normalize(-fragPosition);
    vec3 reflectDir = reflect(-lightDir, fragNormal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = material.specular * light.specular * spec;

    color = vec4(ambient + diffuse + specular, 1.0);
}
