#pragma once
#ifndef RANDOM_PARAMETERS_H
#define RANDOM_PARAMETERS_H
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int random() {
	return 1 + (int)(rand() / (RAND_MAX + 1.0) * 24);
}

int randomParametrs() {
	int positionX[10];
	int positionY[10];
	srand(time(NULL));
	auto arrayLength = end(positionX) - begin(positionX);
	for (int i = 0; i < arrayLength; i++)
	{
		positionY[i] = random();
		positionX[i] = random();
	}
	for (int i = 0; i < arrayLength; i++)
	{
		printf("%d\n", positionX[i]);
		printf("%d\n", positionY[i]);
	}
	return *positionX, *positionY;
}

#endif // !RANDOM_PARAMETERS_H
