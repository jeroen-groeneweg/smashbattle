#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include <vector>

#include "OptionsScreen.h"

#define DIRECTION_NONE	0
#define DIRECTION_LEFT	1
#define DIRECTION_RIGHT	2
#define DIRECTION_UP	4
#define DIRECTION_DOWN	8

OptionsScreen::OptionsScreen() {
	items = new std::vector<OptionItem*>(0);

	align = LEFT;
}

void OptionsScreen::run() {
	SDL_Event event;

	init();

	controls1 = Main::instance->controls1;
	controls2 = Main::instance->controls2;

	frame = 0;

	running = true;

	cursor_direction = 0;
	cursor_direction_start = 0;
	cursor_enter = false;
	cursor_first = false;

	while (Main::running && running) {
		while(SDL_PollEvent(&event)) {
			Main::instance->handle_event(&event);
			handle_input(&event);
		}
		process_cursor();
		
		draw();

		Main::instance->flip();
		frame++;
	}

	cleanup();
}

void OptionsScreen::draw() {
	unsigned int i;
	SDL_Surface * text, * highlight;
	SDL_Rect rect;
	SDL_Surface * screen;

	screen = Main::instance->screen;

	SDL_FillRect(screen, NULL, 0);
	//SDL_BlitSurface(bg, NULL, screen, NULL);

	for(i = 0; i < items->size(); i++) {
		text = surf_items->at(i);
		
		if(selected_item == i) {
			highlight = SDL_CreateRGBSurface(NULL, text->w + 10, menu_item_height, 32, 0, 0, 0, 0);
			SDL_FillRect(highlight, NULL, 0x444488);
			
			rect.x = surf_items_clip->at(i)->x - 5;
			rect.y = surf_items_clip->at(i)->y - 3;

			SDL_BlitSurface(highlight, NULL, screen, &rect);
			SDL_FreeSurface(highlight);
		}

		SDL_BlitSurface(text, NULL, screen, surf_items_clip->at(i));
	}
}

