#pragma once
#include <ctime>
#include <iostream>
using namespace std;
class Time_
{
	int hour;
	int minutes;
	int seconds;
	bool format;// true = utc (24-hours),    false = am/pm (12-hours), 

public:
	Time_(); // Current local time
	Time_(int _hour, int _minutes, int _seconds, bool _format);
	//Time_& operator = (const Time_& obj);
	~Time_();

	int getHour()const;
	int getMinutes()const;
	int getSeconds()const;
	bool getFormat()const;

	void setHour(int _hour);
	void setMinutes(int _minutes);
	void setSeconds(int _seconds);
	void setFormat(bool _format);
	

	bool valid()const; //time check
	void tickTime(); //every tick add one second
	void untickTime(); //every tick remove one second
	void showTime()const; //show time by the format

	//--------- Comparison operators ---------
	bool operator == (const Time_& obj)const&;
	bool operator != (const Time_& obj)const&;
	bool operator > (const Time_& obj)const&;
	bool operator < (const Time_& obj)const&;
	bool operator >= (const Time_& obj)const&;
	bool operator <= (const Time_& obj)const&;

	//--------- Assignment operators ---------	
	Time_& operator += (int s);		// add seconds
	Time_& operator -= (int s);
	Time_& operator += (float m);	// add minutes
	Time_& operator -= (float m);
	Time_& operator += (long h);	// add hours
	Time_& operator -= (long h);

	//--------- Arithmetic operators ---------
	Time_ operator + (int s)const&;	// add seconds
	Time_ operator - (int s)const&;
	Time_ operator + (float m)const&; // add minutes
	Time_ operator - (float m)const&;
	Time_ operator + (long h)const&; // add hours
	Time_ operator - (long h)const&;

	//----------------------------------------

	Time_& operator -- ();
	Time_ operator -- (int);
	Time_& operator ++ ();
	Time_ operator ++ (int);

	friend Time_ operator + (int seconds, const Time_& a);
	friend Time_ operator - (int seconds, const Time_& a);

	friend ostream& operator << (ostream& os, const Time_& t);
	friend istream& operator >> (istream& is, Time_& t);


};
