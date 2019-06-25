#ifndef __MODULECHARACTERTEST_H__
#define __MODULECHARACTERTEST_H__

#include "Globals.h"
#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleCharacterTest : public Module
{
public:
	ModuleCharacterTest();
	~ModuleCharacterTest();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* character_test = nullptr;
	iPoint position;

	Animation idle;
	Animation forward;
	Animation backward;
	Animation jump;
};

#endif