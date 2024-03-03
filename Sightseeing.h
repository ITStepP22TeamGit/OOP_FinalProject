#pragma once
#include "Tour.h"
class Sightseeing :
    public Tour
{
protected:
    string sightseeingTransport;
public:
    Sightseeing();
    Sightseeing(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
        float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber, string _sightseeingTransport);
    Sightseeing(bool a);
    string TourType()const override;
    ~Sightseeing();
    void TourEdit() override;
    void TourShow()const;
    void TourShowClients()const;

    void setSightseeingTransport(string _sightseeingTransport);
    string getSightseeingTransport()const;

    void saveToFile(ofstream& file)const;
    void loadFromFile(ifstream& file);
};

