#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleLevelTest.h"
#include "ModuleCharacterTest.h"

ModuleLevelTest::ModuleLevelTest()
{
	// Ground level test
	background_size.x = 0;
	background_size.y = 0;
	background_size.w = 1000;
	background_size.h = 500;
}

ModuleLevelTest::~ModuleLevelTest()
{}

// Load assets level test
bool ModuleLevelTest::Start()
{
	LOG("LOADING ASSETS LEVEL TEST");
	bool ret = true;

	background = App->textures->Load("Levels/Background_Level_Test.png");

	App->character_test->Enable();

	return ret;
}

// Unload assets level test
bool ModuleLevelTest::CleanUp()
{
	LOG("UNLOADING ASSETS LEVEL TEST");
	
	App->textures->Unload(background);

	App->character_test->Disable();
	
	return true;
}

// Draw background
update_status ModuleLevelTest::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(background, 0, 0, &background_size, 0.75f);

	return UPDATE_CONTINUE;
}