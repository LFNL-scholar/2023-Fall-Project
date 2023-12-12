#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

class Flight{
public:
    string flightNumber;
    string departure;
    string destination;
    string departureTime;
    string arrivalTime;
    string aircraftType;
    double ticketPrice;

    Flight(string number,string depart,string dest,string departTime,string arriveTime,string aircraft,double price)
        : flightNumber(number),departure(depart),destination(dest),departureTime(departTime),arrivalTime(arriveTime),aircraftType(aircraft),ticketPrice(price) {}

    bool compareByNumber(const Flight& other)const{
        return flightNumber < other.flightNumber;
    }
};

// 全局函数，负责读取航班信息并填充 flights 向量
void readFlightsFromFile(vector<Flight>& flights, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string number, depart, dest, departTime, arriveTime, aircraft;
        double price;

        if (!(iss >> number >> depart >> dest >> departTime >> arriveTime >> aircraft >> price)) {
            cerr << "Error parsing line in file." << endl;
            continue;
        }

        flights.emplace_back(number, depart, dest, departTime, arriveTime, aircraft, price);
    }

    inputFile.close();
}

class FlightManager {
private:
    vector<Flight> flights;

public:
    // 调用全局函数读取航班信息
    void readFlightsFromFile(const string& filename) {
        ::readFlightsFromFile(flights, filename);
    }
};


int main() {
    FlightManager flightManager;
    flightManager.readFlightsFromFile("flights.txt");

    // 其他逻辑...

    return 0;
}