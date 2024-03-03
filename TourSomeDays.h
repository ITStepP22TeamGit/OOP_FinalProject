#pragma once
#include "Tour.h"
class TourSomeDays :
    public Tour
{
protected:
    int days;
public:
    TourSomeDays();
    TourSomeDays(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
        float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber, int _days);

    void setDays(int _days);
    int getDays()const;

    virtual void TourShow()const;
    virtual void TourShowClients()const;

    void saveToFile(ofstream& file)const;
    void loadFromFile(ifstream& file);

    virtual void TourEdit();
    virtual string TourType()const = 0;
};