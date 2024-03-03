#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Exceptions.h"
#include "Date.h"
using namespace std;
class Room
{
private:
	static int r_counter;
	void updateId() { id = ++r_counter; }
protected:
	int id;
	bool oqqupied;
	int days;
	string oqqupierName;
	string oqqupierPhone;
	int rooms;
	float price;

	bool haveBalcony;
	bool haveBodyNeeds;
	bool haveKitchen;
	bool haveJakussi;
	bool haveMovieTV;
	bool haveGames;
	bool haveSafe;
	bool haveHeliAccsess;

	Date infiltrationD;

public:
	Room() { oqqupierName = "unknown"; oqqupierPhone = "unknown"; infiltrationD = Date(01,01,1001); haveBodyNeeds = false; rooms = 0; days = 0; updateId(); }
	Room(int rooms, bool haveBalcony, bool haveBodyNeeds = false, bool haveKitchen = false, bool haveGames = false, bool haveMovieTV = false, bool haveSafe = false, bool haveJakussi = false, bool haveHeliAccsess = false)
	{ updateId(); setRooms(rooms); setBalcony(haveBalcony); }
	~Room() {}
	
	void freeRoom() {
		if (getOqqupied()==true){
			oqqupierName = "unknown"; oqqupierPhone = "unknown"; infiltrationD = Date(01, 01, 1001); oqqupied = false;
		}
	}

	void setOqqupied() { if (this->oqqupied == false) { this->oqqupied = true; } }
	void setOqqupie(int days, string oqqupierName = "", string oqqupierPhone = "", Date infiltration_d = Date()) {
		this->oqqupierName = oqqupierName; this->oqqupierPhone = oqqupierPhone; this->infiltrationD = infiltration_d; this->days = days; setOqqupied();
	}
	void setRooms(int rooms) { (rooms > 0 && rooms < 10) ? this->rooms = rooms : this->rooms = 2; }
	void setBalcony(bool haveBalcony) { (haveBalcony == true) ? this->haveBalcony = true : this->haveBalcony = false; }
	void setBodyNeeds(bool haveBodyNeeds) { (haveBodyNeeds == true) ? this->haveBodyNeeds = true : this->haveBodyNeeds = false; }
	void setKitchen(bool haveKitchen) { (haveKitchen == true) ? this->haveKitchen = true : this->haveKitchen = false; }
	void setJakussi(bool haveJakussi) { (haveJakussi == true) ? this->haveJakussi = true : this->haveJakussi = false; }
	void setMovieTV(bool haveMovieTV) { (haveMovieTV == true) ? this->haveMovieTV = true : this->haveMovieTV = false; }
	void setGames(bool haveGames) { (haveGames == true) ? this->haveGames = true : this->haveGames = false; }
	void setSave(bool haveSafe) { (haveSafe == true) ? this->haveSafe = true : this->haveSafe = false; }
	void setHeliAccsess(bool haveHeliAccsess) { (haveHeliAccsess == true) ? this->haveHeliAccsess = true : this->haveHeliAccsess = false; }
	
	int showId() const { return id; }
	bool getOqqupied() const { return oqqupied; }
	string getOqqupierName() const { return oqqupierName; }
	string getOqqupierPhone() const { return oqqupierPhone; }
	Date getInfiltrationDate() const { return infiltrationD; }
	int getRooms() const { return rooms; }
	bool getBalcony() const { return haveBalcony; }
	bool getBodyNeeds() const { return haveBodyNeeds; }
	bool getKitchen() const { return haveKitchen; }
	bool getJakussi() const { return haveJakussi; }
	bool getMovieTV() const { return haveMovieTV; }
	bool getGames() const { return haveGames; }
	bool getSave() const { return haveSafe; }
	bool getHeliAccsess() const { return haveHeliAccsess; }

	void DispId() const { cout << "ID: " << showId() << endl; }

	virtual void showRoomInfo() const = 0;
	virtual void show() const = 0;
	virtual string type() const = 0;
	virtual float calcSumm() = 0;
	virtual void askClients() = 0;
	virtual void loadAddInfo(string filename) = 0;
};

