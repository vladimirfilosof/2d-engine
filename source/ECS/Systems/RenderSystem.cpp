#include "RenderSystem.h"

#ifdef DEBUG
	#include <iostream>
#endif

SDL_Renderer* RenderSystem::renderer = nullptr;

RenderSystem::RenderSystem(const char* window_title, const int& position_x, const int& position_y, const int& width, const int& height, const Uint32& window_flags, const Uint32& renderer_flags)
{
	window = SDL_CreateWindow(window_title, position_x, position_y, width, height, window_flags);
	if (window == NULL) throw std::runtime_error("[RenderSystem] <RenderSystem>: window creating error");
	renderer = SDL_CreateRenderer(window, -1, renderer_flags);
	if (renderer == NULL) throw std::runtime_error("[RenderSystem] <RenderSystem>: renderer creating error");
	
	FPS_Status = false;
	f = nullptr;
}

RenderSystem::~RenderSystem()
{
#ifdef DEBUG
	std::cout << "[Debug]: RenderSystem destructor calling" << std::endl;
#endif
	if (f) delete f;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void RenderSystem::update()
{
	std::vector<Entity*>& entities = manager->get_entities();
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	SDL_Rect rect;
	for (auto& item : entities)
	{
		if (!item->isActive) continue;
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
				SDL_RenderCopyEx(renderer, sprite.get_texture(), &sprite.get_rect(), &rect, sprite.angle(), &center, sprite.flip());
			}

			if (item->has_component<BoxComponent>())
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				if (item->has_component<ColorComponent>())
				{
					ColorComponent& color = item->get_component<ColorComponent>();
					SDL_SetRenderDrawColor(renderer, color.r(), color.g(), color.b(), color.a());
				}
				SDL_RenderDrawRect(renderer, &rect);
			}
		}
	}

	if (FPS_Status) f->print_fps();
	SDL_RenderPresent(renderer);
}
