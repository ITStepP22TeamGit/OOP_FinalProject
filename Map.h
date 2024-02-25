#pragma once

#include<iostream>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include<math.h>
#include<string>
#include"TourException.h"
using namespace std;

class Map
{
protected:
	int length;
	int width;
	vector<int>x;
	vector<int>y;
	vector<string>name;
public:
	Map(int _length, int _width);
	void addPoint(int _x, int _y, string _name);
	void delPoint(int index);
	void delPoint(int _x, int _y);
	void delPoint(string _name);
	void show()const;
	float calcDistance(int index1, int index2)const;

	void showPoints()const;
};