//standart
class LRoom : public Room {
private:
protected:
	vector<int> extra_ordered;
	vector<string> extra;
	vector<float> extra_price;
public:
	LRoom() :Room() {}
	LRoom(int rooms, bool haveBalcony) :Room(rooms, haveBalcony) {}
	~LRoom() {}

	virtual void askClients() override {
		loadAddInfo("data/Hotel/Extras/test.txt");
		if (true)
		{

		}
		int select;
		cout << "List of extra`s avalible for purchasing:\n";
		for (int i = 0; i < extra.size(); i++){
			cout << i+1 << ". " + extra[i] << " " << extra_price[i] << endl;
		}
		do{
			cout << "Input id`s of selected items you prefer to have (0 Stop asking for extra`s): ";
			cin >> select;

			if (select<=extra.size()){
				cout << "Item added: " + extra[select] << endl;
				extra_ordered.push_back(select);
			}
		} while (select != 0);
	}

	virtual void loadAddInfo(string filename) override {
		bool uploading = false;
		//string filename = "test.txt";
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Unable to open file: " << filename << endl;
			return;
		}
		string line;
		while (getline(file, line)) {
			if (line.find("#Init#") != string::npos){
				continue;
			}
			else if (line.find("#Init#") != string::npos) {
				uploading = true;
				continue;
			}
			else if (line.find("#" + type() + "#") != string::npos) {
				istringstream iss(line);
				string t_name;
				float t_price;
				if (!(iss >> t_name >> t_price)) {
					cerr << "Error parsing line: " << line << endl;
					continue;
				}
				cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
				extra.push_back(t_name);
				extra_price.push_back(t_price);
			}
			else {
				continue;
			}
		}
		if (extra.size()==0&&extra_price.size()==0){
			cout << "File is empty or no data have been loaded!\n";
		}
		file.close();
	}

	virtual string type() const override { return "Low Cost Room"; }
	virtual void showRoomInfo() const override {
		cout << "\tRoom # " << showId() << endl;
		cout << "Orderer name: ";  (getOqqupierName() != "") ? cout << getOqqupierName() << endl : cout << "unknown\n";
		cout << "Orderer contact phone: ";  (getOqqupierPhone() != "") ? cout << getOqqupierPhone() << endl : cout << "unknown\n";
		cout << "Infiltration Date: "; ((getInfiltrationDate() != Date(01, 01, 2000)) && getInfiltrationDate() > Date(01, 01, 2000)) ? cout << getInfiltrationDate() << endl : cout << "00.00.0000\n";
		cout << "Defilatrion Date: " << getInfiltrationDate() + days << endl;
	}
	virtual void show() const override {
		cout << "\tRoom # " << showId() << endl;
		cout << type() << endl;
		cout << "Rooms: " << getRooms() << endl;
		cout << "Does have Balcony: "; (getBalcony() == true) ? cout << "Yes\n" : cout << "No\n";
		if ((oqqupierName == "" && oqqupierPhone == ""|| oqqupierName == "unknown" && oqqupierPhone == "unknown") && getOqqupied() == false) {
			cout << "Room haven`t been oqqupied!" << endl;
		}
		else { showRoomInfo(); }
	}
	virtual float calcSumm() override {
		price += 1000.0;
		(getBalcony() == true) ? price+=500 : price += 0;
		//----------------------
		for (int i = 0; i < extra_ordered.size(); i++) {
			price += extra_price[extra_ordered[i]];
		}
		return price;
	}
	
};

//+sanUzel
class SRoom : public Room {
private:
protected:
	vector<int> extra_ordered;
	vector<string> extra;
	vector<float> extra_price;
public:
	SRoom() :Room() {}
	SRoom(int rooms, bool haveBalcony, bool haveBodyNeeds) :Room(rooms, haveBalcony, haveBodyNeeds) {}
	~SRoom() {}

	virtual void askClients() override {
		loadAddInfo("test.txt");
		int select;
		cout << "List of extra`s avalible for purchasing:\n";
		for (int i = 0; i < extra.size(); i++) {
			cout << i + 1 << ". " + extra[i] << " " << extra_price[i] << endl;
		}
		do {
			cout << "Input id`s of selected items you prefer to have (0 Stop asking for extra`s): ";
			cin >> select;

			if (select <= extra.size()) {
				cout << "Item added: " + extra[select] << endl;
				extra_ordered.push_back(select);
			}
		} while (select != 0);
	}

