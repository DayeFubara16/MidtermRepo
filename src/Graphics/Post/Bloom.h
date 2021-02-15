#ifndef __BLOOMBUFFER_H__
#define __BLOOMBUFFER_H__

#include "PostEffect.h"

class BloomEffect : public PostEffect
{
public:
	//Initializes the framebuffer with extra steps
	//*Sets size
	//*Initializes the framebuffer afterwards
	void Init(unsigned width, unsigned height) override;

	//Applies the affect to this screen
	//*Passes the framebuffer with the texture to apply as a parameter
	void ApplyEffect(PostEffect* buffer) override;

	//Reshapes the buffers
	void Reshape(unsigned width, unsigned height) override;

	//Getters
	float GetDownscale() const;
	float GetThreshold() const;
	unsigned GetPasses() const;

	//Setters
	void SetDownscale(float downscale);
	void SetThreshold(float threshold);
	void SetPasses(unsigned passes);

private:
	float _downscale = 2.f;
	float _threshold = 0.01f;
	unsigned _passes = 10;
	glm::vec2 _pixelSize;
};

#endif // !__BLOOMBUFFER_H__