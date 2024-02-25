#include "Map.h"

Map::Map(int _length, int _width)
{
	if (_length > 0 && _width > 0) {
		length = _length;
		width = _width;
	}
}

void Map::addPoint(int _x, int _y, string _name)
{
	if (_x > 0 && _x <= length && _y > 0 && _y <= width && _name.size() > 1) {
		x.push_back(_x);
		y.push_back(_y);
		name.push_back(_name);
	}
	throw new TourInputErrorException();
}

void Map::delPoint(int index)
{
	if (index >= 0 && index < x.size()) {
		x.erase(x.begin() + index);
		y.erase(y.begin() + index);
		name.erase(name.begin() + index);
	}
	throw new TourInputErrorException();
}

void Map::delPoint(int _x, int _y)
{
	bool check = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == _x && y[i] == _y) {
			x.erase(x.begin() + i);
			y.erase(y.begin() + i);
			name.erase(name.begin() + i);
			check = 1;
			break;
		}
	}
	if (check == 0) {
		throw new TourInputErrorException();
	}
}

void Map::delPoint(string _name)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (name[i] == _name) {
			x.erase(x.begin() + i);
			y.erase(y.begin() + i);
			name.erase(name.begin() + i);
			break;
		}
	}
	throw new TourInputErrorException();
}

void Map::show() const
{
	HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = 31;
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
		cout << "|";
		for (int j = 0; j < length; j++)
		{
			bool check = 0;
			for (int d = 0; d < x.size(); d++)
			{
				if (x[d] == j + 1 && y[d] == i + 1) {
					SetConsoleTextAttribute(console_color, color);
					cout << "x";
					SetConsoleTextAttribute(console_color, 15);
					cout << "  ";
					check = 1;
					color += 16;
				}
			}
			if (check == 0) {
				cout << "   ";
			}
		}
		cout << "|\n";
	}
	cout << "   ";
	for (int i = 0; i < length; i++)
	{
		cout << "-  ";
	}
	color = 31;
	cout << endl <<endl;
	for (int i = 0; i < x.size(); i++)
	{
		SetConsoleTextAttribute(console_color, color);
		cout << " ";
		SetConsoleTextAttribute(console_color, 15);
		cout << " - " << name[i] << endl;
		cout << endl;
		color += 16;
	}
	cout << endl;
	for (int i = 0; i < x.size(); i++)
	{
		cout << "(" << x[i] << "; " << y[i] << ") - " << name[i] << endl;
		cout << endl;
	}
}

float Map::calcDistance(int index1, int index2) const
{
	if (index1 >= 0 && index1 < x.size() && index2 >= 0 && index2 < x.size()) {
		return sqrt(pow(x[index2] - x[index1], 2) + pow(y[index2] - y[index1], 2));
	}
	throw new TourInputErrorException();
	return -1;
}

void Map::showPoints() const
{
	for (int i = 0; i < x.size(); i++)
	{
		cout << x[i] << " " << y[i] << endl;
	}
}