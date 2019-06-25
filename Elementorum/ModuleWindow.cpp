#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "SDL/include/SDL.h"

ModuleWindow::ModuleWindow() : Module()
{}

ModuleWindow::~ModuleWindow()
{}

// Called before render is available
bool ModuleWindow::Init()
{
	LOG("INIT SDL WINDOW & SURFACE");
	bool ret = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG("SDL_VIDEO COULD NOT INITIALIZE! SDL_ERROR:\n");
		LOG(SDL_GetError());
		ret = false;
	}
	else
	{
		//Create window
		int width = SCREEN_WIDTH * SCREEN_SIZE;
		int height = SCREEN_HEIGHT * SCREEN_SIZE;
		Uint32 flags = SDL_WINDOW_SHOWN;

		if(WIN_FULLSCREEN == true)
			flags |= SDL_WINDOW_FULLSCREEN;

		if(WIN_BORDERLESS == true)
			flags |= SDL_WINDOW_BORDERLESS;

		if(WIN_RESIZABLE == true)
			flags |= SDL_WINDOW_RESIZABLE;

		if(WIN_FULLSCREEN_DESKTOP == true)
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

		window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		if(window == NULL)
		{
			LOG("WINDOW COULD NOT BE CREATED! SDL_ERROR: %s\n", SDL_GetError());
			ret = false;
		}
		else
		{
			//Get window surface
			screen_surface = SDL_GetWindowSurface(window);
		}
	}

	return ret;
}

// Called before quitting
bool ModuleWindow::CleanUp()
{
	LOG("DESTROYING SDL WINDOW AND QUITTING ALL SDL SYSTEMS");

	//Destroy window
	if(window != NULL)
		SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
	return true;
}

