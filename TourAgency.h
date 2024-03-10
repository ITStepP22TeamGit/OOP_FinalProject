#pragma once
#include <iostream>
#include <string>
#include "Hotel.h"
#include "Accomodation.h"
#include "FoodService.h"
#include "UserException.h"
#include "User.h"
#include "Windows.h"
using namespace std;
class TourAgency
{
protected:
	string name;
	Accomodation hArr;
	FoodService fServ;
	TourArr tour_arr;
	Map map;
	int loggedIn = -1;
	string wayToData;
	vector<User> users;
	float price;
public:
	TourAgency(string name) { setName(name); price = 0; loadAllInfo(map); displayMain(); }
	~TourAgency() {}

	void setName(string _name) {}
	string getName()const { return name; }

	void loadAllInfo(Map& map) {

		//system("cls");
		//cout << "//";
		//for (int i = 0; i < 100; i++) {
		//	cout << '=';
		//}
		//cout << "\\\\\n";
		//cout << "||";
		////cool loading screen
		//for (int i = 0; i < 100; i++){
		//	cout << 'Ы';
		//	
		//	Sleep(50);
		//}
		//cout << "||\n";
		//cout << "\\\\";
		//for (int i = 0; i < 100; i++) {
		//	cout << '=';
		//}
		//cout << "//\n";

		ifstream file("data/TourAgencyData.txt");
		if (file.is_open()) {
			file >> name;
			file >> loggedIn;
			file >> price;
		}
		else {
			cout << "|  File couldn't open!\n";
		}
		
		tour_arr.loadFromFile("data/TourArray.txt");

		fServ.loadFoodServicesFromFile("TestFoodData.txt", map);

		//Hotels
		hArr.loadInfo("data/hotelData.txt");

		ifstream file1("data/UserData.txt");
		int intVar;
		if (file1.is_open()) {
			file1 >> intVar;
			for (int i = 0; i < intVar; i++)
			{
				User usTmp;
				usTmp.loadFromUserFile(file1);
				users.push_back(usTmp);
			}
			file1.close();
		}
		else {
			cout << "|  File couldn't open!\n";
		}
		
		system("cls");
	}

	void saveAllInfo() {
		//Global Directory URL
		string fileDir = "data/";

		//Hotels

	}

