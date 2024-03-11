#pragma once

#include"Tour.h"
#include"Safari.h"
#include"Sightseeing.h"
#include"BeachTour.h"
#include"YachtTour.h"
#include"Excursion.h"
#include"HikingTour.h"
#include"HelicopterFlightTour.h"
#include"GastroTour.h"
#include<vector>
#include<algorithm>

class TourArr
{
	
public:
	vector<Tour*>arr;
	~TourArr();
	int getVectotSize()const;
	Date getDateTour(int index)const;
	float getTotalPrice();

	void addTour(Tour* obj);
	void addTour();
	void delTour(int index);
	void delTour(string _name);
	void delTour(Tour* obj);

	void showTourArr()const;
	void showTourArrAny(vector<Tour*> arrT) const;
	void showTourArrClients()const;
	void askClient(int index);
	float calcAllSumm() const;
	void editTourArray();

	//sort
	void showSortTourArrayByDate(bool order)const;
	void showSortTourArrayByTime(bool order)const;
	void showSortTourArrayByPrice(bool order)const;
	void showSortTourArrayByGuide(bool order)const;
	void showSortTourArrayByNumber(bool order)const;
	void showSortTourArrayByType(bool order)const;
	void showSortTourArrayByRating(bool order)const;

	//sort to order
	int showSortTourArrayByDateOrder(bool order)const;
	int showSortTourArrayByTimeOrder(bool order)const;
	int showSortTourArrayByPriceOrder(bool order)const;
	int showSortTourArrayByGuideOrder(bool order)const;
	int showSortTourArrayByNumberOrder(bool order)const;
	int showSortTourArrayByTypeOrder(bool order)const;
	int showSortTourArrayByRatingOrder(bool order)const;

	//find
	void findTourByName(string _name) const;
	void findTourByAddress(string _address) const;
	void findTourByEquipment(string _equipment) const;
	void findTourByDate(Date _date) const;
	void findTourByTime(Time_ _time) const;
	void findTourByPrice(float minPrice, float maxPrice) const;
	void findTourByGuide(string _guide) const;
	void findTourByNumber(int _minNumber, int _maxNumber) const;
	void findTourByType(string _type) const;

	//find to order
	int findTourByNameOrder(string _name) const;
	int findTourByAddressOrder(string _address) const;
	int findTourByEquipmentOrder(string _equipment) const;
	int findTourByDateOrder(Date _date) const;
	int findTourByTimeOrder(Time_ _time) const;
	int findTourByPriceOrder(float minPrice, float maxPrice) const;
	int findTourByGuideOrder(string _guide) const;
	int findTourByNumberOrder(int _minNumber, int _maxNumber) const;
	int findTourByTypeOrder(string _type) const;

	void showAllForClient() const;
	int showAllForClientOrder() const;
	void showAllForAdmin();
	int showAllForAdminOrder();

	void saveToFile(string fileName);
	void saveToFile(ofstream& file);
	void loadFromFile(string fileName);
	void loadFromFile(ifstream& file);

	Tour* returnTour(int index);
};