	virtual void loadAddInfo(string filename) override {
		//string filename = "test.txt";
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Unable to open file: " << filename << endl;
			return;
		}
		string line;
		while (getline(file, line)) {
			if (line.empty() || line[0] == '#') {
				continue;
			}

			if (line.find("#"+type()+"#") != string::npos) {
				istringstream iss(line);
				string t_name;
				float t_price;
				if (!(iss >> t_name >> t_price)) {
					cerr << "Error parsing line: " << line << endl;
					continue;
				}
				cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
				extra.push_back(t_name);
				extra_price.push_back(t_price);
			}
		}
		if (extra.size() == 0 && extra_price.size() == 0) {
			cout << "File is empty or no data have been loaded!\n";
		}
		file.close();
	}

	virtual string type() const override { return "Small Cost Room"; }
	virtual void showRoomInfo() const override {
		cout << "\tRoom # " << showId() << endl;
		cout << "Orderer name: ";  (getOqqupierName() != "") ? cout << getOqqupierName() << endl : cout << "unknown\n";
		cout << "Orderer contact phone: ";  (getOqqupierPhone() != "") ? cout << getOqqupierPhone() << endl : cout << "unknown\n";
		cout << "Infiltration Date: "; (getInfiltrationDate() != Date(01, 01, 1900)) ? cout << getInfiltrationDate() << endl : cout << "00.00.0000\n";
		cout << "Defilatrion Date: " << getInfiltrationDate() + days << endl;//FIX
	}
	virtual void show() const override {
		cout << type() << endl;
		cout << "\tRoom # " << showId() << endl;
		cout << "Rooms: " << getRooms() << endl;
		cout << "Does have Balcony: "; (getBalcony() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have BodyNeeds: "; (getBodyNeeds() == true) ? cout << "Yes\n" : cout << "No\n";
		if (oqqupierName == "" && oqqupierPhone == "" || oqqupierName == "unknown" && oqqupierPhone == "unknown") {
			cout << "Room haven`t been oqqupied!" << endl;
		}
		else { showRoomInfo(); }
	}
	virtual float calcSumm() override {
		price += 1000.0;
		(getBalcony() == true) ? price += 500 : price += 0;
		(getBodyNeeds() == true) ? price += 500 : price += 0;
		//----------------------
		for (int i = 0; i < extra_ordered.size(); i++) {
			price += extra_price[extra_ordered[i]];
		}
		return price;
	}
};

