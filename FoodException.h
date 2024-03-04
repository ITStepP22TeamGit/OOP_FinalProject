#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class FoodException {
public:
	virtual string message() const = 0;
};

class FoodEmptyNameException : public FoodException {
public:
	virtual string message() const override {
		return "Name is empty!";
	}
};

class FoodTimeException : public FoodException {
public:
	virtual string message() const override {
		return "Invalid time!";
	}
};

class FoodAdressException : public FoodException {
public:
	virtual string message() const override {
		return "Adress is empty or too small to be real!";
	}
};

class FoodRatingException : public FoodException {
public:
	virtual string message() const override {
		return "Incorrect rating! Rating system: 0-10";
	}
};

class FoodMusicGenreException : public FoodException {
public:
	virtual string message() const override {
		return "The music genre is empty!";
	}
};

class FoodCuisineTypeException : public FoodException {
public:
	virtual string message() const override {
		return "The cuisine type is empty, or too small to be real!";
	}
};

class FoodEqualTimesException : public FoodException {
public:
	virtual string message() const override {
		return "Opening and closing times cannot coincide!";
	}
};

class FoodTimeInvalidException : public FoodException {
public:
	virtual string message() const override {
		return "The time is incorrect! Format: HH(0-23) MM(0-59).";
	}
};

class FoodDishNameSameException : public FoodException {
public:
	virtual string message() const override {
		return "Such a dish has already been added!";
	}
};

class FoodDishPriceException : public FoodException {
public:
	virtual string message() const override {
		return "The price cannot be negative or be equal to zero!";
	}
};

class FoodCoordinatesException : public FoodException {
public:
	virtual string message() const override {
		return "The x coordinate cannot be greater than 50 or less than 1.\nThe y coordinate cannot be less than 1 or greater than 40.";
	}
};