#include "TourArr.h"

TourArr::~TourArr()
{
	for (int i = 0; i < arr.size(); i++)
	{
		delete arr[i];
	}
	arr.clear();
}

int TourArr::getVectotSize() const
{
	return arr.size();
}

Date TourArr::getDateTour(int index) const
{
	return arr[index]->getDate();
}

float TourArr::getTotalPrice()
{
	float summ = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		summ += arr[i]->getPrice();
	}
	return summ;
}

void TourArr::addTour(Tour* obj)
{
	arr.push_back(obj);
}

void TourArr::addTour()
{
	try {
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
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }

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
	try {
		if (arr.empty()) {
			throw new TourArrayException(3);
		}
		else {
			for (int i = 0; i < arr.size(); i++)
			{
				cout << " ";
				for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
				{
					cout << "-";
				}
				cout << " #" << i + 1 << " " << arr[i]->TourType() << " ";
				for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
				{
					cout << "-";
				}
				cout << " >\n|\n";
				arr[i]->TourShow();
				cout << "|\n --------------------------------------- <\n\n";
			}
		}
		system("pause");
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

void TourArr::showTourArrAny(vector<Tour*> arrT) const
{
	try {
		if (arrT.empty()) {
			throw new TourArrayException(3);
		}
		else {
			for (int i = 0; i < arrT.size(); i++)
			{
				//cout << "|   #" << i + 1 << endl << endl;
				cout << " ";
				for (int j = 0; j < ceil(float(35 - arrT[i]->TourType().size()) / 2) - 1; j++)
				{
					cout << "-";
				}
				cout << " #" << i + 1 << " " << arrT[i]->TourType() << " ";
				for (int j = 0; j < floor(float(35 - arrT[i]->TourType().size()) / 2); j++)
				{
					cout << "-";
				}
				cout << " >\n|\n";
				arrT[i]->TourShow();
				cout << "|\n --------------------------------------- <\n\n";
			}
		}
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

void TourArr::showTourArrClients() const
{
	try {
		if (arr.empty()) {
			throw new TourArrayException(3);
		}
		else {
			for (int i = 0; i < arr.size(); i++)
			{
				cout << " ";
				for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
				{
					cout << "-";
				}
				cout << " #" << i + 1 << " " << arr[i]->TourType() << " ";
				for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
				{
					cout << "-";
				}
				cout << " >\n|\n";
				arr[i]->TourShowClients();
				cout << "|\n --------------------------------------- <\n\n";
			}
		}
		system("pause");
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

void TourArr::askClient(int index)
{
	try {
		arr[index]->askClient();
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

float TourArr::calcAllSumm() const
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
	try {
		int intVar;
		string str;
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
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

//sort

void TourArr::showSortTourArrayByDate(bool order) const //0 - от меньшего к большему, 1 - от большего к меньшему
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	TourArr arr2;
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
		arr2.addTour(arr1[i]);
	}arr2.showTourArr();
	/*for (int i = 0; i < arr1.size(); i++)
	{
		cout << "|   #" << i + 1 << endl << endl;
		arr1[i]->TourShow();
		cout << endl;
	}*/
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

void TourArr::showSortTourArrayByType(bool order) const
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
			return left->TourType() > right->TourType();
			});
	}
	else {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->TourType() < right->TourType();
			});
	}

	for (int i = 0; i < arr1.size(); i++)
	{
		cout << "|   #" << i + 1 << endl << endl;
		arr1[i]->TourShow();
		cout << endl;
	}
}

void TourArr::showSortTourArrayByRating(bool order) const
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
			return left->getRating() > right->getRating();
			});
	}
	else {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getRating() < right->getRating();
			});
	}

	for (int i = 0; i < arr1.size(); i++)
	{
		cout << "|   #" << i + 1 << endl << endl;
		arr1[i]->TourShow();
		cout << endl;
	}
}

//sort to order

int TourArr::showSortTourArrayByDateOrder(bool order) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	vector<Tour*>arr1;
	//vector<int> vecInt;
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

	/*for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (arr[i] == arr1[j])
			{
				vecInt.push_back(j);
			}
		}
	}*/

	showTourArrAny(arr1);
	/*int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > arr.size());
	return vecInt[tmp - 1];*/
	int tmp;
	cout << "\n|   Choose what you want to order: ";
	cin >> tmp;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == arr1[tmp - 1]) {
			arr1.clear();
			return i;
		}
	}
}

