#include "Map.h"

Map::Map()
{
	length = 50;
	width = 40;
}

Map::Map(int _length, int _width)
{
	if (_length < 3) {
		throw new MapException(1);
	}
	else if (_width < 3) {
		throw new MapException(2);
	}
	else {
		length = _length;
		width = _width;
	}
}

void Map::addPoint(int _x, int _y, string _name, bool _type)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].name == _name) {
			throw new MapException(13);
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		//проверить если уже есть отель с такими координатами
		if (_type == 1 && arr[i].x == _x && arr[i].y == _y && arr[i].type == 1) {
			throw new MapException(14);
		}
	}
	bool check = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		//проверить есть ли уже ресторан с такими координатами и если он не расположен в отеле
		if (checkIsRestaurantInHotel(i) == 0 && _type == 0 && arr[i].x == _x && arr[i].y == _y && arr[i].type == 0) {
			check = 1;
		}
	}
	if (check == 1) {
		throw new MapException(15);
	}
	bool check1 = 0;
	int hotelsCounter = 0;
	int restaurantsCounter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].type == 1 && _type == 0 && arr[i].x == _x && arr[i].y == _y) {
			check1 = 1;
		}
		else if (arr[i].type == 1) {
			hotelsCounter++;
		}
		else if (arr[i].type == 0 && checkIsRestaurantInHotel(i) == 0) {
			restaurantsCounter++;
		}
	}
	if (_type == 1) {
		//проверка на количество отелей
		if (hotelsCounter + 1 > 14) {
			throw new MapException(16);
		}
		staticHotels++;
	}
	else if (_type == 0 && check1 == 0) {
		//проверка на количество ресторанов
		if (restaurantsCounter + 1 > 14) {
			throw new MapException(17);
		}
		staticRestaurants++;
	}
	arr.push_back(Point(_x, length, _y, width, _name, _type));
	setColors();
}

void Map::delPoint(int index)
{
	if (arr.empty()) { //если массив не пустой
		throw new MapException(9);
	}
	else if (index >= 0 && index < arr.size()) {
		arr.erase(arr.begin() + index); //удалить точку по индексу
	}
	else {
		throw new MapException(8);
	}
}

void Map::delPoint(int _x, int _y, bool _type)
{
	if (arr.empty()) { //если массив не пустой
		throw new MapException(9);
	}
	else if (_x < 1) {
		throw new MapException(3);
	}
	else if (_x > length) {
		throw new MapException(4, length);
	}
	else if (_y < 1) {
		throw new MapException(5);
	}
	else if (_y > width) {
		throw new MapException(6, width);
	}
	else {
		bool check = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].x == _x && arr[i].y == _y && arr[i].type == _type) {
				arr.erase(arr.begin() + i); //удалить точку по координатам и типу
				check = 1;
			}
		}
		if (check == 0) {
			throw new MapException(8);
		}
	}
}

void Map::delPoint(string _name)
{
	if (arr.empty()) { //если массив не пустой
		throw new MapException(9);
	}
	else if (_name.size() < 3) {
		throw new MapException(7);
	}
	else {
		bool check = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].name == _name) {
				arr.erase(arr.begin() + i); //удалить точку по имени
				check = 1;
				break;
			}
		}
		if (check == 0) {
			throw new MapException(8);
		}
	}
}

void Map::show()
{
	if (arr.empty()) { //если массив не пустой
		throw new MapException(9);
	}
	else {
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE); //переменная для цвета
		cout << "    ";
		for (int i = 0; i < length; i++) //вывод верхних числ
		{
			if (i + 1 <= 9) {
				cout << i + 1 << "  ";
			}
			else {
				cout << i + 1 << " ";
			}
		}
		cout << endl;
		cout << "    ";
		for (int i = 0; i < length; i++)
		{
			cout << "-  "; //вывод верхней линии
		}
		cout << endl;
		for (int i = 0; i < width; i++)
		{
			if (i + 1 >= 10) {
				cout << i + 1;
			}
			else {
				cout << i + 1 << " ";
			}
			cout << "|"; //вывод либо границы,
			for (int j = 0; j < length; j++)
			{
				bool check = 0;
				for (int d = 0; d < arr.size(); d++)
				{
					if (arr[d].x == j + 1 && arr[d].y == i + 1 && arr[d].type == 1) {

						SetConsoleTextAttribute(console_color, arr[d].color);
						cout << " x "; //либо метки отеля с соответсвующим цветом
						SetConsoleTextAttribute(console_color, 15);
						check = 1;
					}
					else if (checkIsRestaurantInHotel(d) == 0 && arr[d].x == j + 1 && arr[d].y == i + 1 && arr[d].type == 0) {
						SetConsoleTextAttribute(console_color, arr[d].color);
						cout << " o "; //либо метки ресторана с соответсвующим цветом
						SetConsoleTextAttribute(console_color, 15);
						check = 1;
					}
				}
				if (check == 0) {
					cout << "   ";
				}
			}
			cout << "|\n";
		}
		cout << "    ";
		for (int i = 0; i < length; i++)
		{
			cout << "-  "; //вывод нижней линии
		}
		bool hotels = 0, restaurants = 0;
		for (int i = 0; i < arr.size(); i++) //проверка есть ли в массиве отели/рестораны
		{
			if (arr[i].type == 1) {
				hotels = 1;
			}
			else if (arr[i].type == 0 && checkIsRestaurantInHotel(i) == 0) {
				restaurants = 1;
			}
		}
		cout << endl << endl;
		if (hotels == 1) { //если отели есть
			cout << "\nHotels (x):\n\n";
			for (int i = 0; i < arr.size(); i++)
			{
				if (arr[i].type == 1) { //выводим соответсвующий цвет и название
					SetConsoleTextAttribute(console_color, arr[i].color);
					cout << " ";
					SetConsoleTextAttribute(console_color, 15);
					cout << " - " << arr[i].name << endl << endl;
				}
			}
			cout << endl;
		}
		
		if (restaurants == 1) { //если рестораны есть
			cout << "Restaurants (o):\n\n";
			for (int i = 0; i < arr.size(); i++)
			{
				if (checkIsRestaurantInHotel(i) == 0 && arr[i].type == 0) { //и если они не при отелях
					SetConsoleTextAttribute(console_color, arr[i].color);
					cout << " "; //выводим соответсвующий цвет и название
					SetConsoleTextAttribute(console_color, 15);
					cout << " - " << arr[i].name << endl << endl;
				}
			}
			cout << endl;
		}
		bool check = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (checkIsRestaurantInHotel(i) == 1) { //проверить есть ли рестораны при отелях
				check = 1;
			}
		}
		if (check == 1) { //если есть
			cout << "Restaurants in hotels:\n\n";
			int index = 0;
			for (int i = 0; i < arr.size(); i++)
			{
				bool check1 = 0;
				for (int j = 0; j < arr.size(); j++)
				{
					if (arr[i].type == 1 && arr[j].type == 0 && arr[i] == arr[j]) {
						check1 = 1;
					}
				}
				if (check1 == 1) {
					SetConsoleTextAttribute(console_color, 31 + 16 * index);
					cout << " "; //выводим цвет отеля 
					SetConsoleTextAttribute(console_color, 15);
					cout << " :\n\n";

					for (int j = 0; j < arr.size(); j++)
					{
						if (arr[i].type == 1 && arr[j].type == 0 && arr[i] == arr[j]) {
							cout << arr[j].name << endl; //и все названия ресторанов
						}
					}
					cout << endl;
				}
				if (arr[i].type == 1) {
					index++;
				}
			}
		}
	}
}

