﻿#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include "MessageError.h"

void MenuScene(ALLEGRO_BITMAP *background, ALLEGRO_FONT *titles, ALLEGRO_FONT *subtitles, ALLEGRO_FONT *options_titles, int x, int y);
void PlayScene(ALLEGRO_BITMAP *background_game, int x, int y, ALLEGRO_BITMAP *right, ALLEGRO_BITMAP *left, ALLEGRO_BITMAP *up, ALLEGRO_BITMAP *down, ALLEGRO_FONT *fps, int GameFPS, int Speed);
void GameoverScene(ALLEGRO_FONT *titles, ALLEGRO_FONT *subtitlesover);
void SettingScene(ALLEGRO_BITMAP *background, ALLEGRO_FONT *setting_titles, ALLEGRO_FONT *options_titles, ALLEGRO_FONT *subtitles, int x, int y);
void DirectionMove(ALLEGRO_BITMAP *right, ALLEGRO_BITMAP *left, ALLEGRO_BITMAP *up, ALLEGRO_BITMAP *down, int Speed);
void GameRun(ALLEGRO_BITMAP *right, ALLEGRO_BITMAP *left, ALLEGRO_BITMAP *up, ALLEGRO_BITMAP *down, ALLEGRO_FONT *fps, int GameFPS, int Speed);
void Walls();
void CollisionWalls();
void Developer();

//=========== GLOBAL VARIABLES ===========//
const int Width = 800;
const int Height = 800;

const int mapW = (Width/25);
const int mapH = (Height/25);

//const int SIZE = mapW * mapH;
int Map[mapW][mapH];
int Body = 2;

enum STATE { MENU, PLAY, GAMEOVER, SETTING };
bool keys[] = { false, false, false, false, false, false, false, false, false, false, false };
enum KEYS { UP, DOWN, LEFT, RIGHT, ESCAPE, TAB, ENTER, q, w, SPACE, z};

enum DirectionSnake { Up, Down, Left, Right };
int DirectionSnake = Right;

int state = MENU;

bool finish;
bool Collision = false;

//=========== COLLISION VARIABLES ===========//
struct Sprite
{
	int x;
	int y;

	int dx;
	int dy;

	int width;
	int height;

	ALLEGRO_BITMAP *image;
};

Sprite HeadPosX;
Sprite HeadPosY;
Sprite wall;

//=========== GLOBAL VARIABLES ===========//

ALLEGRO_SAMPLE_INSTANCE *SongInst = NULL;
ALLEGRO_SAMPLE_INSTANCE *InGameSoundInst = NULL;
ALLEGRO_SAMPLE *Song = NULL;
ALLEGRO_SAMPLE *EatRed = NULL;
ALLEGRO_SAMPLE *EatMashroom = NULL;
ALLEGRO_SAMPLE *GameoverSong = NULL;
ALLEGRO_SAMPLE *CrashSound = NULL;
ALLEGRO_SAMPLE *InGameSound = NULL;
ALLEGRO_SAMPLE *ChangeOnRedSound = NULL;