int TourArr::showSortTourArrayByTimeOrder(bool order) const
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


	showTourArrAny(arr1);
	int tmp;
	cout << "\n|   Choose what you want to order: ";
	cin >> tmp;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == arr1[tmp - 1]) {
			arr1.clear();
			return i;
		}
	}
}

int TourArr::showSortTourArrayByPriceOrder(bool order) const
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

	showTourArrAny(arr1);
	int tmp;
	cout << "\n|   Choose what you want to order: ";
	cin >> tmp;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == arr1[tmp - 1]) {
			arr1.clear();
			return i;
		}
	}
}

int TourArr::showSortTourArrayByGuideOrder(bool order) const
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

	showTourArrAny(arr1);
	int tmp;
	cout << "\n|   Choose what you want to order: ";
	cin >> tmp;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == arr1[tmp - 1]) {
			arr1.clear();
			return i;
		}
	}
}

int TourArr::showSortTourArrayByNumberOrder(bool order) const
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

	showTourArrAny(arr1);
	int tmp;
	cout << "\n|   Choose what you want to order: ";
	cin >> tmp;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == arr1[tmp - 1]) {
			arr1.clear();
			return i;
		}
	}
}

int TourArr::showSortTourArrayByTypeOrder(bool order) const
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
			return left->TourType() > right->TourType();
			});
	}
	else {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->TourType() < right->TourType();
			});
	}

	showTourArrAny(arr1);
	int tmp;
	cout << "\n|   Choose what you want to order: ";
	cin >> tmp;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == arr1[tmp - 1]) {
			arr1.clear();
			return i;
		}
	}
}

int TourArr::showSortTourArrayByRatingOrder(bool order) const
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
			return left->getRating() > right->getRating();
			});
	}
	else {
		sort(arr1.begin(), arr1.end(), [](const Tour* left, const Tour* right) {
			return left->getRating() < right->getRating();
			});
	}

	showTourArrAny(arr1);
	int tmp;
	cout << "\n|   Choose what you want to order: ";
	cin >> tmp;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == arr1[tmp - 1]) {
			arr1.clear();
			return i;
		}
	}
}

//find

