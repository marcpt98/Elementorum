#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

ModuleTextures::ModuleTextures() : Module()
{
	for (uint i = 0; i < MAX_TEXTURES; ++i)
		textures[i] = nullptr;
}

// Destructor
ModuleTextures::~ModuleTextures()
{}

// Called before render is available
bool ModuleTextures::Init()
{
	LOG("INIT IMAGE LIBRARY");
	bool ret = true;

	// Load support for the PNG image format
	int flags = IMG_INIT_PNG;
	int init = IMG_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("COULD NOT INITIALIZE IMAGE LIB. IMG_INIT: %s", IMG_GetError());
		ret = false;
	}

	return ret;
}

// Called before quitting
bool ModuleTextures::CleanUp()
{
	LOG("FREEING IMAGE TEXTURES AND IMAGE LIBRARY");

	for (uint i = 0; i < MAX_TEXTURES; ++i)
		if (textures[i] != nullptr)
			SDL_DestroyTexture(textures[i]);

	IMG_Quit();
	return true;
}

// Load new texture from file path
SDL_Texture* const ModuleTextures::Load(const char* path)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = IMG_Load(path);

	if (surface == NULL)
	{
		LOG("COULD NOT LOAD SURFACE WITH PATH: %s. IMG_LOAD: %s", path, IMG_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(App->render->renderer, surface);

		if (texture == NULL)
		{
			LOG("UNABLE TO CREATE TEXTURE FROM SURFACE! SDL ERROR: %s\n", SDL_GetError());
		}
		else
		{
			bool room = false;
			for (int i = 0; i < MAX_TEXTURES; ++i)
			{
				if (textures[i] == nullptr)
				{
					textures[i] = texture;
					room = true;
					break;
				}
			}
			if (room == false)
				LOG("TEXTURE BUFFER OVERFLOW");
		}

		SDL_FreeSurface(surface);
	}

	return texture;
}

bool ModuleTextures::Unload(SDL_Texture * texture)
{
	bool ret = false;

	if (texture != nullptr)
	{
		for (int i = 0; i < MAX_TEXTURES; ++i)
		{
			if (textures[i] == texture)
			{
				textures[i] = nullptr;
				ret = true;
				break;
			}
		}
		SDL_DestroyTexture(texture);
	}

	return ret;
}
