#version 420

layout(binding = 0) uniform sampler2D s_screenTex; //Source image
uniform float u_Threshold;

out vec4 frag_color;

layout(location = 0) in vec2 inUV;

void main() 
{
    vec4 colour = texture(s_screenTex, inUV);

    float luminance = (colour.r + colour.g + colour.b) / 3.0;

    if (luminance > u_Threshold) 
    {
        frag_color = colour;
    }
    else
    {
        frag_color = vec4(0.0, 0.0, 0.0, 1.0);
    }
}