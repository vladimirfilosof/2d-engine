#include "RenderSystem.h"
#include "iostream"

SDL_Renderer* RenderSystem::renderer = nullptr;

RenderSystem::RenderSystem()
{
	window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, SDL_WINDOW_SHOWN);
	if (window == NULL) throw std::runtime_error("[RenderSystem] <RenderSystem>: window creating error");
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) throw std::runtime_error("[RenderSystem] <RenderSystem>: renderer creating error");
}
RenderSystem::~RenderSystem()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void RenderSystem::update()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: RenderSystem begin" << std::endl;
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
#endif
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
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
	SDL_RenderPresent(renderer);
	#ifdef DEBUG
	std::chrono::system_clock::time_point e = std::chrono::system_clock::now();
	std::cout << "Render system duration: " << ((std::chrono::duration<double>)(e - b)).count() << std::endl;
	std::cout << "[DEBUG]: RenderSystem end" << std::endl;
#endif

}
