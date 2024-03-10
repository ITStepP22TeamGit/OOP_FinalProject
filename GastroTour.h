#pragma once
#include "Tour.h"
#include"FoodService.h"
#include"FoodException.h"
class GastroTour :
    public Tour
{
protected:
    int restaurantCounter = 0;
    //vector<Food*> foodServices;
    FoodService arr;
public:
    GastroTour();
    GastroTour(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
        float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber);
    GastroTour(bool a, Map& map);
    ~GastroTour();

    void setRestaurantCounter(int _restaurantCounter);
    int getRestaurantCounter()const;

    void TourEdit() override;
    void TourShow()const;
    void TourShowClients()const;
    void askClient();

    void saveToFile(ofstream& file)const;
    void loadFromFile(ifstream& file);
    string TourType()const override;
};