#pragma once
#include "TourSomeDays.h"
class HikingTour :
    public TourSomeDays
{
protected:
    float height;
public:
    HikingTour();
    HikingTour(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
        float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber, int _days, int _height);
    HikingTour(bool a);
    ~HikingTour();

    void setHeight(float _height);
    float getHeight()const;

    virtual void TourShow()const;
    virtual void TourShowClients()const;

    void TourEdit() override;
    string TourType()const override;

    void saveToFile(ofstream& file)const;
    void loadFromFile(ifstream& file);
};