//+kitchen
class MRoom : public Room {
private:
protected:
	vector<int> extra_ordered;
	vector<string> extra;
	vector<float> extra_price;
public:
	MRoom() :Room() {}
	MRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen) {}
	~MRoom() {}

	virtual void askClients() override {
		loadAddInfo("test.txt");
		int select;
		cout << "List of extra`s avalible for purchasing:\n";
		for (int i = 0; i < extra.size(); i++) {
			cout << i + 1 << ". " + extra[i] << " " << extra_price[i] << endl;
		}
		do {
			cout << "Input id`s of selected items you prefer to have (0 Stop asking for extra`s): ";
			cin >> select;

			if (select <= extra.size()) {
				cout << "Item added: " + extra[select] << endl;
				extra_ordered.push_back(select);
			}
		} while (select != 0);
	}

	virtual void loadAddInfo(string filename) override {
		//string filename = "test.txt";
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Unable to open file: " << filename << endl;
			return;
		}
		string line;
		while (getline(file, line)) {
			if (line.empty() || line[0] == '#') {
				// Skip empty lines or lines starting with #
				continue;
			}

			if (line.find("#"+type()+"#") != string::npos) {
				// Process special line
				istringstream iss(line);
				string t_name;
				float t_price;
				if (!(iss >> t_name >> t_price)) {
					cerr << "Error parsing line: " << line << endl;
					continue;
				}
				cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
				extra.push_back(t_name);
				extra_price.push_back(t_price);
			}
		}
		if (extra.size() == 0 && extra_price.size() == 0) {
			cout << "File is empty or no data have been loaded!\n";
		}
		file.close();
	}

	virtual string type() const override { return "Medium Cost Room"; }
	virtual void showRoomInfo() const override {
		cout << "\tRoom # " << showId() << endl;
		cout << "Orderer name: ";  (getOqqupierName() != "") ? cout << getOqqupierName() << endl : cout << "unknown\n";
		cout << "Orderer contact phone: ";  (getOqqupierPhone() != "") ? cout << getOqqupierPhone() << endl : cout << "unknown\n";
		cout << "Infiltration Date: "; (getInfiltrationDate() != Date(01, 01, 1900)) ? cout << getInfiltrationDate() << endl : cout << "00.00.0000\n";
		cout << "Defilatrion Date: " << getInfiltrationDate() + days << endl;//FIX
	}
	virtual void show() const override {
		cout << type() << endl;
		cout << "\tRoom # " << showId() << endl;
		cout << "Rooms: " << getRooms() << endl;
		cout << "Does have Balcony: "; (getBalcony() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have BodyNeeds: "; (getBodyNeeds() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Kitchen: "; (getKitchen() == true) ? cout << "Yes\n" : cout << "No\n";
		if (oqqupierName == "" && oqqupierPhone == "" || oqqupierName == "unknown" && oqqupierPhone == "unknown") {
			cout << "Room haven`t been oqqupied!" << endl;
		}
		else { showRoomInfo(); }
	}
	virtual float calcSumm() override {
		price += 1000.0;
		(getBalcony() == true) ? price += 500 : price += 0;
		(getBodyNeeds() == true) ? price += 500 : price += 0;
		(getKitchen() == true) ? price += 500 : price += 0;
		//----------------------
		for (int i = 0; i < extra_ordered.size(); i++) {
			price += extra_price[extra_ordered[i]];
		}
		return price;
	}
};