void TourArr::findTourByName(string _name) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_name.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getName() == _name) {
			counter++;
			cout << " ";
			for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
			{
				cout << "-";
			}
			cout << " #" << counter << " " << arr[i]->TourType() << " ";
			for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
			{
				cout << "-";
			}
			cout << " >\n|\n";
			arr[i]->TourShow();
			cout << "|\n --------------------------------------- <\n\n";
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByAddress(string _address) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_address.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getAddress() == _address) {
			counter++;
			cout << " ";
			for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
			{
				cout << "-";
			}
			cout << " #" << counter << " " << arr[i]->TourType() << " ";
			for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
			{
				cout << "-";
			}
			cout << " >\n|\n";
			arr[i]->TourShow();
			cout << "|\n --------------------------------------- <\n\n";
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByEquipment(string _equipment) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_equipment.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->checkEquipment(_equipment)) {
			counter++;
			cout << " ";
			for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
			{
				cout << "-";
			}
			cout << " #" << counter << " " << arr[i]->TourType() << " ";
			for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
			{
				cout << "-";
			}
			cout << " >\n|\n";
			arr[i]->TourShow();
			cout << "|\n --------------------------------------- <\n\n";
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByDate(Date _date) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_date <= Date()) {
		throw new TourArrayException(6);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getDate() == _date) {
			counter++;
			cout << " ";
			for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
			{
				cout << "-";
			}
			cout << " #" << counter << " " << arr[i]->TourType() << " ";
			for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
			{
				cout << "-";
			}
			cout << " >\n|\n";
			arr[i]->TourShow();
			cout << "|\n --------------------------------------- <\n\n";
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByTime(Time_ _time) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getTime() == _time) {
			counter++;
			cout << " ";
			for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
			{
				cout << "-";
			}
			cout << " #" << counter << " " << arr[i]->TourType() << " ";
			for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
			{
				cout << "-";
			}
			cout << " >\n|\n";
			arr[i]->TourShow();
			cout << "|\n --------------------------------------- <\n\n";
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByPrice(float minPrice, float maxPrice) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (minPrice < 0 || maxPrice < 0) {
		throw new TourArrayException(7);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getPrice() >= minPrice && arr[i]->getPrice() <= maxPrice || arr[i]->getPrice() <= minPrice && arr[i]->getPrice() >= maxPrice) {
			counter++;
			cout << " ";
			for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
			{
				cout << "-";
			}
			cout << " #" << counter << " " << arr[i]->TourType() << " ";
			for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
			{
				cout << "-";
			}
			cout << " >\n|\n";
			arr[i]->TourShow();
			cout << "|\n --------------------------------------- <\n\n";
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByGuide(string _guide) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_guide.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getGuide() == _guide) {
			counter++;
			cout << " ";
			for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
			{
				cout << "-";
			}
			cout << " #" << counter << " " << arr[i]->TourType() << " ";
			for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
			{
				cout << "-";
			}
			cout << " >\n|\n";
			arr[i]->TourShow();
			cout << "|\n --------------------------------------- <\n\n";
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByNumber(int _minNumber, int _maxNumber) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_minNumber < 0 || _maxNumber < 0) {
		throw new TourArrayException(8);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getNumber() >= _minNumber && arr[i]->getNumber() <= _maxNumber) {
			counter++;
			cout << " ";
			for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
			{
				cout << "-";
			}
			cout << " #" << counter << " " << arr[i]->TourType() << " ";
			for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
			{
				cout << "-";
			}
			cout << " >\n|\n";
			arr[i]->TourShow();
			cout << "|\n --------------------------------------- <\n\n";
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

void TourArr::findTourByType(string _type) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_type.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->TourType() == _type) {
			counter++;
			cout << " ";
			for (int j = 0; j < ceil(float(35 - arr[i]->TourType().size()) / 2) - 1; j++)
			{
				cout << "-";
			}
			cout << " #" << counter << " " << arr[i]->TourType() << " ";
			for (int j = 0; j < floor(float(35 - arr[i]->TourType().size()) / 2); j++)
			{
				cout << "-";
			}
			cout << " >\n|\n";
			arr[i]->TourShow();
			cout << "|\n --------------------------------------- <\n\n";
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
}

//find to order

int TourArr::findTourByNameOrder(string _name) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_name.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	vector<int> vecInt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getName() == _name) {
			counter++;
			cout << "|   #" << counter << endl << endl;
			arr[i]->TourShow();
			vecInt.push_back(i);
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
	int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > counter);
	return vecInt[tmp - 1];
}

int TourArr::findTourByAddressOrder(string _address) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_address.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	vector<int> vecInt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getAddress() == _address) {
			counter++;
			cout << "|   #" << counter << endl << endl;
			arr[i]->TourShow();
			vecInt.push_back(i);
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
	int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > counter);
	return vecInt[tmp - 1];
}

int TourArr::findTourByEquipmentOrder(string _equipment) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_equipment.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	vector<int> vecInt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->checkEquipment(_equipment)) {
			counter++;
			cout << "|   #" << counter << endl << endl;
			arr[i]->TourShow();
			vecInt.push_back(i);
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
	int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > counter);
	return vecInt[tmp - 1];
}

int TourArr::findTourByDateOrder(Date _date) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_date <= Date()) {
		throw new TourArrayException(6);
	}
	int counter = 0;
	vector<int> vecInt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getDate() == _date) {
			counter++;
			cout << "|   #" << counter << endl << endl;
			arr[i]->TourShow();
			vecInt.push_back(i);
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
	int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > counter);
	return vecInt[tmp - 1];
}

int TourArr::findTourByTimeOrder(Time_ _time) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	int counter = 0;
	vector<int> vecInt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getTime() == _time) {
			counter++;
			cout << "|   #" << counter << endl << endl;
			arr[i]->TourShow();
			vecInt.push_back(i);
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
	int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > counter);
	return vecInt[tmp - 1];
}

