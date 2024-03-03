#pragma once

#include<iostream>
#include<string>
#include"Date.h"
#include"Time_.h"
#include"TourException.h"
#include<fstream>
#include<vector>
#include<conio.h>
#include<Windows.h>
using namespace std;

class Tour
{
protected:
	string name;
	string address;
	vector<string>equipment;
	string description;
	Date date;
	Time_ time;
	float rating;
	int amountOfRatings; //возможность ставить пользователю оценку для тура
	float price;
	bool photos;
	float photosPrice;
	int arriveTransport;
	string TransportType[3] = { "bus", "taxi", "minibus" };
	float priceTransportType1;
	float priceTransportType2;
	float priceTransportType3;
	string guide;
	int number;
	int minNumber;
	int maxNumber;
public:
	Tour();
	Tour(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
		float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber);
	virtual ~Tour();

	//сеттеры
	void setName(string _name);
	void setAddress(string _address);
	void setEquipment();
	void setDescription(string _description);
	void setDate(Date _date);
	void setTime(Time_ _time);
	void setRating(float _rating);
	void setPrice(float _price);
	void setPhotos(bool _photos);
	void setPhotosPrice(float _photosPrice);
	void setPriceTransportType1(float _priceTransportType1);
	void setPriceTransportType2(float _priceTransportType2);
	void setPriceTransportType3(float _priceTransportType3);
	void setGuide(string _guide);
	void setNumber(int _number);
	void setMinNumber(int _minNumber);
	void setMaxNumber(int _maxNumber);
	void setNumbers(int _number, int _minNumber, int _maxNumber);
	void setArriveTransport(int _arriveTransport);

	//геттеры
	string getName()const;
	string getAddress()const;
	bool checkEquipment(string _equipment)const;
	string getDescription()const;
	Date getDate()const;
	Time_ getTime()const;
	float getRating()const;
	float getPrice()const;
	bool getPhotos()const;
	float getPhotosPrice()const;
	float getPriceTransportType1()const;
	float getPriceTransportType2()const;
	float getPriceTransportType3()const;
	string getGuide()const;
	int getNumber()const;
	int getMinNumber()const;
	int getMaxNumber()const;
	int getArriveTransport()const;

	void delEquipment(string _name);
	void delAllEquipment();
	void addClientsRating(int _rating);

	//виртуальные методы
	virtual void TourShow()const;
	virtual void TourShowClients()const;
	virtual void TourEdit();
	bool checkIsTourAvailable()const;

	//перегрузки операторов
	bool operator > (const Tour& obj)const&;
	bool operator < (const Tour& obj)const&;

	virtual void saveToFile(ofstream& file)const;
	virtual void loadFromFile(ifstream& file);

	virtual string TourType()const = 0;

	virtual void askClient();
};