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

    bool compareByDeparture(const string& otherDeparture) const {
        return departure == otherDeparture;
    }

    bool compareByDestination(const string& otherDestination) const {
        return destination == otherDestination;
    }

    bool compareByDepartureTime(const string& otherDepartureTime) const {
        return departureTime == otherDepartureTime;
    }

    bool compareByArrivalTime(const string& otherArrivalTime) const {
        return arrivalTime == otherArrivalTime;
    }

    bool compareByAircraftType(const string& otherAircraftType) const {
        return aircraftType == otherAircraftType;
    }

    bool compareByTicketPrice(double otherTicketPrice) const {
        return ticketPrice == otherTicketPrice;
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

    // Simple binary search for a flight by its number
    void searchFlightByNumber(const string& flightNumber) {
        // Sort flights by number (required for binary search)
        sortFlightsByNumber();

        int low = 0;
        int high = flights.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (flights[mid].flightNumber == flightNumber) {
                cout << "Flight found:\n";
                displayFlight(flights[mid]);
                return;
            } else if (flights[mid].flightNumber < flightNumber) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << "Flight not found.\n";
    }

    // Simple linear search for flights by other data elements
    void searchFlightsByDeparture(const string& departureCity) {
        cout << "Flights departing from " << departureCity << ":\n";
        bool found = false;
        for (const auto& flight : flights) {
            if (flight.departure == departureCity) {
                displayFlight(flight);
                found = true;
            }
        }

        if (!found) {
            cout << "No flights found.\n";
        }
    }

    // Linear search for flights by destination
    void searchFlightsByDestination(const string& destination) {
        cout << "Flights going to " << destination << ":\n";
        bool found = false;
        for (const auto& flight : flights) {
            if (flight.compareByDestination(destination)) {
                displayFlight(flight);
                found = true;
            }
        }

        if (!found) {
            cout << "No flights found.\n";
        }
    }

    // Linear search for flights by departure time
    void searchFlightsByDepartureTime(const string& departureTime) {
        cout << "Flights departing at " << departureTime << ":\n";
        bool found = false;
        for (const auto& flight : flights) {
            if (flight.compareByDepartureTime(departureTime)) {
                displayFlight(flight);
                found = true;
            }
        }

        if (!found) {
            cout << "No flights found.\n";
        }
    }

    // Linear search for flights by arrival time
    void searchFlightsByArrivalTime(const string& arrivalTime) {
        cout << "Flights arriving at " << arrivalTime << ":\n";
        bool found = false;
        for (const auto& flight : flights) {
            if (flight.compareByArrivalTime(arrivalTime)) {
                displayFlight(flight);
                found = true;
            }
        }

        if (!found) {
            cout << "No flights found.\n";
        }
    }

    // Linear search for flights by aircraft type
    void searchFlightsByAircraftType(const string& aircraftType) {
        cout << "Flights with aircraft type " << aircraftType << ":\n";
        bool found = false;
        for (const auto& flight : flights) {
            if (flight.compareByAircraftType(aircraftType)) {
                displayFlight(flight);
                found = true;
            }
        }

        if (!found) {
            cout << "No flights found.\n";
        }
    }

    // Linear search for flights by ticket price
    void searchFlightsByTicketPrice(double ticketPrice) {
        cout << "Flights with ticket price " << ticketPrice << ":\n";
        bool found = false;
        for (const auto& flight : flights) {
            if (flight.compareByTicketPrice(ticketPrice)) {
                displayFlight(flight);
                found = true;
            }
        }

        if (!found) {
            cout << "No flights found.\n";
        }
    }




};


int main() {
    FlightManager flightManager;
    flightManager.readFlightsFromFile("FIS_Info.txt");
    flightManager.sortFlightsByNumber();

    cout << "All Flights:"<<endl;
    flightManager.displayAllFlights();

    while (true) {
        cout << "Choose search type:\n";
        cout << "1. Search by flight number\n";
        cout << "2. Search by departure city\n";
        cout << "3. Search by destination\n";
        cout << "4. Search by departure time\n";
        cout << "5. Search by arrival time\n";
        cout << "6. Search by aircraft type\n";
        cout << "7. Search by ticket price\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string flightNumber;
                cout << "Enter flight number to search: ";
                cin >> flightNumber;
                flightManager.searchFlightByNumber(flightNumber);
                break;
            }
            case 2: {
                string departureCity;
                cout << "Enter departure city to search: ";
                cin >> departureCity;
                flightManager.searchFlightsByDeparture(departureCity);
                break;
            }
            case 3: {
                string destination;
                cout << "Enter destination to search: ";
                cin >> destination;
                flightManager.searchFlightsByDestination(destination);
                break;
            }
            case 4: {
                string departureTime;
                cout << "Enter departure time to search: ";
                cin >> departureTime;
                flightManager.searchFlightsByDepartureTime(departureTime);
                break;
            }
            case 5: {
                string arrivalTime;
                cout << "Enter arrival time to search: ";
                cin >> arrivalTime;
                flightManager.searchFlightsByArrivalTime(arrivalTime);
                break;
            }
            case 6: {
                string aircraftType;
                cout << "Enter aircraft type to search: ";
                cin >> aircraftType;
                flightManager.searchFlightsByAircraftType(aircraftType);
                break;
            }
            case 7: {
                double ticketPrice;
                cout << "Enter ticket price to search: ";
                cin >> ticketPrice;
                flightManager.searchFlightsByTicketPrice(ticketPrice);
                break;
            }
            case 8:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    system("pause");
    return 0;
}
