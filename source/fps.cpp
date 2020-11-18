#include "fps.h"
#include "ECS/Systems/RenderSystem.h"
#include <iostream>

fps::fps(const char* font_path, int font_size)
{
	TTF_Init();
	SDL_Color c = {225,255,255};
	this->font_size = font_size;
	this->color = c;
	font = TTF_OpenFont(font_path, font_size);
	
	if (font == nullptr)
	{
		throw std::runtime_error(TTF_GetError()); 
	}
}

fps::~fps()
{
	TTF_CloseFont(font);
}

void fps::print_fps()
{
	SDL_Surface *surf = TTF_RenderUTF8_Blended(font, std::to_string((int)(1/DBHelper::delta)).c_str(), color);
	if (surf == NULL)
	{
		throw std::runtime_error("Surf wasn't created");
	}
	SDL_Texture *out = SDL_CreateTextureFromSurface(RenderSystem::renderer, surf);
	SDL_Rect r;
	r.h = surf->h;
	r.w = surf->w;
	r.x = 0;
	r.y = 0;
	SDL_RenderCopy(RenderSystem::renderer, out, nullptr, &r);
	SDL_DestroyTexture(out);
	SDL_FreeSurface(surf);
}
