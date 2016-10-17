#pragma once
#ifndef MENUSCENE_H
#define MENUSCENE_H

void menuScene(ALLEGRO_BITMAP *background, ALLEGRO_FONT *titles, ALLEGRO_FONT *subtitles, ALLEGRO_FONT *options_titles, int x, int y, int Width, int Height)
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

#endif // MENUSCENE_H
