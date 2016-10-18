#pragma once
#ifndef SETTING_SCENE_H
#define SETTING_SCENE_H

void settingScene(ALLEGRO_BITMAP *background, ALLEGRO_FONT *setting_titles, ALLEGRO_FONT *options_titles, ALLEGRO_FONT *subtitles, int x, int y, int Height, int Width)
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

#endif // !SETTING_SCENE_H