int main()
{
	//=========== VARIABLES ===========//
	float FPS = 10.0;
	bool done = false;
	bool Return = false;

	bool bound = false;

	HeadPosX.x = (Width / 25) * 5;
	HeadPosY.y = (Height / 25) * 5;

	float TimeGame = 0;
	int frame = 0;
	int GameFPS = 0;
	int x = 0;
	int y = 0;
	int Speed = 1;

	/////////////////////////////////

	for (int i = 0; i < 25; i++)
	{
		Map[i][mapH] += 32;
		for (int i = 0; i < 25; i++)
		{
			Map[mapW][i] += 32;
		}
	}

	//=========== VARIABLES ACHIEVEMENTS ===========//
	int Points = 0;
	int Golds = 0;
	int TimeInGame = 0;

	//=========== WALLS ===========//
	wall.x = 32;
	wall.y = 32;

	wall.dx = wall.width;
	wall.dy = wall.height;

	HeadPosX.dx = 32;
	HeadPosY.dy = 32;

	//=========== ALLEGRO VARIABLE ===========//
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *background;
	ALLEGRO_BITMAP *background_game;
	//ALLEGRO_BITMAP *head_up;
	//ALLEGRO_BITMAP *head_down;
	//ALLEGRO_BITMAP *head_right;
	//ALLEGRO_BITMAP *head_left;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *fps;
	ALLEGRO_FONT *titlesover;
	ALLEGRO_FONT *options_titles;
	ALLEGRO_FONT *setting_titles;
	ALLEGRO_FONT *titles;
	ALLEGRO_FONT *subtitles;
	ALLEGRO_FONT *subtitlesover;

	Sprite head_right;
	Sprite head_left;
	Sprite head_up;
	Sprite head_down;

	if (!al_init())
		return -1;

	//=========== DISPLAY ===========//
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
	al_set_new_display_flags(ALLEGRO_WINDOWED);

	display = al_create_display(Width, Height);

	//=========== ADDON INIT ===========//
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_init_primitives_addon();
	al_create_display;
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();

	//=========== SUBTITLES ===========//
	subtitles = al_load_font("BuxtonSketch.ttf", 40, NULL);
	titles = al_load_font("BuxtonSketch.ttf", 100, NULL);
	setting_titles = al_load_font("BuxtonSketch.ttf", 55, NULL);
	options_titles = al_load_font("BuxtonSketch.ttf", 10, NULL);
	fps = al_load_font("arial.ttf", 13, NULL);
	titlesover = al_load_font("arial.ttf", 70, NULL);
	subtitlesover = al_load_font("arial.ttf", 20, NULL);

	//=========== IMAGES ===========//
	background = al_load_bitmap("tlo1.bmp");
	background_game = al_load_bitmap("tlo_gry.png");
	head_right.image = al_load_bitmap("head_snake_right1.bmp");
	head_left.image = al_load_bitmap("head_snake_left1.bmp");
	head_up.image = al_load_bitmap("head_snake_up1.bmp");
	head_down.image = al_load_bitmap("head_snake_down1.bmp");
	//wall1 = al_load_bitmap("wall1.bmp");
	wall.image = al_load_bitmap("wall.bmp");

	wall.width = al_get_bitmap_width(wall.image);
	wall.height = al_get_bitmap_height(wall.image);

	HeadPosX.dx = HeadPosX.width;
	HeadPosY.dy = HeadPosY.height;

	//=========== MESSAGE ERRORS ===========//
	MessageErrors(display, subtitles, titles, setting_titles, options_titles, fps, background, background_game, head_right.image, InGameSoundInst);

	//=========== TIMER ===========//
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	//=========== AUDIO ===========//
	al_reserve_samples(10);

 	//InGameSound = al_load_sample("ingame1.ogg");
	//EatRed = al_load_sample("eatred.gg");
	//EatMashroom= al_load_sample("changeonred.ogg");
	//GameoverSong = al_load_sample("");
	//CrashSound = al_load_sample("song.ogg");
	//ChangeOnRedSound = al_load_sample("");

	//=========== INGAME ===========//
	InGameSoundInst = al_create_sample_instance(InGameSound);
	al_set_sample_instance_playmode(InGameSoundInst, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(InGameSoundInst, al_get_default_mixer());

	//=========== SONG =========== //
	/*
	SongInst = al_create_sample_instance(Song);
	al_set_sample_instance_playmode(SongInst, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(SongInst, al_get_default_mixer());
	*/
	//=================================//
	//=========== START PROGRAM ===========//
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));


	al_play_sample_instance(InGameSoundInst);
	while (!done)
	{
		al_start_timer(timer);
		TimeGame = al_current_time();
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//=========== INPUT ===========//
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				keys[ESCAPE] = true;
				break;
			case ALLEGRO_KEY_TAB:
				keys[TAB] = true;
				break;
			case ALLEGRO_KEY_ENTER:
				keys[ENTER] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_Q:
				keys[q] = true;
				break;
			case ALLEGRO_KEY_W:
				keys[w] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				break;
			case ALLEGRO_KEY_Z:
				keys[z] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				keys[ESCAPE] = false;
				break;
			case ALLEGRO_KEY_TAB:
				keys[TAB] = false;
				break;
			case ALLEGRO_KEY_ENTER:
				keys[ENTER] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_Q:
				keys[q] = false;
				break;
			case ALLEGRO_KEY_W:
				keys[w] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			case ALLEGRO_KEY_Z:
				keys[z] = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			Return = true;

			frame++;
			if (al_current_time() - GameFPS >= 1)
			{
				TimeGame = al_current_time();
				GameFPS = frame;
				frame = 0;
			}
			if (state == MENU)
			{
				if (keys[ENTER])
					state = PLAY;

				if (keys[ESCAPE])
					done = true;

				if (keys[TAB])
					state = SETTING;
			}
			else if (state == PLAY)
			{
				if (keys[RIGHT] && DirectionSnake != 2)
				{
					DirectionSnake = Right;
					keys[ESCAPE] = false;
				}
				else if (keys[LEFT] && DirectionSnake != 3)
				{
					DirectionSnake = Left;
					keys[ESCAPE] = false;
				}
				else if (keys[DOWN] && DirectionSnake != 0)
				{
					DirectionSnake = Down;
					keys[ESCAPE] = false;
				}
				else if (keys[UP] && DirectionSnake != 1)
				{
					DirectionSnake = Up;
					keys[ESCAPE] = false;
				}
				else if (keys[ESCAPE])
				{
					state = MENU;
					keys[ESCAPE] = false;
				}
				else if (keys[SPACE])
				{
					Sleep(30);
					HeadPosX.x = (Width / 25) * 5;
					HeadPosY.y = (Height / 25) * 5;
					DirectionSnake = Right;
				}

				CollisionWalls();
				if (keys[z])
				{
					bound = true;
				}
				else
				{
					bound = false;
				}
			}
			else if (state == SETTING)
			{
				if (keys[ESCAPE])
				{
					state = MENU;
					keys[ESCAPE] = false;
				}
				if (keys[q])
				{
					al_play_sample_instance(InGameSoundInst);
					keys[ESCAPE] = false;
				}
				if (keys[w])
				{
					al_stop_sample_instance(InGameSoundInst);
					keys[ESCAPE] = false;
				}
				if (keys[RIGHT])
				{
					FPS = 8.0;
					keys[ESCAPE] = false;
				}
				else if (keys[LEFT])
				{
					FPS = 16.0;
					keys[ESCAPE] = false;
				}
				else if (keys[SPACE])
				{
					FPS = 10.0;
					keys[ESCAPE] = false;
				}
				/*
				if (keys[q] && al_stop_sample_instance(SongInst))
				{
						al_play_sample_instance(SongInst);
						keys[ESCAPE] = false;
				}

				if (keys[q] && al_play_sample_instance(SongInst))
				{
					al_stop_sample_instance(SongInst);
					keys[ESCAPE] = false;
				}
				*/
			}
			else if (state == GAMEOVER)
			{
				if (keys[ESCAPE])
				{
					state = MENU;
					keys[ESCAPE] = false;
				}
				if (keys[SPACE])
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));
					HeadPosX.x = (Width / 25) * 5;
					HeadPosY.y = (Height / 25) * 5;
					state = PLAY;
					keys[ESCAPE] = false;
				}
			}
		}
		if (Return && al_is_event_queue_empty(event_queue))
		{
			Return = false;

			if (state == MENU)
			{
				Collision = false;
				HeadPosX.x = (Width / 25) * 5;
				HeadPosY.y = (Height / 25) * 5;
				DirectionSnake = Right;
				MenuScene(background, titles, subtitles, options_titles, x, y);
			}
			else if (state == PLAY)
			{
				PlayScene(background_game, x, y, head_right.image, head_left.image, head_up.image, head_down.image, fps, GameFPS, Speed);
				if (Collision)
				{
					state = GAMEOVER;
				}
			}
			else if (state == GAMEOVER)
			{
				Collision = false;
				DirectionSnake = Right;
				al_stop_sample_instance(InGameSoundInst);
				GameoverScene(titlesover, subtitlesover);
			}
			else if (state = SETTING)
			{
				SettingScene(background, setting_titles, options_titles, subtitles, x, y);
			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}
	al_destroy_sample_instance(InGameSoundInst);
	al_destroy_sample(CrashSound);
	al_destroy_sample(Song);
	al_destroy_sample(GameoverSong);
	al_destroy_sample(ChangeOnRedSound);
	al_destroy_sample(EatRed);
	al_destroy_sample(EatMashroom);
	al_destroy_font(fps);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_bitmap(background);
	al_destroy_bitmap(background_game);
	al_destroy_bitmap(head_down.image);
	al_destroy_bitmap(head_up.image);
	al_destroy_bitmap(head_right.image);
	al_destroy_bitmap(head_left.image);
	al_destroy_bitmap(wall.image);
	al_destroy_display(display);

	return 0;
}