int TourArr::findTourByPriceOrder(float minPrice, float maxPrice) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (minPrice < 0 || maxPrice < 0) {
		throw new TourArrayException(7);
	}
	int counter = 0;
	vector<int> vecInt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getPrice() >= minPrice && arr[i]->getPrice() <= maxPrice || arr[i]->getPrice() <= minPrice && arr[i]->getPrice() >= maxPrice) {
			counter++;
			cout << "|   #" << counter << endl << endl;
			arr[i]->TourShow();
			vecInt.push_back(i);
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
	int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > counter);
	return vecInt[tmp - 1];
}

int TourArr::findTourByGuideOrder(string _guide) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_guide.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	vector<int> vecInt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getGuide() == _guide) {
			counter++;
			cout << "|   #" << counter << endl << endl;
			arr[i]->TourShow();
			vecInt.push_back(i);
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
	int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > counter);
	return vecInt[tmp - 1];
}

int TourArr::findTourByNumberOrder(int _minNumber, int _maxNumber) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_minNumber < 0 || _maxNumber < 0) {
		throw new TourArrayException(8);
	}
	int counter = 0;
	vector<int> vecInt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->getNumber() >= _minNumber && arr[i]->getNumber() <= _maxNumber) {
			counter++;
			cout << "|   #" << counter << endl << endl;
			arr[i]->TourShow();
			vecInt.push_back(i);
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
	int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > counter);
	return vecInt[tmp - 1];
}

int TourArr::findTourByTypeOrder(string _type) const
{
	if (arr.empty()) {
		throw new TourArrayException(3);
	}
	if (_type.size() <= 3) {
		throw new TourArrayException(5);
	}
	int counter = 0;
	vector<int> vecInt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->TourType() == _type) {
			counter++;
			cout << "|   #" << counter << endl << endl;
			arr[i]->TourShow();
			vecInt.push_back(i);
		}
	}
	if (counter == 0) {
		throw new TourArrayException(1);
	}
	int tmp;
	do {
		cout << "\n|   Choose what you want to order: ";
		cin >> tmp;
	} while (tmp < 1 || tmp > counter);
	return vecInt[tmp - 1];
}



