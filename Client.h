#pragma once
#include "Date.h"
//#include "Room.h"
class Client
{
protected:
	Date arrive_d;

	string clientName;
	string clientPhone;

	//vector<Room*> arr_r;
	int hotelId;
	int restId;
	int tourId;

public:
	Client() {}
	Client(string clientName="", string clientPhone="") {}

	
};

