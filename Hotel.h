#pragma once
#include "Room.h"
#include <fstream>
class Hotel
{
private:
	static int h_counter;//counter to hotels id; honestly idk why ¯\_(ツ)_/¯
	void updateId() { hotel_id = ++h_counter; }
protected:
	int hotel_id;//global id maybe to map
	int hotelX;//coords
	int hotelY;
	float rating;
	string adress;//adress
	string name;//name of hotel

public:
	vector<Room*> r_arr;//array of rooms

	//Contructors,Destructors
	Hotel() { updateId(); this->name = "unknown"; this->adress = "unknown"; this->hotelX = -1; this->hotelY = -1; this->hotel_id = -1; this->rating = -1; }
	Hotel(string adress, string name, int hotelX, int hotelY, float rating){
		updateId(); setCoords(hotelX, hotelY); setName(name); setAdress(adress); setRating(rating);
	}
	~Hotel() {
		for (int i = 0; i < r_arr.size(); i++)
		{
			//delete r_arr[i];
		}
		//r_arr.clear();
	}
	
	//Setters
	void setAdress(string adress) { (adress.length()>2) ? this->adress = adress : this->adress = "unknown"; }
	void setName(string name) { (name.length()>2) ? this->name = name : this->name = "unknown"; }
	void setCoords(int hotelX, int hotelY) {
		if (hotelX>0&&hotelY>0)
		{
			this->hotelX = hotelX;
			this->hotelY = hotelY;
		}
	}
	void setRating(float rating) { (rating > 0) ? this->rating = rating : this->rating = -1; }
	string getAdress()const { return adress; }
	string getName()const { return name; }
	float getRating()const { return rating; }
	float getPrice(int rid)const { return r_arr[rid]->getPrice(); }
	int getHotelId()const { return hotel_id; }
	int getRSize()const { return r_arr.size(); }
	int getX()const { return hotelX; }
	int getY()const { return hotelY; }

	//Manipulators
	void editHotel() {
		int menu,X,Y;
		float rating;
		string strTmp;
		do {
			cout << "--";
			for (int i = 0; i < 10; i++) {
				cout << "=";
			}
			cout << "~~ Hotel Editor ~~";
			for (int i = 0; i < 10; i++) {
				cout << "=";
			}
			cout << "--\n";
			showHotelInfo();
			cout << "--";
			for (int i = 0; i < 20; i++) {
				cout << "=";
			}
			cout << "--\n";
			cout << "|   1. Set Hotels name\n";
			cout << "|   2. Set Hotels adress\n";
			cout << "|   3. Set Hotels rating\n";
			cout << "|   4. Set Hotels coords\n";
			cout << "|   0. Return/Exit\n";
			cout << "| > > >";
			cin >> menu;
			switch (menu)
			{
			case 0:
				return;
			case 1:
				cout << "|   Input new hotel name\n";
				
				cout << "| > > >";
				cin.ignore();
				getline(cin, strTmp);
				setName(strTmp);
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "|   Input new hotel name\n";
				cout << "| > > >";
				cin.ignore();
				getline(cin, strTmp);
				setAdress(strTmp);
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "|   Input new hotel rating\n";
				cout << "| > > >";
				cin >> rating;
				setRating(rating);
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "|   Input new hotel coords\n";
				cout << "| > > >";
				cin >> X;
				cin >> Y;
				setCoords(X, Y);
				system("pause");
				system("cls");
				break;
			default:
				break;
			}
		} while (menu != 0);
		system("cls");
	}

