#include "fps.h"
#include "ECS/Systems/RenderSystem.h"
#include <iostream>

fps::fps(const char* font_path, int font_size)
{
	SDL_Color c = {225,255,255};
	this->font_size = font_size;
	this->color = c;
	font = TTF_OpenFont(font_path, font_size);
	
	if (font == nullptr)
	{
		std::cout << "font" << TTF_GetError();
		exit(1);
	}
}

fps::~fps()
{

}

void fps::print_fps()
{
	SDL_Surface *surf = TTF_RenderUTF8_Blended(font, std::to_string((int)(1/DeltaTime::delta)).c_str(), color);
	if (surf == nullptr)
	{
		std::cout << "surf";
		exit(1);
	}
	SDL_Texture *out = SDL_CreateTextureFromSurface(RenderSystem::renderer, surf);

	SDL_Rect r;
	r.h = 0;
	r.w = 0;
	r.x = 0;
	r.y = 0;
	SDL_QueryTexture(out, nullptr, nullptr, &r.w, &r.h);
	SDL_RenderCopy(RenderSystem::renderer, out, nullptr, &r);
}
