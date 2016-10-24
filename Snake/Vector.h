#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Position
{
	int x;
	int y;

	Position()
	{
		x = 0;
		y = 0;
	}

	Position(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

struct MyVector
{
private:
	Position* data;
	unsigned int iterator = 0;
	unsigned int amount = 0;

public:
	//Struct default constructor. It's set to 517 elements
	MyVector()
	{
		data = (Position*)calloc(517, sizeof(Position));
		iterator = amount = 517;
	}

	//Struct constructor. Argument sets amount of elements
	MyVector(unsigned int i)
	{
		iterator = amount = i;
		data = (Position*)calloc(amount, sizeof(Position));
	}

	~MyVector()
	{
		free(data);
	}

	//if neccesary adds more elements
	void push_back(Position input)
	{
		if (iterator < amount)
		{
			data[iterator] = input;
		}
		else
		{
			amount += 10;
			data = (Position*)realloc(data, amount * sizeof(Position));
			data[iterator] = input;
		}
		iterator++;
	}

	//Returns element of type Position and deletes last element
	Position pop()
	{
		iterator--;
		return data[amount -= 1];
	};

	//Proxy for operations like vec[10].x = ... | vec[10] = Position(int, int)
	struct Proxy
	{
	private:
		Position &pos;
	public:
		int &x, &y;
		void operator = (const Position pos)
		{
			this->pos = pos;
		}
		Proxy(Position &pos) : pos(pos), x(pos.x), y(pos.y) {}
	};

	// Proxy operator[] for operations like vec[10].x = ... | vec[10] = Position(int, int)
	Proxy operator [] (unsigned int i)
	{
		return Proxy(data[i]);
	}

	unsigned int size()
	{
		return amount;
	}
};
