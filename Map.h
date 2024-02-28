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
	vector<bool>type; //1 - отели - x; 0 - рестораны - o
	//vector<int>hotelIndex;
public:
	Map();
	Map(int _length, int _width);
	void addPoint(int _x, int _y, string _name, bool _type);
	void delPoint(int index);
	void delPoint(int _x, int _y, bool _type);
	void delPoint(string _name);
	void show();
	float calcDistance(int index1, int index2)const;
	float calcDistance(string name1, string name2)const;
};