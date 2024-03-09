#pragma once
#include "Food.h"
#include "Restaraunt.h"
#include "Canteen.h"
#include "Cafe.h"
#include "Map.h"
#include <vector>

//������ ������ ���������
class FoodService
{
protected:
	vector<Food*> foodServices; //������ ���������
	string name; //��������

public:
	//����������� �� ���������
	FoodService();
	//����������� � ����������
	FoodService(string _name);
	//����������
	~FoodService();

	//������ � �������
	void setName(string _name);
	string getName() const;
	int getFoodServicesSize() const;

	//���������� � �������� ��������� � ����������� �������
	void addFoodService(Food* obj);
	void addFoodService(Map& map);
	void delFoodServiceByName(string userName);
	void delFoodService(Map& map);

	//������� ���������� ��������� � �� �������� ��������
	double calculateAverageRating() const;
	int getTotalFoodCount() const;

	//����� ��� ��������������
	void edit(Map& map);
	void editForTour();
	int editForClient();

	//������ ��� ������
	void searchByName(string _name, bool flag) const;
	int searchByName(string _name);
	void searchByAdress(string _adress, bool flag) const;
	int searchByAdress(string _adress);
	void searchByRating(int _ratingLow, int _ratingHigh, bool flag) const;
	int searchByRating(int _ratingLow, int _ratingHigh);
	void searchByType(string _type, bool flag) const;
	int searchByType(string _type);

	//������ ��� ����������
	void sortByRating(bool flag) const;
	int sortByRating();
	void sortByOpeningTime(bool flag) const;
	int sortByOpeningTime();
	void sortByClosingTime(bool flag) const;
	int sortByClosingTime();

	//����� ���� ���������
	void showFoodServices() const;

	float askClient() const;

	void saveFoodServicesToFile(const string& filename) const;
	void saveFoodServicesToFile(ofstream& file) const;

	void loadFoodServicesFromFile(const string& filename, Map& map);
	void loadFoodServicesFromFile(ifstream& file);
};