#ifndef __MODULEINPUT_H__
#define __MODULEINPUT_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"

typedef unsigned char Uint8;

class ModuleInput : public Module
{
public:
	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	const Uint8 *keyboard = nullptr;
};

#endif // __MODULEINPUT_H__