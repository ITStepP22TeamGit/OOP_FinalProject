#include "Dish.h"

Dish::Dish()
{
    name = "Pizza";
    price = 15;
}

Dish::Dish(string _name, float _price)
{
    setName(_name);
    setPrice(_price);
}

void Dish::setName(string _name)
{
    name = _name;
}

string Dish::getName() const
{
    return name;
}

void Dish::setPrice(float _price)
{
    price = _price;
}

float Dish::getPrice() const
{
    return price;
}

void Dish::showDish() const
{
    if (name.size() >= 8) {
        cout << name << "   " << price << "$" << endl;
    }
    else {
        cout << name << "\t   " << price << "$" << endl;
    }
}

void Dish::saveDishToFile(ofstream& file) const
{
    file << name << endl;
    file << price << endl;
}

void Dish::loadDishFromFile(ifstream& file)
{
    getline(file, name);
    file >> price;
}
