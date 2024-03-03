#pragma once
#include "Room.h"
class Hotel
{
private:
	static int h_counter;
	void updateId() { hotel_id = ++h_counter; }
protected:
	int hotel_id;
	int hotelX;
	int hotelY;
	vector<Room*> r_arr;
	string adress;

public:
	Hotel() { updateId(); }
	Hotel(string adress, int hotelX, int hotelY) { updateId(); loadMainInfo(); }
	~Hotel() {
		for (int i = 0; i < r_arr.size(); i++)
		{
			delete r_arr[i];
		}
		r_arr.clear();
	}
	
	string setAdress(string adress) { (adress.length()>2) ? this->adress = adress : this->adress = "unknown"; }

	string getAdress()const { return adress; }
	int getHotelId()const { return hotel_id; }

	void addRoom() { 
		int choose;
		cout << "=================================================\n";
		cout << "\t(for administration only!!!!)\n";
		cout << "=================================================\n";
		do{
			int rooms, bul, i = r_arr.size();
			bool bul_on = false, bul_two = false, bul_tre = false, bul_for = false, bul_fiv = false, bul_six = false, bul_sev = false, bul_eig = false;
			system("cls");
			cout << "\tAdding new Room\n";
			cout << "We have several options to choose:\n";
			cout << "1 Add Low Cost Room\n";
			cout << "2 Add Small Cost Room\n";
			cout << "3 Add Medium Cost Room\n";
			cout << "4 Add Premium Room\n";
			cout << "5 Add High Cost Room\n";
			cout << "6 Add Vip Room\n";
			cout << "7 Add Lux Room\n";
			cout << "8 Add Presidential Room\n";
			cout << "0 Exit\n";
			cin >> choose;
			switch (choose){
			case 0:
				break;

			case 1:
				cout << "\tLow Cost Room\n";
				cout << "Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				r_arr.push_back(new LRoom(rooms, bul_on));
				r_arr[r_arr.size() - 1]->askClients();
				r_arr[r_arr.size() - 1]->loadAddInfo();
				break;

			case 2:
				cout << "\tSmall Cost Room\n";
				cout << "Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				r_arr.push_back(new SRoom(rooms, bul_on, bul_two));
				break;

			case 3:
				cout << "\tMeduim Cost Room\n";
				cout << "Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				r_arr.push_back(new MRoom(rooms, bul_on, bul_two, bul_tre));
				break;

			case 4:
				cout << "\tPremium Room\n";
				cout << "Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				r_arr.push_back(new PRoom(rooms, bul_on, bul_two, bul_tre, bul_for));
				break;

			case 5:
				cout << "\tHigh Cost Room\n";
				cout << "Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_fiv = true : bul_fiv = false;
				r_arr.push_back(new HRoom(rooms, bul_on, bul_two, bul_tre, bul_for, bul_fiv));
				break;

			case 6:
				cout << "\tVIP Room\n";
				cout << "Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_fiv = true : bul_fiv = false;
				cout << "\nInput boolean value to add Safe 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_six = true : bul_six = false;
				r_arr.push_back(new VRoom(rooms, bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six));
				break;

			case 7:
				cout << "\tLux Room\n";
				cout << "Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_fiv = true : bul_fiv = false;
				cout << "\nInput boolean value to add Safe 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_six = true : bul_six = false;
				cout << "\nInput boolean value to add Jakussi 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_sev = true : bul_sev = false;
				r_arr.push_back(new LxRoom(rooms, bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six, bul_sev));
				break;

			case 8:
				cout << "\tPresidetial Room\n";
				cout << "Input amount of rooms you wish to set in: ";
				cin >> rooms;

				cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_fiv = true : bul_fiv = false;
				cout << "\nInput boolean value to add Safe 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_six = true : bul_six = false;
				cout << "\nInput boolean value to add Jakussi 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_sev = true : bul_sev = false;
				cout << "\nInput boolean value to add Access to Helicopter 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_eig = true : bul_eig = false;
				r_arr.push_back(new PresRoom(rooms, bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six, bul_sev, bul_eig));
				break;

			default:
				cout << "\nInputed incorrect code, please try again\n";
				system("pause");
				system("cls");
				break;
			}
			
		} while (choose != 0);
	}

