#include "BoxComponent.h"

BoxComponent::BoxComponent(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}
BoxComponent::BoxComponent(SDL_Renderer* renderer, int w, int h, int x, int y) : BoxComponent::BoxComponent(renderer)
{
	rect.w = w;
	rect.h = h;
	rect.x = x;
	rect.y = y;
}
BoxComponent::~BoxComponent()
{
}

void BoxComponent::init()
{
}

void BoxComponent::draw()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderDrawRect(renderer, &rect);
}

void BoxComponent::update()
{
}
