#include "Time.h"

Time_::Time_()
{
    tm* obj = new tm;
    time_t Time_ = time(0);
    localtime_s(obj, &Time_);

    hour = obj->tm_hour;
    minutes = obj->tm_min;
    seconds = obj->tm_sec;
    format = true;
    delete obj;
}

Time_::Time_(int _hour, int _minutes, int _seconds, bool _format)
{
    *this = Time_();
    setHour(_hour);
    setMinutes(_minutes);
    setSeconds(_seconds);
    setFormat(_format);
}

//Time_& Time_::operator=(const Time_& obj)
//{
//    // TODO: insert return statement here
//}

Time_::~Time_()
{
}

int Time_::getHour() const
{
    return hour;
}

int Time_::getMinutes() const
{
    return minutes;
}

int Time_::getSeconds() const
{
    return seconds;
}

bool Time_::getFormat() const
{
    return format;
}

void Time_::setHour(int _hour)
{
    if (_hour > -1 && _hour <=24)
    {
        
        hour = _hour;
    }
}

void Time_::setMinutes(int _minutes)
{
    if (_minutes > -1 && _minutes <= 59)
    {
        minutes = _minutes;
    }
}

void Time_::setSeconds(int _seconds)
{
    if (_seconds > -1 && _seconds <= 59)
    {
        seconds = _seconds;
    }
}

void Time_::setFormat(bool _format)
{
    if (true || _format == 1)
    {
        format = true;
    }
    else if (false || _format == 0)
    {
        format = false;
    }
}

bool Time_::valid() const
{
    return (hour>-1 && hour<=24)&& (minutes > -1 && minutes <= 60) && (seconds > -1 && seconds <= 24);
}

void Time_::tickTime()
{
    if (seconds >= 59 && minutes >= 59 && hour >= 23)
    {
        hour = 0;
        minutes = 0;
        seconds = 0;
    }
    else if (minutes >= 59 && seconds >= 59)
    {
        seconds = 0;
        minutes = 0;
        hour++;
    }
    else if (seconds >= 59)
    {
        seconds = 0;
        minutes++;
    }
    else
    {
        seconds++;
    }
}

void Time_::untickTime()
{
    if (seconds == 0 && minutes == 0)
    {
        hour--;
        minutes = 59;
        seconds = 59;
    }
    else if (seconds == 0)
    {
        seconds = 59;
        minutes--;
    }
    else if (hour != -1)
    {
        seconds--;
    }
    else
    {
        seconds = 0;
        minutes = 0;
        hour = 0;
    }
}

void Time_::showTime() const
{
    if (getFormat() == true)
    {
        cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << endl;
    }
    else if (getFormat() == false)
    {
        cout << hour / 24 << hour % 12 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << endl;
    }
    
}

void Time_::displayTime() const
{
    if (getFormat() == true)
    {
        cout << "Current time: ";
        cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << endl;
    }
    else if (getFormat() == false)
    {
        cout << "Current time: ";
        cout << hour / 24 << hour % 12 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << endl;
    }
}

bool Time_::operator==(const Time_& obj) const&
{
    return (this->hour == obj.hour) && (this->minutes == obj.minutes) && (this->seconds == obj.seconds);
}

bool Time_::operator!=(const Time_& obj) const&
{
    return (this->hour != obj.hour) || (this->minutes != obj.minutes) || (this->seconds != obj.seconds);
}

bool Time_::operator>(const Time_& obj) const&
{
    if (this->hour > obj.hour)
    {
        return true;
    }
    else if ((this->hour == obj.hour) && (this->minutes > obj.minutes))
    {
        return true;
    }
    else if ((this->hour == obj.hour) && (this->minutes == obj.minutes) && (this->seconds > obj.seconds))
    {
        return true;
    }
    else
        return false;
}

bool Time_::operator<(const Time_& obj) const&
{
    return !(*this > obj) && *this != obj;
}

bool Time_::operator>=(const Time_& obj) const&
{
    return *this > obj || *this == obj;
}

bool Time_::operator<=(const Time_& obj) const&
{
    return !(*this > obj) || *this == obj;
}

Time_& Time_::operator+=(int s)
{
    for (int i = 0; i < s; i++)
    {
        this->tickTime();
    }
    return*this;
}

Time_& Time_::operator-=(int s)
{
    for (int i = 0; i < s; i++)
    {
        this->untickTime();
    }
    return*this;
}

Time_& Time_::operator+=(float m)
{
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < 60; i++)
        {
            this->tickTime();
        }
    }
    return*this;
}

Time_& Time_::operator-=(float m)
{
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < 60; i++)
        {
            this->untickTime();
        }
    }
    return*this;
}

Time_& Time_::operator+=(long h)
{
    for (int k = 0; k < h; k++)
    {
        for (int j = 0; j < 60; j++)
        {
            for (int i = 0; i < 60; i++)
            {
                this->tickTime();
            }
        }
    }
    return*this;
}

Time_& Time_::operator-=(long h)
{
    for (int k = 0; k < h; k++)
    {
        for (int j = 0; j < 60; j++)
        {
            for (int i = 0; i < 60; i++)
            {
                this->untickTime();
            }
        }
    }
    return*this;
}

Time_ Time_::operator+(int s) const&
{
    Time_ tmp = *this;
    tmp += s;
    return tmp;
}

Time_ Time_::operator-(int s) const&
{
    Time_ tmp = *this;
    tmp -= s;
    return tmp;
}

Time_ Time_::operator+(float m) const&
{
    Time_ tmp = *this;
    tmp += m;
    return tmp;
}

Time_ Time_::operator-(float m) const&
{
    Time_ tmp = *this;
    tmp -= m;
    return tmp;
}

Time_ Time_::operator+(long h) const&
{
    Time_ tmp = *this;
    tmp += h;
    return tmp;
}

Time_ Time_::operator-(long h) const&
{
    Time_ tmp = *this;
    tmp -= h;
    return tmp;
}

Time_& Time_::operator--()
{
    this->untickTime();
    return*this;
}

Time_ Time_::operator--(int)
{
    Time_ tmp = *this;
    this->untickTime();
    return tmp;
}

Time_& Time_::operator++()
{
    this->tickTime();
    return*this;
}

Time_ Time_::operator++(int)
{
    Time_ tmp = *this;
    this->tickTime();
    return tmp;
}

Time_ operator+(int seconds, const Time_& a)
{
    return a + seconds;
}

Time_ operator-(int seconds, const Time_& a)
{
    return a - seconds;
}

ostream& operator<<(ostream& os, const Time_& t)
{
    if (t.getFormat() == true)
    {
        os << t.hour / 10 << t.hour % 10 << ":" << t.minutes / 10 << t.minutes % 10 << ":" << t.seconds / 10 << t.seconds % 10 << endl;
    }
    else if (t.getFormat() == false)
    {
        os << t.hour / 24 << t.hour % 12 << ":" << t.minutes / 10 << t.minutes % 10 << ":" << t.seconds / 10 << t.seconds % 10 << endl;
    }
    return os;
}

istream& operator>>(istream& is, Time_& t)
{
    do {
        cout << "Seconds minutes hours\n";
        is >> t.seconds >> t.minutes >> t.hour;
    } while (!t.valid());
    return is;
}
