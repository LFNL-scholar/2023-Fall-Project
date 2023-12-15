#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<Windows.h>
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

    // bool compareByNumber(const Flight& other) const{
    //     return flightNumber<other.flightNumber;
    // }

    void swap(Flight& a, Flight& b) {
        Flight temp = a;
        a = b;
        b = temp;
    }

    bool compareByDeparture(const string& otherDeparture) const{
        return departure==otherDeparture;
    }

    bool compareByDestination(const string& otherDestination) const{
        return destination==otherDestination;
    }

    bool compareByDepartureTime(const string& otherDepartureTime) const{
        return departureTime==otherDepartureTime;
    }

    bool compareByArrivalTime(const string& otherArrivalTime) const{
        return arrivalTime==otherArrivalTime;
    }

    bool compareByAircraftType(const string& otherAircraftType) const{
        return aircraftType==otherAircraftType;
    }

    bool compareByTicketPrice(double otherTicketPrice) const{
        return ticketPrice==otherTicketPrice;
    }

};

void readFlightsFromFile(vector<Flight>& flights, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()){
        cerr<<"Error opening file for reading."<<endl;
        return;
    }

    string line;
    int lineNumber = 0; 
    while(getline(inputFile, line)){
        lineNumber++;
        istringstream iss(line);
        string number,depart,dest,departTime,arriveTime,aircraft;
        double price;

        if(!(iss>>number>>depart>>dest>>departTime>>arriveTime>>aircraft>>price)){
            cerr<<"Error parsing line in file."<< lineNumber << "." << endl;
            continue;
        }

        flights.emplace_back(number, depart, dest, departTime, arriveTime, aircraft, price);
    }

    inputFile.close();
}

//输出区块
enum ConsoleColor {
    DEFAULT = 7,
    RED = 12,
    GREEN = 10,
    YELLOW = 14,
    BLUE = 9,
    MAGENTA = 13,
    CYAN = 11,
    WHITE = 15
};

void setConsoleColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void resetConsoleColor() {
    setConsoleColor(DEFAULT);
}

void displayAllFlights(const vector<Flight>& flights){
    setConsoleColor(GREEN);
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    resetConsoleColor();
    for(const auto& flight : flights){
        cout<<flight.flightNumber<<" "<<flight.departure<<" to "<<flight.destination
            <<" Departure: "<<flight.departureTime<<" Arrival: "<<flight.arrivalTime
            <<" Aircraft: "<<flight.aircraftType<<" Price: "<<flight.ticketPrice<<"¥"<<endl;
    }
    setConsoleColor(GREEN);
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    resetConsoleColor();
}

void displayFlight(const Flight& flight) {
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    setConsoleColor(GREEN);
    cout << flight.flightNumber << " " << flight.departure << " to " << flight.destination
         << " Departure: " << flight.departureTime << " Arrival: " << flight.arrivalTime
         << " Aircraft: " << flight.aircraftType << " Price: " << flight.ticketPrice << "¥" << endl;
    resetConsoleColor();
    cout << "--------------------------------------------------------------------------------------------------" << endl;

}
//-----

class FlightManager {
private:
    vector<Flight> flights;

    void quicksort(vector<Flight>& flights, int low, int high) {
        // 如果待排序的范围有效（至少包含两个元素）
        if (low < high) {
            // 找到分区点（pivot）的索引
            int pivotIndex = partition(flights, low, high);

            // 对分区点左右两侧的子数组进行递归排序
            quicksort(flights, low, pivotIndex - 1);
            quicksort(flights, pivotIndex + 1, high);
        }
    }

    // 分区函数，用于确定分区点的位置
    int partition(vector<Flight>& flights, int low, int high) {
        Flight pivot = flights[high];
        int i = low - 1;

        // 遍历当前范围内的元素
        for (int j = low; j < high; j++) {
            if (flights[j].flightNumber <= pivot.flightNumber) {
                i++;
                swap(flights[i], flights[j]);
            }
        }

        // 将分区点元素放置到正确的位置上
        swap(flights[i + 1], flights[high]);

        return i + 1;
    }

public:
    // 调用全局函数读取航班信息
    void readFlightsFromFile(const string& filename){
        ::readFlightsFromFile(flights, filename);
    }

    void sortFlightsByNumber() {
        int n = flights.size();
        quicksort(flights, 0, n - 1);
    }

    // 显示全部航班信息
    void displayAllFlights(){
        ::displayAllFlights(flights);
    }
    