void MenuScene(ALLEGRO_BITMAP *background, ALLEGRO_FONT *titles, ALLEGRO_FONT *subtitles, ALLEGRO_FONT *options_titles, int x, int y)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background, x, y, 0);
	al_draw_textf(titles, al_map_rgb(0, 0, 0), Width / 2, Height / 4.5, ALLEGRO_ALIGN_CENTRE, "SNAKE !"); 
	al_draw_textf(subtitles, al_map_rgb(0, 0, 0), 400, Height / 2 + 50, ALLEGRO_ALIGN_CENTRE, "Nowa gra");
	al_draw_textf(subtitles, al_map_rgb(0, 0, 0), 400, Height / 2 + 100, ALLEGRO_ALIGN_CENTRE, "Ustawienia");
	al_draw_textf(subtitles, al_map_rgb(0, 0, 0), 400, Height / 2 + 150, ALLEGRO_ALIGN_CENTRE, "Zamknij gre");
	al_draw_textf(options_titles, al_map_rgb(0, 0, 0), 495, Height / 2 + 70, ALLEGRO_ALIGN_CENTRE, "[ENTER]");
	al_draw_textf(options_titles, al_map_rgb(0, 0, 0), 495, Height / 2 + 120, ALLEGRO_ALIGN_CENTRE, "[TAB]");
	al_draw_textf(options_titles, al_map_rgb(0, 0, 0), 495, Height / 2 + 170, ALLEGRO_ALIGN_CENTRE, "[ESC]");
	al_flip_display();
}

