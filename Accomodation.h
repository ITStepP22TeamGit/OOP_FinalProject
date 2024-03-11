#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "Hotel.h"
#include<algorithm>
using namespace std;

class Accomodation{
protected:
	vector<Hotel> hArr;
public:
	Accomodation() {}
	~Accomodation() {
		//hArr.clear();
	}

	int size()const {
		return hArr.size();
	}

	void addHotel() {
		string name, adress;
		float rating;
		int X, Y;
		cin.ignore();
		cout << "Enter future hotel name\n";
		cout << "| > > >";
		getline(cin, name);
		cout << "Enter future hotel adress\n";
		cout << "| > > >";
		getline(cin, adress);
		cout << "Enter future hotels adress\n";
		cout << "| > > >";
		cin.ignore();
		cin >> rating;
		cout << "Enter future hotels adress (X,Y)\n";
		cout << "| > > >";
		cin >> X;
		cout << "| > > >";
		cin >> Y;
		cin.ignore();
		hArr.push_back(Hotel(adress, name, X, Y, rating));
		hArr[hArr.size() - 1].addRoom();
	}
	void addHotel(string adress, string name, float rating, int hotelX, int hotelY, Map& map) {
		hArr.push_back(Hotel(adress, name, hotelX, hotelY, rating));
		map.addPoint(hotelX, hotelY, name, 1);
	}
	void addHotel(Hotel obj) {
		hArr.push_back(obj);
	}

	void editHotel() {}


	void addRoom() {
		int chose;
		showHotelInfo();
		cout << "| Input hotel id to add room";
		cout << "| > > >";
		cin >> chose;
		chose--;
		hArr[chose].addRoom();
	}
	void addRoom(int hid, Room* obj) {}

	void delHotel() {
		int chose;
		showHotelInfo();
		cout << "Input hotel id\n";
		cout << "| > > >";
		cin >> chose;
		chose--;
		hArr.erase(hArr.begin() + chose);
	}
	void delHotel(Hotel obj) {
		for (int i = 0; i < hArr.size(); i++) {
			if (obj.getHotelId()==hArr[i].getHotelId()) {
				hArr.erase(hArr.begin()+i);
			}
		}
		
	}
	void delHotel(int id) {
		hArr.erase(hArr.begin() + id);
	}

	void showHotelForClients() {
		for (int i = 0; i < hArr.size(); i++) {
			cout << "--===========================================--\n";
			cout << "|   " << i + 1 << ". " + hArr[i].getName() + " on " + hArr[i].getAdress() << endl;
			cout << "==============================================>\n";
			hArr[i].showForClients();
			cout << "==============================================>\n";
		}
		cout << "--===========================================--\n";
	}
	int showHotelForClientsOrder() {
		for (int i = 0; i < hArr.size(); i++) {
			cout << "--===========================================--\n";
			cout << "|   " << i + 1 << ". " + hArr[i].getName() + " on " + hArr[i].getAdress() << endl;
			cout << "==============================================>\n";
			hArr[i].showForClients();
			cout << "==============================================>\n";
		}
		cout << "--===========================================--\n";
		int intVar;
		cout << "|   Choose a number you want to order: ";
		cin >> intVar;
		return intVar - 1;
	}
	void showForOrder() {
		for (int i = 0; i < hArr.size(); i++) {
			cout << "--===========================================--\n";
			cout << "|   " << i + 1 << ". " + hArr[i].getName() + " on " + hArr[i].getAdress() << endl;
			cout << "==============================================>\n";
			hArr[i].showAval();
			cout << "==============================================>\n";
		}
		cout << "--===========================================--\n";
	}
	void showRoomsInfo() {
		for (int i = 0; i < hArr.size(); i++) {
			cout << "--===========================================--\n";
			cout << "|   " << i + 1 << ". " + hArr[i].getName() + " on " + hArr[i].getAdress() << endl;
			cout << "==============================================>\n";
			hArr[i].showRoomInfo();
			cout << "==============================================>\n";
		}
		cout << "--===========================================--\n";
	}
	void showHotelInfo() {
		for (int i = 0; i < hArr.size(); i++){
			cout << "|   " + i + 1 << endl;
			hArr[i].showHotelInfo();
		}
	}

