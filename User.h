#pragma once
#include <iostream>
#include <string>
#include "Hotel.h"
#include "TourArr.h"
#include "FoodService.h"
#include "UserException.h"
using namespace std;

class User
{
protected:
	string login;
	string password;
	int isAdmin;			//0 - user; 1 - admin; 2 - host;
	string userName;
	string userPhone;
	FoodService fArr;
	TourArr TArr;
	vector<Hotel> HArr;
	float totalPrice;
public:
	User() {
		isAdmin = 0;
		totalPrice = 0;
		login = "login";
		password = "password";
		userName = "un";
		userPhone = "up";
	}

	void setLogin(string _login) {
		if (_login.empty()) {
			throw new UserStringException();
		}
		login = _login;
	}
	void setPassword(string _password) {
		if (_password.empty()) {
			throw new UserStringException();
		}
		password = _password;
	}
	void setUserName(string _userName) {
		if (_userName.empty()) {
			throw new UserStringException();
		}
		userName = _userName;
	}
	void setUserPhone(string _userPhone) {
		if (_userPhone.empty()) {
			throw new UserStringException();
		}
		userPhone = _userPhone;
	}

	string getLogin() const {
		return login;
	}
	string getPassword() const {
		return password;
	}
	bool getIsAdmin() const {
		return isAdmin;
	}

	void saveUserToFile(ofstream& file) {
		file << login << endl;
		file << password << endl;
		file << isAdmin << endl;
		file << userName << endl;
		file << userPhone << endl;
		fArr.saveFoodServicesToFile("UserArr.txt");
		TArr.saveToFile("UserArr.txt");
		file << "#Init#\n";
		for (int i = 0; i < HArr.size(); i++) {
			HArr[i].saveMainInfo(file);
		}
	}
	
	void addTour(Tour* obj) {
		TArr.addTour(obj);
	}

	void addFoodService(Food* obj) {
		fArr.addFoodService(obj);
	}

	void showUser() {
		cout << "Login: " << login << endl;
		cout << "Name: " << userName << endl;
		cout << endl << "Choose an action:\n";
		int menu;
		cout << "1. Show my purchases.\n";
		cout << "2. Edit my profile.\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			int menu1;
			cout << "Select a purchase to see:\n";
			cout << "1. Show hotels.\n";
			cout << "2. Show food services.\n";
			cout << "3. Show tours.\n";
			cin >> menu1;
			switch (menu1)
			{
			case 1:
				if (HArr.size() == 0) {
					cout << "There are no hotels, at lest for now.\n";
				}
				else {
					for (int i = 0; i < HArr.size(); i++) {
						cout << i + 1 << HArr[i].getAdress() << endl;
						cout << "==============================================\n";
						HArr[i].dispAllRooms();
						cout << "==============================================\n";
					}
					cout << "===============================\n";
				}
				break;
			case 2:
				fArr.showFoodServices();
				break;
			case 3:
				TArr.showAllForClient();
				break;
			default:
				//exception
				cout << "Input error!\n";
				break;
			}
			break;
		}
		case 2:
		{
			int menu1;
			cout << "Select an option to edit:\n";
			cout << "1. Name.\n";
			cout << "2. Password.\n";
			cout << "3. Phone number.\n";
			cin >> menu1;
			switch (menu1)
			{
			case 1:
			{
				string str;
				cout << "Enter new name: ";
				cin.ignore();
				getline(cin, str);
				if (str == userName) {
					//exception
					cout << "It is already your name!\n";
				}
				else {
					setUserName(str);
				}
				break;
			}
			case 2:
			{
				string str;
				cout << "Enter new password: ";
				cin.ignore();
				getline(cin, str);
				if (str == userName) {
					//exception
					cout << "It is already your password!\n";
				}
				else {
					setPassword(str);
				}
				break;
			}
			case 3:
			{
				string str;
				cout << "Enter new phone number: ";
				cin.ignore();
				getline(cin, str);
				if (str == userName) {
					//exception
					cout << "It is already your phone number!\n";
				}
				else {
					setUserPhone(str);
				}
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
	}
};

