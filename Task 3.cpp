#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string pName, int pAge) {
        name = pName;
        age = pAge;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;

public:
    Teacher(string pName, int pAge, string pSubject) : Person(pName, pAge) {
        subject = pSubject;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;

public:
    Researcher(string pName, int pAge, string pResearchArea) : Person(pName, pAge) {
        researchArea = pResearchArea;
    }

    void displayDetails() override {
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string pName, int pAge, string pSubject, string pResearchArea, int pPublications) 
        : Person(pName, pAge), Teacher(pName, pAge, pSubject), Researcher(pName, pAge, pResearchArea) {
        publications = pPublications;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter professor's name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter subject expertise: ";
    getline(cin, subject);

    cout << "Enter research area: ";
    getline(cin, researchArea);

    cout << "Enter number of publications: ";
    cin >> publications;

    Professor professor(name, age, subject, researchArea, publications);
    cout << "\nProfessor Details:\n";
    professor.displayDetails();

    return 0;
}
