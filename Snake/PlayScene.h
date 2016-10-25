#pragma once
#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include "Walls.h"

void playScene(ALLEGRO_BITMAP *background_game, int x, int y)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background_game, x, y, 0);
}

#endif // !PLAYSCENE
