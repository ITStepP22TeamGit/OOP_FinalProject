#pragma once
#include <iostream>
#include <string>
using namespace std;

class UserException {
public:
	virtual string message() const = 0;
};

class UserStringException : public UserException {
public:
	virtual string message() const override {
		return "Input is empty!";
	}
};