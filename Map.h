#pragma once

#include<iostream>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include<math.h>
#include<string>
#include"TourException.h"
using namespace std;

//âñïîìîãàòåëüíûé êëàññ
class Point {
public:
	int x;
	int y;
	string name;
	bool type; //1 - îòåëè - x; 0 - ðåñòîðàíû - o
	int color;

	Point(int _x, int length, int _y, int width, string _name, bool _type);
	void setX(int _x, int length);
	void setY(int _y, int width);
	void setType(bool _type);
	void setName(string _name);

	//ïåðåãðóçêà îïåðàòîðîâ
	bool operator == (const Point& obj)const&;
	int operator - (const Point& obj)const&;
};

class Map
{
protected:
	//ñ÷åò÷èêè îòåëåé è ðåñòîðàíîâ (íå áîëüøå 14)
	int static staticHotels;
	int static staticRestaurants;

	int length;
	int width;
	vector<Point> arr;
public:
	//êîíñòðóêòîðû
	Map();
	Map(int _length, int _width);
	~Map(){}
	
	//ðàáîòà ñ òî÷êàìè
class Map
{
protected:
	int length;
	int width;
	vector<int>x;
	vector<int>y;
	vector<string>name;
	vector<bool>type; //1 - îòåëè - x; 0 - ðåñòîðàíû - o
	//vector<int>hotelIndex;
public:
	Map();
	Map(int _length, int _width);
	void addPoint(int _x, int _y, string _name, bool _type);
	void delPoint(int index);
	void delPoint(int _x, int _y, bool _type);
	void delPoint(string _name);

	//âûâîä
	void show();
	float calcDistance(int index1, int index2)const;
	float calcDistance(string name1, string name2)const;

	//âñïîìîãàòåëüíûå ôóíêöèè
	void setColors();
	bool checkIsRestaurantInHotel(int index);
	void show();
	float calcDistance(int index1, int index2)const;
	float calcDistance(string name1, string name2)const;
};