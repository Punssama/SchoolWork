#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    int age;
    double salary;

public:
    Employee() : name("Nguyen Van A"), age(20), salary(1000.0) {}

    Employee(string name1, int age1, double sal1)
        : name(name1), age(age1), salary(sal1) {}

    // Getter & Setter
    string getName() { return name; }
    void setName(string n) { name = n; }
    int getAge() { return age; }
    void setAge(int a) { age = a; }
    double getSalary() { return salary; }
    void setSalary(double s) { salary = s; }

    virtual void selfIntroduce()
    {
        cout << "I am an employee" << endl;
    }

    virtual void output()
    {
        cout << "Name: " << name << ", Age: " << age << ", Salary: " << salary << " USD" << endl;
    }
};

class Doctor : public Employee
{
private:
    double fee;
    string speciality;

public:
    Doctor() : Employee(), fee(0), speciality("General") {}

    Doctor(string name1, int age1, double sal1, double fee1, string spec1)
        : Employee(name1, age1, sal1), fee(fee1), speciality(spec1) {}

    // Getter & Setter
    double getFee() { return fee; }
    void setFee(double f) { fee = f; }
    string getSpeciality() { return speciality; }
    void setSpeciality(string s) { speciality = s; }

    void selfIntroduce() override
    {
        cout << "I am a doctor" << endl;
    }

    void output() override
    {
        Employee::output();
        cout << "Speciality: " << speciality << ", Fee: " << fee << " USD" << endl;
    }
};

int main()
{
    Employee emp("Tran Thi B", 25, 1200);
    emp.selfIntroduce();
    emp.output();

    cout << "--------------------" << endl;

    Doctor doc("Le Van C", 40, 5000, 200, "Cardiology");
    doc.selfIntroduce();
    doc.output();

    return 0;
}