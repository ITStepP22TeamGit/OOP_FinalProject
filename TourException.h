#pragma once
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

class TourException
{
public:
	virtual string message()const = 0;
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
	string message()const override {
		switch (choice)
		{
		case 1:
			return "Too small string!\n";
		case 2:
			return "Too small price!\n";
		case 3:
			return "Too small number!\n";
		case 4:
			return "Number is bigger than max number!\n";
		case 5:
			return "Min number is bigger than max number!\n";
		case 6:
			return "Too small amount of days!\n";
		case 7:
			return "Tour can't be for more than 30 days!\n";
		case 8:
			return "Height is smaller than the lowest in the world mountain's!\n";
		case 9:
			return "Height can be bigger than Everest's!\n";
		case 10:
			return "Couldn't open a file with name \"" + str + "\"!\n";
		case 11:
			return "Incorrect type!\n";
		default:
			return "Input error!\n";
		}
	}
};

class TourInputDateException : public TourException
{
public:
	Date t = Date();
	string message()const override {
		return "The input date can only be after the current one (" + to_string(t.getDay() / 10) + to_string(t.getDay() % 10) + "." + to_string(t.getMonth() / 10) + to_string(t.getMonth() % 10) + "." + to_string(t.getYear() / 10) + to_string(t.getYear() % 10) + ")\n";
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
	string message()const override {
		return "Price of service is bigger than the price of the tour (price of tour - " + to_string(price) + " $)\n";
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
	string message()const override {
		switch (choice)
		{
		case 1:
			return "Number of tourists is bigger than max number (max number of tourists - " + to_string(number) + ")\n";
		case 2:
			return "Min number of tourists is bigger than max number (max number of tourists - " + to_string(number) + ")\n";
		case 3:
			return "Number of tourists is bigger than max number (number of tourists - " + to_string(number) + ")\n";
		case 4:
			return "Min number of tourists is bigger than max number (min number of tourists - " + to_string(number) + ")\n";
		default:
			return "Input error!\n";
		}
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
	string message()const override {
		switch (choice)
		{
		case 1:
			return "There is no such an object with this parameter/parameters!\n";
		case 2:
			return "There is no object like this in the array!\n";
		case 3:
			return "There are no tours yet!\n";
		default:
			return "Input error!\n";
			break;
		}
	}
};

class MapException : public TourException
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
	string message()const override {
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