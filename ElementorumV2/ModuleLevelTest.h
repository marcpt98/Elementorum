#ifndef __MODULELEVELTEST_H__
#define __MODULELEVELTEST_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleLevelTest : public Module
{
public:
	ModuleLevelTest();
	~ModuleLevelTest();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* graphics = nullptr;

	SDL_Rect background;

	float foreground_pos;
	bool forward;
};

#endif // __MODULELEVELTEST_H__