	void displayMain() {
		int chooseTmp;
		string s_choose;

		/*users.push_back(User());
		users[0].setLogin("admin");
		users[0].setPassword("admin");
		users[0].setUserPhone("12344667890");
		users[0].setUserName("admin");
		loggedIn = 0;*/

		do
		{
			if (loggedIn == -1) {
				/*do {
					
				} while (chooseTmp != 0);*/
				cout << "Welcome to Tour agency: " + getName() << endl;
				cout << "===============================\n";
				cout << "1. Show Hotels\n";
				cout << "2. Show Tours\n";
				cout << "3. Show Food Services\n";
				cout << "4. Show Map\n";
				cout << "5. Make an order\n";
				cout << "6. Log in\n";
				cout << "0. Exit\n";
				cout << "===============================\n";
				cin >> chooseTmp;
				switch (chooseTmp)
				{
				case 0:
					break;
				case 1:
					if (hArr.size() == 0) {
						cout << "There are no hotels, at least for now.\n";
					}
					else {
						hArr.showHotelForClients();
					}
					break;
				case 2:
					try {
						tour_arr.showTourArr();
					}
					catch (TourArrayException* err) {
						err->message();
						delete err;
					}
					break;
				case 3:
					fServ.editForClient(true);
					break;
				case 4:
					try
					{
						map.show();
					}
					catch (MapException* err) { cout<<err->message(); delete err; }
					
					break;
				case 5: {
					verification();
					cout << "Input categories on which you wish to make an order: \n";
					cout << "1. Hotel\n";
					cout << "2. Retoraunt\n";
					cout << "3. Tour\n";

					int t_one = 0, t_two = 0, t_tree = 0;
					do
					{
						cout << "Input your choice: ";
						cin.ignore();
						getline(cin, s_choose);
						for (int i = 0; i < s_choose.length(); i++) {
							if (s_choose[i] == '1' || s_choose[i] == '2' || s_choose[i] == '3') {
								int intVar = s_choose[i] - '0';
								switch (intVar)
								{
								case 1:
									t_one = 1;
									break;
								case 2:
									t_two = 1;
									break;
								case 3:
									t_tree = 1;
									break;
								default:
									break;
								}
							}
							// 1 2 3
						}
					} while (t_one == 0 && t_two == 0 && t_tree == 0);
					makeOrder(t_one, t_two, t_tree);
					break;
				}
				case 6:
					verification();
					break;
				default:
					break;
				}
			}
			else {
				cout << "Welcome to Tour agency: " + getName() << endl;
				cout << "===============================\n";
				cout << "1. Show Hotels\n";
				cout << "2. Show Tours\n";
				cout << "3. Show Food Services\n";
				cout << "4. Show Map\n";
				cout << "5. Make an order\n";
				cout << "6. My account\n";
				cout << "7. Log out\n";
				cout << "0. Exit\n";
				cout << "===============================\n";
				cin >> chooseTmp;
				switch (chooseTmp)
				{
				case 0:
					break;
				case 1:
					if (hArr.size() == 0) {
						cout << "There are no hotels, at lest for now.\n";
					}
					else {
						hArr.showHotelForClients();
					}
					break;
				case 2:
					try {
						tour_arr.showAllForClient();
					}
					catch (TourArrayException* err) {
						err->message();
						delete err;
					}
					break;
				case 3:
					fServ.editForClient(true);
					break;
				case 4:
					map.show();
					break;
				case 5: {
					cout << "Input categories on which you wish to make an order: \n";
					cout << "1. Hotel\n";
					cout << "2. Retoraunt\n";
					cout << "3. Tour\n";

					int t_one = 0, t_two = 0, t_tree = 0;
					do
					{
						cout << "Input your choice: ";
						cin.ignore();
						getline(cin, s_choose);
						for (int i = 0; i < s_choose.length(); i++) {
							if (s_choose[i] == '1' || s_choose[i] == '2' || s_choose[i] == '3') {
								int intVar = s_choose[i] - '0';
								switch (intVar)
								{
								case 1:
									t_one = 1;
									break;
								case 2:
									t_two = 1;
									break;
								case 3:
									t_tree = 1;
									break;
								default:
									break;
								}
							}
						}
					} while (t_one == 0 && t_two == 0 && t_tree == 0);
					makeOrder(t_one, t_two, t_tree);
					break;
				}
				case 6:
					users[loggedIn].showUser();
					break;
				case 7:
				{
					string str;
					cout << "Are you sure you want to log out?\n";
					do {
						cout << "Your choice (yes/no) >> ";
						cin >> str;
						cout << endl;
					} while (str != "yes" && str != "no" && str != "Yes" && str != "No"&&str!="y"&&str!="n");
					if (str == "Yes" || str == "yes"||str=="y") {
						users.erase(users.begin() + loggedIn);
						loggedIn = -1;
						cout << "Successfully logged out!\n";;
					}
				}
				default:
					break;
				}
			} 
		}while (chooseTmp != 0);

		ofstream file("data/UserData.txt");
		if (file.is_open()) {
			file << users.size() << endl;
			for (int i = 0; i < users.size(); i++)
			{
				users[i].saveUserToFile(file);
			}
		}
		else {
			cout << "|  File couldn't create!\n";
		}
	}

	//void compareUsersLogins() {}

	void verification() {
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
				{
					cout << "Input login: ";
					cin >> tmpStr;
					for (int i = 0; i < users.size(); i++) {
						if (tmpStr == users[i].getLogin()) {
							//Exception equal login
						}
					}
					User tmpUser;
					tmpUser.setLogin(tmpStr);
					cout << "Input password: ";
					cin >> tmpStr;
					tmpUser.setPassword(tmpStr);
					cout << "Input name: ";
					cin >> tmpStr;
					tmpUser.setUserName(tmpStr);
					cout << "Input phone number: ";
					cin >> tmpStr;
					tmpUser.setUserPhone(tmpStr);
					cout << "Successfully signed in!\n";
					users.push_back(tmpUser);
					loggedIn = users.size() - 1;
					menu = 0;
					
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
				}
				default:
					break;
				}
			} while (menu != 0);
		}
	}

	void makeOrder(bool hotel, bool food, bool tour) {
		if (hotel == 1){
			int hid = 0, rid = 0;
			hArr.showForOrder();
			//two cin for adress and roomid
			//cin date
			//cin term
			//h_arr[hid].addOqqupier();
			price += hArr.calcSumm(hid, rid);
			cout << "Final price: " << price;
		}
		if (tour == 1) {
			int index = tour_arr.showAllForClientOrder();
			if (index == -1) {
				return;
			}
			users[loggedIn].addTour(tour_arr.returnTour(index));
		}
		if (food == 1) {
			int index = fServ.editForClient();
			if (index == -1){
				return;
			}
			users[loggedIn].addFoodService(fServ.returnFoodService(index));
		}
		if (hotel == 1 && tour == 1 && food == 1) {
			price *= 0.7;
		}
		//else if (!hotel && food && !tour)
	}
};
	