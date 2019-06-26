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
	idle.PushBack({ 0, 0, 60, 90 }, 0.1, 0, 0, 0, 0);
	idle.PushBack({ 61, 0, 60, 87 }, 0.1, 0, 0, 0, 0);
	idle.PushBack({ 122, 0, 60, 84 }, 0.1, 0, 0, 0, 0);
	idle.PushBack({ 61, 0, 60, 87 }, 0.1, 0, 0, 0, 0);

	// Walk forward animation
	forward.PushBack({ 0, 91, 60, 90 }, 0.1, 0, 0, 0, 0);
	forward.PushBack({ 61, 91, 60, 87 }, 0.1, 0, 0, 0, 0);
	forward.PushBack({ 0, 0, 60, 90 }, 0.1, 0, 0, 0, 0);
	forward.PushBack({ 122, 91, 60, 90 }, 0.1, 0, 0, 0, 0);
	forward.PushBack({ 183, 91, 60, 87 }, 0.1, 0, 0, 0, 0);
	forward.PushBack({ 0, 0, 60, 90 }, 0.1, 0, 0, 0, 0);

	// Walk backward animation
	backward.PushBack({ 0, 91, 60, 90 }, 0.1, 0, 0, 0, 0);
	backward.PushBack({ 61, 91, 60, 87 }, 0.1, 0, 0, 0, 0);
	backward.PushBack({ 0, 0, 60, 90 }, 0.1, 0, 0, 0, 0);
	backward.PushBack({ 122, 91, 60, 90 }, 0.1, 0, 0, 0, 0);
	backward.PushBack({ 183, 91, 60, 87 }, 0.1, 0, 0, 0, 0);
	backward.PushBack({ 0, 0, 60, 90 }, 0.1, 0, 0, 0, 0);

	// Jump animation
	jump.PushBack({ 320, 88, 60, 90 }, 0.03, 0, 0, 0, 0);

	// Crouch Animation
	crouch.PushBack({ 391, 0, 60, 87 }, 0.1, 0, 0, 0, 0);
	crouch.PushBack({ 452, 0, 60, 75 }, 0.1, 0, 0, 0, 0);
	crouch.loop = false;

	// Attack animation
	attack.PushBack({ 0, 270, 96, 93 }, 0.1, 0, 0, 0, 0);
	attack.PushBack({ 97, 270, 96, 105 }, 0.1, 0, 0, 0, 0);
	attack.PushBack({ 203, 270, 102, 99 }, 0.1, 0, 0, 0, 0);
	attack.PushBack({ 306, 270, 96, 99 }, 0.1, 0, 0, 0, 0);
	attack.PushBack({ 97, 270, 96, 105 }, 0.1, 0, 0, 0, 0);
	attack.PushBack({ 0, 270, 96, 93 }, 0.1, 0, 0, 0, 0);

	// Damage animation
	damage.PushBack({ 0, 182, 60, 87 }, 0.2, 0, 0, 0, 0);
	damage.PushBack({ 61, 182, 63, 87 }, 0.2, 0, 0, 0, 0);
	damage.PushBack({ 125, 182, 63, 87 }, 0.3, 0, 0, 0, 0);
	damage.PushBack({ 189, 182, 63, 87 }, 0.3, 0, 0, 0, 0);
	damage.PushBack({ 125, 182, 63, 87 }, 0.3, 0, 0, 0, 0);
	damage.PushBack({ 189, 182, 63, 87 }, 0.3, 0, 0, 0, 0);
	damage.PushBack({ 61, 182, 63, 87 }, 0.2, 0, 0, 0, 0);

	// Die animation
	die.PushBack({ 0, 376, 72, 84 }, 0.1, 0, 0, 0, 0);
	die.PushBack({ 73, 376, 99, 54 }, 0.1, 0, 0, 0, 0);
	die.PushBack({ 173, 376, 93, 48 }, 0.1, 0, 0, 0, 0);
	die.PushBack({ 267, 376, 90, 21 }, 0.1, 0, 0, 0, 0);
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


	// Crouch


	// Attack


	// Damage


	// Die

	//////////////////////////////////////////////////////////////////////

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(character_test, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}