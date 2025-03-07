#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string vBrand, int vSpeed) {
        brand = vBrand;
        speed = vSpeed;
    }

    virtual void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(string vBrand, int vSpeed, int vSeats) : Vehicle(vBrand, vSpeed) {
        seats = vSeats;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Seating Capacity: " << seats << " seats" << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(string vBrand, int vSpeed, int vSeats, int vBatteryLife) : Car(vBrand, vSpeed, vSeats) {
        batteryLife = vBatteryLife;
    }

    void displayDetails() override {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " km" << endl;
    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;

    cout << "Enter brand: ";
    getline(cin, brand);

    cout << "Enter speed: ";
    cin >> speed;

    cout << "Enter seating capacity: ";
    cin >> seats;

    cout << "Enter battery life (in km): ";
    cin >> batteryLife;

    ElectricCar eCar(brand, speed, seats, batteryLife);
    cout << "\nElectric Car Details:\n";
    eCar.displayDetails();

    return 0;
}
