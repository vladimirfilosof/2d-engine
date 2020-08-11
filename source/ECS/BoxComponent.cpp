#include "BoxComponent.h"

BoxComponent::BoxComponent(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

BoxComponent::~BoxComponent()
{
}

void BoxComponent::init()
{
	if (entity->has_component<TransformComponent>())
	{
		transform = &entity->get_component<TransformComponent>();
	}
	else
	{
		std::cerr << "[Engine] <BoxComponent>: TransformComponent doesn't exist!" << std::endl;
		exit(1);
	}
}

void BoxComponent::draw()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderDrawRect(renderer, &rect);
}

void BoxComponent::update()
{
	rect.w = transform->size().w();
	rect.h = transform->size().h();
	rect.x = transform->coords().x();
	rect.y = transform->coords().y();
}