void OptionsScreen::handle_input(SDL_Event * event) {
	int old_direction;
	old_direction = cursor_direction;

	if(event->type == SDL_KEYDOWN) {
		// Keyboard 1
		if(controls1.use_keyboard) {
			if(event->key.keysym.sym == controls1.kb_left)
				cursor_direction |= DIRECTION_LEFT;
			if(event->key.keysym.sym == controls1.kb_right)
				cursor_direction |= DIRECTION_RIGHT;
			if(event->key.keysym.sym == controls1.kb_up)
				cursor_direction |= DIRECTION_UP;
			if(event->key.keysym.sym == controls1.kb_down)
				cursor_direction |= DIRECTION_DOWN;
			else if(event->key.keysym.sym == controls1.kb_shoot || 
				event->key.keysym.sym == controls1.kb_run ||
				event->key.keysym.sym == controls1.kb_start ||
				(controls1.kb_up != controls1.kb_jump &&
				event->key.keysym.sym == controls1.kb_jump)) {
					cursor_enter = true;
			}
		}
		// Keyboard 2
		if(controls2.use_keyboard) {
			if(event->key.keysym.sym == controls2.kb_left)
				cursor_direction |= DIRECTION_LEFT;
			if(event->key.keysym.sym == controls2.kb_right)
				cursor_direction |= DIRECTION_RIGHT;
			if(event->key.keysym.sym == controls2.kb_up)
				cursor_direction |= DIRECTION_UP;
			if(event->key.keysym.sym == controls2.kb_down)
				cursor_direction |= DIRECTION_DOWN;
			else if(event->key.keysym.sym == controls2.kb_shoot || 
				event->key.keysym.sym == controls2.kb_run ||
				event->key.keysym.sym == controls2.kb_start ||
				(controls2.kb_up != controls2.kb_jump &&
				event->key.keysym.sym == controls2.kb_jump)) {
					cursor_enter = true;
			}
		}
	}
	if(event->type == SDL_KEYUP) {
		// Keyboard 1
		if(controls1.use_keyboard) {
			if(event->key.keysym.sym == controls1.kb_left && cursor_direction & DIRECTION_LEFT)
				cursor_direction ^= DIRECTION_LEFT;
			if(event->key.keysym.sym == controls1.kb_right && cursor_direction & DIRECTION_RIGHT)
				cursor_direction ^= DIRECTION_RIGHT;
			if(event->key.keysym.sym == controls1.kb_up && cursor_direction & DIRECTION_UP)
				cursor_direction ^= DIRECTION_UP;
			if(event->key.keysym.sym == controls1.kb_down && cursor_direction & DIRECTION_DOWN)
				cursor_direction ^= DIRECTION_DOWN;
		}
		// Keyboard 2
		if(controls2.use_keyboard) {
			if(event->key.keysym.sym == controls2.kb_left && cursor_direction & DIRECTION_LEFT)
				cursor_direction ^= DIRECTION_LEFT;
			if(event->key.keysym.sym == controls2.kb_right && cursor_direction & DIRECTION_RIGHT)
				cursor_direction ^= DIRECTION_RIGHT;
			if(event->key.keysym.sym == controls2.kb_up && cursor_direction & DIRECTION_UP)
				cursor_direction ^= DIRECTION_UP;
			if(event->key.keysym.sym == controls2.kb_down && cursor_direction & DIRECTION_DOWN)
				cursor_direction ^= DIRECTION_DOWN;
		}
	}
	if(event->type == SDL_JOYBUTTONDOWN) {
		// Joystick 1 Buttons
		if(controls1.use_joystick && event->jbutton.which == controls1.joystick_idx) {
			if(event->jbutton.button == controls1.js_left)
				cursor_direction |= DIRECTION_LEFT;
			if(event->jbutton.button == controls1.js_right)
				cursor_direction |= DIRECTION_RIGHT;
			if(event->jbutton.button == controls1.js_jump ||
				event->jbutton.button == controls1.js_run ||
				event->jbutton.button == controls1.js_shoot ||
				event->jbutton.button == controls1.js_start) {
					cursor_enter = true;
			}
		}
		// Joystick 2 Buttons
		if(controls2.use_joystick && event->jbutton.which == controls2.joystick_idx) {
			if(event->jbutton.button == controls2.js_left)
				cursor_direction |= DIRECTION_LEFT;
			if(event->jbutton.button == controls2.js_right)
				cursor_direction |= DIRECTION_RIGHT;
			if(event->jbutton.button == controls2.js_jump ||
				event->jbutton.button == controls2.js_run ||
				event->jbutton.button == controls2.js_shoot ||
				event->jbutton.button == controls2.js_start) {
					cursor_enter = true;
			}
		}
	}
	if(event->type == SDL_JOYBUTTONUP) {
		// Joystick 1 Buttons
		if(controls1.use_joystick && event->jbutton.which == controls1.joystick_idx) {
			if(event->jbutton.button == controls1.js_left && cursor_direction & DIRECTION_LEFT)
				cursor_direction ^= DIRECTION_LEFT;
			if(event->jbutton.button == controls1.js_right && cursor_direction & DIRECTION_RIGHT)
				cursor_direction ^= DIRECTION_RIGHT;
		}
		// Joystick 2 Buttons
		if(controls2.use_joystick && event->jbutton.which == controls2.joystick_idx) {
			if(event->jbutton.button == controls2.js_left && cursor_direction & DIRECTION_LEFT)
				cursor_direction ^= DIRECTION_LEFT;
			if(event->jbutton.button == controls2.js_right && cursor_direction & DIRECTION_RIGHT)
				cursor_direction ^= DIRECTION_RIGHT;
		}
	}
	if(event->type == SDL_JOYAXISMOTION) {
		// Joystick 1 Axis
		if(controls1.use_joystick && event->jbutton.which == controls1.joystick_idx) {
			if(event->jaxis.axis == 0) {
				if(event->jaxis.value < -Main::JOYSTICK_AXIS_THRESHOLD)
					cursor_direction |= DIRECTION_LEFT;
				else if(event->jaxis.value > Main::JOYSTICK_AXIS_THRESHOLD)
					cursor_direction |= DIRECTION_RIGHT;
				else {
					if(cursor_direction & DIRECTION_LEFT)
						cursor_direction ^= DIRECTION_LEFT;
					if(cursor_direction & DIRECTION_RIGHT)
						cursor_direction ^= DIRECTION_RIGHT;
				}
			}
			if(event->jaxis.axis == 1) {
				if(event->jaxis.value < -Main::JOYSTICK_AXIS_THRESHOLD)
					cursor_direction |= DIRECTION_UP;
				else if(event->jaxis.value > Main::JOYSTICK_AXIS_THRESHOLD)
					cursor_direction |= DIRECTION_DOWN;
				else {
					if(cursor_direction & DIRECTION_UP)
						cursor_direction ^= DIRECTION_UP;
					if(cursor_direction & DIRECTION_DOWN)
						cursor_direction ^= DIRECTION_DOWN;
				}
			}
		}
		// Joystick 2 Axis
		if(controls2.use_joystick && event->jbutton.which == controls2.joystick_idx) {
			if(event->jaxis.axis == 0) {
				if(event->jaxis.value < -Main::JOYSTICK_AXIS_THRESHOLD)
					cursor_direction |= DIRECTION_LEFT;
				else if(event->jaxis.value > Main::JOYSTICK_AXIS_THRESHOLD)
					cursor_direction |= DIRECTION_RIGHT;
				else {
					if(cursor_direction & DIRECTION_LEFT)
						cursor_direction ^= DIRECTION_LEFT;
					if(cursor_direction & DIRECTION_RIGHT)
						cursor_direction ^= DIRECTION_RIGHT;
				}
			}
			if(event->jaxis.axis == 1) {
				if(event->jaxis.value < -Main::JOYSTICK_AXIS_THRESHOLD)
					cursor_direction |= DIRECTION_UP;
				else if(event->jaxis.value > Main::JOYSTICK_AXIS_THRESHOLD)
					cursor_direction |= DIRECTION_DOWN;
				else {
					if(cursor_direction & DIRECTION_UP)
						cursor_direction ^= DIRECTION_UP;
					if(cursor_direction & DIRECTION_DOWN)
						cursor_direction ^= DIRECTION_DOWN;
				}
			}
		}
	}
	if(old_direction != cursor_direction) {
		cursor_first = true;
	}
}