	void addRoom() { 
		int choose;
		cout << "=================================================>\n";
		cout << "\t(for administration only!!!!)\n";
		cout << "=================================================>\n";
		do{
			int rooms, bul, i = r_arr.size();
			bool bul_on = false, bul_two = false, bul_tre = false, bul_for = false, bul_fiv = false, bul_six = false, bul_sev = false, bul_eig = false;
			system("cls");
			cout << "--==========~~ Adding new Room ~~==========--\n";
			cout << "|   We have several options to choose:\n";
			cout << "|   1 Add Low Cost Room\n";
			cout << "|   2 Add Small Cost Room\n";
			cout << "|   3 Add Medium Cost Room\n";
			cout << "|   4 Add Premium Room\n";
			cout << "|   5 Add High Cost Room\n";
			cout << "|   6 Add Vip Room\n";
			cout << "|   7 Add Lux Room\n";
			cout << "|   8 Add Presidential Room\n";
			cout << "|   0 Exit\n";
			cin >> choose;
			switch (choose){
			case 0:
				break;

			case 1:
				cout << "|   \tLow Cost Room\n";
				cout << "|   Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				r_arr.push_back(new LRoom(rooms, bul_on));
				r_arr[r_arr.size() - 1]->askClients();
				break;

			case 2:
				cout << "|   \tSmall Cost Room\n";
				cout << "|   Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				r_arr.push_back(new SRoom(rooms, bul_on, bul_two));
				break;

			case 3:
				cout << "|   \tMeduim Cost Room\n";
				cout << "|   Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				r_arr.push_back(new MRoom(rooms, bul_on, bul_two, bul_tre));
				break;

			case 4:
				cout << "|   \tPremium Room\n";
				cout << "|   Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				r_arr.push_back(new PRoom(rooms, bul_on, bul_two, bul_tre, bul_for));
				break;

			case 5:
				cout << "|   \tHigh Cost Room\n";
				cout << "|   Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				cout << "\n|   Input boolean value to add Movie TV 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_fiv = true : bul_fiv = false;
				r_arr.push_back(new HRoom(rooms, bul_on, bul_two, bul_tre, bul_for, bul_fiv));
				break;

			case 6:
				cout << "|   \tVIP Room\n";
				cout << "|   Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				cout << "\n|   Input boolean value to add Movie TV 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_fiv = true : bul_fiv = false;
				cout << "\n|   Input boolean value to add Safe 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_six = true : bul_six = false;
				r_arr.push_back(new VRoom(rooms, bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six));
				break;

			case 7:
				cout << "|   \tLux Room\n";
				cout << "|   Input amount of rooms you wish to set in: ";
				cin >> rooms;
				
				cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				cout << "\n|   Input boolean value to add Movie TV 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_fiv = true : bul_fiv = false;
				cout << "\n|   Input boolean value to add Safe 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_six = true : bul_six = false;
				cout << "\n|   Input boolean value to add Jakussi 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_sev = true : bul_sev = false;
				r_arr.push_back(new LxRoom(rooms, bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six, bul_sev));
				break;

			case 8:
				cout << "|   \tPresidetial Room\n";
				cout << "|   Input amount of rooms you wish to set in: ";
				cin >> rooms;

				cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_on = true : bul_on = false;
				cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_two = true : bul_two = false;
				cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_tre = true : bul_tre = false;
				cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_for = true : bul_for = false;
				cout << "\n|   Input boolean value to add Movie TV 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_fiv = true : bul_fiv = false;
				cout << "\n|   Input boolean value to add Safe 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_six = true : bul_six = false;
				cout << "\n|   Input boolean value to add Jakussi 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_sev = true : bul_sev = false;
				cout << "\n|   Input boolean value to add Access to Helicopter 1(yes)/0(no): ";
				cin >> bul;
				(bul == 1) ? bul_eig = true : bul_eig = false;
				r_arr.push_back(new PresRoom(rooms, bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six, bul_sev, bul_eig));
				break;

			default:
				cout << "\n#   Inputed incorrect code, please try again\n";
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
			cout << "|   Input ID of room to delete it: ";
			cin >> choose;
			if (choose !=0){
				for (int i = 0; i < r_arr.size(); i++) {
					if (choose == r_arr[i]->showId()) {
						if (r_arr[i]->getOqqupied() == true) {
							r_arr[i]->freeRoom();
						}
						cout << "|   Room #" << r_arr[i]->showId() << " have been deleted from hotel.";
						r_arr.erase(r_arr.begin() + i);
						break;
					}
				}
				cout << "\n#   You have entered wrong number.\n";
			}
			else { cout << "\n|   Exiting. . .\n"; system("pause"); }
			
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
			cout << "--==========~~ Editing existing Room ~~==========--\n";
			for (int i = 0; i < r_arr.size(); i++){
				cout << r_arr[i]->type() + " "; r_arr[i]->DispId(); cout << endl;
				r_arr[i]->show();
			}
			cout << "|   Enter Room number to edit (0: Exit): ";
			cin >> choose;
			
			for (int i = 0; i < r_arr.size(); i++){
				if (choose == r_arr[i]->showId()) {
					if (r_arr[i]->type() == "Presidential Room") {
						cout << "|   \t" << r_arr[i]->type();
						cout << "|   Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						cout << "\n|   Input boolean value to add Movie TV 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
						cout << "\n|   Input boolean value to add Safe 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setSave(true) : r_arr[i]->setSave(false);
						cout << "\n|   Input boolean value to add Jakussi 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setJakussi(true) : r_arr[i]->setJakussi(false);
						cout << "\n|   Input boolean value to add Access to Helicopter 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setHeliAccsess(true) : r_arr[i]->setHeliAccsess(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Lux Room") {
						cout << "|   \t" << r_arr[i]->type();
						cout << "|   Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						cout << "\n|   Input boolean value to add Movie TV 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
						cout << "\n|   Input boolean value to add Safe 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setSave(true) : r_arr[i]->setSave(false);
						cout << "\n|   Input boolean value to add Jakussi 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setJakussi(true) : r_arr[i]->setJakussi(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "VIP Room") {
						cout << "|   \t" << r_arr[i]->type();
						cout << "|   Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						cout << "\n|   Input boolean value to add Movie TV 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
						cout << "\n|   Input boolean value to add Safe 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setSave(true) : r_arr[i]->setSave(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "High Cost Room") {
						cout << "|   \t" << r_arr[i]->type();
						cout << "|   Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						cout << "\n|   Input boolean value to add Movie TV 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setMovieTV(true) : r_arr[i]->setMovieTV(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Premium Room") {
						cout << "|   \t" << r_arr[i]->type();
						cout << "|   Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						cout << "\n|   Input boolean value to add Games 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setGames(true) : r_arr[i]->setGames(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Meduim Cost Room") {
						cout << "|   \t" << r_arr[i]->type();
						cout << "|   Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						cout << "\n|   Input boolean value to add Better kitchen 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setKitchen(true) : r_arr[i]->setKitchen(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Small Cost Room") {
						cout << "|   \t" << r_arr[i]->type();
						cout << "|   Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\n|   Input boolean value to add Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						cout << "\n|   Input boolean value to add Better toilet and bath 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBodyNeeds(true) : r_arr[i]->setBodyNeeds(false);
						r_arr[i]->setRooms(rooms);
					}
					else if (r_arr[i]->type() == "Low Cost Room") {
						cout << "|   \t" << r_arr[i]->type();
						cout << "|   Input amount of rooms you wish to set in: ";
						cin >> rooms;
						cout << "\n|   Input boolean value to set Balcony 1(yes)/0(no): ";
						cin >> bul;
						(bul == 1) ? r_arr[i]->setBalcony(true) : r_arr[i]->setBalcony(false);
						r_arr[i]->setRooms(rooms);
					}
				}
				if(i==r_arr.size()-1&&choose!=0) {
					cout << "\n#   Inputed incorrect code, please try again\n";
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
			if (i == r_arr.size() - 1 && r_id != 0) {
				cout << "\nInputed incorrect code, please try again\n";
				system("pause");
				system("cls");
				continue;
			}
		}
	}

	//Accessors
	void addOqqupier(int rId, int days, string oqqupierName, string oqqupierPhone, Date infiltration_d) {
		for (int i = 0; i < r_arr.size(); i++){
			if (i == rId){
				if (r_arr[i]->getOqqupied()==false){
					r_arr[i]->setOqqupie(days,oqqupierName,oqqupierPhone,infiltration_d);
					r_arr[i]->askClients();
					system("pause");
					return;
				}
				else {
					cout << "#   This room misteriously got oqqupied(\n";
					return;
				}
			}
		}
		cout << "#   Unable to make order to this room, hope you luck next time!\n";
		system("pause");
	}
	float calcSumm(int rId) { return r_arr[rId]->calcSumm(); }
	float calcOqupied()const {
		int ret = 0;
		for (int i = 0; i < r_arr.size(); i++) {
			if (r_arr[i]->getOqqupied()) {
				ret++;
			}
		}
		return ret;
	}

	//Displayers
	void dispAllRooms()const {
		if (r_arr.size()==0){
			cout << "#   How already created hotel can be without rooms???\n";
		}
		else {
			for (int i = 0; i < r_arr.size(); i++)
			{
				r_arr[i]->show();
			}
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
	void showForClients()const {
		for (int i = 0; i < r_arr.size(); i++)
		{
			r_arr[i]->showClient();
		}
	}
	void showHotelInfo() {
		cout << "==========================================================>\n";
		cout << "|   \tHotel: " + getName() << endl;
		cout << "|   Adress: " + getAdress() + "; Coordinates on map" << getX() << " " << getY() << endl;
		cout << "|   Rating: " << getRating() << endl;
		cout << "|   Fullness: " << calcOqupied() / r_arr.size() <<"%" << endl;
		cout << "|   Amount of Rooms: " << r_arr.size() << endl;
		cout << "==========================================================>\n";
	}
	void showRoomInfo() {
		for (int i = 0; i < r_arr.size(); i++)
		{
			r_arr[i]->show();
		}
	}

	//File manipulation
	void loadMainInfo(ifstream& file) {
		bool uploading = false;
		char delimiter = '|';
		string line;
		while (getline(file, line)) {
			//cout << line << endl;
			if (line.find("#Rooms#") != string::npos) {
				uploading = true;
			}
			else if (line.find("#Rooms#") == string::npos && !uploading) {
				continue;
			}
			if (line.find("#Hotel#") != string::npos || line.find("#End#") != string::npos || line.find("") == string::npos || line.empty()) {
				if (uploading){
					uploading = false;
				}
				break;
			}
			else if (line.find("#Rooms#") != string::npos && uploading || uploading && line.find("#Hotel#") == string::npos) {
				getline(file, line);
				vector<string> tokens;
				stringstream ss(line);
				string token;
				while (getline(ss, token, delimiter)) {
					tokens.push_back(token);
				}
				int r_tmp, bul;
				bool bul_on = false, bul_two = false, bul_tre = false, bul_for = false, bul_fiv = false, bul_six = false, bul_sev = false, bul_eig = false;
				switch (tokens.size()) {
				case 2:
					r_tmp = stoi(tokens[0], nullptr, 10);
					(stoi(tokens[1], nullptr, 10) == 1) ? bul_on = true : bul_on = false;
					r_arr.push_back(new LRoom(r_tmp, bul_on));
					continue;
				case 3:
					r_tmp = stoi(tokens[0], nullptr, 10);
					(stoi(tokens[1], nullptr, 10) == 1) ? bul_on = true : bul_on = false;
					(stoi(tokens[2], nullptr, 10) == 1) ? bul_two = true : bul_two = false;
					r_arr.push_back(new SRoom(r_tmp, bul_on, bul_two));
					continue;
				case 4:
					r_tmp = stoi(tokens[0], nullptr, 10);
					(stoi(tokens[1], nullptr, 10) == 1) ? bul_on = true : bul_on = false;
					(stoi(tokens[2], nullptr, 10) == 1) ? bul_two = true : bul_two = false;
					(stoi(tokens[3], nullptr, 10) == 1) ? bul_tre = true : bul_tre = false;
					r_arr.push_back(new MRoom(r_tmp, bul_on, bul_two, bul_tre));
					continue;
				case 5:
					r_tmp = stoi(tokens[0], nullptr, 10);
					(stoi(tokens[1], nullptr, 10) == 1) ? bul_on = true : bul_on = false;
					(stoi(tokens[2], nullptr, 10) == 1) ? bul_two = true : bul_two = false;
					(stoi(tokens[3], nullptr, 10) == 1) ? bul_tre = true : bul_tre = false;
					(stoi(tokens[4], nullptr, 10) == 1) ? bul_for = true : bul_for = false;
					r_arr.push_back(new PRoom(r_tmp, bul_on, bul_two, bul_tre, bul_for));
					continue;
				case 6:
					r_tmp = stoi(tokens[0], nullptr, 10);
					(stoi(tokens[1], nullptr, 10) == 1) ? bul_on = true : bul_on = false;
					(stoi(tokens[2], nullptr, 10) == 1) ? bul_two = true : bul_two = false;
					(stoi(tokens[3], nullptr, 10) == 1) ? bul_tre = true : bul_tre = false;
					(stoi(tokens[4], nullptr, 10) == 1) ? bul_for = true : bul_for = false;
					(stoi(tokens[5], nullptr, 10) == 1) ? bul_fiv = true : bul_fiv = false;
					r_arr.push_back(new HRoom(r_tmp, bul_on, bul_two, bul_tre, bul_for, bul_fiv));
					continue;
				case 7:
					r_tmp = stoi(tokens[0], nullptr, 10);
					(stoi(tokens[1], nullptr, 10) == 1) ? bul_on = true : bul_on = false;
					(stoi(tokens[2], nullptr, 10) == 1) ? bul_two = true : bul_two = false;
					(stoi(tokens[3], nullptr, 10) == 1) ? bul_tre = true : bul_tre = false;
					(stoi(tokens[4], nullptr, 10) == 1) ? bul_for = true : bul_for = false;
					(stoi(tokens[5], nullptr, 10) == 1) ? bul_fiv = true : bul_fiv = false;
					(stoi(tokens[6], nullptr, 10) == 1) ? bul_six = true : bul_six = false;
					r_arr.push_back(new VRoom(r_tmp, bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six));
					continue;
				case 8:
					r_tmp = stoi(tokens[0], nullptr, 10);
					(stoi(tokens[1], nullptr, 10) == 1) ? bul_on = true : bul_on = false;
					(stoi(tokens[2], nullptr, 10) == 1) ? bul_two = true : bul_two = false;
					(stoi(tokens[3], nullptr, 10) == 1) ? bul_tre = true : bul_tre = false;
					(stoi(tokens[4], nullptr, 10) == 1) ? bul_for = true : bul_for = false;
					(stoi(tokens[5], nullptr, 10) == 1) ? bul_fiv = true : bul_fiv = false;
					(stoi(tokens[6], nullptr, 10) == 1) ? bul_six = true : bul_six = false;
					(stoi(tokens[7], nullptr, 10) == 1) ? bul_sev = true : bul_sev = false;
					r_arr.push_back(new LxRoom(r_tmp, bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six, bul_sev));
					continue;
				case 9:
					r_tmp = stoi(tokens[0], nullptr, 10);
					(stoi(tokens[1], nullptr, 10) == 1) ? bul_on = true : bul_on = false;
					(stoi(tokens[2], nullptr, 10) == 1) ? bul_two = true : bul_two = false;
					(stoi(tokens[3], nullptr, 10) == 1) ? bul_tre = true : bul_tre = false;
					(stoi(tokens[4], nullptr, 10) == 1) ? bul_for = true : bul_for = false;
					(stoi(tokens[5], nullptr, 10) == 1) ? bul_fiv = true : bul_fiv = false;
					(stoi(tokens[6], nullptr, 10) == 1) ? bul_six = true : bul_six = false;
					(stoi(tokens[7], nullptr, 10) == 1) ? bul_sev = true : bul_sev = false;
					(stoi(tokens[8], nullptr, 10) == 1) ? bul_eig = true : bul_eig = false;
					r_arr.push_back(new PresRoom(r_tmp, bul_on, bul_two, bul_tre, bul_for, bul_fiv, bul_six, bul_sev, bul_eig));
					continue;
				case 0: case 1:
					cout << "#   Not enought data to load into system.\n";
				}
			}
			else if (!(line.find("#Init#") != string::npos)) {
				cout << "#   File is empty or it is unable to find correct info, please check info for fixing problem.\n";
			}
		}
	}
	void saveMainInfo(ofstream& file) {
		string out_tmp;
		if (r_arr.size() == 0){
			file.close();
		}
		else {
			file << "#Rooms#\n";
			for (int i = 0; i < r_arr.size(); i++){
				if (r_arr[i]->type() == "Low Cost Room") {
					out_tmp = to_string(r_arr[i]->getRooms()) + "|" + to_string(r_arr[i]->getBalcony());
					file << out_tmp;
					file << endl;
				}
				else if (r_arr[i]->type() == "Small Cost Room") {
					out_tmp = to_string(r_arr[i]->getRooms()) + "|" + to_string(r_arr[i]->getBalcony()) + "|" + to_string(r_arr[i]->getBodyNeeds());
					file << out_tmp;
					file << endl;
				}
				else if (r_arr[i]->type() == "Meduim Cost Room") {
					out_tmp = to_string(r_arr[i]->getRooms()) + "|" + to_string(r_arr[i]->getBalcony()) + "|" + to_string(r_arr[i]->getBodyNeeds()) + "|" + to_string(r_arr[i]->getKitchen());
					file << out_tmp;
					file << endl;
				}
				else if (r_arr[i]->type() == "Premium Room") {
					out_tmp = to_string(r_arr[i]->getRooms()) + "|" + to_string(r_arr[i]->getBalcony()) + "|" + to_string(r_arr[i]->getBodyNeeds()) + "|" + to_string(r_arr[i]->getKitchen()) + "|" + to_string(r_arr[i]->getGames());
					file << out_tmp;
					file << endl;
				}
				else if (r_arr[i]->type() == "High Cost Room") {
					out_tmp = to_string(r_arr[i]->getRooms()) + "|" + to_string(r_arr[i]->getBalcony()) + "|" + to_string(r_arr[i]->getBodyNeeds()) + "|" + to_string(r_arr[i]->getKitchen()) + "|" + to_string(r_arr[i]->getGames()) + "|" + to_string(r_arr[i]->getMovieTV());
					file << out_tmp;
					file << endl;
				}
				else if (r_arr[i]->type() == "VIP Room") {
					out_tmp = to_string(r_arr[i]->getRooms()) + "|" + to_string(r_arr[i]->getBalcony()) + "|" + to_string(r_arr[i]->getBodyNeeds()) + "|" + to_string(r_arr[i]->getKitchen()) + "|" + to_string(r_arr[i]->getGames()) + "|" + to_string(r_arr[i]->getMovieTV()) + "|" + to_string(r_arr[i]->getSave());
					file << out_tmp;
					file << endl;
				}
				else if (r_arr[i]->type() == "Lux Room") {
					out_tmp = to_string(r_arr[i]->getRooms()) + "|" + to_string(r_arr[i]->getBalcony()) + "|" + to_string(r_arr[i]->getBodyNeeds()) + "|" + to_string(r_arr[i]->getKitchen()) + "|" + to_string(r_arr[i]->getGames()) + "|" + to_string(r_arr[i]->getMovieTV()) + "|" + to_string(r_arr[i]->getSave()) + "|" + to_string(r_arr[i]->getJakussi());
					file << out_tmp;
					file << endl;
				}
				else if (r_arr[i]->type() == "Presidential Room") {
					out_tmp = to_string(r_arr[i]->getRooms()) + "|" + to_string(r_arr[i]->getBalcony()) + "|" + to_string(r_arr[i]->getBodyNeeds()) + "|" + to_string(r_arr[i]->getKitchen()) + "|" + to_string(r_arr[i]->getGames()) + "|" + to_string(r_arr[i]->getMovieTV()) + "|" + to_string(r_arr[i]->getSave()) + "|" + to_string(r_arr[i]->getJakussi()) + "|" + to_string(r_arr[i]->getHeliAccsess());
					file << out_tmp;
					file << endl;
				}
			}
		}
	}
};
