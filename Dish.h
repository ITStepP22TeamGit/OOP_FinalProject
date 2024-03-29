#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Dish
{
protected:
	string name;
	float price;

public:
	Dish();
	Dish(string _name, float _price);

	void setName(string _name);
	string getName() const;

	void setPrice(float _price);
	float getPrice() const;

	void showDish() const;

	void saveDishToFile(ofstream& file) const;
	void loadDishFromFile(ifstream& file);
};

