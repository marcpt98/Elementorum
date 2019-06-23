#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleLevelTest.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"

ModuleLevelTest::ModuleLevelTest()
{
	background.x = 0;
	background.y = 0;
	background.w = 552;
	background.h = 224;
}

ModuleLevelTest::~ModuleLevelTest()
{}

// Load assets
bool ModuleLevelTest::Start()
{
	LOG("LOADING LEVEL TEST");
	
	graphics = App->textures->Load("Background_Level_Test.png");

	App->player->Enable();
	return true;
}

// Unload assets
bool ModuleLevelTest::CleanUp()
{
	LOG("UNLOADING LEVEL TEST");
	
	App->player->Disable();
	return true;
}

// Draw background
update_status ModuleLevelTest::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background, 0.75f);

	return UPDATE_CONTINUE;
}