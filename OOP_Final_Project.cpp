#include <iostream>
#include "Hotel.h"
#include "TourAgency.h"
#include "Map.h"
using namespace std;
//#include "Room.h"
//int Room::r_counter = 0;
int Hotel::h_counter = 0;
int Map::staticHotels = 0;
int Map::staticRestaurants = 0;

int main()
{
    //TourAgency albania("Alb Escorts");


    srand(time(0));
    cout << "Hello World!\n";

    //Hotel a("Somewhere in city", 5, 5);
    //a.addRoom(new LRoom(6, true));
    //a.loadMainInfo("data/Hotel/tro.txt");
    //a.saveMainInfo("data/Hotel/tra.txt");
    //a.dispAllRooms();

    //a.addRoom();

    //a.dispAllRooms();
}

//vector<Room*>arr;
//arr.push_back(new LRoom(5, true));
//arr.push_back(new SRoom(5, true));
//arr.push_back(new MRoom(5, true));
//arr.push_back(new PRoom(5, true));
//arr.push_back(new HRoom(5, true));
//arr.push_back(new VRoom(5, true));
//arr.push_back(new LxRoom(5, true));
//arr.push_back(new PresRoom(5, true));
//
//for (int i = 0; i < arr.size(); i++) {
//    arr[i]->show();
//}
//
//arr[0]->setOqqupierInfo(60, "Vasilij Pupkin", "", Date(01, 07, 2024));
//
//for (int i = 0; i < arr.size(); i++) {
//    arr[i]->show();
//}


