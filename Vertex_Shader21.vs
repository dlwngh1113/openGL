#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 textureUV;
layout (location = 2) in vec3 aNormal;

out vec3 FragPos;
out vec2 UV;
out vec3 Normal;

uniform mat4 modelTransform;
uniform mat4 projTransform;

void main()
{
	gl_Position = projTransform * modelTransform * vec4(vPos, 1.0);
	FragPos = vec3(modelTransform * vec4(vPos, 1.0));
	UV = textureUV;
	Normal = mat3(transpose(inverse(modelTransform))) * aNormal;
}