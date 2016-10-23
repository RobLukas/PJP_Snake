#pragma once
#ifndef RANDOM_PARAMETERS_H
#define RANDOM_PARAMETERS_H
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int random() {
	return 1 + (int)(rand() / (RAND_MAX + 1.0) * 23);
}

void randomParametersXY(int *pos) {
	for (int i = 0; i < 10; i++)
	{
		pos[i] = random();
	}
}

int randomParameters() {
	int positionX[10];
	int positionY[10];
	srand(time(NULL));
	auto arrayLength = end(positionX) - begin(positionX);
	for (int i = 0; i < arrayLength; i++)
	{
		positionX[i] = random();
		positionY[i] = random();
	}
	for (int i = 0; i < arrayLength; i++)
	{
		printf("%d\t", positionX[i]);
		printf("%d\n", positionY[i]);
	}
	return *positionX, *positionY;
}

#endif // !RANDOM_PARAMETERS_H
