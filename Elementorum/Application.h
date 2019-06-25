#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 6

class ModuleWindow;
class ModuleRender;
class ModuleInput;
class ModuleTextures;
class ModuleLevelTest;
class ModuleCharacterTest;

class Module;
class Application
{
public:
	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleLevelTest* level_test;
	ModuleCharacterTest* character_test;

public:
	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();
};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__