    void searchFlightByNumber(const string& flightNumber){

        int low=0;
        int high=flights.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(flights[mid].flightNumber==flightNumber){
                cout<<"Flight found:"<<endl;
                displayFlight(flights[mid]);
                return;
            }else if(flights[mid].flightNumber<flightNumber){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        cout << "Flight not found."<<endl;
    }

    void searchFlightsByDeparture(const string& departureCity) {
        cout <<"Flights departing from "<<departureCity<<":"<<endl;
        bool found=false;
        for(const auto& flight : flights){
            if(flight.compareByDeparture(departureCity)) {
                displayFlight(flight);
                found=true;
            }
        }

        if(!found){
            cout<<"No flights found."<<endl;
        }
    }

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

    // 组合查找
    void searchFlightsCombined(const string& departureCity, const string& destination,const string& departureTime, const string& arrivalTime,
                                const string& aircraftType, double minPrice, double maxPrice) {

        setConsoleColor(GREEN);
        cout << "Flights matching the criteria:" << endl;
        resetConsoleColor(); 

        bool found = false;

        for (const auto& flight : flights) {
            if ((departureCity.empty() || flight.compareByDeparture(departureCity)) &&
                (destination.empty() || flight.compareByDestination(destination)) &&
                (departureTime.empty() || flight.compareByDepartureTime(departureTime)) &&
                (arrivalTime.empty() || flight.compareByArrivalTime(arrivalTime)) &&
                (aircraftType.empty() || flight.compareByAircraftType(aircraftType)) &&
                (minPrice == 0 || (flight.ticketPrice >= minPrice && flight.ticketPrice <= maxPrice))) {
                displayFlight(flight);
                found = true;
            }
        }

        if (!found) {
            setConsoleColor(GREEN);
            cout << "No flights found matching the criteria.\n";
            resetConsoleColor();
        }
    }


    void searchFlightsByPriceRange(double minPrice, double maxPrice) {
        cout << "Flights within price range " << minPrice << " - " << maxPrice << ":\n";
        bool found = false;

        for (const auto& flight : flights) {
            if (flight.ticketPrice >= minPrice && flight.ticketPrice <= maxPrice) {
                displayFlight(flight);
                found = true;
            }
        }

        if (!found) {
            cout << "No flights found within the specified price range.\n";
        }
    }

};

int main() {
    SetConsoleOutputCP(65001);
    FlightManager flightManager;
    flightManager.readFlightsFromFile("FIS_Info.txt");
    flightManager.sortFlightsByNumber();

    setConsoleColor(GREEN);
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"-  Welcome to the LFNL TECH Flight Searching System!  -"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    resetConsoleColor();


    while (true) {
        cout << "Choose search type:\n";
        cout << "1. Search by flight number\n";
        cout << "2. Search by departure city\n";
        cout << "3. Search by destination\n";
        cout << "4. Search by departure time\n";
        cout << "5. Search by arrival time\n";
        cout << "6. Search by aircraft type\n";
        cout << "7. Search by price range\n";
        cout << "8. Combined Search\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";

        string userChoice;
        cin >> userChoice;

        if (userChoice == "display") {
            flightManager.displayAllFlights();
        } else if(userChoice=="cls"){
            system("cls");
        }else {
            int choice = stoi(userChoice);
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
                double minPrice, maxPrice;
                cout << "Enter minimum ticket price: ";
                cin >> minPrice;

                cout << "Enter maximum ticket price: ";
                cin >> maxPrice;

                if (minPrice > maxPrice) {
                    cout << "Invalid price range. Minimum price should be less than or equal to maximum price.\n";
                } else {
                    flightManager.searchFlightsByPriceRange(minPrice, maxPrice);
                }
                break;
            }
            case 8: {
                string departureCity, destination, departureTime, arrivalTime, aircraftType;
                double minPrice, maxPrice;

                cout << "Enter departure city (or leave empty): ";
                cin.ignore(); // Ignore any newline characters in the input buffer
                getline(cin, departureCity);

                cout << "Enter destination (or leave empty): ";
                getline(cin, destination);

                cout << "Enter departure time (or leave empty): ";
                getline(cin, departureTime);

                cout << "Enter arrival time (or leave empty): ";
                getline(cin, arrivalTime);

                cout << "Enter aircraft type (or leave empty): ";
                getline(cin, aircraftType);

                cout << "Enter minimum ticket price (or enter 0 for any price): ";
                cin >> minPrice;

                cout << "Enter maximum ticket price (or enter 0 for any price): ";
                cin >> maxPrice;

                flightManager.searchFlightsCombined(departureCity, destination, departureTime, arrivalTime, aircraftType, minPrice, maxPrice);
                break;
            }
            case 9:{
                setConsoleColor(GREEN);
                cout << "Exiting program.\n";
                cout << "Thank you for using LFNL TECH Flight Searching System. Have a great day!\n";
                resetConsoleColor();
                system("pause");
                return 0;
            }
            default:
                cout << "Invalid choice. Try again.\n";
            
            }
        
        }
    
    }
    system("pause");
    return 0;
}