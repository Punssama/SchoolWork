#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        standardize();
    }

    void standardize()
    {
        if (seconds >= 60)
        {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

    friend istream &operator>>(istream &is, Time &t)
    {
        cout << "Nhap gio, phut, giay: ";
        is >> t.hours >> t.minutes >> t.seconds;
        t.standardize();
        return is;
    }

    friend ostream &operator<<(ostream &os, const Time &t)
    {
        os << setfill('0') << setw(2) << t.hours << ":"
           << setfill('0') << setw(2) << t.minutes << ":"
           << setfill('0') << setw(2) << t.seconds;
        return os;
    }

    friend const Time operator+(const Time &t1, const Time &t2)
    {
        Time result;
        result.hours = t1.hours + t2.hours;
        result.minutes = t1.minutes + t2.minutes;
        result.seconds = t1.seconds + t2.seconds;
        result.standardize();
        return result;
    }

    friend const Time operator-(const Time &t1, const Time &t2)
    {
        long totalSec1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
        long totalSec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

        long diff = totalSec1 - totalSec2;
        if (diff < 0)
            diff = 0;

        Time result;
        result.hours = diff / 3600;
        diff %= 3600;
        result.minutes = diff / 60;
        result.seconds = diff % 60;
        return result;
    }

    friend bool operator==(const Time &t1, const Time &t2)
    {
        return (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds == t2.seconds);
    }

    Time operator-() const
    {
        return Time(-hours, -minutes, -seconds);
    }

    Time &operator++()
    {
        seconds++;
        standardize();
        return *this;
    }

    Time operator++(int)
    {
        Time temp = *this;
        seconds++;
        standardize();
        return temp;
    }
};

int main()
{
    Time t1, t2;

    cout << "--- Nhap thong tin Time 1 ---\n";
    cin >> t1;
    cout << "--- Nhap thong tin Time 2 ---\n";
    cin >> t2;

    cout << "\nTime 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;

    Time t3 = t1 + t2;
    cout << "Tong (t1 + t2): " << t3 << endl;

    Time t4 = t1 - t2;
    cout << "Hieu (t1 - t2): " << t4 << endl;

    if (t1 == t2)
        cout << "t1 bang t2" << endl;
    else
        cout << "t1 khac t2" << endl;

    cout << "\nThu nghiem tang tien to (++t1): ";
    cout << ++t1 << endl;

    cout << "Thu nghiem tang hau to (t2++): ";
    cout << t2++ << " (Gia tri sau khi in dong nay moi tang: " << t2 << ")" << endl;

    return 0;
}