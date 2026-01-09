#include <iostream>
using namespace std;

class CPU
{
protected:
    double tocdo;

public:
    // CPU() {};
    CPU(double s)
    {
        // tocdo = s;
    }
    virtual double sucManh() const
    {
        return tocdo;
    }

    void xepHang()
    {
        if (sucManh() > 3)
        {
            cout << "Con chip nay rat manh!" << endl;
        }
    }
};

class Core2Dual : public CPU
{
public:
    Core2Dual(double s);
    double sucManh() const
    {
        return 2 * tocdo;
    }
};

int main()
{
    Core2Dual aChip(2);
    aChip.xepHang();
}