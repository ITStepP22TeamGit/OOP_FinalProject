#pragma once
#include "Tour.h"
class Safari :
    public Tour
{
public:
    Safari();
    Safari(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
        float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber);
    Safari(bool a);
    ~Safari();
    string TourType()const override;
};