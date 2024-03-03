#pragma once

#include"Tour.h"
#include"Safari.h"
#include"Sightseeing.h"
#include"BeachTour.h"
#include"YachtTour.h"
#include"Excursion.h"
#include"HikingTour.h"
#include<vector>
#include<algorithm>

class TourArr
{
	vector<Tour*>arr;
public:
	~TourArr();

	void addTour(Tour* obj);
	void addTour();
	void delTour(int index);
	void delTour(string _name);
	void delTour(Tour* obj);

	void showTourArr()const;
	void showTourArrClients()const;
	void askClient(int index);
	float calcAllSumm();
	void editTourArray();

	//sort
	void showSortTourArrayByDate(bool order)const;
	void showSortTourArrayByTime(bool order)const;
	void showSortTourArrayByPrice(bool order)const;
	void showSortTourArrayByGuide(bool order)const;
	void showSortTourArrayByNumber(bool order)const;

	//find
	void findTourByName(string _name);
	void findTourByAddress(string _address);
	void findTourByEquipment(string _equipment);
	void findTourByDate(Date _date);
	void findTourByTime(Time_ _time);
	void findTourByPrice(float minPrice, float maxPrice);
	void findTourByGuide(string _guide);
	void findTourByNumber(int _minNumber, int _maxNumber);

	void saveToFile(string fileName);
	void loadFromFile(string fileName);
};