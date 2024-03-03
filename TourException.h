#pragma once
#include<iostream>
#include<string>
#include"Date.h"
#include<conio.h>
#include<Windows.h>
using namespace std;

class TourException
{
public:
	virtual void message()const = 0;
};

class TourInputErrorException : public TourException
{
protected:
	int choice;
	string str;
public:
	TourInputErrorException() {
		choice = 0;
		str = "";
	}
	TourInputErrorException(int _choice) {
		choice = _choice;
		str = "";
	}
	TourInputErrorException(int _choice, string _str) {
		choice = _choice;
		str = _str;
	}
	void message()const override{
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, 4);
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "|   Too small string!\n";
			break;
			//return "|   Too small string!\n";
		case 2:
			cout << "|   Too small price!\n";
			break;
		case 3:
			cout << "|   Too small number!\n";
			break;
		case 4:
			cout << "|   Number is bigger than max number!\n";
			break;
		case 5:
			cout << "|   Min number is bigger than max number!\n";
			break;
		case 6:
			cout << "|   Too small amount of days!\n";
			break;
		case 7:
			cout << "|   Tour can't be for more than 30 days!\n";
			break;
		case 8:
			cout << "|   Height is smaller than the lowest in the world mountain's!\n";
			break;
		case 9:
			cout << "|   Height can be bigger than Everest's!\n";
			break;
		case 10:
			cout << "|   Couldn't open a file with name \"" << str << "\"!\n";
			break;
		case 11:
			cout << "|   Incorrect type!\n";
			break;
		case 12:
			cout << "|   Amount of restaurants is bigger than 4!\n";
			break;
		case 13:
			cout << "|   Object can't be added because limit of restaurant is reached!\n";
			break;
		case 14:
			cout << "|   There are no restaurants yet!\n";
			break;
		case 15:
			cout << "|   There are no type of transport with this index! (max index: 3)\n";
			break;
		case 16:
			cout << "|   There are no equipment yet!\n";
			break;
		case 17:
			cout << "|   There are no equipment with such a name!\n";
			break;
		case 18:
			cout << "|   Rating is bigger than 5!\n";
			break;
		default:
			cout << "|   Input error!\n";
			break;
		}
		SetConsoleTextAttribute(console_color, 15);
	}
};

class TourInputDateException : public TourException
{
public:
	Date t = Date();
	void message()const override {
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, 4);
		cout << endl;
		cout<< "|   The input date can only be after the current one (" + to_string(t.getDay() / 10) + to_string(t.getDay() % 10) + "." + to_string(t.getMonth() / 10) + to_string(t.getMonth() % 10) + "." + to_string(t.getYear() / 10) + to_string(t.getYear() % 10) + ")\n";
		SetConsoleTextAttribute(console_color, 15);
	}
};

class TourInputPriceServiceException : public TourException
{
protected:
	float price;
public:
	TourInputPriceServiceException(int _price) {
		price = _price;
	}
	void message()const override {
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, 4);
		cout << endl;
		cout<< "|   Price of service is bigger than the price of the tour (price of tour - " + to_string(price) + " $)\n";
		SetConsoleTextAttribute(console_color, 15);
	}
};

class TourInputNumberException : public TourException
{
protected:
	int choice, number;
public:
	TourInputNumberException(int _choice, int _number) {
		choice = _choice;
		number = _number;
	}
	void message()const override {
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, 4);
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "|   Number of tourists is bigger than max number (max number of tourists - " + to_string(number) + ")\n";
			break;
		case 2:
			cout << "|   Min number of tourists is bigger than max number (max number of tourists - " + to_string(number) + ")\n";
			break;
		case 3:
			cout << "|   Number of tourists is bigger than max number (number of tourists - " + to_string(number) + ")\n";
			break;
		case 4:
			cout << "|   Min number of tourists is bigger than max number (min number of tourists - " + to_string(number) + ")\n";
			break;
		default:
			cout << "|   Input error!\n";
			break;
		}
		SetConsoleTextAttribute(console_color, 15);
	}
};

class TourArrayException : public TourException
{
protected:
	int choice;
public:
	TourArrayException() {
		choice = 0;
	}
	TourArrayException(int _choice) {
		choice = _choice;
	}
	void message()const override {
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, 4);
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "|   There is no such an object with this parameter/parameters!\n";
			break;
		case 2:
			cout << "|   There is no object like this in the array!\n";
			break;
		case 3:
			cout << "|   There are no tours yet!\n";
			break;
		case 4:
			cout << "|   There is no such a tour type!\n";
			break;
		case 5:
			cout << "|   Too small string!\n";
			break;
		default:
			cout << "|   Input error!\n";
			break;
		}
		SetConsoleTextAttribute(console_color, 15);
	}
};

class MapException
{
protected:
	int choice;
	int intVar;
public:
	MapException() {
		choice = 0;
		intVar = 0;
	}
	MapException(int _choice) {
		choice = _choice;
		intVar = 0;
	}
	MapException(int _choice, float _floatVar) {
		choice = _choice;
		intVar = _floatVar;
	}
	string message()const {
		switch (choice)
		{
		case 1:
			return "Length is smaller than min length! (min length: 3)\n";
		case 2:
			return "Width is smaller than min width! (min width: 3)\n";
		case 3:
			return "Too small x!\n";
		case 4:
			return "x is bigger than length! (length: " + to_string(intVar) + ")\n";
		case 5:
			return "Too small y!\n";
		case 6:
			return "y is bigger than width! (width: " + to_string(intVar) + ")\n";
		case 7:
			return "Too small string!\n";
		case 8:
			return "There is no such an object!\n";
		case 9:
			return "There are no points yet!\n";
		case 10:
			if (intVar == 1) {
				return "There is no such an object with the first index!\n";
			}
			else {
				return "There is no such an object with the second index!\n";
			}
		case 11:
			if (intVar == 1) {
				return "There is no such an object with the first name!\n";
			}
			else {
				return "There is no such an object with the second name!\n";
			}
		case 12:
			return "Chosen points are probably the same one! Distance is 0.\n";
		case 13:
			return "There is already an object with such a name!\n";
		case 14:
			return "There is already a hotel with these coordinates!\n";
		case 15:
			return "There is already a restaurant with these coordinates!\n";
		case 16:
			return "Reached hotels limit! (limit: 14)\n";
		case 17:
			return "Reached restaurants limit! (limit: 14)\n";
		default:
			return "Input error!\n";
		}
	}
};