//+games
class PRoom : public Room {
private:
protected:
	vector<int> extra_ordered;
	vector<string> extra;
	vector<float> extra_price;
public:
	PRoom() :Room() {}
	PRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames) {}
	~PRoom() {}

	virtual void askClients() override {
		loadAddInfo("test.txt");
		int select;
		cout << "List of extra`s avalible for purchasing:\n";
		for (int i = 0; i < extra.size(); i++) {
			cout << i + 1 << ". " + extra[i] << " " << extra_price[i] << endl;
		}
		do {
			cout << "Input id`s of selected items you prefer to have (0 Stop asking for extra`s): ";
			cin >> select;

			if (select <= extra.size()) {
				cout << "Item added: " + extra[select] << endl;
				extra_ordered.push_back(select);
			}
		} while (select != 0);
	}

	virtual void loadAddInfo(string filename) override {
		//string filename = "test.txt";
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Unable to open file: " << filename << endl;
			return;
		}
		string line;
		while (getline(file, line)) {
			if (line.empty() || line[0] == '#') {
				// Skip empty lines or lines starting with #
				continue;
			}

			if (line.find("#"+type()+"#") != string::npos) {
				// Process special line
				istringstream iss(line);
				string t_name;
				float t_price;
				if (!(iss >> t_name >> t_price)) {
					cerr << "Error parsing line: " << line << endl;
					continue;
				}
				cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
				extra.push_back(t_name);
				extra_price.push_back(t_price);
			}
		}
		if (extra.size() == 0 && extra_price.size() == 0) {
			cout << "File is empty or no data have been loaded!\n";
		}
		file.close();
	}

	virtual string type() const override { return "Premium Room"; }
	virtual void showRoomInfo() const override {
		cout << "\tRoom # " << showId() << endl;
		cout << "Orderer name: ";  (getOqqupierName() != "") ? cout << getOqqupierName() << endl : cout << "unknown\n";
		cout << "Orderer contact phone: ";  (getOqqupierPhone() != "") ? cout << getOqqupierPhone() << endl : cout << "unknown\n";
		cout << "Infiltration Date: "; (getInfiltrationDate() != Date(01, 01, 1900)) ? cout << getInfiltrationDate() << endl : cout << "00.00.0000\n";
		cout << "Defilatrion Date: " << getInfiltrationDate() + days << endl;//FIX
	}
	virtual void show() const override {
		cout << type() << endl;
		cout << "\tRoom # " << showId() << endl;
		cout << "Rooms: " << getRooms() << endl;
		cout << "Does have Balcony: "; (getBalcony() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have BodyNeeds: "; (getBodyNeeds() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Kitchen: "; (getKitchen() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Games: "; (getGames() == true) ? cout << "Yes\n" : cout << "No\n";
		if (oqqupierName == "" && oqqupierPhone == "" || oqqupierName == "unknown" && oqqupierPhone == "unknown") {
			cout << "Room haven`t been oqqupied!" << endl;
		}
		else { showRoomInfo(); }
	}
	virtual float calcSumm() override {
		price += 1000.0;
		(getBalcony() == true) ? price += 500 : price += 0;
		(getBodyNeeds() == true) ? price += 500 : price += 0;
		(getKitchen() == true) ? price += 500 : price += 0;
		(getGames() == true) ? price += 500 : price += 0;
		//----------------------
		for (int i = 0; i < extra_ordered.size(); i++) {
			price += extra_price[extra_ordered[i]];
		}
		return price;
	}
};

//+betterTv
class HRoom : public Room {
private:
protected:
	vector<int> extra_ordered;
	vector<string> extra;
	vector<float> extra_price;
public:
	HRoom() :Room() {}
	HRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames, bool haveMovieTV) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames, haveMovieTV) {}
	~HRoom() {}

	virtual void askClients() override {
		loadAddInfo("test.txt");
		int select;
		cout << "List of extra`s avalible for purchasing:\n";
		for (int i = 0; i < extra.size(); i++) {
			cout << i + 1 << ". " + extra[i] << " " << extra_price[i] << endl;
		}
		do {
			cout << "Input id`s of selected items you prefer to have (0 Stop asking for extra`s): ";
			cin >> select;

			if (select <= extra.size()) {
				cout << "Item added: " + extra[select] << endl;
				extra_ordered.push_back(select);
			}
		} while (select != 0);
	}

	virtual void loadAddInfo(string filename) override {
		//string filename = "test.txt";
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Unable to open file: " << filename << endl;
			return;
		}
		string line;
		while (getline(file, line)) {
			if (line.empty() || line[0] == '#') {
				// Skip empty lines or lines starting with #
				continue;
			}

			if (line.find("#"+type()+"#") != string::npos) {
				// Process special line
				istringstream iss(line);
				string t_name;
				float t_price;
				if (!(iss >> t_name >> t_price)) {
					cerr << "Error parsing line: " << line << endl;
					continue;
				}
				cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
				extra.push_back(t_name);
				extra_price.push_back(t_price);
			}
		}
		if (extra.size() == 0 && extra_price.size() == 0) {
			cout << "File is empty or no data have been loaded!\n";
		}
		file.close();
	}

	virtual string type() const override { return "High Cost Room"; }
	virtual void showRoomInfo() const override {
		cout << "\tRoom # " << showId() << endl;
		cout << "Orderer name: ";  (getOqqupierName() != "") ? cout << getOqqupierName() << endl : cout << "unknown\n";
		cout << "Orderer contact phone: ";  (getOqqupierPhone() != "") ? cout << getOqqupierPhone() << endl : cout << "unknown\n";
		cout << "Infiltration Date: "; (getInfiltrationDate() != Date(01, 01, 1900)) ? cout << getInfiltrationDate() << endl : cout << "00.00.0000\n";
		cout << "Defilatrion Date: " << getInfiltrationDate() + days << endl;//FIX
	}
	virtual void show() const override {
		cout << type() << endl;
		cout << "\tRoom # " << showId() << endl;
		cout << "Rooms: " << getRooms() << endl;
		cout << "Does have Balcony: "; (getBalcony() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have BodyNeeds: "; (getBodyNeeds() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Kitchen: "; (getKitchen() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Games: "; (getGames() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Movie TV: "; (getMovieTV() == true) ? cout << "Yes\n" : cout << "No\n";
		if (oqqupierName == "" && oqqupierPhone == "" || oqqupierName == "unknown" && oqqupierPhone == "unknown") {
			cout << "Room haven`t been oqqupied!" << endl;
		}
		else { showRoomInfo(); }
	}
	virtual float calcSumm() override {
		price += 1000.0;
		(getBalcony() == true) ? price += 500 : price += 0;
		(getBodyNeeds() == true) ? price += 500 : price += 0;
		(getKitchen() == true) ? price += 500 : price += 0;
		(getGames() == true) ? price += 500 : price += 0;
		(getMovieTV() == true) ? price += 500 : price += 0;
		//----------------------
		for (int i = 0; i < extra_ordered.size(); i++) {
			price += extra_price[extra_ordered[i]];
		}
		return price;
	}
};

//+safe
class VRoom : public Room {
private:
protected:
	vector<int> extra_ordered;
	vector<string> extra;
	vector<float> extra_price;
public:
	VRoom() :Room() {}
	VRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames, bool haveMovieTV, bool haveSafe) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames, haveMovieTV, haveSafe) {}
	~VRoom() {}

	virtual void askClients() override {
		loadAddInfo("test.txt");
		int select;
		cout << "List of extra`s avalible for purchasing:\n";
		for (int i = 0; i < extra.size(); i++) {
			cout << i + 1 << ". " + extra[i] << " " << extra_price[i] << endl;
		}
		do {
			cout << "Input id`s of selected items you prefer to have (0 Stop asking for extra`s): ";
			cin >> select;

			if (select <= extra.size()) {
				cout << "Item added: " + extra[select] << endl;
				extra_ordered.push_back(select);
			}
		} while (select != 0);
	}

	virtual void loadAddInfo(string filename) override {
		//string filename = "test.txt";
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Unable to open file: " << filename << endl;
			return;
		}
		string line;
		while (getline(file, line)) {
			if (line.empty() || line[0] == '#') {
				// Skip empty lines or lines starting with #
				continue;
			}

			if (line.find("#"+type()+"#") != string::npos) {
				// Process special line
				istringstream iss(line);
				string t_name;
				float t_price;
				if (!(iss >> t_name >> t_price)) {
					cerr << "Error parsing line: " << line << endl;
					continue;
				}
				cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
				extra.push_back(t_name);
				extra_price.push_back(t_price);
			}
		}
		if (extra.size() == 0 && extra_price.size() == 0) {
			cout << "File is empty or no data have been loaded!\n";
		}
		file.close();
	}

	virtual string type() const override { return "VIP Room"; }
	virtual void showRoomInfo() const override {
		cout << "\tRoom # " << showId() << endl;
		cout << "Orderer name: ";  (getOqqupierName() != "") ? cout << getOqqupierName() << endl : cout << "unknown\n";
		cout << "Orderer contact phone: ";  (getOqqupierPhone() != "") ? cout << getOqqupierPhone() << endl : cout << "unknown\n";
		cout << "Infiltration Date: "; (getInfiltrationDate() != Date(01, 01, 1900)) ? cout << getInfiltrationDate() << endl : cout << "00.00.0000\n";
		cout << "Defilatrion Date: " << getInfiltrationDate() + days << endl;//FIX
	}
	virtual void show() const override {
		cout << type() << endl;
		cout << "\tRoom # " << showId() << endl;
		cout << "Rooms: " << getRooms() << endl;
		cout << "Does have Balcony: "; (getBalcony() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have BodyNeeds: "; (getBodyNeeds() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Kitchen: "; (getKitchen() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Games: "; (getGames() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Movie TV: "; (getMovieTV() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Save: "; (getSave() == true) ? cout << "Yes\n" : cout << "No\n";
		if (oqqupierName == "" && oqqupierPhone == "" || oqqupierName == "unknown" && oqqupierPhone == "unknown") {
			cout << "Room haven`t been oqqupied!" << endl;
		}
		else { showRoomInfo(); }
	}
	virtual float calcSumm() override {
		price += 1000.0;
		(getBalcony() == true) ? price += 500 : price += 0;
		(getBodyNeeds() == true) ? price += 500 : price += 0;
		(getKitchen() == true) ? price += 500 : price += 0;
		(getGames() == true) ? price += 500 : price += 0;
		(getMovieTV() == true) ? price += 500 : price += 0;
		(getSave() == true) ? price += 500 : price += 0;
		//----------------------
		for (int i = 0; i < extra_ordered.size(); i++) {
			price += extra_price[extra_ordered[i]];
		}
		return price;
	}
};

//+jakussi
class LxRoom : public Room {
private:
protected:
	vector<int> extra_ordered;
	vector<string> extra;
	vector<float> extra_price;
public:
	LxRoom() :Room() {}
	LxRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames, bool haveMovieTV, bool haveSafe, bool haveJakussi) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames, haveMovieTV, haveSafe, haveJakussi) {}
	~LxRoom() {}

	virtual void askClients() override {
		loadAddInfo("test.txt");
		int select;
		cout << "List of extra`s avalible for purchasing:\n";
		for (int i = 0; i < extra.size(); i++) {
			cout << i + 1 << ". " + extra[i] << " " << extra_price[i] << endl;
		}
		do {
			cout << "Input id`s of selected items you prefer to have (0 Stop asking for extra`s): ";
			cin >> select;

			if (select <= extra.size()) {
				cout << "Item added: " + extra[select] << endl;
				extra_ordered.push_back(select);
			}
		} while (select != 0);
	}

	virtual void loadAddInfo(string filename) override {
		//string filename = "test.txt";
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Unable to open file: " << filename << endl;
			return;
		}
		string line;
		while (getline(file, line)) {
			if (line.empty() || line[0] == '#') {
				// Skip empty lines or lines starting with #
				continue;
			}

			if (line.find("#"+type()+"#") != string::npos) {
				// Process special line
				istringstream iss(line);
				string t_name;
				float t_price;
				if (!(iss >> t_name >> t_price)) {
					cerr << "Error parsing line: " << line << endl;
					continue;
				}
				cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
				extra.push_back(t_name);
				extra_price.push_back(t_price);
			}
		}
		if (extra.size() == 0 && extra_price.size() == 0) {
			cout << "File is empty or no data have been loaded!\n";
		}
		file.close();
	}

	virtual string type() const override { return "Lux Room"; }
	virtual void showRoomInfo() const override {
		cout << "\tRoom # " << showId() << endl;
		cout << "Orderer name: ";  (getOqqupierName() != "") ? cout << getOqqupierName() << endl : cout << "unknown\n";
		cout << "Orderer contact phone: ";  (getOqqupierPhone() != "") ? cout << getOqqupierPhone() << endl : cout << "unknown\n";
		cout << "Infiltration Date: "; (getInfiltrationDate() != Date(01, 01, 1900)) ? cout << getInfiltrationDate() << endl : cout << "00.00.0000\n";
		cout << "Defilatrion Date: " << getInfiltrationDate() + days << endl;//FIX
	}
	virtual void show() const override {
		cout << type() << endl;
		cout << "\tRoom # " << showId() << endl;
		cout << "Rooms: " << getRooms() << endl;
		cout << "Does have Balcony: "; (getBalcony() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have BodyNeeds: "; (getBodyNeeds() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Kitchen: "; (getKitchen() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Games: "; (getGames() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Movie TV: "; (getMovieTV() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Save: "; (getSave() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Jakussi: "; (getJakussi() == true) ? cout << "Yes\n" : cout << "No\n";
		if (oqqupierName == "" && oqqupierPhone == "" || oqqupierName == "unknown" && oqqupierPhone == "unknown") {
			cout << "Room haven`t been oqqupied!" << endl;
		}
		else { showRoomInfo(); }
	}
	virtual float calcSumm() override {
		price += 1000.0;
		(getBalcony() == true) ? price += 500 : price += 0;
		(getBodyNeeds() == true) ? price += 500 : price += 0;
		(getKitchen() == true) ? price += 500 : price += 0;
		(getGames() == true) ? price += 500 : price += 0;
		(getMovieTV() == true) ? price += 500 : price += 0;
		(getSave() == true) ? price += 500 : price += 0;
		(getJakussi() == true) ? price += 500 : price += 0;
		//----------------------
		for (int i = 0; i < extra_ordered.size(); i++) {
			price += extra_price[extra_ordered[i]];
		}
		return price;
	}
};

//+accessToHelicopter
class PresRoom : public Room {
private:
protected:
	vector<int> extra_ordered;
	vector<string> extra;
	vector<float> extra_price;
public:
	PresRoom() :Room() {}
	PresRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames, bool haveMovieTV, bool haveSafe, bool haveJakussi, bool haveHeliAccsess) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames, haveMovieTV, haveSafe, haveJakussi, haveHeliAccsess) {}
	~PresRoom() {}

	virtual void askClients() override {
		loadAddInfo("test.txt");
		int select;
		cout << "List of extra`s avalible for purchasing:\n";
		for (int i = 0; i < extra.size(); i++) {
			cout << i + 1 << ". " + extra[i] << " " << extra_price[i] << endl;
		}
		do {
			cout << "Input id`s of selected items you prefer to have (0 Stop asking for extra`s): ";
			cin >> select;

			if (select <= extra.size()) {
				cout << "Item added: " + extra[select] << endl;
				extra_ordered.push_back(select);
			}
		} while (select != 0);
	}

	virtual void loadAddInfo(string filename) override {
		//string filename = "test.txt";
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Unable to open file: " << filename << endl;
			return;
		}
		string line;
		while (getline(file, line)) {
			if (line.empty() || line[0] == '#') {
				// Skip empty lines or lines starting with #
				continue;
			}

			if (line.find("#"+type()+"#") != string::npos) {
				// Process special line
				istringstream iss(line);
				string t_name;
				float t_price;
				if (!(iss >> t_name >> t_price)) {
					cerr << "Error parsing line: " << line << endl;
					continue;
				}
				cout << "Product Name: " << t_name << ", Price: " << t_price << endl;
				extra.push_back(t_name);
				extra_price.push_back(t_price);
			}
		}
		if (extra.size() == 0 && extra_price.size() == 0) {
			cout << "File is empty or no data have been loaded!\n";
		}
		file.close();
	}

	virtual string type() const override { return "Presidential Room"; }
	virtual void showRoomInfo() const override {
		cout << "\tRoom # " << showId() << endl;
		cout << "Orderer name: ";  (getOqqupierName() != "") ? cout << getOqqupierName() << endl : cout << "unknown\n";
		cout << "Orderer contact phone: ";  (getOqqupierPhone() != "") ? cout << getOqqupierPhone() << endl : cout << "unknown\n";
		cout << "Infiltration Date: "; (getInfiltrationDate() != Date(01, 01, 1900)) ? cout << getInfiltrationDate() << endl : cout << "00.00.0000\n";
		cout << "Defilatrion Date: " << getInfiltrationDate() + days << endl;//FIX
	}
	virtual void show() const override {
		cout << type() << endl;
		cout << "\tRoom # " << showId() << endl;
		cout << "Rooms: " << getRooms() << endl;
		cout << "Does have Balcony: "; (getBalcony() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have BodyNeeds: "; (getBodyNeeds() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Kitchen: "; (getKitchen() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Games: "; (getGames() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Movie TV: "; (getMovieTV() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Save: "; (getSave() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have Jakussi: "; (getJakussi() == true) ? cout << "Yes\n" : cout << "No\n";
		cout << "Does have accsess to Helicopter: "; (getHeliAccsess() == true) ? cout << "Yes\n" : cout << "No\n";
		if (oqqupierName == "" && oqqupierPhone == "" || oqqupierName == "unknown" && oqqupierPhone == "unknown") {
			cout << "Room haven`t been oqqupied!" << endl;
		}
		else { showRoomInfo(); }
	}
	virtual float calcSumm() override {
		price += 9000.0;
		(getBalcony() == true) ? price += 1000 : price += 0;
		(getBodyNeeds() == true) ? price += 2500 : price += 0;
		(getKitchen() == true) ? price += 5000 : price += 0;
		(getGames() == true) ? price += 10000 : price += 0;
		(getMovieTV() == true) ? price += 20000 : price += 0;
		(getSave() == true) ? price += 20000 : price += 0;
		(getJakussi() == true) ? price += 250000 : price += 0;
		(getHeliAccsess() == true) ? price += 400000 : price += 0;
		//----------------------
		for (int i = 0; i < extra_ordered.size(); i++) {
			price += extra_price[extra_ordered[i]];
		}
		return price;
	}
};

