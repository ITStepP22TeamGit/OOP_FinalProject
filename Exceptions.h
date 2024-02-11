#pragma once
#include<iostream>
#include<string>
using namespace std;

class Exceptions
{
public:
	virtual string message() const = 0;
};

class RoomsException : public Exceptions {
public:
	string message() const override {
		return "You can`t have less then one room in Room\n";
	}
};