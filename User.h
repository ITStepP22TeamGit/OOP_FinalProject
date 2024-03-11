#pragma once
#include <iostream>
#include <string>
#include "Hotel.h"
#include "TourArr.h"
#include "FoodService.h"
#include"Accomodation.h"
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
	//vector<Hotel> HArr;
	Accomodation HArr;
	float totalPriceTour = 0;
	float totalPriceRestaurant = 0;
	float totalPriceHotel = 0;
public:
	User() {
		isAdmin = 0;
		totalPriceTour = 0;
		totalPriceRestaurant = 0;
		totalPriceHotel = 0;
		login = "login";
		password = "password";
		userName = "un";
		userPhone = "up";
	}

	~User() {
	}

	void showMiniVertoZilla() {
		system("cls");
		cout << " \n\n";
		cout << "  ____   ____                __         __________.__ .__   .__           \n";
		cout << "  \\   \\ /   / ____ _______ _/  |_  ____ \\____    /|__||  |  |  |  _____   \n";
		cout << "   \\   Y   /_/ __ \\\\_  __ \\\\   __\\/  _ \\  /     / |  ||  |  |  |  \\__  \\  \n";
		cout << "    \\     / \\  ___/ |  | \\/ |  | (  <_> )/     /_ |  ||  |__|  |__ / __ \\_\n";
		cout << "     \\___/   \\___  >|__|    |__|  \\____//_______ \\|__||____/|____/(____  /\n";
		cout << "                 \\/                             \\/                     \\/ \n\n\n";

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
	string getUserName()const {
		return userName;
	}
	string getUserPhone()const {
		return userPhone;
	}

	void saveUserToFile(ofstream& file) {
		file << login << endl;
		file << password << endl;
		file << isAdmin << endl;
		file << userName << endl;
		file << userPhone << endl;
		fArr.saveFoodServicesToFile(file);
		try {
			TArr.saveToFile(file);
		}
		catch (TourArrayException* err) { err->message(); delete err; }
		file << "#Init#\n";
		for (int i = 0; i < HArr.size(); i++) {
			HArr.saveInfo(file);
		}
	}

	void loadFromUserFile(ifstream& file) {
		file.ignore();
		getline(file, login);
		getline(file, password);
		file >> isAdmin;
		file.ignore();
		getline(file, userName);
		getline(file, userPhone);
		fArr.loadFoodServicesFromFile(file);
		try {
			TArr.loadFromFile(file);
		}
		catch (TourArrayException* err) { err->message(); delete err; }
		//cout << TArr.getVectotSize();
		
		/*string str1;
		file >> str1;*/
		
		string str;
		file >> str;
		for (int i = 0; i < HArr.size(); i++) {
			HArr.loadInfo(file);
		}
	}

	void addHotel(Hotel obj) {
		HArr.addHotel(obj);
	}
	
	void addTour(Tour* obj) {
		try {
			if (obj->TourType() == "Safari") {
				//Safari* b = static_cast<Safari*>(obj);
				/*Safari c;
				c = *static_cast<Safari*>(obj);
				Tour* d = &c;
				TArr.addTour(d);*/
				Safari* b = static_cast<Safari*>(obj);
				Safari* c = new Safari(*b); // Create a new Safari object on the heap
				c->askClient();
				TArr.addTour(c);
			}
			else if (obj->TourType() == "Sightseeing") {
				Sightseeing* b = static_cast<Sightseeing*>(obj);
				Sightseeing* c = new Sightseeing(*b);
				c->askClient();
				TArr.addTour(c);
			}
			else if (obj->TourType() == "BeachTour") {
				BeachTour* b = static_cast<BeachTour*>(obj);
				BeachTour* c = new BeachTour(*b);
				c->askClient();
				TArr.addTour(c);
			}
			else if (obj->TourType() == "YachtTour") {
				YachtTour* b = static_cast<YachtTour*>(obj);
				YachtTour* c = new YachtTour(*b);
				c->askClient();
				TArr.addTour(c);
			}
			else if (obj->TourType() == "Excursion") {
				Excursion* b = static_cast<Excursion*>(obj);
				Excursion* c = new Excursion(*b);
				c->askClient();
				TArr.addTour(c);
			}
			else if (obj->TourType() == "HikingTour") {
				HikingTour* b = static_cast<HikingTour*>(obj);
				HikingTour* c = new HikingTour(*b);
				c->askClient();
				TArr.addTour(c);
			}
			else if (obj->TourType() == "HelicopterFlightTour") {
				HelicopterFlightTour* b = static_cast<HelicopterFlightTour*>(obj);
				HelicopterFlightTour* c = new HelicopterFlightTour(*b);
				c->askClient();
				TArr.addTour(c);
			}
			else if (obj->TourType() == "GastroTour") {
				GastroTour* b = static_cast<GastroTour*>(obj);
				GastroTour* c = new GastroTour(*b);
				c->askClient();
				TArr.addTour(c);
			}
		}
		catch (TourArrayException* err) { err->message(); delete err; }
		//obj->TourType();
		
		//TArr.addTour(obj);
		//if (obj->TourType() == "Safari") {
		//	Safari* b = ((Safari*)& obj);
		//	cout << "\n\n\n\n\n";
		//	cout << b->TourType();
		//	TArr.addTour(b);
		////	//TArr.addTour(new Sightseeing(obj->getName(), obj->getAddress(), obj->getDescription(), obj->getDate(), obj->getTime(), obj->getRating(), obj->getPrice(), obj->getPhotosPrice(), obj->getGuide(), obj->getNumber(), obj->getMinNumber(), obj->getMaxNumber()));
		//}
	}
	/*if (obj->TourType() == "Safari") {
			Safari obj1 = obj;
			TArr.addTour(&obj1);
		}*/
	void addFoodService(Food* obj) {
		//fArr.addFoodService(obj);
		if (obj->type() == "CAFE") {
			Cafe* b = static_cast<Cafe*>(obj);
			Cafe* c = new Cafe(*b);
			fArr.addFoodService(c);
		}
		if (obj->type() == "CANTEEN") {
			Canteen* b = static_cast<Canteen*>(obj);
			Canteen* c = new Canteen(*b);
			if (c->askClientBanquet()) {
				totalPriceRestaurant += 25;
			}
			fArr.addFoodService(c);
		}
		if (obj->type() == "RESTARAUNT") {
			Restaraunt* b = static_cast<Restaraunt*>(obj);
			Restaraunt* c = new Restaraunt(*b);
			if (c->askClientBanquet()) {
				totalPriceRestaurant += 25;
			}
			fArr.addFoodService(c);
		}
	}

	void showUser() {
		int menu;
		do
		{
			system("cls");
			showMiniVertoZilla();
			cout << " ======================= Hello, " << userName << "! ======================== >\n";
			cout << "|   Login: " << login << endl;
			cout << "|   Password: ";
			for (int i = 0; i < password.size(); i++)
			{
				cout << "*";
			}
			cout << endl;
			cout << "|   Phone number: " << userPhone << endl;
			cout << "|\n|   Choose an action:\n";
			cout << "|   1. Show my purchases.\n";
			cout << "|   2. Cancel a purchase.\n";
			cout << "|   3. Edit my profile.\n";
			cout << "|   0. Exit.\n";
			cout << "\n > > > ";
			cin >> menu;
			switch (menu)
			{
			case 1:
			{
				system("cls");
				showMiniVertoZilla();
				int menu1;
				cout << "|   Select a purchase to see:\n";
				cout << "|   1. Show hotels.\n";
				cout << "|   2. Show food services.\n";
				cout << "|   3. Show tours.\n";
				cout << "\n > > > ";
				cin >> menu1;
				switch (menu1)
				{
				case 1:
					system("cls");
					showMiniVertoZilla();
					if (HArr.size() == 0) {
						cout << "|   There are no hotels, at lest for now.\n";
					}
					else {
						HArr.showHotelForClients();
					}
					break;
				case 2:
					system("cls");
					showMiniVertoZilla();
					fArr.showFoodServices(1);
					system("pause");
					break;
				case 3:
					system("cls");
					showMiniVertoZilla();
					try {
						TArr.showTourArrClients();
					}
					catch (TourArrayException* err) { err->message(); delete err; }
					break;
				default:
					//exception
					cout << "|   Input error!\n";
					break;
				}
				break;
			}
			case 2:
			{
				system("cls");
				showMiniVertoZilla();
				int menu1;
				cout << "|   Select a purchase to cancel:\n";
				cout << "|   1. Cancel a hotel.\n";
				cout << "|   2. Cancel a food service.\n";
				cout << "|   3. Cancel a tour.\n";
				cout << "\n > > > ";
				cin >> menu1;
				switch (menu1)
				{
				case 1:
					break;
				case 2:
				{
					int intVarFood = fArr.showFoodServices();
					if (intVarFood == -1) {
						return;
					}
					fArr.delFoodService(intVarFood);
					break;
				}
				case 3:
				{
					int intVarTour = TArr.showAllForClientOrder();
					if (intVarTour == -1) {
						return;
					}
					TArr.delTour(intVarTour);
					break;
				}
				default:
					break;
				}
				break;
			}
			case 3:
			{
				system("cls");
				showMiniVertoZilla();
				int menu1;
				cout << "|   Select an option to edit:\n";
				cout << "|   1. Name.\n";
				cout << "|   2. Password.\n";
				cout << "|   3. Phone number.\n";
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
				cout << "|   Input error!\n";
				break;
			}
		} while (menu != 0);
	}
};

