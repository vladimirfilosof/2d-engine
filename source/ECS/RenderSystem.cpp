#include "RenderSystem.h"

RenderSystem::RenderSystem(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}
RenderSystem::~RenderSystem()
{
}

void RenderSystem::init()
{
	entities = manager->get_entities();
}

void RenderSystem::update()
{
	SDL_Rect rect;
	for (auto& item : entities)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		rect.w = item->get_component<TransformComponent>().size().w();
		rect.h = item->get_component<TransformComponent>().size().h();
		rect.x = item->get_component<TransformComponent>().coords().x();
		rect.y = item->get_component<TransformComponent>().coords().y();
		SDL_RenderDrawRect(renderer, &rect);
	}
}
