#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include <cstdio>

#include "Timer.h"
#include "Block.h"
#include "Menu.h"
#include "AudioController.h"

#include "Main.h"

const int Main::FRAMES_PER_SECOND = 60;

Main * Main::instance = NULL;

SDL_Surface * Main::screen = NULL;
TTF_Font * Main::font = NULL;

bool Main::running = false;
int Main::frame_delay = 0;
int Main::frame = 0;
bool Main::fps_cap = false;

Timer * Main::fps = NULL;

AudioController * Main::audio = NULL;

bool Main::music_on = true;
bool Main::sound_on = true;

Main::Main() {
	Main::instance = this;
}

Main::~Main() {
	if(Main::instance == this) {
		Main::instance = NULL;
	}
}

bool Main::init() {
	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_SWSURFACE);
	SDL_ShowCursor(0);

	fps_cap = true;

	if(screen == NULL) return false;

	if(TTF_Init() == -1) return false;

	//font = TTF_OpenFont("tahoma.ttf", 28);
	//if(font == NULL) return false;

	SDL_WM_SetCaption("Battle", NULL);
	
	fps = new Timer();

	audio = new AudioController();
	audio->open_audio();
	audio->load_files();

	// enable joystick throughout the game
	SDL_JoystickEventState(SDL_ENABLE);
	if(SDL_NumJoysticks() >= 1)
		joystick1 = SDL_JoystickOpen(0);
	if(SDL_NumJoysticks() >= 2)
		joystick2 = SDL_JoystickOpen(1);


	return true;
}

void Main::clean_up() {

	SDL_FreeSurface(screen);
	
	//TTF_CloseFont(font);

	delete fps;

	audio->close_files();
	audio->close_audio();
	delete audio;

	if(SDL_JoystickOpened(1))
		SDL_JoystickClose(joystick2);
	if(SDL_JoystickOpened(0))
		SDL_JoystickClose(joystick1);

	//Quit SDL
	SDL_Quit();
}

void Main::flip() {
	SDL_Flip(screen);
	frame++;
	if((fps_cap == true) && (fps->get_ticks() < frame_delay)) {
		SDL_Delay((frame_delay) - fps->get_ticks());
	}
}

void Main::handle_event(SDL_Event * event) {
	/* Catch quit event and ALT-F4 */
	if(event->type == SDL_QUIT) {
		running = false;
	}
	if(event->type == SDL_KEYDOWN) {
		if(event->key.keysym.mod & KMOD_ALT) {
			if(event->key.keysym.sym == SDLK_F4) {
				running = false;
			}
		}
	}
}

int Main::run() {
	if(!init()) return 1;

	frame_delay = 1000 / FRAMES_PER_SECOND;
	frame = 0;

	Menu * menu;
	menu = new Menu();

	running = true;
	menu->run();

	delete menu;

	clean_up();

	return 0;
}


int main(int argc, char* args[]) {
	Main main;
	return main.run();
}