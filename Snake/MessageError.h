#pragma once
#ifndef MESSAGE_ERROR_H
#define MESSAGE_ERROR_H

int messageErrors(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *subtitles, ALLEGRO_FONT *titles, ALLEGRO_FONT *setting_titles, 
	ALLEGRO_FONT *options_titles, ALLEGRO_FONT *fps, ALLEGRO_BITMAP *background, ALLEGRO_BITMAP *background_game, 
	ALLEGRO_BITMAP *head_right, ALLEGRO_SAMPLE_INSTANCE *InGameSound)
{

	if (!al_install_audio()) 
	{
		fprintf(stderr, "Error: failed to initialize audio!\n");
		return -1;
	}
	if (!al_init())
	{
		fprintf(stderr, "Error: failed to initialize al_init!\n");
		return -1;
	}
	if (!display)
	{
		fprintf(stderr, "Error: Cannot create display!\n");
		return -1;
	}
	if (!al_init_font_addon)
	{
		fprintf(stderr, "Error: failed to initialize al_init_font_addon!\n");
		return -1;
	}
	if (!al_init_ttf_addon())
	{
		fprintf(stderr, "Error: failed to initialize al_init_ttf_addon!\n");
		return -1;
	}
	if (!al_install_keyboard())
	{
		fprintf(stderr, "Error: failed to initialize al_install_keyboard!\n");
		return -1;
	}
	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "Error: failed to initialize al_init_primitives_addon!\n");
		return -1;
	}
	if (!al_create_display)
	{
		fprintf(stderr, "Error: Cannot create display!\n");
		return -1;
	}
	if (!al_init_acodec_addon())
	{
		fprintf(stderr, "Error: failed to initialize al_init_acodec_addon!\n");
		return -1;
	}
	if (!subtitles)
	{
		fprintf(stderr, "Error: Not found file BuxtonSketch.ttf!\n");
		return -1;
	}
	if (!titles)
	{
		fprintf(stderr, "Error: Not found file BuxtonSketch.ttf!\n");
		return -1;
	}
	if (!setting_titles)
	{
		fprintf(stderr, "Error: Not found file BuxtonSketch.ttf!\n");
		return -1;
	}
	if (!options_titles)
	{
		fprintf(stderr, "Error: Not found file BuxtonSketch.ttf!\n");
		return -1;
	}
	if (!fps)
	{
		fprintf(stderr, "Error: Not found file arial.ttf!\n");
		return -1;
	}
	if (!background)
	{
		fprintf(stderr, "Error: Not found file background!\n");
		return -1;
	}
	if (!background_game)
	{
		fprintf(stderr, "Error: Not found file background_game!\n");
		return -1;
	}
	if (!head_right)
	{
		fprintf(stderr, "Error: Not found file head_right!\n");
		return -1;
	}
	if (!InGameSound)
	{
		fprintf(stderr, "Error: Not found file InGameSound!\n");
		return -1;
	}
}

#endif // !MessageError.h