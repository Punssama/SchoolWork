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
    Employee() : name("Staff Member"), age(25), salary(1500.0) {}

    Employee(string name1, int age1, double sal1)
        : name(name1), age(age1), salary(sal1) {}

    // Getter/Setter
    string getName() { return name; }
    void setName(string n) { name = n; }
    int getAge() { return age; }
    void setAge(int a) { age = a; }
    double getSalary() { return salary; }
    void setSalary(double s) { salary = s; }

    virtual void selfIntroduce()
    {
        cout << "[System]: Checking employee status..." << endl;
        cout << "Role: I am a hospital employee." << endl;
    }

    virtual void output()
    {
        cout << "Profile -> Name: " << name << " | Age: " << age << " | Basic Salary: $" << salary << endl;
    }
};

class Doctor : public Employee
{
private:
    double fee;
    string speciality;

public:
    Doctor() : Employee(), fee(50.0), speciality("General Practice") {}

    Doctor(string name1, int age1, double sal1, double fee1, string spec1)
        : Employee(name1, age1, sal1), fee(fee1), speciality(spec1) {}

    void setFee(double f) { fee = f; }
    double getFee() { return fee; }
    void setSpeciality(string s) { speciality = s; }
    string getSpeciality() { return speciality; }

    void selfIntroduce() override
    {
        cout << "[System]: Verification complete." << endl;
        cout << "Role: I am a specialized Doctor." << endl;
    }

    void output() override
    {
        Employee::output();
        cout << "Speciality: " << speciality << " | Consultation Fee: $" << fee << endl;
    }
};

int main()
{
    Doctor d1("Dr. Steven", 45, 8000, 500, "Neurosurgeon");
    d1.selfIntroduce();
    d1.output();
    return 0;
}