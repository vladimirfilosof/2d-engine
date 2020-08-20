#ifndef COLORCOMPONENT_H
#define COLORCOMPONENT_H

#include "../ECS.h"
#include <SDL2/SDL_render.h>

class ColorComponent : public Component
{
private:
	SDL_Color color;
public:
	ColorComponent(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a);
	~ColorComponent();

	Uint8& r(){return color.r;}
	Uint8& g(){return color.g;}
	Uint8& b(){return color.b;}
	Uint8& a(){return color.a;}

	void rgba(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a);

	void init();
};

#endif
