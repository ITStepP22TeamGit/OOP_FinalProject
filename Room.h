#pragma once
#include <iostream>
#include <vector>
#include <string>
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
	Room(int rooms, bool haveBalcony = false, bool haveBodyNeeds = false, bool haveKitchen = false, bool haveGames = false, bool haveMovieTV = false, bool haveSafe = false, bool haveJakussi = false, bool haveHeliAccsess = false)
	{ updateId(); setRooms(rooms); setBodyNeeds(haveBodyNeeds); }
	~Room() {}
	
	//запрос экстра заказов
	void askClients(){
		cout << "Хотите включить в поездку фотосъемку?\n(да/нет): ";
		string str;
		do {
			cin >> str;
		} while (str != "да" && str != "нет" && str != "Да" && str != "Нет");
		if (str == "да" || str == "Да") {
			
		}
		else {
			
		}
		cout << "Какое количество людей? ";
	}

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
};

//standart
class LRoom : public Room {
private:
protected:
	string extra_ordered;
	string extra;
	vector<float> extra_price;
public:
	LRoom() :Room() {}
	LRoom(int rooms, bool haveBalcony) :Room(rooms, haveBalcony) {}
	~LRoom() {}

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
		cout << "Does have Balcony: "; (getBodyNeeds() == true) ? cout << "Yes\n" : cout << "No\n";
		if ((oqqupierName == "" && oqqupierPhone == ""|| oqqupierName == "unknown" && oqqupierPhone == "unknown") && getOqqupied() == false) {
			cout << "Room haven`t been oqqupied!" << endl;
		}
		else { showRoomInfo(); }
	}
};

//+sanUzel
class SRoom : public Room {
private:
protected:
	string extra_ordered;
	string extra;
	vector<float> extra_price;
public:
	SRoom() :Room() {}
	SRoom(int rooms, bool haveBalcony, bool haveBodyNeeds) :Room(rooms, haveBalcony, haveBodyNeeds) {}
	~SRoom() {}

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
};

//+kitchen
class MRoom : public Room {
private:
protected:
	string extra_ordered;
	string extra;
	vector<float> extra_price;
public:
	MRoom() :Room() {}
	MRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen) {}
	~MRoom() {}

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
};

//+games
class PRoom : public Room {
private:
protected:
	string extra_ordered;
	string extra;
	vector<float> extra_price;
public:
	PRoom() :Room() {}
	PRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames) {}
	~PRoom() {}

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
};

//+betterTv
class HRoom : public Room {
private:
protected:
	string extra_ordered;
	string extra;
	vector<float> extra_price;
public:
	HRoom() :Room() {}
	HRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames, bool haveMovieTV) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames, haveMovieTV) {}
	~HRoom() {}

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
};

//+safe
class VRoom : public Room {
private:
protected:
	string extra_ordered;
	string extra;
	vector<float> extra_price;
public:
	VRoom() :Room() {}
	VRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames, bool haveMovieTV, bool haveSafe) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames, haveMovieTV, haveSafe) {}
	~VRoom() {}

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
};

//+jakussi
class LxRoom : public Room {
private:
protected:
	string extra_ordered;
	string extra;
	vector<float> extra_price;
public:
	LxRoom() :Room() {}
	LxRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames, bool haveMovieTV, bool haveSafe, bool haveJakussi) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames, haveMovieTV, haveSafe, haveJakussi) {}
	~LxRoom() {}

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
};

//+accessToHelicopter
class PresRoom : public Room {
private:
protected:
	string extra_ordered;
	string extra;
	vector<float> extra_price;
public:
	PresRoom() :Room() {}
	PresRoom(int rooms, bool haveBalcony, bool haveBodyNeeds, bool haveKitchen, bool haveGames, bool haveMovieTV, bool haveSafe, bool haveJakussi, bool haveHeliAccsess) :Room(rooms, haveBalcony, haveBodyNeeds, haveKitchen, haveGames, haveMovieTV, haveSafe, haveJakussi, haveHeliAccsess) {}
	~PresRoom() {}

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
};

