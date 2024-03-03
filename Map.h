#pragma once

#include<iostream>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include<math.h>
#include<string>
#include"TourException.h"
using namespace std;

//��������������� �����
class Point {
public:
	int x;
	int y;
	string name;
	bool type; //1 - ����� - x; 0 - ��������� - o
	int color;

	Point(int _x, int length, int _y, int width, string _name, bool _type);
	void setX(int _x, int length);
	void setY(int _y, int width);
	void setType(bool _type);
	void setName(string _name);

	//���������� ����������
	bool operator == (const Point& obj)const&;
	int operator - (const Point& obj)const&;
};

class Map
{
protected:
	//�������� ������ � ���������� (�� ������ 14)
	int static staticHotels;
	int static staticRestaurants;

	int length;
	int width;
	vector<Point> arr;
public:
	//������������
	Map();
	Map(int _length, int _width);
	~Map(){}
	
	//������ � �������
	void addPoint(int _x, int _y, string _name, bool _type);
	void delPoint(int index);
	void delPoint(int _x, int _y, bool _type);
	void delPoint(string _name);

	//�����
	void show();
	float calcDistance(int index1, int index2)const;
	float calcDistance(string name1, string name2)const;

	//��������������� �������
	void setColors();
	bool checkIsRestaurantInHotel(int index);
};