#include "TourArr.h"

TourArr::~TourArr()
{
	if (!arr.empty()) {
		for (int i = 0; i < arr.size(); i++)
		{
			delete arr[i];
		}
		arr.clear();
	}
}

void TourArr::addTour(Tour* obj)
{
	arr.push_back(obj);
}

void TourArr::addTour()
{
	int intVar;
	cout << "|   Choose type of tour:\n|\n";
	cout << "|   1. Safari.\n";
	cout << "|   2. Sightseeing.\n";
	cout << "|   3. BeachTour.\n";
	cout << "|   4. YachtTour.\n";
	cout << "|   5. Excursion.\n";
	cout << "|   6. HikingTour.\n";
	cout << "|   7. HelicopterFlightTour.\n";
	cout << "\nYour choice >> ";
	cin >> intVar;
	cout << endl;
	switch (intVar)
	{
	case 1:
	{
		Safari* obj = new Safari(1);
		arr.push_back(obj);
		break;
	}
	case 2:
	{
		Sightseeing* obj = new Sightseeing(1);
		arr.push_back(obj);
		break;
	}
	case 3:
	{
		BeachTour* obj = new BeachTour(1);
		arr.push_back(obj);
		break;
	}
	case 4:
	{
		YachtTour* obj = new YachtTour(1);
		arr.push_back(obj);
		break;
	}
	case 5:
	{
		Excursion* obj = new Excursion(1);
		arr.push_back(obj);
		break;
	}
	case 6:
	{
		HikingTour* obj = new HikingTour(1);
		arr.push_back(obj);
		break;
	}
	case 7:
	{
		HelicopterFlightTour* obj = new HelicopterFlightTour(1);
		arr.push_back(obj);
		break;
	}
	default:
		throw new TourArrayException(4);
		break;
	}

	/*if (str == "Safari") {
		cout << endl;
		Safari* obj = new Safari(1);
		arr.push_back(obj);
	}
	else if (str == "HikingTour") {
		cout << endl;
		HikingTour* obj = new HikingTour(1);
		arr.push_back(obj);
	}
	else if (str == "Excursion") {
		cout << endl;
		Excursion* obj = new Excursion(1);
		arr.push_back(obj);
	}
	else if (str == "Sightseeing") {
		cout << endl;
		Sightseeing* obj = new Sightseeing(1);
		arr.push_back(obj);
	}
	else if (str == "BeachTour") {
		cout << endl;
		BeachTour* obj = new BeachTour(1);
		arr.push_back(obj);
	}
	else if (str == "YachtTour") {
		cout << endl;
		YachtTour* obj = new YachtTour(1);
		arr.push_back(obj);
	}
	else if (str == "HelicopterFlightTour") {
		cout << endl;
		HelicopterFlightTour* obj = new HelicopterFlightTour(1);
		arr.push_back(obj);
	}
	else {
		throw new TourArrayException(4);
	}*/
}

void TourArr::delTour(int index)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	else if (index >= 0 && index < arr.size()) {
		arr.erase(arr.begin() + index);
	}
	else {
		throw new TourArrayException(1);
	}
}

void TourArr::delTour(string _name)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_name.size() <= 3) {
		throw new TourArrayException(5);
	}
	bool check = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getName() == _name) {
			arr.erase(arr.begin() + i);
			check = 1;
			break;
		}
	}
	if (check == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::delTour(Tour* obj)
{
	auto it = find(arr.begin(), arr.end(), obj);
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	else if (it != arr.end()) {
		arr.erase(it);
	}
	else {
		throw new TourArrayException(2);
	}
}

void TourArr::showTourArr() const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	else {
		for (int i = 0; i < arr.size(); i++)
		{
			cout << "|   #" << i + 1 << endl << endl;
			arr[i]->TourShow();
			cout << endl;
		}
	}
}

void TourArr::showTourArrClients() const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	else {
		for (int i = 0; i < arr.size(); i++)
		{
			cout << "|   #" << i + 1 << endl << endl;
			arr[i]->TourShowClients();
			cout << endl;
		}
	}
}