	void menu() {
		int menu;
		do{
			cout << "--";
			for (int i = 0; i < 10; i++) {
				cout << "=";
			}
			cout << "~~ Hotels ~~";
			for (int i = 0; i < 10; i++) {
				cout << "=";
			}
			cout << "--\n";
			cout << "|   1. Show Hotels\n";
			cout << "|   2. Sort Hotels\n";
			cout << "|   3. Search Hotels\n";
			cout << "|   0. Return/Exit\n";
			cout << "| > > >";
			cin >> menu;
			switch (menu)
			{
			case 0:
				return;
			case 1:
				showHotelInfo();
				system("pause");
				system("cls");
				break;
			case 2:
				//showHotelInfo();
				system("pause");
				system("cls");
				break;
			case 3:
				//showHotelInfo();
				system("pause");
				system("cls");
				break;
			default:
				break;
			}
		} while (menu !=0);
		system("cls");
	}
	void menuSort() {
		int menu;
		do {
			cout << "--";
			for (int i = 0; i < 10; i++) {
				cout << "=";
			}
			cout << "~~ Hotels Sorter ~~";
			for (int i = 0; i < 10; i++) {
				cout << "=";
			}
			cout << "--\n";
			cout << "|   1. Show Hotels\n";
			cout << "|   2. Sort Hotels\n";
			cout << "|   3. Search Hotels\n";
			cout << "|   0. Return/Exit\n";
			cout << "| > > >";
			cin >> menu;
			switch (menu)
			{
			case 0:
				return;
			case 1:
				showHotelInfo();
				system("pause");
				system("cls");
				break;
			case 2:
				//showHotelInfo();
				system("pause");
				system("cls");
				break;
			case 3:
				//showHotelInfo();
				system("pause");
				system("cls");
				break;
			default:
				break;
			}
		} while (menu != 0);
		system("cls");
	}
	void menuSearch() {
		int menu;
		do {
			cout << "--";
			for (int i = 0; i < 10; i++) {
				cout << "=";
			}
			cout << "~~ Hotels Searcher ~~";
			for (int i = 0; i < 10; i++) {
				cout << "=";
			}
			cout << "--\n";
			cout << "|   1. Show Hotels\n";
			cout << "|   2. Sort Hotels\n";
			cout << "|   3. Search Hotels\n";
			cout << "|   0. Return/Exit\n";
			cout << "| > > >";
			cin >> menu;
			switch (menu)
			{
			case 0:
				return;
			case 1:
				showHotelInfo();
				system("pause");
				system("cls");
				break;
			case 2:
				//showHotelInfo();
				system("pause");
				system("cls");
				break;
			case 3:
				//showHotelInfo();
				system("pause");
				system("cls");
				break;
			default:
				break;
			}
		} while (menu != 0);
		system("cls");
	}

	float calcSumm(int hid, int rid) {
		return hArr[hid].calcSumm(rid);
	}
	void addOqupier(int hid,int rId, int days, string oqqupierName, string oqqupierPhone, Date infiltration_d) {
		hArr[hid].addOqqupier(rId, days, oqqupierName, oqqupierPhone, infiltration_d);
	}
	void askClient(int hid, int rid) {
		hArr[hid].r_arr[rid]->askClients();
	}

