#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

SpriteComponent::~SpriteComponent()
{
	for (register int i = 0 ; i < size ; i++)
	{
		SDL_DestroyTexture(animation[i].texture);
	}
	delete[] animation;
}

void SpriteComponent::init()
{
	animation = nullptr;
	rect.w = 0;
	rect.h = 0;
	rect.x = 0;
	rect.y = 0;
	size = 0;
	current_animation = 0;
	isLocked = false;

	fp = SDL_FLIP_NONE;

	ang = 0;

	begin = std::chrono::system_clock::now();
}

void SpriteComponent::update()
{
	rect.w = animation[current_animation].frame_w;
	rect.h = animation[current_animation].frame_h;
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - begin;
	if (diff.count() >= animation[current_animation].SPF)
	{
		rect.x += rect.w;
		if (rect.x >= animation[current_animation].width)
		{
			rect.x = 0;
		}
		begin = std::chrono::system_clock::now();
	}
}
	
void SpriteComponent::add_animation(const char* texture_path, const double& SPF, const int& frame_count)
{
	if (frame_count <= 0) throw std::runtime_error("[SpriteComponent] <add_animation>: the frame_count isn't positive");
	if (size == 0)
	{
		animation = new Animation[++size];
	}
	else
	{
		Animation* buf = new Animation[size + 1];
		for (int i = 0 ; i < size ; i++)
		{
			buf[i] = animation[i];
		}
		delete[] animation;
		animation = buf;
		size++;
	}
	SDL_Surface* surf = IMG_Load(texture_path);
	if (surf == NULL) throw std::runtime_error("[SpriteComponent] <add_animation>: texture loading error");
	animation[size - 1].frame_h = surf->h;
	animation[size - 1].frame_w = surf->w / frame_count;
	animation[size - 1].width = surf->w;
	animation[size - 1].height = surf->h;
	animation[size - 1].SPF = SPF;
	animation[size - 1].texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
}

void SpriteComponent::set_animation(const int& animation_number, const bool& isLocked)
{
	if (animation_number >= size) throw std::runtime_error("[SpriteComponent] <set_animation>: new number is more than size");
	if (!isLocked)
	{
		current_animation = animation_number;
	}
}
