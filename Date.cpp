#include "Date.h"

bool Date::isLeapYear() const
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int Date::monthDays() const
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear() ? 29 : 28;
    }
}

void Date::nextDate()
{
    if (day == 31 && month == 12)
    {
        year++;
        day = 1;
        month = 1;
    }
    else if (day == monthDays())
    {
        day = 1;
        month++;
    }
    else
    {
        day++;
    }
}

void Date::prevDate()
{
    if (day == 1 && month == 1)
    {
        year--;
        day = 31;
        month = 12;
    }
    else if (day == 1)
    {
        month--;
        day = monthDays();
    }
    else
    {
        day--;
    }
}

Date::Date()
{
    tm* obj = new tm;
    time_t time_ = time(0);
    localtime_s(obj, &time_);

    day = obj->tm_mday;
    month = obj->tm_mon + 1;
    year = obj->tm_year + 1900;
    delete obj;
}

Date::Date(int _day, int _month, int _year)
{
    *this = Date();
    setYear(_year);
    setMonth(_month);
    setDay(_day);
}

Date::~Date()
{
}

void Date::setYear(int _year)
{
    year = _year;
}

int Date::getYear() const
{
    return year;
}

void Date::setMonth(int _month)
{
    if (_month > 0 && _month <= 12)
    {
        month = _month;
    }
}

int Date::getMonth() const
{
    return month;
}

void Date::setDay(int _day)
{
    if (_day>0 && _day<=monthDays())
    {
        day = _day;
    }
}

int Date::getDay() const
{
    return day;
}

void Date::showDate() const
{
    cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year;
}

bool Date::valid() const
{
    return (month >= 0 && month <= 12) && (day > 0 && day <= monthDays());
}

bool Date::operator==(const Date& obj) const&
{
    //*this == obj
    return this->day == obj.day && this->month == obj.month && this->year == obj.year;
}

bool Date::operator!=(const Date& obj) const&
{
    return this->day != obj.day || this->month != obj.month || this->year != obj.year;
}

bool Date::operator>(const Date& obj) const&
{
    if (this->year > obj.year)
    {
        return true;
    }
    else if (this->year == obj.year && this->month > obj.month)
    {
        return true;
    }
    else if (this->year == obj.year && this->month == obj.month && this->day > obj.day)
    {
        return true;
    }
    else
        return false;
}

bool Date::operator<(const Date& obj) const&
{
    return !(*this>obj) && *this != obj;
}

bool Date::operator>=(const Date& obj) const&
{
    return *this > obj || *this == obj;
}

bool Date::operator<=(const Date& obj) const&
{
    return !(*this > obj) || *this == obj;
}

Date& Date::operator+=(int days)
{
    for (int i = 0; i < days; i++)
    {
        this->nextDate();
    }
    return* this;
}

Date& Date::operator-=(int days)
{
    for (int i = 0; i < days; i++)
    {
        this->prevDate();
    }
    return* this;
}

Date& Date::operator+=(float months)
{
    this->month += months;
    if (this->month > 12)
    {
        year += (this->month-1) / 12;
        this->month = (this->month - 1) % 12;
    }
    return* this;
}

Date& Date::operator-=(float months)
{
    this->month -= months;
    if (this->month < 1)
    {
        /*year -= (12 - this->month + 1) / 12;
        this->month = (12 + this->month - 1) % 12;*/
        year -= (abs(this->month - 1)) / 12;
        this->month = (abs(this->month - 1)) % 12;
    }
    return* this;
}

Date& Date::operator+=(long years)
{
    this->year += years;
    return*this;
}

Date& Date::operator-=(long years)
{
    this->year -= years;
    return*this;
}

Date Date::operator+(int days) const&
{
    Date tmp = *this;
    tmp += days;
    return tmp;
}

Date Date::operator-(int days) const&
{
    Date tmp = *this;
    tmp -= days;
    return tmp;
}

Date Date::operator+(float months) const&
{
    Date tmp = *this;
    tmp += months;
    return tmp;
}

Date Date::operator-(float months) const&
{
    Date tmp = *this;
    tmp -= months;
    return tmp;
}

Date Date::operator+(long years) const&
{
    Date tmp = *this;
    tmp += years;
    return tmp;
}

Date Date::operator-(long years) const&
{
    Date tmp = *this;
    tmp -= years;
    return tmp;
}

int Date::operator-(const Date& obj) const&
{
    int amount = 0;
    Date tmp = *this;
    if (tmp < obj)
    {
        while (tmp != obj)
        {
            tmp += 1;
            amount++;
        }
    }
    else if (tmp >obj)
    {
        while (tmp > obj)
        {
            tmp += 1;
            amount++;
        }
    }
    return amount;
}

Date& Date::operator--()
{
    this->prevDate();
    return*this;
}

Date& Date::operator++()
{
    this->nextDate();
    return*this;
}

Date& Date::operator--(int)
{
    Date tmp = *this;
    this->prevDate();
    return tmp;
}

Date& Date::operator++(int)
{
    Date tmp = *this;
    this->nextDate();
    return tmp;
}

Date operator+(int n, const Date& a)
{
    return a + n;
}

Date operator-(int n, const Date& a)
{
    return a - n;
}

ostream& operator<<(ostream& os, const Date& t)
{
    os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year / 10 << t.year % 10;
    return os;
}

istream& operator>>(istream& is, Date& t)
{
    do {
        cout << "dd mm yyyy\n";
        is >> t.day >> t.month >> t.year;
    } while (!t.valid());
    return is;
}