	void loadInfo(ifstream& file) {
		char delimiter = '|';
		string line;
		while (getline(file, line)) {
			//cout << line << endl;
			if (line.find("#Hotel#") != string::npos) {
				while (getline(file, line)) {
					vector<string> tokens;
					stringstream ss(line);
					string token;
					while (getline(ss, token, delimiter)) {
						tokens.push_back(token);
					}
					//name|adress|id|rating|x|y

					//tokens[0] = this->name;
					//tokens[1] = this->adress;
					//this->hotel_id = stoi(tokens[2], nullptr, 10);
					//this->rating = stof(tokens[3], nullptr);
					//this->hotelX = stoi(tokens[4], nullptr, 10);
					//this->hotelY = stoi(tokens[5], nullptr, 10);

					hArr.push_back(Hotel(tokens[1], tokens[0], stoi(tokens[4], nullptr, 10), stoi(tokens[5], nullptr, 10), stof(tokens[3],nullptr)));
					return;
				}
			}
			else if ((line.find("#Rooms#") == string::npos) || (line.find("#") != string::npos && line.find("") == string::npos)) {
				return;
			}
		}
		//string line;
		//bool uploading;
		//while (getline(file, line)) {
		//	if (line.find("#Hotel#") == string::npos) {
		//		continue;
		//	}
		//	else if (line.find("#Hotel#") != string::npos) {
		//		uploading = true;
		//		continue;
		//	}
		//	if (line.find("##") != string::npos && uploading) {
		//		istringstream iss(line);
		//		string t_name;
		//		float t_price;
		//		if (!(iss >> t_name >> t_price)) {
		//			cerr << "Error parsing line: " << line << endl;
		//			continue;
		//		}
		//		cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
		//		//extra.push_back(t_name);
		//		//extra_price.push_back(t_price);
		//	}
		//	else if (line.find("#") != string::npos && line.find("") == string::npos) {
		//		uploading = false;
		//		break;
		//	}
		//}
		//loadMainInfo(file);
		//file.close();
	}
	void loadInfo(ifstream& file, Map& map) {
		char delimiter = '|';
		string line;
		while (getline(file, line)) {
			//cout << line << endl;
			if (line.find("#Hotel#") != string::npos) {
				while (getline(file, line)) {
					vector<string> tokens;
					stringstream ss(line);
					string token;
					while (getline(ss, token, delimiter)) {
						tokens.push_back(token);
					}
					//name|adress|id|rating|x|y

					//tokens[0] = this->name;
					//tokens[1] = this->adress;
					//this->hotel_id = stoi(tokens[2], nullptr, 10);
					//this->rating = stof(tokens[3], nullptr);
					//this->hotelX = stoi(tokens[4], nullptr, 10);
					//this->hotelY = stoi(tokens[5], nullptr, 10);

					hArr.push_back(Hotel(tokens[1], tokens[0], stoi(tokens[4], nullptr, 10), stoi(tokens[5], nullptr, 10), stof(tokens[3], nullptr)));
					map.addPoint(hArr[hArr.size() - 1].getX(), hArr[hArr.size() - 1].getY(), hArr[hArr.size() - 1].getName(), 1);
					return;
				}
			}
			else if ((line.find("#Rooms#") == string::npos) || (line.find("#") != string::npos && line.find("") == string::npos)) {
				return;
			}
		}
		//string line;
		//bool uploading;
		//while (getline(file, line)) {
		//	if (line.find("#Hotel#") == string::npos) {
		//		continue;
		//	}
		//	else if (line.find("#Hotel#") != string::npos) {
		//		uploading = true;
		//		continue;
		//	}
		//	if (line.find("##") != string::npos && uploading) {
		//		istringstream iss(line);
		//		string t_name;
		//		float t_price;
		//		if (!(iss >> t_name >> t_price)) {
		//			cerr << "Error parsing line: " << line << endl;
		//			continue;
		//		}
		//		cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
		//		//extra.push_back(t_name);
		//		//extra_price.push_back(t_price);
		//	}
		//	else if (line.find("#") != string::npos && line.find("") == string::npos) {
		//		uploading = false;
		//		break;
		//	}
		//}
		//loadMainInfo(file);
		//file.close();
	}

	void loadInfo(string filename) {
		ifstream file(filename);
		char delimiter = '|';
		string line;
		getline(file, line);
		while (getline(file, line)) {
			//cout << line << endl;
			if (line.find("#Hotel#") != string::npos) {
				while (getline(file, line)) {
					vector<string> tokens;
					stringstream ss(line);
					string token;
					while (getline(ss, token, delimiter)) {
						tokens.push_back(token);
					}
					//tokens[0] = this->name;
					//tokens[1] = this->adress;
					//this->hotel_id = stoi(tokens[2], nullptr, 10);
					//this->hotelX = stoi(tokens[3], nullptr, 10);
					//this->hotelY = stoi(tokens[4], nullptr, 10);
					//setName(tokens[0]);
					//setAdress(tokens[1]);
					//setCoords(stoi(tokens[3], nullptr, 10), stoi(tokens[4], nullptr, 10));
					hArr.push_back(Hotel(tokens[1], tokens[0], stoi(tokens[4], nullptr, 10), stoi(tokens[5], nullptr, 10), stof(tokens[3], nullptr)));
					hArr[hArr.size() - 1].loadMainInfo(file);
					return;
				}
			}
			else if ((line.find("#Rooms#") == string::npos) || (line.find("#") != string::npos && line.find("") == string::npos)) {
				return;
			}
		}
	}
	void loadInfo(string filename, Map& map) {
		ifstream file(filename);
		char delimiter = '|';
		string line;
		getline(file, line);
		while (getline(file, line)) {
			//cout << line << endl;
			if (line.find("#Hotel#") != string::npos) {
				while (getline(file, line)) {
					vector<string> tokens;
					stringstream ss(line);
					string token;
					while (getline(ss, token, delimiter)) {
						tokens.push_back(token);
					}
					//tokens[0] = this->name;
					//tokens[1] = this->adress;
					//this->hotel_id = stoi(tokens[2], nullptr, 10);
					//this->hotelX = stoi(tokens[3], nullptr, 10);
					//this->hotelY = stoi(tokens[4], nullptr, 10);
					//setName(tokens[0]);
					//setAdress(tokens[1]);
					//setCoords(stoi(tokens[3], nullptr, 10), stoi(tokens[4], nullptr, 10));
					hArr.push_back(Hotel(tokens[1], tokens[0], stoi(tokens[4], nullptr, 10), stoi(tokens[5], nullptr, 10), stof(tokens[3], nullptr)));
					map.addPoint(hArr[hArr.size() - 1].getX(), hArr[hArr.size() - 1].getY(), hArr[hArr.size() - 1].getName(), 1);
					hArr[hArr.size() - 1].loadMainInfo(file);
					return;
				}
			}
			else if ((line.find("#Rooms#") == string::npos) || (line.find("#") != string::npos && line.find("") == string::npos)) {
				return;
			}
		}
	}

