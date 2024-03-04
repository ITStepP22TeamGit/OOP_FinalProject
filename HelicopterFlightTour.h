#pragma once
#include "Tour.h"
class HelicopterFlightTour :
    public Tour
{
protected:
    bool activity; //1 - полет, 0 - прыгание с парашютом
    float priceFlight;
    float priceSkydiving;
public:
    HelicopterFlightTour();
    HelicopterFlightTour(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
        float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber, float _priceFlight, float _priceSkydiving);
    HelicopterFlightTour(bool a);
    ~HelicopterFlightTour();
    string TourType()const override;
    void TourEdit() override;

    void setActivity(bool _activity);
    void setPriceFlight(float _priceFlight);
    void setPriceSkydiving(float _priceSkydiving);

    bool getActivity()const;
    float getPriceFlight()const;
    float getPriceSkydiving()const;

    void TourShow()const;
    void TourShowClients()const;
    void askClient();

    void saveToFile(ofstream& file)const;
    void loadFromFile(ifstream& file);
};