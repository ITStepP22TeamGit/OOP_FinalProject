#pragma once
#include "Food.h"

//Кафе - класс-наследник класса Food
class Cafe :
    public Food
{
protected:
    bool freeWifi; //наявность бесплатного wifi
    string musicGenre; //жанр музыки
    bool boardGames; //настольные игры
    bool petFriendly; //пет френдли заведение

public:
    //Конструктор
    Cafe();
    //Конструктор с параметром
    Cafe(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime,
        Time_ _closingTime, bool _freeWifi, string _musicGenre, bool _boardGames, bool _petFr);

    //сеттеры и геттеры
    void setFreeWifi(bool _freeWifi);
    bool getFreeWifi() const;

    void setMusicGenre(string _musicGenre);
    string getMusicGenre() const;

    void setBoardGames(bool _boardGames);
    bool getBoardGames() const;

    void setPetFriendly(bool _petFr);
    bool getPetFriendly() const;

    //вывод, возвращение типа объекта, метод для редактирования
    virtual void showFoodService() const override;
    virtual string type() const override;
    virtual void edit() override;
};