	void saveInfo(ofstream& file) {
		//ofstream file(file);
		file << endl;
		for (int i = 0; i < hArr.size(); i++) {
			file << "#Hotel#\n";
			string tmpStr;
			tmpStr = hArr[i].getName() + "|" + hArr[i].getAdress() + "|" + to_string(hArr[i].getHotelId()) + "|" + to_string(hArr[i].getRating()) + "|" + to_string(hArr[i].getX()) + "|" + to_string(hArr[i].getY());
			file << tmpStr;//name|adress|id|rating|x|y
			file << endl;//переход на н.с.
			hArr[i].saveMainInfo(file);
		}
		file << "#End#";
	}
	void saveInfo(string filename) {
		ofstream file(filename + "hotelData.txt");
		file << endl;
		for (int i = 0; i < hArr.size(); i++) {
			file << "#Hotel#\n";
			string tmpStr;
			tmpStr = hArr[i].getName() + "|" + hArr[i].getAdress() + "|" + to_string(hArr[i].getHotelId()) + "|" + to_string(hArr[i].getRating()) + "|" + to_string(hArr[i].getX()) + "|" + to_string(hArr[i].getY());
			file << tmpStr;//name|adress|id|rating|x|y
			file << endl;//переход на н.с.
			hArr[i].saveMainInfo(file);
		}
		file << "#End#";
	}

	void searchById() {
		int chose;
		for (int i = 0; i < hArr.size(); i++) {
			hArr[i].showHotelInfo();
		}
		cout << "Input Hotel number to search room: ";
		cin >> chose;
		hArr[chose].showForClients();
	}

	void searchRoomById() {
		int chose;
		for (int i = 0; i < hArr.size(); i++) {
			hArr[i].showHotelInfo();
		}
		cout << "Input Hotel number to search room: ";
		cin >> chose;
		hArr[chose].dispAllRooms();
	}
	void searchRoomByOqqupation() {
		int chose;
		for (int i = 0; i < hArr.size(); i++) {
			hArr[i].showHotelInfo();
		}
		cout << "Input Hotel number to search room: ";
		cin >> chose;
		hArr[chose].showAval();
	}

	void searchByType() {
		string choose;
		int chose;
		for (int i = 0; i < hArr.size(); i++) {
			hArr[i].showHotelInfo();
		}
		cout << "Input Hotel number to search room: ";
		cin >> chose;
		cin.ignore();
		cout << "Input Room type you want ot search: ";
		getline(cin, choose);
		for (int i = 0; i < hArr.size(); i++){
			if (hArr[chose].r_arr[i]->type()==choose){
				hArr[chose].r_arr[i]->showClient();
			}
		}
	}
	void searchRoomByType() {
		string choose;
		int chose;
		for (int i = 0; i < hArr.size(); i++) {
			hArr[i].showHotelInfo();
		}
		cout << "Input Hotel number to search room: ";
		cin >> chose;
		cin.ignore();
		cout << "Input Room type ypu want ot search: ";
		getline(cin, choose);
		for (int i = 0; i < hArr.size(); i++) {
			if (hArr[chose].r_arr[i]->type() == choose) {
				hArr[chose].r_arr[i]->show();
			}
		}
	}

	void searchByName() {
		string chose;
		for (int i = 0; i < hArr.size(); i++) {
			hArr[i].showHotelInfo();
		}
		cout << "Input Hotel name you want to find info: ";
		getline(cin, chose);

		for (int i = 0; i < hArr.size(); i++) {
			if (hArr[i].getName() == chose) {
				hArr[i].showHotelInfo();
			}
		}
	}

	void sortByRating() {
		vector<Hotel> tmp;
		tmp = hArr;
		sort(tmp.begin(), tmp.end(), [](const Hotel a, const Hotel b) {
			return a.getRating() > b.getRating();
		});

		for (int i = 0; i < tmp.size(); i++){
			hArr[i].showHotelInfo();
		}
	}
	void sortByFullness() {
		vector<Hotel> tmp;
		tmp = hArr;
		sort(tmp.begin(), tmp.end(), [](const Hotel a, const Hotel b) {
			return a.calcOqupied() / a.getRSize() > b.calcOqupied() / b.getRSize();
			});

		for (int i = 0; i < tmp.size(); i++) {
			tmp[i].showHotelInfo();
		}
	}
	Hotel getHotel(int hid) {
		for (int i = 0; i < hArr.size(); i++) {
			if (i == hid) {
				return hArr[hid];
			}
		}
		return hArr[-1];
	}
};