#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <exception>
using namespace std;

class Vehicle {
protected:
    string licensePlate;
    time_t entryTime;
public:
    Vehicle(string licensePlate, time_t entryTime) : licensePlate(licensePlate), entryTime(entryTime) {}
    virtual ~Vehicle() {}
    virtual double calculateFee(time_t exitTime) const = 0;
    string getLicensePlate() const { return licensePlate; }
    time_t getEntryTime() const { return entryTime; }
};

class Car : public Vehicle {
public:
    Car(string licensePlate, time_t entryTime) : Vehicle(licensePlate, entryTime) {}
    double calculateFee(time_t exitTime) const override {
        double hours = difftime(exitTime, entryTime) / 3600;
        return hours * 2.0; 
    }
};

class Bike : public Vehicle {
public:
    Bike(string licensePlate, time_t entryTime) : Vehicle(licensePlate, entryTime) {}
    double calculateFee(time_t exitTime) const override {
        double hours = difftime(exitTime, entryTime) / 3600;
        return hours * 1.0;
    }
};

class Truck : public Vehicle {
public:
    Truck(string licensePlate, time_t entryTime) : Vehicle(licensePlate, entryTime) {}
    double calculateFee(time_t exitTime) const override {
        double hours = difftime(exitTime, entryTime) / 3600;
        return hours * 3.0; 
    }
};

template <typename T>
class ParkingLot {
private:
    vector<T*> vehicles;
    static int totalVehiclesParked;
public:
    void parkVehicle(T* vehicle) {
        vehicles.push_back(vehicle);
        totalVehiclesParked++;
    }

    void saveRecords(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        for (const auto& vehicle : vehicles) {
            file << vehicle->getLicensePlate() << "," << vehicle->getEntryTime() << endl;
        }
        file.close();
    }

    static int getTotalVehiclesParked() {
        return totalVehiclesParked;
    }
};

template <typename T>
int ParkingLot<T>::totalVehiclesParked = 0;

int main() {
    ParkingLot<Vehicle> parkingLot;
    time_t now = time(0); // Current time

    int vehicleType;
    cout << "Enter vehicle type (1=Car, 2=Bike, 3=Truck): ";
    cin >> vehicleType;

    Vehicle* vehicle = nullptr;

    switch (vehicleType) {
        case 1:
            vehicle = new Car("CAR123", now);
            break;
        case 2:
            vehicle = new Bike("BIKE456", now);
            break;
        case 3:
            vehicle = new Truck("TRUCK789", now);
            break;
        default:
            cout << "Invalid vehicle type selected." << endl;
            return 1;
    }

    if (vehicle != nullptr) {
        parkingLot.parkVehicle(vehicle);
        cout << "Vehicle parked successfully." << endl;

        time_t exitTime = now + (2 * 3600); 
        double fee = vehicle->calculateFee(exitTime);
        cout << "Parking fee for this vehicle: $" << fee << endl;

        parkingLot.saveRecords("parking_records.txt");

        delete vehicle;
    }

    cout << "Total vehicles parked: " << ParkingLot<Vehicle>::getTotalVehiclesParked() << endl;

    return 0;
}
