#pragma once
#include "Food.h"
#include "Restaraunt.h"
#include "Canteen.h"
#include "Cafe.h"
#include "Map.h"
#include <vector>

//Хранит вектор заведений
class FoodService
{
protected:
	vector<Food*> foodServices; //вектор заведений
	string name; //название

public:
	//Конструктор по умолчанию
	FoodService();
	//Конструктор с параметром
	FoodService(string _name);
	//Деструктор
	~FoodService();

	//сеттер и геттеры
	void setName(string _name);
	string getName() const;
	int getFoodServicesSize() const;

	//добавление и удаление заведений с перегрузкой методов
	void addFoodService(Food* obj);
	void addFoodService(Map& map);
	void delFoodServiceByName(string userName);
	void delFoodService(Map& map);

	//подсчет количества заведений и их среднего рейтенга
	double calculateAverageRating() const;
	int getTotalFoodCount() const;

	//метод для редактирования
	void edit(Map& map);
	void editForTour();
	int editForClient();

	//методы для поиска
	void searchByName(string _name, bool flag) const;
	int searchByName(string _name);
	void searchByAdress(string _adress, bool flag) const;
	int searchByAdress(string _adress);
	void searchByRating(int _ratingLow, int _ratingHigh, bool flag) const;
	int searchByRating(int _ratingLow, int _ratingHigh);
	void searchByType(string _type, bool flag) const;
	int searchByType(string _type);

	//методы для сортировки
	void sortByRating(bool flag) const;
	int sortByRating();
	void sortByOpeningTime(bool flag) const;
	int sortByOpeningTime();
	void sortByClosingTime(bool flag) const;
	int sortByClosingTime();

	//вывод всех заведений
	void showFoodServices() const;

	float askClient() const;

	void saveFoodServicesToFile(const string& filename) const;
	void saveFoodServicesToFile(ofstream& file) const;

	void loadFoodServicesFromFile(const string& filename, Map& map);
	void loadFoodServicesFromFile(ifstream& file);
};