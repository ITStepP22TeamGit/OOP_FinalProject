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
		for (int i = 0; i < HArr.size(); i++) {
			HArr[i].saveMainInfo("UserArr.txt");
		}
	}
};

