#ifndef _PLAYER_H
#define _PLAYER_H

#define FACE_LEFT 0
#define FACE_RIGHT 1

#define SPR_R		0
#define SPR_R_WALK1	1
#define SPR_R_WALK2	2
#define SPR_R_WALK3	3
#define SPR_R_RUN1	4
#define SPR_R_RUN2	5
#define SPR_R_RUN3	6
#define SPR_L_BRAKE	7
#define SPR_R_JUMP	8
#define SPR_R_DUCK	9
#define SPR_L		10
#define SPR_L_WALK1	11
#define SPR_L_WALK2	12
#define SPR_L_WALK3	13
#define SPR_L_RUN1	14
#define SPR_L_RUN2	15
#define SPR_L_RUN3	16
#define SPR_R_BRAKE	17
#define SPR_L_JUMP	18
#define SPR_L_DUCK	19

#define CYCLE_UP 0
#define CYCLE_DN 1

#define PLAYER_W 22
#define PLAYER_H 44
#define PLAYER_DUCK_H 26

#define DUCK_FORCE_FRAMES 10

class Player {
public:
	Player(const char * sprite_file);
	~Player();
	SDL_Rect * position;
	SDL_Surface * sprites;
	SDL_Rect * clip[20];

	int momentumx, momentumy;
	int last_speedx, last_speedy;

	bool is_running;
	bool is_duck;
	bool is_duck_forced;
	int duck_force_start;

	bool is_jumping, is_falling;
	int jump_start;

	int current_sprite;
	int cycle_direction;
	int distance_walked;

	bool keydn_l, keydn_r, keydn_u, keydn_d, keydn_run, keydn_shoot;
	int key_l, key_r, key_u, key_d, key_run, key_shoot;
	int joystick_idx;
	int js_btn_u, js_btn_run, js_btn_shoot, js_btn_start;

	bool is_hit;
	int hit_start;
	int hit_delay;
	int hit_flicker_frame;

	int shoot_start;
	int shoot_delay;

	int score;
	int hitpoints;

	static const int jump_height;

	void handle_input(SDL_Event * event);
	void show(SDL_Surface * screen);
	void set_sprite(int sprite);
	void cycle_sprite(int first, int last);
	void cycle_sprite_updown(int first, int last);

private:
	void load_images(const char * sprite_file);
	void free_images();
	void set_clips();
};

#endif