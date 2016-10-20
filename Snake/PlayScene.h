#pragma once
#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include "Walls.h"

void playScene(ALLEGRO_BITMAP *background_game, int x, int y)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background_game, x, y, 0);
	/*
	int lineSpace = 32;
	for (size_t i = 1; i < 25; i++)
	{
	al_draw_line(i*lineSpace, 0, i*lineSpace, 800, al_map_rgb(0, 255, 255), NULL);
	al_flip_display();
	al_draw_line(0, i*lineSpace, 800, i*lineSpace, al_map_rgb(0, 255, 255), NULL);
	al_flip_display();
	}
	*/
}

#endif // !PLAYSCENE