void TourArr::askClient(int index)
{
	arr[index]->askClient();
}

float TourArr::calcAllSumm()
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	float summ = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		summ += arr[i]->getPrice();
	}
	return summ;
}

void TourArr::editTourArray()
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	else {
		int menu, intVar;
		do {
			cout << " ============== Tour Edit ==============\n|\n";
			string str;
			cout << "|   Enter what you want to edit:\n|\n";
			cout << "|   1. Add tour.\n";
			cout << "|   2. Delete tour.\n";
			cout << "|   3. Edit tour.\n";
			cout << "|   4. Leave.\n";
			cout << "\nYour choice >> ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				addTour();
				break;
			case 2:
				cout << "|   Enter what you want to delete object by:\n|\n";
				cout << "|   1. By index.\n";
				cout << "|   2. By name.\n";
				cout << "\nYour choice >> ";
				cin >> intVar;
				cout << endl;
				switch (intVar)
				{
				case 1:
					cout << "|   Enter index: ";
					cin >> intVar;
					delTour(intVar);
					break;
				case 2:
					cout << "|   Enter name: ";
					cin.ignore();
					getline(cin, str);
					delTour(str);
					break;
				default:
					cout << "|   Input error!\n";
					break;
				}
				break;
			case 3:
				cout << "|   Enter what you want to edit object by:\n|\n";
				cout << "|   1. By index.\n";
				cout << "|   2. By name.\n";
				cout << "\nYour choice >> ";
				cin >> intVar;
				cout << endl;
				switch (intVar)
				{
				case 1:
					cout << "|   Enter index: ";
					cin >> intVar;
					cout << endl;
					arr[intVar]->TourEdit();
					break;
				case 2:
				{
					cout << "|   Enter name: ";
					cin.ignore();
					getline(cin, str);
					bool check = 0;
					for (int i = 0; i < arr.size(); i++)
					{
						if (arr[i]->getName() == str) {
							cout << "|\n";
							arr[i]->TourEdit();
							check = 1;
							break;
						}
					}
					if (check == 0) {
						throw new TourArrayException(1);
					}
					break;
				}
				default:
					cout << "|   Input error!\n";
					break;
				}
				break;
			case 4:
				break;
			default:
				cout << "|   Input error!\n";
				break;
			}
		} while (menu != 4);
	}
}

//sort

void TourArr::showSortTourArrayByDate(bool order) const //0 - от меньшего к большему, 1 - от большего к меньшему
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	vector<Tour*>arr1;
	for (int i = 0; i < arr.size(); i++)
	{
		arr1.push_back(arr[i]);
	}

	if (order) {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return *left > *right;
			});
	}
	else {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return *left < *right;
			});
	}

	for (int i = 0; i < arr1.size(); i++)
	{
		cout << "|   #" << i + 1 << endl << endl;
		arr1[i]->TourShow();
		cout << endl;
	}
}

void TourArr::showSortTourArrayByTime(bool order) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	vector<Tour*>arr1;
	for (int i = 0; i < arr.size(); i++)
	{
		arr1.push_back(arr[i]);
	}

	if (order) {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getTime() > right->getTime();
			});
	}
	else {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getTime() < right->getTime();
			});
	}

	for (int i = 0; i < arr1.size(); i++)
	{
		cout << "|   #" << i + 1 << endl << endl;
		arr1[i]->TourShow();
		cout << endl;
	}
}

void TourArr::showSortTourArrayByPrice(bool order) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	vector<Tour*>arr1;
	for (int i = 0; i < arr.size(); i++)
	{
		arr1.push_back(arr[i]);
	}

	if (order) {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getPrice() > right->getPrice();
			});
	}
	else {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getPrice() < right->getPrice();
			});
	}

	for (int i = 0; i < arr1.size(); i++)
	{
		cout << "|   #" << i + 1 << endl << endl;
		arr1[i]->TourShow();
		cout << endl;
	}
}

