#pragma once
#include "Canteen.h"

//�������� - �����-��������� ������ Canteen
class Restaraunt :
    public Canteen
{
protected:
    string cuisineType; //��� �����
    bool alcohol; //��������� ����������� ��������
    bool liveMusic; //������� ����� ������
public:
    //�����������
    Restaraunt();
    //����������� � ����������
    Restaraunt(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime,
        Time_ _closingTime, bool _banquet, bool _veganOptions, string _cuisineType, bool _alcohol,
        bool _liveMusic);

    //������� � �������
    void setCuisineType(string _cuisineType);
    string getCuisineType() const;

    void setAlcohol(bool _alcohol);
    bool getAlcohol() const;

    void setLiveMusic(bool _liveMusic);
    bool getLiveMusic() const;

    //�����, ����������� ���� �������, ����� ��� ��������������
    virtual void showFoodService() const override;
    virtual string type() const override;
    virtual void edit() override;
    virtual void setInfo() override;

    virtual void saveToFile(ofstream& file) const override;
    virtual void loadFromFile(ifstream& file) override;
};

