#pragma once
#ifndef GAME_OVER_SCENE_H
#define GAME_OVER_SCENE_H

void gameOverScene(ALLEGRO_FONT *titlesover, ALLEGRO_FONT *subtitlesover, int Height, int Width, int point)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_textf(titlesover, al_map_rgb(255, 0, 255), Width / 2, Height / 4.5, ALLEGRO_ALIGN_CENTRE, "GAMEOVER");
	al_draw_textf(subtitlesover, al_map_rgb(255, 0, 255), Width / 2, Height - 150, ALLEGRO_ALIGN_CENTRE, "Wcisnij [ESC] aby wejsc do Menu lub Spacje aby zagrac ponownie.");
	al_draw_textf(subtitlesover, al_map_rgb(255, 0, 255), Width / 2, Height / 2.5, ALLEGRO_ALIGN_CENTRE, "Wynik: %d", point);
	al_flip_display();
}

#endif // !GAME_OVER_SCENE_H
