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

	//сеттер и геттер
	void setName(string _name);
	string getName() const;

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

	//методы для поиска
	void searchByName(string _name) const;
	void searchByAdress(string _adress) const;
	void searchByRating(int _ratingLow, int _ratingHigh) const;

	//методы для сортировки
	void sortByRating() const;
	void sortByOpeningTime() const;
	void sortByClosingTime() const;

	//вывод всех заведений
	void showFoodServices() const;

	float askClient() const;

	void saveFoodServicesToFile(const string& filename) const;
	void loadFoodServicesFromFile(const string& filename, Map& map);
};