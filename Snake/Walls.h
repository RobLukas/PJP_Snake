#pragma once
#ifndef WALLS_H
#define WALLS_H
//
//void Walls(ALLEGRO_BITMAP *image, int width, int height, Sprite wall)
//{
//	al_draw_bitmap(wall.image, wall.width * 10, wall.height * 1, NULL);
//	al_draw_bitmap(wall.image, wall.width * 9, wall.height * 8, NULL);
//	al_draw_bitmap(wall.image, wall.width * 9, wall.height * 12, NULL);
//	al_draw_bitmap(wall.image, wall.width * 15, wall.height * 8, NULL);
//	al_draw_bitmap(wall.image, wall.width * 15, wall.height * 12, NULL);
//	al_draw_bitmap(wall.image, wall.width * 5, wall.height * 7, NULL);
//	al_draw_bitmap(wall.image, wall.width * 20, wall.height * 20, NULL);
//	al_draw_bitmap(wall.image, wall.width * 20, wall.height * 5, NULL);
//	al_draw_bitmap(wall.image, wall.width * 5, wall.height * 20, NULL);
//	al_draw_bitmap(wall.image, wall.width * 18, wall.height * 5, NULL);
//	al_draw_bitmap(wall.image, wall.width * 2, wall.height * 2, NULL);
//	al_draw_bitmap(wall.image, wall.width * 3, wall.height * 17, NULL);
//	al_draw_bitmap(wall.image, wall.width * 16, wall.height * 16, NULL);
//	al_draw_bitmap(wall.image, wall.width * 7, wall.height * 17, NULL);
//}
//
//void CollisionWalls()
//{
//	int Collision1 = (
//		(HeadPosition.x < wall.width * 11) &&
//		(HeadPosition.x + 32 > wall.width * 10) &&
//		(HeadPosition.y < wall.height * 2) &&
//		(HeadPosition.y + 32 > wall.height));
//
//	int Collision2 = (
//		(HeadPosition.x < wall.width * 10) &&
//		(HeadPosition.x + 32 > wall.width * 9) &&
//		(HeadPosition.y < wall.height * 9) &&
//		(HeadPosition.y + 32 > wall.height * 8));
//
//	int Collision3 = (
//		(HeadPosition.x < wall.width * 10) &&
//		(HeadPosition.x + 32 > wall.width * 9) &&
//		(HeadPosition.y < wall.height * 13) &&
//		(HeadPosition.y + 32 > wall.height * 12));
//
//	int Collision4 = (
//		(HeadPosition.x < wall.width * 16) &&
//		(HeadPosition.x + 32 > wall.width * 15) &&
//		(HeadPosition.y < wall.height * 9) &&
//		(HeadPosition.y + 32 > wall.height * 8));
//
//	int Collision5 = (
//		(HeadPosition.x < wall.width * 16) &&
//		(HeadPosition.x + 32 > wall.width * 15) &&
//		(HeadPosition.y < wall.height * 13) &&
//		(HeadPosition.y + 32 > wall.height * 12));
//
//	int Collision6 = (
//		(HeadPosition.x < wall.width * 6) &&
//		(HeadPosition.x + 32 > wall.width * 5) &&
//		(HeadPosition.y < wall.height * 8) &&
//		(HeadPosition.y + 32 > wall.height * 7));
//
//	int Collision7 = (
//		(HeadPosition.x < wall.width * 21) &&
//		(HeadPosition.x + 32 > wall.width * 20) &&
//		(HeadPosition.y < wall.height * 21) &&
//		(HeadPosition.y + 32 > wall.height * 20));
//
//	int Collision8 = (
//		(HeadPosition.x < wall.width * 21) &&
//		(HeadPosition.x + 32 > wall.width * 20) &&
//		(HeadPosition.y < wall.height * 6) &&
//		(HeadPosition.y + 32 > wall.height * 5));
//
//	int Collision9 = (
//		(HeadPosition.x < wall.width * 6) &&
//		(HeadPosition.x + 32 > wall.width * 5) &&
//		(HeadPosition.y < wall.height * 21) &&
//		(HeadPosition.y + 32 > wall.height * 20));
//
//	int Collision10 = (
//		(HeadPosition.x < wall.width * 19) &&
//		(HeadPosition.x + 32 > wall.width * 18) &&
//		(HeadPosition.y < wall.height * 6) &&
//		(HeadPosition.y + 32 > wall.height * 5));
//
//	int Collision11 = (
//		(HeadPosition.x < wall.width * 3) &&
//		(HeadPosition.x + 32 > wall.width * 2) &&
//		(HeadPosition.y < wall.height * 3) &&
//		(HeadPosition.y + 32 > wall.height * 2));
//
//	int Collision12 = (
//		(HeadPosition.x < wall.width * 4) &&
//		(HeadPosition.x + 32 > wall.width * 3) &&
//		(HeadPosition.y < wall.height * 18) &&
//		(HeadPosition.y + 32 > wall.height * 17));
//
//	int Collision13 = (
//		(HeadPosition.x < wall.width * 17) &&
//		(HeadPosition.x + 32 > wall.width * 16) &&
//		(HeadPosition.y < wall.height * 17) &&
//		(HeadPosition.y + 32 > wall.height * 16));
//
//	int Collision14 = (
//		(HeadPosition.x < wall.width * 8) &&
//		(HeadPosition.x + 32 > wall.width * 7) &&
//		(HeadPosition.y < wall.height * 18) &&
//		(HeadPosition.y + 32 > wall.height * 17));
//
//	if (Collision1 || Collision2 || Collision3 ||
//		Collision4 || Collision5 || Collision6 ||
//		Collision7 || Collision8 || Collision9 ||
//		Collision10 || Collision11 || Collision12 ||
//		Collision13 || Collision14)
//	{
//		Collision = true;
//		state = GAMEOVER;
//	}
//	else
//	{
//		Collision = false;
//	}
//}
#endif // !WALLS_H