void TourArr::showSortTourArrayByGuide(bool order) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	vector<Tour*>arr1;
	for (int i = 0; i < arr.size(); i++)
	{
		arr1.push_back(arr[i]);
	}

	if (order) {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getGuide() > right->getGuide();
			});
	}
	else {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getGuide() < right->getGuide();
			});
	}

	for (int i = 0; i < arr1.size(); i++)
	{
		cout << "|   #" << i + 1 << endl << endl;
		arr1[i]->TourShow();
		cout << endl;
	}
}

void TourArr::showSortTourArrayByNumber(bool order) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	vector<Tour*>arr1;
	for (int i = 0; i < arr.size(); i++)
	{
		arr1.push_back(arr[i]);
	}

	if (order) {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getNumber() > right->getNumber();
			});
	}
	else {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getNumber() < right->getNumber();
			});
	}

	for (int i = 0; i < arr1.size(); i++)
	{
		cout << "|   #" << i + 1 << endl << endl;
		arr1[i]->TourShow();
		cout << endl;
	}
}

//find

void TourArr::findTourByName(string _name)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getName() == _name) {
			counter++;
			if (counter > 1) {
				cout << "|   #" << i + 1 << endl << endl;
			}
			arr[i]->TourShow();
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByAddress(string _address)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getAddress() == _address) {
			counter++;
			if (counter > 1) {
				cout << "|   #" << i + 1 << endl << endl;
			}
			arr[i]->TourShow();
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByEquipment(string _equipment)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->checkEquipment(_equipment)) {
			counter++;
			cout << "|   #" << i + 1 << endl << endl;
			arr[i]->TourShow();
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByDate(Date _date)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getDate() == _date) {
			counter++;
			if (counter > 1) {
				cout << "|   #" << i + 1 << endl << endl;
			}
			arr[i]->TourShow();
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByTime(Time_ _time)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getTime() == _time) {
			counter++;
			if (counter > 1) {
				cout << "|   #" << i + 1 << endl << endl;
			}
			arr[i]->TourShow();
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByPrice(float minPrice, float maxPrice)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getPrice() >= minPrice && arr[i]->getPrice() <= maxPrice) {
			counter++;
			if (counter > 1) {
				cout << "|   #" << i + 1 << endl << endl;
			}
			arr[i]->TourShow();
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByGuide(string _guide)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getGuide() == _guide) {
			counter++;
			if (counter > 1) {
				cout << "|   #" << i + 1 << endl << endl;
			}
			arr[i]->TourShow();
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByNumber(int _minNumber, int _maxNumber)
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getNumber() >= _minNumber && arr[i]->getNumber() <= _maxNumber) {
			counter++;
			if (counter > 1) {
				cout << "|   #" << i + 1 << endl << endl;
			}
			arr[i]->TourShow();
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::saveToFile(string fileName)
{
	ofstream file(fileName + ".txt");
	if (file.is_open()) {
		string str;
		for (int i = 0; i < arr.size(); i++)
		{
			file << "#" << i + 1 << endl;
			arr[i]->saveToFile(file);
			if (i <= arr.size() - 2) {
				string str = "\n";
				file.write(str.c_str(), str.size());
			}
		}
		file.close();
	}
	else {
		throw new TourInputErrorException(10, fileName);
	}
}

void TourArr::loadFromFile(string fileName)
{
	if (!arr.empty()) {
		for (int i = 0; i < arr.size(); i++)
		{
			delete arr[i];
		}
		arr.clear();
	}
	ifstream file(fileName + ".txt");
	if (file.is_open()) {
		string str;
		while (getline(file, str))
		{
			if (str[0] == '#') continue;
			if (str == "Safari") {
				Safari* a = new Safari();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "Sightseeing") {
				Sightseeing* a = new Sightseeing();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "BeachTour") {
				BeachTour* a = new BeachTour();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "YachtTour") {
				YachtTour* a = new YachtTour();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "Excursion") {
				Excursion* a = new Excursion();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "HikingTour") {
				HikingTour* a = new HikingTour();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "HelicopterFlightTour") {
				HelicopterFlightTour* a = new HelicopterFlightTour();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else {
				throw new TourInputErrorException(11);
			}
		}
		file.close();
	}
	else {
		throw new TourInputErrorException(10, fileName);
	}
}