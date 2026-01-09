#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
public:
    SinhVien() {};
    void input();
    void output();
    void Scoring();

private:
    string name, id, GPA = "";
    double score;
};

void SinhVien::input()
{
    cout << "Name: ";
    getline(cin, name);
    cout << "ID: ";
    getline(cin, id);
    cout << "Score: ";
    cin >> score;
}

void SinhVien::output()
{
    cout << "Name" << name << endl;
    cout << "ID: " << id << endl;
    cout << "GPA: " << GPA << endl;
}

void SinhVien::Scoring()
{
    if (score >= 8.5 && score <= 10.0)
    {
        GPA = "A";
    }
    else if (score >= 7.0 && score <= 8.4)
    {
        GPA = "B";
    }
    else if (score >= 5.5 && score <= 6.9)
    {
        GPA = "C";
    }
    else if (score >= 4.0 && score <= 5.4)
    {
        GPA = "D";
    }
    else
    {
        GPA = "F";
    }
}

int main()
{
    SinhVien a;
    a.input();
    a.Scoring();
    a.output();
}