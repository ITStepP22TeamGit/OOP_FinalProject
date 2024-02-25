#pragma once
#include "Food.h"

//�������� - �����-��������� ������ Food
class Canteen :
    public Food
{
protected:
    bool banquet; //���������� �������
    bool veganOptions; //��� ��� �������

public:
    //�����������
    Canteen();
    //����������� � ����������
    Canteen(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime,
        Time_ _closingTime, bool _banquet, bool _veganOptions);

    //������� � �������
    void setBanquet(bool _banquet);
    bool getBanquet() const;

    void setVegan(bool _veganOptions);
    bool getVegan() const;

    //������ � ���������� ������� � ���������
    bool askClientBanquet() const;

    //�����, ����������� ���� �������, ����� ��� ��������������
    virtual void showFoodService() const override;
    virtual string type() const override;
    virtual void edit() override;
};

