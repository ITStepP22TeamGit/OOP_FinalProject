#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
using namespace std;

class Accomodation{
protected:
	static string id;
	int coordX;
	int coordY;
	bool haveRest;
	//vector<Tour*> t_arr;
public:
	Accomodation();
	Accomodation(int X, int Y, bool haveRest);
	~Accomodation();
};