#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleCharacterTest.h"

ModuleCharacterTest::ModuleCharacterTest()
{
	position.x = 100;
	position.y = 400;

	// Idle animation 
	idle.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	idle.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	idle.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);

	// Walk forward animation
	forward.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	forward.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	forward.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	forward.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);

	// Walk backward animation
	backward.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	backward.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	backward.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	backward.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);

	// Jump animation
	jump.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	jump.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	jump.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	jump.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	jump.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	jump.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
	jump.PushBack({ 0, 0, 0, 0 }, 0, 0, 0, 0, 0);
}

ModuleCharacterTest::~ModuleCharacterTest()
{}

// Load assets player test
bool ModuleCharacterTest::Start()
{
	LOG("LOADING ASSETS CHARACTER TEST");
	bool ret = true;

	character_test = App->textures->Load("Character/Spritesheet_Character_Test.png");

	return ret;
}

// Unload assets player test
bool ModuleCharacterTest::CleanUp()
{
	LOG("UNLOADING ASSETS CHARACTER TEST");

	App->textures->Unload(character_test);

	return true;
}


update_status ModuleCharacterTest::Update()
{
	float speed = 1;
	int inicial = 120;

	// ANIMATIONS
	////////////////////////////////////////////////////////////////////// 
	//Default
	Animation *current_animation = &idle;

	// Walk forward
	if (App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &forward;
		position.x += speed;
	}

	// Walk backward
	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		current_animation = &backward;
		position.x -= speed;
	}

	// Jump

	//////////////////////////////////////////////////////////////////////

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(character_test, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}