#include "RenderSystem.h"

RenderSystem::RenderSystem(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}
RenderSystem::~RenderSystem()
{
}

void RenderSystem::update()
{
	SDL_Rect rect;
	for (auto& item : entities)
	{
		if (item->has_component<TransformComponent>())
		{
			rect = item->get_component<TransformComponent>().get_rect();

			if (item->has_component<SpriteComponent>())
			{
				SpriteComponent& sprite = item->get_component<SpriteComponent>();
				sprite.update();
				SDL_Point center;
				center.x = rect.w / 2;
				center.y = rect.h / 2;
				SDL_RenderCopyEx(renderer, sprite.get_texture(), &sprite.get_rect(), &rect, sprite.angle() * 0.0176, &center, sprite.flip());
			}

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			if (item->has_component<ColorComponent>())
			{
				ColorComponent& color = item->get_component<ColorComponent>();
				SDL_SetRenderDrawColor(renderer, color.r(),color.g(), color.b(), color.a());
			}
			SDL_RenderDrawRect(renderer, &rect);
		}
	}
}