	void addRoom(Room* obj) { r_arr.push_back(obj); }

	void delRoom() {
		int choose;
		do {
			dispAllRooms();
			cout << "Input ID of room to delete it: ";
			cin >> choose;
			if (choose !=0){
				for (int i = 0; i < r_arr.size(); i++) {
					if (choose == r_arr[i]->showId()) {
						if (r_arr[i]->getOqqupied() == true) {
							r_arr[i]->freeRoom();
						}
						cout << "Room #" << r_arr[i]->showId() << " have been deleted from hotel.";
						r_arr.erase(r_arr.begin() + i);
						break;
					}
				}
				cout << "\nYou have entered wrong number.\n";
			}
			else { cout << "\nExiting. . .\n"; }
			
		} while (choose != 0);
	}

	void delRoom(int id) { 
		if (id != 0) {
			for (int i = 0; i < r_arr.size(); i++) {
				if (id == r_arr[i]->showId()) {
					if (r_arr[i]->getOqqupied() == true) {
						r_arr[i]->freeRoom();
					}
					cout << "Room #" << r_arr[i]->showId() << " have been deleted from hotel.";
					r_arr.erase(r_arr.begin() + i);
					break;
				}
			}
		}
		else { cout << "\nYou have entered wrong number.\n"; }
	}

	void editRoom() {
		int choose;
		cout << "=================================================\n";
		cout << "\t(for administration only!!!!)\n";
		cout << "=================================================\n";
		do {
			int rooms, bul;
			bool bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six, bul_sev, bul_eig;
			//system("cls");
			cout << "\tEditing existing Room\n";
			cout << "Enter Room number to edit (0: Exit): ";
			cin >> choose;
			
			for (int i = 0; i < r_arr.size(); i++){
				if (choose == r_arr[i]->showId()) {
					if (r_arr[i]->type() == "Presidential Room") {
						cout << "\t" << r_arr[i]->type();
						cout << "Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
						cout << "\nInput boolean value to add Safe 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setSave(true) : r_arr[i]->setSave(false);
						cout << "\nInput boolean value to add Jakussi 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setJakussi(true) : r_arr[i]->setJakussi(false);
						cout << "\nInput boolean value to add Access to Helicopter 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setHeliAccsess(true) : r_arr[i]->setHeliAccsess(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Lux Room") {
						cout << "\t" << r_arr[i]->type();
						cout << "Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
						cout << "\nInput boolean value to add Safe 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setSave(true) : r_arr[i]->setSave(false);
						cout << "\nInput boolean value to add Jakussi 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setJakussi(true) : r_arr[i]->setJakussi(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "VIP Room") {
						cout << "\t" << r_arr[i]->type();
						cout << "Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
						cout << "\nInput boolean value to add Safe 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setSave(true) : r_arr[i]->setSave(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "High Cost Room") {
						cout << "\t" << r_arr[i]->type();
						cout << "Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Premium Room") {
						cout << "\t" << r_arr[i]->type();
						cout << "Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Meduim Cost Room") {
						cout << "\t" << r_arr[i]->type();
						cout << "Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Small Cost Room") {
						cout << "\t" << r_arr[i]->type();
						cout << "Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Low Cost Room") {
						cout << "\t" << r_arr[i]->type();
						cout << "Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\nInput boolean value to set Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						r_arr[i]->setRooms(rooms);
					}
				}
				if(i==r_arr.size()-1&&choose!=0) {
					cout << "\nInputed incorrect code, please try again\n";
					system("pause");
					system("cls");
					continue;
				}
			}
		} while (choose != 0);
	}
	
