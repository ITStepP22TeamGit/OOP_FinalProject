#pragma once
#include "Tour.h"
class Excursion :
    public Tour
{
public:
    Excursion();
    Excursion(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
        float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber);
    Excursion(bool a);
    ~Excursion();
    string TourType()const override;
};