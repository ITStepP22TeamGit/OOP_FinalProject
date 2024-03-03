#pragma once
#include "BeachTour.h"
class YachtTour :
    public BeachTour
{
protected:
    bool lunch;
    float lunchPrice;
public:
    YachtTour();
    YachtTour(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
        float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber, float _aquasuitPrice, float _divingMaskPrice, float _lunchPrice);
    YachtTour(bool a);
    ~YachtTour();
    
    string TourType()const override;
    void TourEdit() override;

    void setLunch(bool _lunch);
    void setLunchPrice(float _lunchPrice);

    bool getLunch()const;
    float getLunchPrice()const;

    void TourShow()const;
    void TourShowClients()const;
    void askClient();

    void saveToFile(ofstream& file)const;
    void loadFromFile(ifstream& file);
};

