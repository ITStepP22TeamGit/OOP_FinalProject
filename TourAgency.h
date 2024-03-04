#pragma once
#include <iostream>
#include <string>
#include "Hotel.h"
#include "TourArr.h"
#include "FoodService.h"
#include "UserException.h"
#include "User.h"
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
	vector<User> users;
public:
	TourAgency(string name) { setName(name); /*full load as function*/ display(); }
	~TourAgency() {}

	void setName(string _name) {}
	string getName()const { return name; }

	void loadAllInfo() {}

	void display() {
		int chooseTmp;
		//сделать запрос гость или пользователь
		if (loggedIn == -1) {
			int menu;
			do {
				system("cls");
				cout << "Welcome to our Tour Agency: " + name + "!\n";
				cout << "If you have account please Log In,\n";
				cout << "Otherwise Sign In\n";
				cout << "1. Log In" << endl;
				cout << "2. Sign In" << endl;
				cout << "0 - EXIT" << endl;
				cin >> menu;
				string tmpStr;
				switch (menu)
				{
				case 1:
					//Exception empty users
					cout << "Input login: ";
					cin >> tmpStr;
					for (int i = 0; i < users.size(); i++) {
						if (tmpStr == users[i].getLogin()) {
							cout << "Input password: ";
							cin >> tmpStr;
							if (tmpStr == users[i].getPassword()) {
								loggedIn = i;
								cout << "Successfully logged in!" << endl;
								menu = 0;
								break;
							}
							else {
								cout << "Incorrect password! Please check yourself.\n";
							}
						}
					}
					if (loggedIn == -1) cout << "Incorrect login! There are no users with that login!\n";
					break;
				case 2:
					cout << "Input login: ";
					cin >> tmpStr;
					for (int i = 0; i < users.size(); i++) {
						if (tmpStr == users[i].getLogin()) {
							//Exception equal login
						}
					}
					users.push_back(User());
					users[users.size()].setLogin(tmpStr);
					cout << "Input password: ";
					cin >> tmpStr;
					users[users.size()].setPassword(tmpStr);
					cout << "Input name: ";
					cin >> tmpStr;
					users[users.size()].setUserName(tmpStr);
					cout << "Input phone number";
					cin >> tmpStr;
					users[users.size()].setUserPhone(tmpStr);
					cout << "Successfully signed in!\n";
					loggedIn = users.size();
					/*bool login(db * arr, int arr_sz, char* log, char* pss) {

						for (int i = 0; i < arr_sz; i++)
						{
							if (strcmp(log, arr[i].login.str) >= 0)
							{
								if (strcmp(pss, arr[i].password.str) >= 0)
								{
									cout << "Loged In!\n";
									return true; break;
								}
							}
						}
						cout << "Error";
						return false;
					}*/

				default:
					break;
				}
			} while (menu != 0);
		}
		if (loggedIn > -1) {
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
	}

	//void compareUsersLogins
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
		