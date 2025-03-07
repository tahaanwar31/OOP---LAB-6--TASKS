#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    float salary;

public:
    Employee(string empName, float empSalary) {
        name = empName;
        salary = empSalary;
    }

    virtual void displayDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Manager : public Employee {
private:
    float bonus;

public:
    Manager(string empName, float empSalary, float empBonus) : Employee(empName, empSalary) {
        bonus = empBonus;
    }

    void displayDetails() override {
        cout << "Manager Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Bonus: $" << bonus << endl;
    }
};

int main() {
    string name;
    float salary, bonus;

    cout << "Enter manager name: ";
    getline(cin, name);

    cout << "Enter salary: ";
    cin >> salary;

    cout << "Enter bonus: ";
    cin >> bonus;

    Manager manager(name, salary, bonus);
    cout << "\nManager Details:\n";
    manager.displayDetails();

    return 0;
}