void TourArr::showAllForClient() const
{
	try {
		if (arr.empty()) {
			throw new TourArrayException(3);
		}
		else {
			int menu, intVar;
			string str;
			do {
				cout << " ============== Tour Show ==============\n|\n";
				cout << "|   Enter what you want to see:\n|\n";
				cout << "|   1. Show all tours.\n";
				cout << "|   2. Show sorted tours.\n";
				cout << "|   3. Find tour.\n";
				cout << "|   4. Leave.\n";
				do
				{
					cout << "\nYour choice >> ";
					cin >> menu;
				} while (menu < 1 && menu > 4);
				cout << endl;
				switch (menu)
				{
				case 1:
					showTourArr();
					/*int index1;
					cout << "Make your choice: ";
					return index1;*/
					break;
				case 2:
				{
					cout << "|   Choose sort type:\n|\n";
					cout << "|   1. By date.\n";
					cout << "|   2. By time.\n";
					cout << "|   3. By price.\n";
					cout << "|   4. By guide.\n";
					cout << "|   5. By amount of tourists.\n";
					cout << "|   6. By type.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 6);
					cout << endl;
					int intVar1;
					cout << "|   Choose sort order:\n|\n";
					cout << "|   1. From smaller to larger.\n";
					cout << "|   2. From larger to smaller.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar1;
					} while (intVar1 < 1 && intVar1 > 2);
					intVar1--;
					cout << endl;
					switch (intVar)
					{
					case 1:
						showSortTourArrayByDate(intVar1);
						break;
					case 2:
						showSortTourArrayByTime(intVar1);
						break;
					case 3:
						showSortTourArrayByPrice(intVar1);
						break;
					case 4:
						showSortTourArrayByGuide(intVar1);
						break;
					case 5:
						showSortTourArrayByNumber(intVar1);
						break;
					case 6:
						showSortTourArrayByType(intVar1);
						break;
					default:
						break;
					}
					system("pause");
					break;
				}
				case 3:
					cout << "|   Choose object you want to search:\n|\n";
					cout << "|   1. Name.\n";
					cout << "|   2. Address.\n";
					cout << "|   3. Equipment.\n";
					cout << "|   4. Date.\n";
					cout << "|   5. Time.\n";
					cout << "|   6. Price.\n";
					cout << "|   7. Guide.\n";
					cout << "|   8. Amount of tourists.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 8);
					cout << endl;
					switch (intVar)
					{
					case 1:
					{
						cout << "|   Enter name: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						findTourByName(str);
						break;
					}
					case 2:
					{
						cout << "|   Enter address: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						findTourByAddress(str);
						break;
					}
					case 3:
					{
						cout << "|   Enter equipment: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						findTourByEquipment(str);
						break;
					}
					case 4:
					{
						Date d;
						cout << "|   Enter date: ";
						cin >> d;
						cout << endl;
						findTourByDate(d);
						break;
					}
					case 5:
					{
						Time_ t;
						cout << "|   Enter time: ";
						cin >> t;
						cout << endl;
						findTourByTime(t);
						break;
					}
					case 6:
					{
						float flVar, flVar1;
						cout << "|   Enter min price: ";
						cin >> flVar;
						cout << "|   Enter max price: ";
						cin >> flVar1;
						cout << endl;
						findTourByPrice(flVar, flVar1);
						break;
					}
					case 7:
					{
						cout << "|   Enter name: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						findTourByGuide(str);
						break;
					}
					case 8:
					{
						int iVar, iVar1;
						cout << "|   Enter min amount: ";
						cin >> iVar;
						cout << "|   Enter max amount: ";
						cin >> iVar1;
						cout << endl;
						findTourByNumber(iVar, iVar1);
						break;
					}
					default:
						break;
					}
					system("pause");
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
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

int TourArr::showAllForClientOrder() const
{
	try {
		if (arr.empty()) {
			throw new TourArrayException(3);
		}
		else {
			int menu, intVar;
			string str;
			do {
				cout << " ============== Tour Show ==============\n|\n";
				cout << "|   Enter what you want to see/edit:\n|\n";
				cout << "|   1. Show all tours.\n";
				cout << "|   2. Show sorted tours.\n";
				cout << "|   3. Find tour.\n";
				cout << "|   4. Leave.\n";
				do
				{
					cout << "\nYour choice >> ";
					cin >> menu;
				} while (menu < 1 && menu > 4);
				cout << endl;
				switch (menu)
				{
				case 1:
				{
					showTourArr();
					int index;
					do
					{
						cout << "Make your choice: ";
						cin >> index;
					} while (index < 0 || index > arr.size());
					return index - 1;
					break;
				}
				case 2:
				{
					cout << "|   Choose sort type:\n|\n";
					cout << "|   1. By date.\n";
					cout << "|   2. By time.\n";
					cout << "|   3. By price.\n";
					cout << "|   4. By guide.\n";
					cout << "|   5. By amount of tourists.\n";
					cout << "|   6. By type.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 6);
					cout << endl;
					int intVar1;
					cout << "|   Choose sort order:\n|\n";
					cout << "|   1. From smaller to larger.\n";
					cout << "|   2. From larger to smaller.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar1;
					} while (intVar1 < 1 && intVar1 > 2);
					intVar1--;
					cout << endl;
					switch (intVar)
					{
					case 1:
						return showSortTourArrayByDateOrder(intVar1);
						break;
					case 2:
						return showSortTourArrayByTimeOrder(intVar1);
						break;
					case 3:
						return showSortTourArrayByPriceOrder(intVar1);
						break;
					case 4:
						return showSortTourArrayByGuideOrder(intVar1);
						break;
					case 5:
						return showSortTourArrayByNumberOrder(intVar1);
						break;
					case 6:
						return showSortTourArrayByTypeOrder(intVar1);
						break;
					default:
						break;
					}
					break;
				}
				case 3:
					cout << "|   Choose object you want to search:\n|\n";
					cout << "|   1. Name.\n";
					cout << "|   2. Address.\n";
					cout << "|   3. Equipment.\n";
					cout << "|   4. Date.\n";
					cout << "|   5. Time.\n";
					cout << "|   6. Price.\n";
					cout << "|   7. Guide.\n";
					cout << "|   8. Amount of tourists.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 8);
					cout << endl;
					switch (intVar)
					{
					case 1:
					{
						cout << "|   Enter name: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						return findTourByNameOrder(str);
						break;
					}
					case 2:
					{
						cout << "|   Enter address: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						return findTourByAddressOrder(str);
						break;
					}
					case 3:
					{
						cout << "|   Enter equipment: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						return findTourByEquipmentOrder(str);
						break;
					}
					case 4:
					{
						Date d;
						cout << "|   Enter date: ";
						cin >> d;
						cout << endl;
						return findTourByDateOrder(d);
						break;
					}
					case 5:
					{
						Time_ t;
						cout << "|   Enter time: ";
						cin >> t;
						cout << endl;
						return findTourByTimeOrder(t);
						break;
					}
					case 6:
					{
						float flVar, flVar1;
						cout << "|   Enter min price: ";
						cin >> flVar;
						cout << "|   Enter max price: ";
						cin >> flVar1;
						cout << endl;
						return findTourByPriceOrder(flVar, flVar1);
						break;
					}
					case 7:
					{
						cout << "|   Enter name: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						return findTourByGuideOrder(str);
						break;
					}
					case 8:
					{
						int iVar, iVar1;
						cout << "|   Enter min amount: ";
						cin >> iVar;
						cout << "|   Enter max amount: ";
						cin >> iVar1;
						cout << endl;
						return findTourByNumberOrder(iVar, iVar1);
						break;
					}
					default:
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
		return -1;
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

void TourArr::showAllForAdmin()
{
	try {
		if (arr.empty()) {
			throw new TourArrayException(3);
		}
		else {
			int menu, intVar;
			string str;
			do {
				cout << " ============== Tour Show ==============\n|\n";
				cout << "|   Enter what you want to edit:\n|\n";
				cout << "|   1. Show all tours.\n";
				cout << "|   2. Show sorted tours.\n";
				cout << "|   3. Find tour.\n";
				cout << "|   4. Add tour.\n";
				cout << "|   5. Delete tour.\n";
				cout << "|   6. Edit tour.\n";
				cout << "|   7. Leave.\n";
				do
				{
					cout << "\nYour choice >> ";
					cin >> menu;
				} while (menu < 1 && menu > 7);
				cout << endl;
				switch (menu)
				{
				case 1:
					showTourArr();
					break;
				case 2:
				{
					cout << "|   Choose sort type:\n|\n";
					cout << "|   1. By date.\n";
					cout << "|   2. By time.\n";
					cout << "|   3. By price.\n";
					cout << "|   4. By guide.\n";
					cout << "|   5. By amount of tourists.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 5);
					cout << endl;
					int intVar1;
					cout << "|   Choose sort order:\n|\n";
					cout << "|   1. From smaller to larger.\n";
					cout << "|   2. From larger to smaller.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar1;
					} while (intVar1 < 1 && intVar1 > 2);
					intVar1--;
					cout << endl;
					switch (intVar)
					{
					case 1:
						showSortTourArrayByDate(intVar1);
						break;
					case 2:
						showSortTourArrayByTime(intVar1);
						break;
					case 3:
						showSortTourArrayByPrice(intVar1);
						break;
					case 4:
						showSortTourArrayByGuide(intVar1);
						break;
					case 5:
						showSortTourArrayByNumber(intVar1);
						break;
					default:
						break;
					}
					system("pause");
					break;
				}
				case 3:
					cout << "|   Choose object you want to search:\n|\n";
					cout << "|   1. Name.\n";
					cout << "|   2. Address.\n";
					cout << "|   3. Equipment.\n";
					cout << "|   4. Date.\n";
					cout << "|   5. Time.\n";
					cout << "|   6. Price.\n";
					cout << "|   7. Guide.\n";
					cout << "|   8. Amount of tourists.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 8);
					cout << endl;
					switch (intVar)
					{
					case 1:
					{
						cout << "|   Enter name: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						findTourByName(str);
						break;
					}
					case 2:
					{
						cout << "|   Enter address: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						findTourByAddress(str);
						break;
					}
					case 3:
					{
						cout << "|   Enter equipment: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						findTourByEquipment(str);
						break;
					}
					case 4:
					{
						Date d;
						cout << "|   Enter date: ";
						cin >> d;
						cout << endl;
						findTourByDate(d);
						break;
					}
					case 5:
					{
						Time_ t;
						cout << "|   Enter time: ";
						cin >> t;
						cout << endl;
						findTourByTime(t);
						break;
					}
					case 6:
					{
						float flVar, flVar1;
						cout << "|   Enter min price: ";
						cin >> flVar;
						cout << "|   Enter max price: ";
						cin >> flVar1;
						cout << endl;
						findTourByPrice(flVar, flVar1);
						break;
					}
					case 7:
					{
						cout << "|   Enter name: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						findTourByGuide(str);
						break;
					}
					case 8:
					{
						int iVar, iVar1;
						cout << "|   Enter min amount: ";
						cin >> iVar;
						cout << "|   Enter max amount: ";
						cin >> iVar1;
						cout << endl;
						findTourByNumber(iVar, iVar1);
						break;
					}
					default:
						break;
					}
					system("pause");
					break;
				case 4:
					addTour();
					break;
				case 5:
					cout << "|   Enter what you want to delete object by:\n|\n";
					cout << "|   1. By index.\n";
					cout << "|   2. By name.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 2);
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
				case 6:
					editTourArray();
					break;
				case 7:
					break;
				default:
					cout << "|   Input error!\n";
					break;
				}
			} while (menu != 7);
		}
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }

	/*if (arr.empty()) {
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
				do
				{
					cout << "\nYour choice >> ";
					cin >> intVar;
				} while (intVar < 1 && intVar > 2);
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
				editTourArray();
				break;
			case 4:
				break;
			default:
				cout << "|   Input error!\n";
				break;
			}
		} while (menu != 4);
	}*/
}

int TourArr::showAllForAdminOrder()
{
	try {
		if (arr.empty()) {
			throw new TourArrayException(3);
		}
		else {
			int menu, intVar;
			string str;
			do {
				cout << " ============== Tour Show ==============\n|\n";
				cout << "|   Enter what you want to edit:\n|\n";
				cout << "|   1. Show all tours.\n";
				cout << "|   2. Show sorted tours.\n";
				cout << "|   3. Find tour.\n";
				cout << "|   4. Add tour.\n";
				cout << "|   5. Delete tour.\n";
				cout << "|   6. Edit tour.\n";
				cout << "|   7. Leave.\n";
				do
				{
					cout << "\nYour choice >> ";
					cin >> menu;
				} while (menu < 1 && menu > 7);
				cout << endl;
				switch (menu)
				{
				case 1:
					showTourArr();
					int index;
					do
					{
						cout << "Make your choice: ";
						cin >> index;
					} while (index < 0 || index > arr.size());
					return index;
					break;
				case 2:
				{
					cout << "|   Choose sort type:\n|\n";
					cout << "|   1. By date.\n";
					cout << "|   2. By time.\n";
					cout << "|   3. By price.\n";
					cout << "|   4. By guide.\n";
					cout << "|   5. By amount of tourists.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 5);
					cout << endl;
					int intVar1;
					cout << "|   Choose sort order:\n|\n";
					cout << "|   1. From smaller to larger.\n";
					cout << "|   2. From larger to smaller.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar1;
					} while (intVar1 < 1 && intVar1 > 2);
					intVar1--;
					cout << endl;
					switch (intVar)
					{
					case 1:
						return showSortTourArrayByDateOrder(intVar1);
						break;
					case 2:
						return showSortTourArrayByTimeOrder(intVar1);
						break;
					case 3:
						return showSortTourArrayByPriceOrder(intVar1);
						break;
					case 4:
						return showSortTourArrayByGuideOrder(intVar1);
						break;
					case 5:
						return showSortTourArrayByNumberOrder(intVar1);
						break;
					default:
						break;
					}
					break;
				}
				case 3:
					cout << "|   Choose object you want to search:\n|\n";
					cout << "|   1. Name.\n";
					cout << "|   2. Address.\n";
					cout << "|   3. Equipment.\n";
					cout << "|   4. Date.\n";
					cout << "|   5. Time.\n";
					cout << "|   6. Price.\n";
					cout << "|   7. Guide.\n";
					cout << "|   8. Amount of tourists.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 8);
					cout << endl;
					switch (intVar)
					{
					case 1:
					{
						cout << "|   Enter name: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						return findTourByNameOrder(str);
						break;
					}
					case 2:
					{
						cout << "|   Enter address: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						return findTourByAddressOrder(str);
						break;
					}
					case 3:
					{
						cout << "|   Enter equipment: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						return findTourByEquipmentOrder(str);
						break;
					}
					case 4:
					{
						Date d;
						cout << "|   Enter date: ";
						cin >> d;
						cout << endl;
						return findTourByDateOrder(d);
						break;
					}
					case 5:
					{
						Time_ t;
						cout << "|   Enter time: ";
						cin >> t;
						cout << endl;
						return findTourByTimeOrder(t);
						break;
					}
					case 6:
					{
						float flVar, flVar1;
						cout << "|   Enter min price: ";
						cin >> flVar;
						cout << "|   Enter max price: ";
						cin >> flVar1;
						cout << endl;
						return findTourByPriceOrder(flVar, flVar1);
						break;
					}
					case 7:
					{
						cout << "|   Enter name: ";
						cin.ignore();
						getline(cin, str);
						cout << endl;
						return findTourByGuideOrder(str);
						break;
					}
					case 8:
					{
						int iVar, iVar1;
						cout << "|   Enter min amount: ";
						cin >> iVar;
						cout << "|   Enter max amount: ";
						cin >> iVar1;
						cout << endl;
						return findTourByNumberOrder(iVar, iVar1);
						break;
					}
					default:
						break;
					}
					break;
				case 4:
					addTour();
					break;
				case 5:
					cout << "|   Enter what you want to delete object by:\n|\n";
					cout << "|   1. By index.\n";
					cout << "|   2. By name.\n";
					do
					{
						cout << "\nYour choice >> ";
						cin >> intVar;
					} while (intVar < 1 && intVar > 2);
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
				case 6:
					editTourArray();
					break;
				case 7:
					break;
				default:
					cout << "|   Input error!\n";
					break;
				}
			} while (menu != 7);
		}
		return -1;
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}



void TourArr::saveToFile(string fileName)
{
	try {
		ofstream file(fileName);
		if (file.is_open()) {
			string str;
			file << arr.size() << endl;
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
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

void TourArr::saveToFile(ofstream& file)
{
	try {
		string str;
		file << arr.size() << endl;
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
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

void TourArr::loadFromFile(string fileName)
{
	try {
		if (!arr.empty()) {
			for (int i = 0; i < arr.size(); i++)
			{
				delete arr[i];
			}
			arr.clear();
		}
		ifstream file(fileName);
		if (file.is_open()) {
			int typeN, sizeN;
			file >> sizeN;
			file.ignore();
			string str;
			for (int i = 0; i < sizeN; i++)
			{
				getline(file, str);
				if (str[0] == '#') {
					getline(file, str);
				}
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
				else if (str == "GastroTour") {
					GastroTour* a = new GastroTour();
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
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }

	/*try {

	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }*/
}

void TourArr::loadFromFile(ifstream& file)
{
	try {
		int sizeN;
		file >> sizeN;
		file.ignore();
		if (!arr.empty()) {
			for (int i = 0; i < arr.size(); i++)
			{
				delete arr[i];
			}
			arr.clear();
		}
		string str;
		
		//while (getline(file, str))
		for (int i = 0; i < sizeN; i++)
		{
			//file >> typeN;
			getline(file, str);
			if (str[0] == '#') {
				getline(file, str);
			}
			//if(str.find("#")!=string::npos&&)
			if (str == "Safari") {
				file.ignore();
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
				file.ignore();
				BeachTour* a = new BeachTour();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "YachtTour") {
				file.ignore();
				YachtTour* a = new YachtTour();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "Excursion") {
				file.ignore();
				Excursion* a = new Excursion();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "HikingTour") {
				file.ignore();
				HikingTour* a = new HikingTour();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "HelicopterFlightTour") {
				file.ignore();
				HelicopterFlightTour* a = new HelicopterFlightTour();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else if (str == "GastroTour") {
				file.ignore();
				GastroTour* a = new GastroTour();
				a->loadFromFile(file);
				arr.push_back(a);
			}
			else {
				throw new TourInputErrorException(11);
			}
		}
	}
	catch (TourInputErrorException* err) { err->message(); delete err; }
	catch (TourInputDateException* err) { err->message(); delete err; }
	catch (TourInputPriceServiceException* err) { err->message(); delete err; }
	catch (TourInputNumberException* err) { err->message(); delete err; }
}

Tour* TourArr::returnTour(int index)
{
	return arr[index];
}
