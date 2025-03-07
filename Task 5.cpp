#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int dID, bool dStatus) {
        deviceID = dID;
        status = dStatus;
    }

    virtual void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : virtual public Device {
protected:
    float screenSize;

public:
    SmartPhone(int dID, bool dStatus, float dScreenSize) : Device(dID, dStatus) {
        screenSize = dScreenSize;
    }

    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int dID, bool dStatus, bool dHeartRateMonitor) : Device(dID, dStatus) {
        heartRateMonitor = dHeartRateMonitor;
    }

    void displayDetails() override {
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:
    SmartWearable(int dID, bool dStatus, float dScreenSize, bool dHeartRateMonitor, int dStepCounter)
        : Device(dID, dStatus), SmartPhone(dID, dStatus, dScreenSize), SmartWatch(dID, dStatus, dHeartRateMonitor) {
        stepCounter = dStepCounter;
    }

    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    int deviceID, stepCounter;
    bool status, heartRateMonitor;
    float screenSize;

    cout << "Enter Device ID: ";
    cin >> deviceID;

    cout << "Enter status (1 for On, 0 for Off): ";
    cin >> status;

    cout << "Enter screen size (in inches): ";
    cin >> screenSize;

    cout << "Does it have a heart rate monitor? (1 for Yes, 0 for No): ";
    cin >> heartRateMonitor;

    cout << "Enter step counter value: ";
    cin >> stepCounter;

    SmartWearable wearable(deviceID, status, screenSize, heartRateMonitor, stepCounter);
    cout << "\nSmart Wearable Details:\n";
    wearable.displayDetails();

    return 0;
}
