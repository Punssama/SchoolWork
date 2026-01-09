#include <iostream>
#include <string>

using namespace std;

class Month
{
public:
    Month();
    Month(string monthWord);
    Month(int monthNum);
    void nextMonth();
    void input();
    void output();

private:
    int month;
    string monthName;
};

Month::Month()
{
    month = 1;
    monthName = "Jan";
}

Month::Month(int monthNum)
{
    if (month >= 1 && month <= 12)
    {
        cout << "Thang hop le";
        month = monthNum;
    }
    else
    {
        cout << "Khong hop le";
    }
}

Month::Month(string monthWord)
{
    string months[12] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int result = 1;
    for (int i = 0; i < 12; i++)
    {
        if (monthWord == months[i])
        {
            result = i + 1;
            return;
        }
    }
}
void Month::output()
{
    string months[12] = {"January", "Febuary",
                         "March", "April", "May", "June", "July", "August", "September", "October",
                         "November", "December"};
    cout << "\nThang: " << months[month - 1];
}

void Month::input()
{
    cout << "Nhap vao thang cua ban la so: ";
    cin >> month;
    getchar();
    cout << "Nhap vao thang cua ban la chu: ";
    getline(cin, monthName);
}
void Month::nextMonth()
{
    int rs = month;
    if (month == 12)
    {
        rs = 1;
    }
    else
    {
        rs += 1;
    }
    cout << "\nThang tiep theo cua thang " << month << " la: "
         << "thang " << rs;
}
int main()
{
    Month m1;
    m1.input();
    m1.output();
    m1.nextMonth();
}