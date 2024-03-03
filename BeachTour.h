#pragma once
#include "Tour.h"
class BeachTour :
    public Tour
{
protected:
    bool aquasuit;
    float aquasuitPrice;
    bool divingMask;
    float divingMaskPrice;
public:
    BeachTour();
    BeachTour(string _name, string _address, string _description, Date _date, Time_ _time, float _rating, float _price,
        float _photosPrice, string _guide, int _number, int _minNumber, int _maxNumber, float _aquasuitPrice, float _divingMaskPrice);
    BeachTour(bool a);
    ~BeachTour();
    string TourType()const override;
    void TourEdit() override;

    void setAquasuit(bool _aquasuit);
    void setDivingMask(bool _divingMask);
    void setAquasuitPrice(float _aquasuitPrice);
    void setDivingMaskPrice(float _divingMaskPrice);

    bool getAquasuit()const;
    bool getDivingMask()const;
    float getAquasuitPrice()const;
    float getDivingMaskPrice()const;

    void TourShow()const;
    void TourShowClients()const;
    void askClient();

    void saveToFile(ofstream& file)const;
    void loadFromFile(ifstream& file);
};

