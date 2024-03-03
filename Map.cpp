#include "Map.h"

Map::Map()
{
	length = 50;
	width = 30;
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
		//��������� ���� ��� ���� ����� � ������ ������������
		if (_type == 1 && arr[i].x == _x && arr[i].y == _y && arr[i].type == 1) {
			throw new MapException(14);
		}
	}
	bool check = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		//��������� ���� �� ��� �������� � ������ ������������ � ���� �� �� ���������� � �����
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
		//�������� �� ���������� ������
		if (hotelsCounter + 1 > 14) {
			throw new MapException(16);
		}
		staticHotels++;
	}
	else if (_type == 0 && check1 == 0) {
		//�������� �� ���������� ����������
		if (restaurantsCounter + 1 > 14) {
			throw new MapException(17);
		}
		staticRestaurants++;
	}
	arr.push_back(Point(_x, length, _y, width, _name, _type));
	setColors();

	for (int i = 0; i < x.size(); i++)
	{
		if (name[i] == _name) {
			throw new MapException(13);
		}
	}
	for (int i = 0; i < x.size(); i++)
	{
		if (_type == 1 && x[i] == _x && y[i] == _y && type[i] == 1) {
			throw new MapException(14);
		}
	}
	if (_x < 1) {
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
	else if (_name.size() < 3) {
		throw new MapException(7);
	}
	else {
		for (int i = 0; i < x.size(); i++)
		{
			if (_type == 0 && type[i] == 1 && x[i] == _x && y[i] == _y) {
				//indexes.push_back(i);
			}
		}
		x.push_back(_x);
		y.push_back(_y);
		name.push_back(_name);
		type.push_back(_type);
	}
}