	void editRoom(int r_id) {
		int rooms;
		bool bul;
		for (int i = 0; i < r_arr.size(); i++) {
			if (r_id == r_arr[i]->showId()) {
				if (r_arr[i]->type() == "Presidential Room") {
					cout << "\t" << r_arr[i]->type();
					cout << "Input amount of rooms you wish to set in: ";
					cin >> rooms;
					cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
					cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
					cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
					cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
					cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
					cout << "\nInput boolean value to add Safe 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setSave(true) : r_arr[i]->setSave(false);
					cout << "\nInput boolean value to add Jakussi 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setJakussi(true) : r_arr[i]->setJakussi(false);
					cout << "\nInput boolean value to add Access to Helicopter 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setHeliAccsess(true) : r_arr[i]->setHeliAccsess(false);
					r_arr[i]->setRooms(rooms);
				}
				else if (r_arr[i]->type() == "Lux Room") {
					cout << "\t" << r_arr[i]->type();
					cout << "Input amount of rooms you wish to set in: ";
					cin >> rooms;
					cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
					cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
					cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
					cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
					cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
					cout << "\nInput boolean value to add Safe 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setSave(true) : r_arr[i]->setSave(false);
					cout << "\nInput boolean value to add Jakussi 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setJakussi(true) : r_arr[i]->setJakussi(false);
					r_arr[i]->setRooms(rooms);
				}
				else if (r_arr[i]->type() == "VIP Room") {
					cout << "\t" << r_arr[i]->type();
					cout << "Input amount of rooms you wish to set in: ";
					cin >> rooms;
					cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
					cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
					cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
					cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
					cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
					cout << "\nInput boolean value to add Safe 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setSave(true) : r_arr[i]->setSave(false);
					r_arr[i]->setRooms(rooms);
				}
				else if (r_arr[i]->type() == "High Cost Room") {
					cout << "\t" << r_arr[i]->type();
					cout << "Input amount of rooms you wish to set in: ";
					cin >> rooms;
					cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
					cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
					cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
					cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
					cout << "\nInput boolean value to add Movie TV 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
					r_arr[i]->setRooms(rooms);
				}
				else if (r_arr[i]->type() == "Premium Room") {
					cout << "\t" << r_arr[i]->type();
					cout << "Input amount of rooms you wish to set in: ";
					cin >> rooms;
					cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
					cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
					cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
					cout << "\nInput boolean value to add Games 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
					r_arr[i]->setRooms(rooms);
				}
				else if (r_arr[i]->type() == "Meduim Cost Room") {
					cout << "\t" << r_arr[i]->type();
					cout << "Input amount of rooms you wish to set in: ";
					cin >> rooms;
					cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
					cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
					cout << "\nInput boolean value to add Better kitchen 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
					r_arr[i]->setRooms(rooms);
				}
				else if (r_arr[i]->type() == "Small Cost Room") {
					cout << "\t" << r_arr[i]->type();
					cout << "Input amount of rooms you wish to set in: ";
					cin >> rooms;
					cout << "\nInput boolean value to add Balcony 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
					cout << "\nInput boolean value to add Better toilet and bath 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
					r_arr[i]->setRooms(rooms);
				}
				else if (r_arr[i]->type() == "Low Cost Room") {
					cout << "\t" << r_arr[i]->type();
					cout << "Input amount of rooms you wish to set in: ";
					cin >> rooms;
					cout << "\nInput boolean value to set Balcony 1(yes)/0(no): ";
					cin >> bul;
					(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
					r_arr[i]->setRooms(rooms);
				}
			}
			if (i == r_arr.size() - 1 && choose != 0) {
				cout << "\nInputed incorrect code, please try again\n";
				system("pause");
				system("cls");
				continue;
			}
		}
	}

	void addOqqupier(string type, int max_rooms, int days, string oqqupierName, string oqqupierPhone, Date infiltration_d) {
		for (int i = 0; i < r_arr.size(); i++){
			if ((type.compare(r_arr[i]->type())==0)&& r_arr[i]->getRooms()==max_rooms){
				if (r_arr[i]->getOqqupied()==false){
					r_arr[i]->setOqqupie(days,oqqupierName,oqqupierPhone,infiltration_d);
				}
			}
		}
	}

	void dispAllRooms()const {
		for (int i = 0; i < r_arr.size(); i++)
		{
			r_arr[i]->show();
		}
	}

	void showAval()const {
		for (int i = 0; i < r_arr.size(); i++)
		{
			if (r_arr[i]->getOqqupied()==false)
			{
				r_arr[i]->show();
			}
		}
	}

	void loadMainInfo() {
		
	}//WRITE!!!!
};
