#include "Globals.h"
#include "Application.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneHonda.h"
ModuleWelcomeScreen::ModuleWelcomeScreen()
{
	Welcomeimage = { 284,369,455,335 };
}


ModuleWelcomeScreen::~ModuleWelcomeScreen()
{}

bool ModuleWelcomeScreen::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("welcome.png");

	// TODO 1: Enable (and properly disable) the player module
	//App->player->Enable();

	return ret;
}

bool ModuleWelcomeScreen::CleanUp()
{
	// TODO 5: Remove all memory leaks
	//SDL_DestroyTexture(graphics);
	LOG("Unloading honda stage");
	App->player->Disable();
	return true;
}

update_status ModuleWelcomeScreen::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, -50, -50, &Welcomeimage);

	// TODO 2: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->scene_Welcome,App->scene_honda, 2);
	}

	return UPDATE_CONTINUE;
}