float Map::calcDistance(int index1, int index2) const
{
	if (arr.empty()) { //если массив не пустой
		throw new MapException(9);
	}
	else if (index1 < 0 || index1 > arr.size()) {
		throw new MapException(10, 1);
	}
	else if (index2 < 0 || index2 > arr.size()) {
		throw new MapException(10, 2);
	}
	else { //считаем растояние между 2 точками с помощью векторов
		return sqrt(pow(arr[index2] - arr[index1], 2) + pow(arr[index2].y - arr[index1].y, 2));
	}
	return -1;
}

float Map::calcDistance(string name1, string name2) const
{
	if (arr.empty()) { //если массив не пустой
		throw new MapException(9);
	}
	else if (name1.size() < 3) {
		throw new MapException(11, 1);
	}
	else if (name2.size() < 3) {
		throw new MapException(11, 2);
	}
	else if (name1 == name2) {
		throw new MapException(12);
	}
	else {
		int index1, index2;
		if (name1.size() > 3 && name2.size() > 3) {
			for (int i = 0; i < arr.size(); i++)
			{
				if (arr[i].name == name1) {
					index1 = i;
				}
				else if (arr[i].name == name2) {
					index2 = i;
				}
			}
			//считаем растояние между 2 точками с помощью векторов
			return sqrt(pow(arr[index2] - arr[index1], 2) + pow(arr[index2].y - arr[index1].y, 2));
		}
	}
	return -1;
}

void Map::setColors() //метод, изменяющий индексы цветов (от меньшего к большему в 
			          //соответствие с порядком в массиве) отелей и ресторанов по отдельности. 
					  //Для ресторанов при отелях ставятся значения цвета отеля
{
	int color = 31, color1;
	bool check = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].type == 1) {
			arr[i].color = color;
			color += 16;
		}
	}
	color = 31;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j].type == 1 && arr[i].type == 0 && arr[j] == arr[i]) {
				check = 1;
				color1 = arr[j].color;
			}
		}
		if(check == 0 && arr[i].type == 0) {
			arr[i].color = color;
			color += 16;
		}
		else if(arr[i].type == 0) {
			arr[i].color = color1;
		}
		check = 0;
	}
}

bool Map::checkIsRestaurantInHotel(int index) //метод, возвращающий true, если ресторан находится при отеле,
											  //false, если нет
{
	for (int j = 0; j < arr.size(); j++)
	{
		if (arr[j].type == 1 && arr[index].type == 0 && arr[j] == arr[index]) {
			return true;
		}
	}
	return false;
}

Point::Point(int _x, int length, int _y, int width, string _name, bool _type)
{
	setX(_x, length);
	setY(_y, width);
	setName(_name);
	setType(_type);
}

void Point::setX(int _x, int length)
{
	if (_x < 1) {
		throw new MapException(3);
	}
	else if (_x > length) {
		throw new MapException(4, length);
	}
	else {
		x = _x;
	}
}

void Point::setY(int _y, int width)
{
	if (_y < 1) {
		throw new MapException(5);
	}
	else if (_y > width) {
		throw new MapException(6, width);
	}
	else {
		y = _y;
	}
}

void Point::setType(bool _type)
{
	type = _type;
}

void Point::setName(string _name)
{
	if (_name.size() < 3) {
		throw new MapException(7);
	}
	else {
		name = _name;
	}
}

bool Point::operator==(const Point& obj) const&
{
	return this->x == obj.x && this->y == obj.y; //сравнивает объекты по х и у; использован в разных методах
}

int Point::operator-(const Point& obj) const&
{
	return x - obj.x; //отнимает иксы; использован в calcDistance()
}