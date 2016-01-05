#ifndef Animation.h
#define Animation

bool finish = false;

void MoveUP()
{
	
}

void MoveDown()
{

}

void MoveRight(ALLEGRO_BITMAP *head_right)
{
	al_draw_tinted_bitmap(head_right, al_map_rgba_f(1, 1, 1, 255), 5, 5, 0);
	switch (!finish)
	{

	default:
		break;
	}
}

void MoveLeft()
{

}


#endif // !Animation.h
