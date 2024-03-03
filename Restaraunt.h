#pragma once
#include "Canteen.h"

//Ресторан - класс-наследник класса Canteen
class Restaraunt :
    public Canteen
{
protected:
    string cuisineType; //тип кухни
    bool alcohol; //наявность алкогольных напитков
    bool liveMusic; //наличие живой музыки
public:
    //Конструктор
    Restaraunt();
    //Конструктор с параметром
    Restaraunt(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime,
        Time_ _closingTime, bool _banquet, bool _veganOptions, string _cuisineType, bool _alcohol,
        bool _liveMusic);

    //сеттеры и геттеры
    void setCuisineType(string _cuisineType);
    string getCuisineType() const;

    void setAlcohol(bool _alcohol);
    bool getAlcohol() const;

    void setLiveMusic(bool _liveMusic);
    bool getLiveMusic() const;

    //вывод, возвращение типа объекта, метод для редактирования
    virtual void showFoodService() const override;
    virtual string type() const override;
    virtual void edit() override;
    virtual void setInfo() override;

    virtual void saveToFile(ofstream& file) const override;
    virtual void loadFromFile(ifstream& file) override;
};