void OptionsScreen::process_cursor() {
	int delay;

	if(cursor_enter) {
		cursor_enter = false;
		select();
	}

	if(cursor_direction != 0) {
		if(cursor_first)
			delay = 0;
		else
			delay = Main::CONTROLS_REPEAT_SPEED;
		if(frame - cursor_direction_start > delay) {
			cursor_direction_start = frame;
			cursor_first = false;
			if(cursor_direction & DIRECTION_UP) {
				select_up();
			}
			if(cursor_direction & DIRECTION_DOWN) {
				select_down();
			}
			if(cursor_direction & DIRECTION_LEFT) {
				select_left();
			}
			if(cursor_direction & DIRECTION_RIGHT) {
				select_right();
			}
		}
	}
}

void OptionsScreen::select() {
	Main::audio->play(SND_SELECT);
	item_selected();
	Main::audio->play_music(MUSIC_TITLE);
}

void OptionsScreen::select_up() {
	Main::audio->play(SND_SELECT);

	selected_item--;

	if(selected_item < 0) {
		selected_item = (int)items->size() - 1;
	}
}

void OptionsScreen::select_down() {
	Main::audio->play(SND_SELECT);

	selected_item++;

	if(selected_item == (int)items->size()) {
		selected_item = 0;
	}
}

void OptionsScreen::select_left() {
	OptionItem * item;
	unsigned int count;

	item = items->at(selected_item);
	if(item->options == NULL) return;
	
	count = item->options->size();

	if(item->selected == 0)
		item->selected = count - 1;
	else
		item->selected--;
}

void OptionsScreen::select_right() {
	OptionItem * item;
	unsigned int count;

	item = items->at(selected_item);
	if(item->options == NULL) return;
	
	count = item->options->size();

	if(item->selected == (count - 1))
		item->selected = 0;
	else
		item->selected++;
}

void OptionsScreen::add_item(OptionItem * item) {
	items->push_back(item);
}

void OptionsScreen::item_selected() { }

void OptionsScreen::init() {
	SDL_Surface * surface;
	SDL_Rect * rect;

	font26 = TTF_OpenFont("fonts/slick.ttf", 26);
	font13 = TTF_OpenFont("fonts/slick.ttf", 13);
	fontColor.r = 255;
	fontColor.g = 255;
	fontColor.b = 255;

	selected_item = 0;

	screen_w = Main::instance->screen->w;
	screen_h = Main::instance->screen->h;

	menu_item_height = 26;
	menu_top_offset = 30;
	menu_left_offset = 20;

	surf_items = new std::vector<SDL_Surface*>(0);
	surf_items_clip = new std::vector<SDL_Rect*>(0);
	for(unsigned int i = 0; i < items->size(); i++) {
		surface = TTF_RenderText_Solid(font26, items->at(i)->name, fontColor);
		surf_items->push_back(surface);

		rect = new SDL_Rect();
		if(align == LEFT) {
			rect->x = menu_left_offset;
		} else if(align == CENTER) {
			rect->x = (screen_w - surface->w) / 2;
		} else {
			rect->x = screen_w - surface->w - menu_left_offset;
		}
		rect->y = menu_top_offset + (i * menu_item_height) - 3;
		surf_items_clip->push_back(rect);
	}
}

void OptionsScreen::cleanup() {
	TTF_CloseFont(font26);
	TTF_CloseFont(font13);

	for(unsigned int i = 0; i < items->size(); i++) {
		delete items->at(i);
	}
	items->clear();
	delete items;

	for(unsigned int i = 0; i < surf_items->size(); i++) {
		SDL_FreeSurface(surf_items->at(i));
	}
	surf_items->clear();
	delete surf_items;

	for(unsigned int i = 0; i < surf_items_clip->size(); i++) {
		delete surf_items_clip->at(i);
	}
	surf_items_clip->clear();
	delete surf_items_clip;
}