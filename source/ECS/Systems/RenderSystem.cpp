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
		if (item->has_component<TransformComponent>())
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			if (item->has_component<ColorComponent>())
			{
				ColorComponent& color = item->get_component<ColorComponent>();
				SDL_SetRenderDrawColor(renderer, color.r(),color.g(), color.b(), color.a());
			}
			rect.w = item->get_component<TransformComponent>().size().w();
			rect.h = item->get_component<TransformComponent>().size().h();
			rect.x = item->get_component<TransformComponent>().coords().x();
			rect.y = item->get_component<TransformComponent>().coords().y();
			SDL_RenderDrawRect(renderer, &rect);
		}
	}
}
