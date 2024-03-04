#pragma once
#include "Dish.h"
#include <vector>
#include "Time.h"
#include "FoodException.h"
#include <fstream>
#include "Map.h"

//����������� �����
class Food
{
protected:
	string name; //�������� ���������
	string adress; //������
	vector<Dish*> menu; //��������� � ��������� ������ Dish
	int rating; //������� ���������
	int x; //�
	int y; //�
	Time_ openingTime; //����� ��������
	Time_ closingTime; //����� ��������

public:
	//�����������
	Food();
	//����������� � ����������
	Food(string _name, string _adress, int _rating, int _x, int _y, Time_ _openingTime,
		Time_ _closingTime);
	//����������
	~Food();

	//������� � �������
	void setOpeningTime(Time_ obj);
	void setClosingTime(Time_ obj);
	Time_ getOpeningTime() const;
	Time_ getClosingTime() const;

	void setName(string _name);
	string getName() const;

	void setAdress(string _adress);
	string getAdress() const;

	void setRating(int _rating);
	int getRating() const;

	void changeCoordinates(int _x, int _y);
	int getX() const;
	int getY() const;

	//���������� � �������� ����� �� ����
	void addDish(Dish* obj);
	void delDish(string _dishName);

	//�����, ����������� ���� �������, ����� ��� ��������������
	virtual void showFoodService() const = 0;
	virtual string type() const = 0;
	virtual void edit(Map& map) = 0;
	virtual void setInfo() = 0;
	virtual void saveToFile(ofstream& file) const = 0;
	virtual void loadFromFile(ifstream& file) = 0;

	//���������� ����������
	bool operator<(const Food& other) const;
	bool operator>(const Food& other) const;
};

