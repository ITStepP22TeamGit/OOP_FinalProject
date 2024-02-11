#pragma once
#include <ctime>
#include <iostream>
using namespace std;
class Date
{
	int year;
	int month;
	int day;

	bool isLeapYear()const; //�������� �� ���������� ���
	int monthDays()const; //���������� ���� �� ������
	void nextDate(); //��������� ����
	void prevDate(); //���������� ����

public:
	//---------������������ � ����������---------//
	Date(); // �� ���������  - ������� ����
	Date(int _day, int _month, int _year); //� ����������� - �������� ����
	//��� �� ���
	~Date();// ����������

	//---------���������---------
	void setYear(int _year);
	int getYear()const;
	void setMonth(int _month);
	int getMonth()const;
	void setDay(int _day);
	int getDay()const;

	void showDate()const;
	bool valid()const; //�������� ���� �� ������������

	//--------- ��������� ��������� ---------
	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;

	//--------- ��������� ���������� ---------	
	Date& operator += (int days); //�������� days ���� � ����
	Date& operator -= (int days); //������� days ���� �� ����
	Date& operator += (float months); //�������� months ������� � ����
	Date& operator -= (float months); //������� months ������� �� ����
	Date& operator += (long years); //�������� years ��� � ����
	Date& operator -= (long years); //������� years ��� �� ����

	//--------- �������������� ��������� ---------
	Date operator + (int days)const&;
	Date operator - (int days)const&;
	Date operator + (float months)const&; //�������� months ������� � ����
	Date operator - (float months)const&; //������� months ������� �� ����
	Date operator + (long years)const&; //�������� years ��� � ����
	Date operator - (long years)const&; //������� years ��� �� ����

	int operator - (const Date& obj)const&; //���������� ���� ����� ������

	//--------- 
	Date& operator -- ();
	Date& operator ++ ();
	Date& operator -- (int);
	Date& operator ++ (int);

	friend Date operator + (int n, const Date& a);
	friend Date operator - (int n, const Date& a);

	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);
};