void PlayScene(ALLEGRO_BITMAP *background_game, int x, int y, ALLEGRO_BITMAP *right, ALLEGRO_BITMAP *left, ALLEGRO_BITMAP *up, ALLEGRO_BITMAP *down, ALLEGRO_FONT *fps, int GameFPS, int Speed)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//al_draw_bitmap(background_game, x, y, 0);
	//al_draw_bitmap(wall.image, wall.width / 2, wall.height / 2, NULL);
	//al_draw_bitmap(wall.image, wall.width, wall.height, NULL);
	int lineSpace = 32;
	for (size_t i = 1; i < 25; i++)
	{
		al_draw_line(i*lineSpace, 0, i*lineSpace, 800, al_map_rgb(0, 255, 255), NULL);
		al_flip_display();
		al_draw_line(0, i*lineSpace, 800, i*lineSpace, al_map_rgb(0, 255, 255), NULL);
		al_flip_display();
	}
	Walls();
	//al_draw_bitmap(wall.image, wall.width, wall.height*6, NULL);
	//Developer();
	GameRun(right, left, up, down, fps, GameFPS, Speed);	
}

void GameoverScene(ALLEGRO_FONT *titlesover, ALLEGRO_FONT *subtitlesover)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_textf(titlesover, al_map_rgb(255, 0, 255), Width / 2, Height / 4.5, ALLEGRO_ALIGN_CENTRE, "GAMEOVER");
	al_draw_textf(subtitlesover, al_map_rgb(255, 0, 255), Width /2, Height - 150, ALLEGRO_ALIGN_CENTRE, "Wcisnij [ESC] aby wejsc do Menu lub Spacje aby zagrac ponownie.");
	al_flip_display();
}

void SettingScene(ALLEGRO_BITMAP *background, ALLEGRO_FONT *setting_titles, ALLEGRO_FONT *options_titles, ALLEGRO_FONT *subtitles, int x, int y)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background, x, y, 0);
	al_draw_textf(setting_titles, al_map_rgb(0, 0, 0), Width / 2, Height / 4.5, ALLEGRO_ALIGN_CENTRE, "Ustawienia");
	al_draw_textf(subtitles, al_map_rgb(0, 0, 0), 250, Height / 2 + 50, ALLEGRO_ALIGN_CENTRE, "Dzwiek: ");
	al_draw_textf(subtitles, al_map_rgb(0, 0, 0), 400, Height / 2 + 50, ALLEGRO_ALIGN_CENTRE, "ON");
	al_draw_textf(subtitles, al_map_rgb(0, 0, 0), 500, Height / 2 + 50, ALLEGRO_ALIGN_CENTRE, "OFF");
	al_draw_textf(options_titles, al_map_rgb(0, 0, 0), 435, Height / 2 + 65, ALLEGRO_ALIGN_CENTRE, "[Q]");
	al_draw_textf(options_titles, al_map_rgb(0, 0, 0), 543, Height / 2 + 65, ALLEGRO_ALIGN_CENTRE, "[W]");
	al_draw_textf(subtitles, al_map_rgb(0, 0, 0), 330, Height / 2 + 150, ALLEGRO_ALIGN_CENTRE, "Predkosc:        <       >");
	al_draw_textf(options_titles, al_map_rgb(0, 0, 0), 400, Height / 2 + 190, ALLEGRO_ALIGN_CENTER, "mniejsza");
	al_draw_textf(options_titles, al_map_rgb(0, 0, 0), 480, Height / 2 + 190, ALLEGRO_ALIGN_CENTER, "wieksza");
	//al_draw_textf()
	al_flip_display();
}