void Map::delPoint(int index)
{
	if (arr.empty()) { //���� ������ �� ������
		throw new MapException(9);
	}
	else if (index >= 0 && index < arr.size()) {
		arr.erase(arr.begin() + index); //������� ����� �� �������
	if (x.empty()) {
		throw new MapException(9);
	}
	else if (index >= 0 && index < x.size()) {
		x.erase(x.begin() + index);
		y.erase(y.begin() + index);
		name.erase(name.begin() + index);
		type.erase(type.begin() + index);
	}
	else {
		throw new MapException(8);
	}
}

void Map::delPoint(int _x, int _y, bool _type)
{
	if (arr.empty()) { //���� ������ �� ������
	if (x.empty()) {
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
				arr.erase(arr.begin() + i); //������� ����� �� ����������� � ����
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == _x && y[i] == _y && type[i] == _type) {
				x.erase(x.begin() + i);
				y.erase(y.begin() + i);
				name.erase(name.begin() + i);
				type.erase(type.begin() + i);
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
	if (arr.empty()) { //���� ������ �� ������
	if (x.empty()) {
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
				arr.erase(arr.begin() + i); //������� ����� �� �����
		for (int i = 0; i < x.size(); i++)
		{
			if (name[i] == _name) {
				x.erase(x.begin() + i);
				y.erase(y.begin() + i);
				name.erase(name.begin() + i);
				type.erase(type.begin() + i);
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
	if (arr.empty()) { //���� ������ �� ������
		throw new MapException(9);
	}
	else {
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE); //���������� ��� �����
		cout << "    ";
		for (int i = 0; i < length; i++) //����� ������� ����
	if (x.empty()) {
		throw new MapException(9);
	}
	else {
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		vector<int>colors;
		vector<int>indexes;
		vector<int>indexes1;
		int color = 31, color1 = 31;
		for (int i = 0; i < x.size(); i++)
		{
			bool check = 0;
			if (type[i] == 1) {
				indexes.push_back(color);
				color += 16;
			}
			else {
				for (int b = 0; b < x.size(); b++)
				{
					if (type[b] == 1 && type[i] == 0 && x[b] == x[i] && y[b] == y[i]) {
						check = 1;
					}
				}
				if (check == 0) {
					indexes.push_back(color1);
					color1 += 16;
				}
				else {
					indexes.push_back(-1);
				}
			}
		}
		for (int i = 0; i < indexes.size(); i++)
		{
			cout << indexes[i] << " ";
		}cout << endl;
		color = 31;
		color1 = 31;
		int b = 0;
		cout << "   ";
		for (int i = 0; i < length; i++)
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
			cout << "-  "; //����� ������� �����
		cout << "   ";
		for (int i = 0; i < length; i++)
		{
			cout << "-  ";
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
			cout << "|"; //����� ���� �������,
			for (int j = 0; j < length; j++)
			{
				bool check = 0;
				for (int d = 0; d < arr.size(); d++)
				{
					if (arr[d].x == j + 1 && arr[d].y == i + 1 && arr[d].type == 1) {

						SetConsoleTextAttribute(console_color, arr[d].color);
						cout << " x "; //���� ����� ����� � �������������� ������
						SetConsoleTextAttribute(console_color, 15);
						check = 1;
					}
					else if (checkIsRestaurantInHotel(d) == 0 && arr[d].x == j + 1 && arr[d].y == i + 1 && arr[d].type == 0) {
						SetConsoleTextAttribute(console_color, arr[d].color);
						cout << " o "; //���� ����� ��������� � �������������� ������
						SetConsoleTextAttribute(console_color, 15);
						check = 1;
					}
			cout << "|";
			for (int j = 0; j < length; j++)
			{
				bool check = 0, check1 = 0;
				for (int d = 0; d < x.size(); d++)
				{
					for (int b = 0; b < x.size(); b++)
					{
						if (type[b] == 1 && type[d] == 0 && x[b] == x[d] && y[b] == y[d]) {
							check1 = 1;
						}
					}
					if (x[d] == j + 1 && y[d] == i + 1 && type[d] == 1) {
						
						SetConsoleTextAttribute(console_color, indexes[d]);
						cout << "x";
						SetConsoleTextAttribute(console_color, 15);
						cout << "  ";
						colors.push_back(indexes[d]);
						check = 1;
						color += 16;
					}
					else if (check1 == 0 && x[d] == j + 1 && y[d] == i + 1 && type[d] == 0) {
						SetConsoleTextAttribute(console_color, indexes[d]);
						cout << "o";
						SetConsoleTextAttribute(console_color, 15);
						cout << "  ";
						colors.push_back(0);
						check = 1;
						color1 += 16;
					}
					check1 = 0;
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
			cout << "-  "; //����� ������ �����
		}
		bool hotels = 0, restaurants = 0;
		for (int i = 0; i < arr.size(); i++) //�������� ���� �� � ������� �����/���������
		{
			if (arr[i].type == 1) {
				hotels = 1;
			}
			else if (arr[i].type == 0 && checkIsRestaurantInHotel(i) == 0) {
				restaurants = 1;
			}
		}
		cout << endl << endl;
		if (hotels == 1) { //���� ����� ����
			cout << "\nHotels (x):\n\n";
			for (int i = 0; i < arr.size(); i++)
			{
				if (arr[i].type == 1) { //������� �������������� ���� � ��������
					SetConsoleTextAttribute(console_color, arr[i].color);
					cout << " ";
					SetConsoleTextAttribute(console_color, 15);
					cout << " - " << arr[i].name << endl << endl;
				}
			}
			cout << endl;
		}
		
		if (restaurants == 1) { //���� ��������� ����
			cout << "Restaurants (o):\n\n";
			for (int i = 0; i < arr.size(); i++)
			{
				if (checkIsRestaurantInHotel(i) == 0 && arr[i].type == 0) { //� ���� ��� �� ��� ������
					SetConsoleTextAttribute(console_color, arr[i].color);
					cout << " "; //������� �������������� ���� � ��������
					SetConsoleTextAttribute(console_color, 15);
					cout << " - " << arr[i].name << endl << endl;
				}
			}
			cout << endl;
		}
		bool check = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (checkIsRestaurantInHotel(i) == 1) { //��������� ���� �� ��������� ��� ������
				check = 1;
			}
		}
		if (check == 1) { //���� ����
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
					cout << " "; //������� ���� ����� 
					SetConsoleTextAttribute(console_color, 15);
					cout << " :\n\n";

					for (int j = 0; j < arr.size(); j++)
					{
						if (arr[i].type == 1 && arr[j].type == 0 && arr[i] == arr[j]) {
							cout << arr[j].name << endl; //� ��� �������� ����������
						}
					}
					cout << endl;
				}
				if (arr[i].type == 1) {
					index++;
		cout << "   ";
		for (int i = 0; i < length; i++)
		{
			cout << "-  ";
		}
		bool hotels = 0, restaurants = 0;
		for (int i = 0; i < x.size(); i++)
		{
			if (type[i] == 1) {
				hotels = 1;
			}
			else if (type[i] == 0) {
				bool check = 0;
				for (int j = 0; j < x.size(); j++)
				{
					if (type[j] == 1 && type[i] == 0 && x[j] == x[i] && y[j] == y[i]) {
						check = 1;
					}
				}
				if (check == 0) {
					restaurants = 1;
				}
			}
		}
		if (hotels == 1) {
			color = 31;
			cout << endl << endl;
			cout << "Hotels (x):\n\n";
			for (int i = 0; i < x.size(); i++)
			{
				if (type[i] == 1) {
					SetConsoleTextAttribute(console_color, color);
					cout << " ";
					SetConsoleTextAttribute(console_color, 15);
					cout << " - " << name[i] << endl;
					cout << endl;
					color += 16;
				}
			}
		}
		if (restaurants == 1) {
			color = 31;
			cout << "\nRestaurants (o):\n\n";
			for (int i = 0; i < x.size(); i++)
			{
				bool check = 0;
				for (int j = 0; j < x.size(); j++)
				{
					if (type[j] == 1 && type[i] == 0 && x[j] == x[i] && y[j] == y[i]) {
						check = 1;
					}
				}
				if (check == 0 && type[i] == 0) {
					SetConsoleTextAttribute(console_color, color);
					cout << " ";
					SetConsoleTextAttribute(console_color, 15);
					cout << " - " << name[i] << endl;
					cout << endl;
					color += 16;
				}
			}
		}
		if (colors.size() > 0) {
			cout << "\nRestaurants in hotels:\n\n";
			for (int i = 0; i < x.size(); i++)
			{
				bool check = 0;
				int index = 0;
				for (int j = 0; j < x.size(); j++)
				{
					if (type[j] == 1 && type[i] == 0 && x[j] == x[i] && y[j] == y[i]) {
						check = 1;
						index = j;
						//indexes.push_back(d);
					}
				}
				if (check == 1) {
					SetConsoleTextAttribute(console_color, colors[index]);
					cout << " ";
					SetConsoleTextAttribute(console_color, 15);
					cout << " - " << name[i] << endl;
					cout << endl;
					color += 16;
				}
			}
		}
	}
}

float Map::calcDistance(int index1, int index2) const
{
	if (arr.empty()) { //���� ������ �� ������
		throw new MapException(9);
	}
	else if (index1 < 0 || index1 > arr.size()) {
		throw new MapException(10, 1);
	}
	else if (index2 < 0 || index2 > arr.size()) {
		throw new MapException(10, 2);
	}
	else { //������� ��������� ����� 2 ������� � ������� ��������
		return sqrt(pow(arr[index2] - arr[index1], 2) + pow(arr[index2].y - arr[index1].y, 2));
	if (x.empty()) {
		throw new MapException(9);
	}
	else if (index1 < 0 || index1 > x.size()) {
		throw new MapException(10, 1);
	}
	else if (index2 < 0 || index2 > x.size()) {
		throw new MapException(10, 2);
	}
	else {
		return sqrt(pow(x[index2] - x[index1], 2) + pow(y[index2] - y[index1], 2));
	}
	return -1;
}

float Map::calcDistance(string name1, string name2) const
{
	if (arr.empty()) { //���� ������ �� ������
	if (x.empty()) {
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
			//������� ��������� ����� 2 ������� � ������� ��������
			return sqrt(pow(arr[index2] - arr[index1], 2) + pow(arr[index2].y - arr[index1].y, 2));
		}
	}
	return -1;
}

void Map::setColors() //�����, ���������� ������� ������ (�� �������� � �������� � 
			          //������������ � �������� � �������) ������ � ���������� �� �����������. 
					  //��� ���������� ��� ������ �������� �������� ����� �����
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

bool Map::checkIsRestaurantInHotel(int index) //�����, ������������ true, ���� �������� ��������� ��� �����,
											  //false, ���� ���
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
	return this->x == obj.x && this->y == obj.y; //���������� ������� �� � � �; ����������� � ������ �������
}

int Point::operator-(const Point& obj) const&
{
	return x - obj.x; //�������� ����; ����������� � calcDistance()
			for (int i = 0; i < x.size(); i++)
			{
				if (name[i] == name1) {
					index1 = i;
				}
				else if (name[i] == name2) {
					index2 = i;
				}
			}
			return sqrt(pow(x[index2] - x[index1], 2) + pow(y[index2] - y[index1], 2));
		}
	}
	return -1;
}