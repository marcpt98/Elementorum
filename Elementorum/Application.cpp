#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleLevelTest.h"
#include "ModuleCharacterTest.h"
#include "ModuleCollisions.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[5] = textures = new ModuleTextures();
	modules[3] = level_test = new ModuleLevelTest();
	modules[4] = character_test = new ModuleCharacterTest();
	modules[5] = collisions = new ModuleCollisions();
}	

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i) 
	{
		delete modules[i];
	}		
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	character_test->Disable();
	// Disable the map that you do not start with
	
	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
	{
		ret = modules[i]->Init();
	}
	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
	{
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;
	}
		
	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}