void GameRun(ALLEGRO_BITMAP *right, ALLEGRO_BITMAP *left, ALLEGRO_BITMAP *up, ALLEGRO_BITMAP *down, ALLEGRO_FONT *fps, int GameFPS, int Speed)
{
	al_draw_textf(fps, al_map_rgb(100, 0, 100), 5, 5, 0, "FPS: %d", GameFPS);
	finish = true;
	DirectionMove(right, left, up, down, Speed);
}

void DirectionMove(ALLEGRO_BITMAP *right, ALLEGRO_BITMAP *left, ALLEGRO_BITMAP *up, ALLEGRO_BITMAP *down, int Speed)
{
	int HeadXNow = 0;
	int HeadYNow = 0;
	int HeadPosNowX = 0;
	int HeadPosNowY = 0;
	
	switch (DirectionSnake)
	{
		case Right:
		{
			HeadPosNowX = HeadPosX.x;
			HeadXNow = HeadPosNowX + mapW;
			if (HeadPosNowX > 767)
			{
				//HeadXNow = 0;
				Collision = true;
			}
			HeadPosX.x = HeadXNow;
			al_draw_bitmap(right, HeadPosX.x, HeadPosY.y, 0);
		}
			break;
		case Left:
		{
			HeadPosNowX = HeadPosX.x;
			HeadXNow = HeadPosNowX - mapW;
			if (HeadPosNowX < 0)
			{
				//HeadXNow = 767;
				Collision = true;
			}
			HeadPosX.x = HeadXNow;
			al_draw_bitmap(left, HeadPosX.x, HeadPosY.y, 0);
		}
			break;
		case Up:
		{
			HeadPosNowY = HeadPosY.y;
			HeadYNow = HeadPosNowY - mapH;
			if (HeadPosNowY < 0)
			{
				//HeadYNow = 576;
				Collision = true;
			}
			HeadPosY.y = HeadYNow;
			al_draw_bitmap(up, HeadPosX.x, HeadPosY.y, 0);
		}
			break;
		case Down:
		{
			HeadPosNowY = HeadPosY.y;
			HeadYNow = HeadPosNowY + mapH;
			if (HeadPosNowY > 767)
			{
				//HeadYNow = 0;
				Collision = true;
			}
			HeadPosY.y = HeadYNow;
			al_draw_bitmap(down, HeadPosX.x, HeadPosY.y, 0);
		}			
			break;
		default:
			break;
	}
}

void Developer()
{
	int lineSpace = 32;
	for (size_t i = 1; i < 25; i++)
	{
		al_draw_line(i*lineSpace, 0, i*lineSpace, 800, al_map_rgb(0, 255, 255), NULL);
		al_flip_display();
		al_draw_line(0, i*lineSpace, 800, i*lineSpace, al_map_rgb(0, 255, 255), NULL);
		al_flip_display();
	}
}

void Walls()
{
	al_draw_bitmap(wall.image, wall.width * 10, wall.height * 1, NULL);
	al_draw_bitmap(wall.image, wall.width * 9, wall.height * 8, NULL);
	al_draw_bitmap(wall.image, wall.width * 9, wall.height * 12, NULL);
	al_draw_bitmap(wall.image, wall.width * 15, wall.height * 8, NULL);
	al_draw_bitmap(wall.image, wall.width * 15, wall.height * 12, NULL);
	al_draw_bitmap(wall.image, wall.width * 5, wall.height * 7, NULL);
	al_draw_bitmap(wall.image, wall.width * 20, wall.height * 20, NULL);
	al_draw_bitmap(wall.image, wall.width * 20, wall.height * 5, NULL);
	al_draw_bitmap(wall.image, wall.width * 5, wall.height * 20, NULL);
	al_draw_bitmap(wall.image, wall.width * 18, wall.height * 5, NULL);
	al_draw_bitmap(wall.image, wall.width * 2, wall.height * 2, NULL);
	al_draw_bitmap(wall.image, wall.width * 3, wall.height * 17, NULL);
	al_draw_bitmap(wall.image, wall.width * 16, wall.height * 16, NULL);
	al_draw_bitmap(wall.image, wall.width * 7, wall.height * 17, NULL);
}

