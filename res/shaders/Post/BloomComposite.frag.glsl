#version 420

layout(binding = 0) uniform sampler2D uScene;
layout(binding = 1) uniform sampler2D uBloom;

layout(location = 0) in vec2 inUV;

out vec4 frag_color;

void main() 
{
	vec4 colorA = texture(uScene, inUV);
	vec4 colorB = texture(uBloom, inUV);

	frag_color = 1.0 - (1.0 - colorA) * (1.0 - colorB);
	//FragColor = colorB;
}