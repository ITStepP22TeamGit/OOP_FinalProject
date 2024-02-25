#pragma once
#include "Food.h"

//���� - �����-��������� ������ Food
class Cafe :
    public Food
{
protected:
    bool freeWifi; //��������� ����������� wifi
    string musicGenre; //���� ������
    bool boardGames; //���������� ����
    bool petFriendly; //��� ������� ���������

public:
    //�����������
    Cafe();
    //����������� � ����������
    Cafe(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime,
        Time_ _closingTime, bool _freeWifi, string _musicGenre, bool _boardGames, bool _petFr);

    //������� � �������
    void setFreeWifi(bool _freeWifi);
    bool getFreeWifi() const;

    void setMusicGenre(string _musicGenre);
    string getMusicGenre() const;

    void setBoardGames(bool _boardGames);
    bool getBoardGames() const;

    void setPetFriendly(bool _petFr);
    bool getPetFriendly() const;

    //�����, ����������� ���� �������, ����� ��� ��������������
    virtual void showFoodService() const override;
    virtual string type() const override;
    virtual void edit() override;
};

