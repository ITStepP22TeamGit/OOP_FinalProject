#pragma once
#include "Food.h"

//Столовая - класс-наследник класса Food
class Canteen :
    public Food
{
protected:
    bool banquet; //проведение банкета
    bool veganOptions; //еда для веганов

public:
    //Конструктор
    Canteen();
    //Конструктор с параметром
    Canteen(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime,
        Time_ _closingTime, bool _banquet, bool _veganOptions);

    //сеттеры и геттеры
    void setBanquet(bool _banquet);
    bool getBanquet() const;

    void setVegan(bool _veganOptions);
    bool getVegan() const;

    //вопрос о проведении банкета в заведении
    bool askClientBanquet() const;

    //вывод, возвращение типа объекта, метод для редактирования
    virtual void showFoodService() const override;
    virtual string type() const override;
    virtual void edit() override;
};

