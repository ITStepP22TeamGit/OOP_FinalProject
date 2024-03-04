#pragma once
#include <iostream>
#include <string>
#include "Hotel.h"
#include "TourArr.h"
#include "FoodService.h"
using namespace std;
class TourAgency
{
protected:
	string name;
	vector<Hotel> h_arr;
	FoodService fServ;
	TourArr tour_arr;
	Map map;
	int loggedIn = -1;
	string wayToData;
public:
	TourAgency(string name) { setName(name); /*full load as function*/ display(); }
	~TourAgency() {}

	void setName(string _name) {}
	string getName()const { return name; }

	void loadAllInfo() {}

	void display() {
		int chooseTmp;
		//сделать запрос гость или пользователь
		do {
			cout << "Welcome to Tour agency: " + getName() << endl;
			cout << "===============================\n";
			cout << "1. Show Hotels\n";
			cout << "2. Show Tours\n";
			cout << "3. Show Food Services\n";
			cout << "3. Show Map\n";
			cout << "0. Exit\n";
			cout << "===============================\n";
			cin >> chooseTmp;
			switch (chooseTmp)
			{
			case 0:
				break;
			case 1:
				if (h_arr.size() == 0) {
					cout << "There are no hotels, at lest for now.\n";
				}
				else {
					for (int i = 0; i < h_arr.size(); i++) {
						cout << i + 1 << h_arr[i].getAdress() << endl;
						cout << "==============================================\n";
						h_arr[i].showAval();
						cout << "==============================================\n";
					}
				}
				break;
			case 2:
				tour_arr.showTourArr();
				break;
			case 3:
				fServ.showFoodServices();
				break;
			case 4:
				map.show();
				break;
			default:
				break;
			}
		} while (chooseTmp != 0);
	}
};

//class User
// protected:
// string login
// string password
// bool isAdmin 
// string userName
// string userPhone
// public:
//
		