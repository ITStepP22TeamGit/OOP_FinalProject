#pragma once
#include "Food.h"
#include "Restaraunt.h"
#include "Canteen.h"
#include "Cafe.h"
#include <vector>

//������ ������ ���������
class FoodService
{
protected:
	vector<Food*> foodServices; //������ ���������
	string name; //��������

public:
	//�����������
	FoodService(string _name);
	FoodService();
	//����������
	~FoodService();

	//������ � ������
	void setName(string _name);
	string getName() const;

	//���������� � �������� ��������� � ����������� �������
	void addFoodService(Food* obj);
	void addFoodService();
	void delFoodServiceByName(string userName);
	void delFoodService();

	//������� ���������� ��������� � �� �������� ��������
	double calculateAverageRating() const;
	int getTotalFoodCount() const;

	//����� ��� ��������������
	void edit();

	//������ ��� ������
	void searchByName(string _name) const;
	void searchByAdress(string _adress) const;
	void searchByRating(int _ratingLow, int _ratingHigh) const;

	//������ ��� ����������
	void sortByRating() const;
	void sortByOpeningTime() const;
	void sortByClosingTime() const;

	//����� ���� ���������
	void showFoodServices() const;

	float askClient() const;

	void saveFoodServicesToFile(const string& filename) const;
	void loadFoodServicesFromFile(const string& filename);
};