#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
    Time();
    Time(int h, int m, int n);
    void standardize();
    void input();
    void output() const;
    void setHour(int hourVal);
    void setMinute(int minuteVal);
    void setSecond(int secondVal);
    int getHour() const { return hour; };
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

private:
    int hour;
    int minute;
    int second;
};

Time::Time() {};
void Time::setHour(int hourVal)
{
    hour = hourVal;
}
void Time::setMinute(int minuteVal)
{
    minute = minuteVal;
}
void Time::setSecond(int secondVal)
{
    second = secondVal;
}

void Time::standardize()
{
    second = second % 60;
    minute += second / 60;
    minute = minute % 60;
    hour += minute / 60;
    hour = hour % 24;
}

void Time::input()
{
    cout << "Nhap vao gio: ";
    cin >> hour;
    cout << "Nhap vao phut: ";
    cin >> minute;
    cout << "Nhap vao giay: ";
    cin >> second;
}

void Time::output() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
    standardize();
}

const Time operator+(const Time &var1, const Time &var2);
const Time operator-(Time &var1, Time &var2);
const bool operator==(const Time &val1, Time &val2)
{
    return (val1.getHour() == val2.getHour() && val1.getMinute() == val2.getMinute() && val1.getSecond() == val2.getSecond()) ? true : false;
}

int main()
{
    Time timeval1, timeval2, timeval3;
    timeval1.input();
    timeval1.standardize();
    cout << "Thoi gian 1 la: ";
    timeval1.output();
    timeval2.input();
    timeval2.standardize();
    cout << "Thoi gian 2 la: ";
    timeval2.output();

    cout << "Tong thoi gian cua timeval1 + timeval2: ";
    (timeval1 + timeval2).output();
    if (timeval1 == timeval2)
    {
        cout << "Thoi gian bang nhau";
    }
}

const Time operator+(const Time &var1, const Time &var2)
{
    int h = var1.getHour() + var2.getHour();
    int m = var1.getMinute() + var2.getMinute();
    int s = var1.getSecond() + var2.getSecond();
    return Time(h, m, s);
}

const Time operator-(const Time &var1, const Time &var2)
{
    int h = var1.getHour() - var2.getHour();
    int m = var1.getMinute() - var2.getMinute();
    int s = var1.getSecond() - var2.getSecond();
    return Time(h, m, s);
}