//void DirectionByWall()
//{
//	if()
//}

void Food()
{
	int x = 0;
	int y = 0;
	do
	{
		// Generate random x and y values within the map
		x = rand() % (mapW - 2) + 1;
		y = rand() % (mapH - 2) + 1;

		// If location is not free try again
	} while (Map[x + y * mapW] != 0);

	// Place new food
	//Map[x + y * mapW] = -2;
}

void CollisionWalls()
{
	int Collision1 = (
		(HeadPosX.x < wall.x * 10) &&
		(HeadPosX.x + 32 > wall.x * 10) &&
		(HeadPosY.y < wall.y * 2) &&
		(HeadPosY.y + 32 > wall.y));

	int Collision2 = (
		(HeadPosX.x < wall.x * 9) &&
		(HeadPosX.x + 32 > wall.x * 9) &&
		(HeadPosY.y < wall.y * 9) &&
		(HeadPosY.y + 32 > wall.y * 8));

	int Collision3 = (
		(HeadPosX.x < wall.x * 9) &&
		(HeadPosX.x + 32 > wall.x * 9) &&
		(HeadPosY.y < wall.y * 13) &&
		(HeadPosY.y + 32 > wall.y * 12));

	int Collision4 = (
		(HeadPosX.x < wall.x * 15) &&
		(HeadPosX.x + 32 > wall.x * 15) &&
		(HeadPosY.y < wall.y * 9) &&
		(HeadPosY.y + 32 > wall.y * 8));

	int Collision5 = (
		(HeadPosX.x < wall.x * 15) &&
		(HeadPosX.x + 32 > wall.x * 15) &&
		(HeadPosY.y < wall.y * 13) &&
		(HeadPosY.y + 32 > wall.y * 12));

	int Collision6 = (
		(HeadPosX.x < wall.x * 5) &&
		(HeadPosX.x + 32 > wall.x * 5) &&
		(HeadPosY.y < wall.y * 8) &&
		(HeadPosY.y + 32 > wall.y * 7));

	int Collision7 = (
		(HeadPosX.x < wall.x * 20) &&
		(HeadPosX.x + 32 > wall.x * 20) &&
		(HeadPosY.y < wall.y * 21) &&
		(HeadPosY.y + 32 > wall.y * 20));

	int Collision8 = (
		(HeadPosX.x < wall.x * 20) &&
		(HeadPosX.x + 32 > wall.x * 20) &&
		(HeadPosY.y < wall.y * 6) &&
		(HeadPosY.y + 32 > wall.y * 5));

	int Collision9 = (
		(HeadPosX.x < wall.x * 5) &&
		(HeadPosX.x + 32 > wall.x * 5) &&
		(HeadPosY.y < wall.y * 21) &&
		(HeadPosY.y + 32 > wall.y * 20));

	int Collision10 = (
		(HeadPosX.x < wall.x * 18) &&
		(HeadPosX.x + 32 > wall.x * 18) &&
		(HeadPosY.y < wall.y * 6) &&
		(HeadPosY.y + 32 > wall.y * 5));

	int Collision11 = (
		(HeadPosX.x < wall.x * 2) &&
		(HeadPosX.x + 32 > wall.x * 2) &&
		(HeadPosY.y < wall.y * 3) &&
		(HeadPosY.y + 32 > wall.y * 2));

	int Collision12 = (
		(HeadPosX.x < wall.x * 3) &&
		(HeadPosX.x + 32 > wall.x * 3) &&
		(HeadPosY.y < wall.y * 18) &&
		(HeadPosY.y + 32 > wall.y * 17));

	int Collision13 = (
		(HeadPosX.x < wall.x * 16) &&
		(HeadPosX.x + 32 > wall.x * 16) &&
		(HeadPosY.y < wall.y * 17) &&
		(HeadPosY.y + 32 > wall.y * 16));

	int Collision14 = (
		(HeadPosX.x < wall.x * 7) &&
		(HeadPosX.x + 32 > wall.x * 7) &&
		(HeadPosY.y < wall.y * 18) &&
		(HeadPosY.y + 32 > wall.y * 17));

	if (Collision1 || Collision2 || Collision3 ||
		Collision4 || Collision5 || Collision6 ||
		Collision7 || Collision8 || Collision9 || 
		Collision10 || Collision11 || Collision12 || 
		Collision13 || Collision14)
	{
		Collision = true;
		state = GAMEOVER;
	}
	else
	{
		Collision = false;
	}
}