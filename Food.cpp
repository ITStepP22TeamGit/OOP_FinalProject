#include "Food.h"

Food::Food()
{
    name = "South Snakes";
    adress = "Miami, Snakes street 8";
    rating = 0;
    x = 0;
    y = 0;
}

Food::Food(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime,
    Time_ _closingTime)
{
    setName(_name);
    setAdress(_adress);
    setRating(_rating);
    changeCoordinates(_x, _y);
    setOpeningTime(_openingTime);
    setClosingTime(_closingTime);
}

Food::~Food()
{
    for (int i = 0; i < menu.size(); i++) {
        delete menu[i];
    }
    menu.clear();
}

void Food::setOpeningTime(Time_ obj)
{
    if (obj == closingTime) {
        throw new FoodEqualTimesException();
    }
    openingTime = obj;
}

void Food::setClosingTime(Time_ obj)
{
    if (obj == openingTime) {
        throw new FoodEqualTimesException();
    }
    closingTime = obj;
}

Time_ Food::getOpeningTime() const
{
    return openingTime;
}

Time_ Food::getClosingTime() const
{
    return closingTime;
}

void Food::setName(string _name)
{
    if (_name.empty()) {
        throw new FoodEmptyNameException();
    }
    name = _name;
}

string Food::getName() const
{
    return name;
}

void Food::setAdress(string _adress)
{
    if (_adress.size() <= 3) {
        throw new FoodAdressException();
    }
    adress = _adress;
}

string Food::getAdress() const
{
    return adress;
}

void Food::setRating(int _rating)
{
    if (_rating < 0 || _rating > 10) {
        throw new FoodRatingException();
    }
    rating = _rating;
}

int Food::getRating() const
{
    return rating;
}

void Food::changeCoordinates(int _x, int _y)
{
    x = _x;
    y = _y;
}

int Food::getX() const
{
    return x;
}

int Food::getY() const
{
    return y;
}

void Food::addDish(Dish* obj)
{
    menu.push_back(obj);
}

void Food::delDish(string _dishName)
{
    for (int i = 0; i < menu.size(); i++) {
        if (menu[i]->getName() == _dishName) {
            menu.erase(menu.begin() + i);
            cout << "The dish has been successfully deleted!" << endl;
            return;
        }
    }
    cout << "Dish with this name does not found!" << endl;
}

bool Food::operator<(const Food& other) const
{
    return rating < other.rating;
}

bool Food::operator>(const Food& other) const
{
    return rating > other.rating;
}
