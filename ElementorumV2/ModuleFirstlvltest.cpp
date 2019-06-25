#include "Globals.h"
#include "Application.h"
#include "ModuleFirstlvltest.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleScenewin.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleFirstlvltest::ModuleFirstlvltest()
{
	// ground
	background2.x = 0;
	background2.y = 0;
	background2.w = 552;
	background2.h = 224;
}

ModuleFirstlvltest::~ModuleFirstlvltest()
{}

// Load assets
bool ModuleFirstlvltest::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("level_2.png");

	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();

	return ret;
}

// Load assets
bool ModuleFirstlvltest::CleanUp()
{
	// TODO 5: Remove all memory leaks
	//SDL_DestroyTexture(graphics);
	LOG("Unloading honda stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleFirstlvltest::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background2, 0.75f);
	// TODO 2: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->first_lvl, App->scene_win, 2);
	}

	return UPDATE_CONTINUE;
}