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

// 全局函数，用于显示全部航班信息
void displayAllFlights(const vector<Flight>& flights) {
    for (const auto& flight : flights) {
        cout << flight.flightNumber << " " << flight.departure << " to " << flight.destination
             << " Departure: " << flight.departureTime << " Arrival: " << flight.arrivalTime
             << " Aircraft: " << flight.aircraftType << " Price: " << flight.ticketPrice << "¥" << "\n";
    }
}

// 显示航班信息
void displayFlight(const Flight& flight) {
    cout << flight.flightNumber << " " << flight.departure << " to " << flight.destination
         << " Departure: " << flight.departureTime << " Arrival: " << flight.arrivalTime
         << " Aircraft: " << flight.aircraftType << " Price: " << flight.ticketPrice << "¥" << "\n";
}



class FlightManager {
private:
    vector<Flight> flights;

public:
    // 调用全局函数读取航班信息
    void readFlightsFromFile(const string& filename) {
        ::readFlightsFromFile(flights, filename);
    }

    // 冒泡排序算法
    void sortFlightsByNumber() {
        int n = flights.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (flights[j].flightNumber > flights[j + 1].flightNumber) {
                    // 交换 flights[j] 和 flights[j + 1]
                    Flight temp = flights[j];
                    flights[j] = flights[j + 1];
                    flights[j + 1] = temp;
                }
            }
        }
    }

    // 显示全部航班信息
    void displayAllFlights() {
        ::displayAllFlights(flights);
    }


};


int main() {
    FlightManager flightManager;
    flightManager.readFlightsFromFile("FIS_Info.txt");
    flightManager.sortFlightsByNumber();

    cout << "All Flights:"<<endl;
    flightManager.displayAllFlights();


    system("pause");
    return 0;
}