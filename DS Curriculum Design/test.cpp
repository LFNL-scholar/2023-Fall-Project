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

    // 比较函数，用于二分查找
    bool compareByNumber(const Flight& other)const{
        return flightNumber < other.flightNumber;
    }
};

class FlightManager{
private:
    vector<Flight> flights;

public:
    void readFlightsFromFile(const string& filename){
        
        // 打开指定文件以进行读取操作
        ifstream inputFile(filename);
        if(!inputFile.is_open()){
            cerr<<"Error opening file for reading."<<endl;
        }
        string line;
        
        // 逐行读取文件
        while(getline(inputFile,line)){
            istringstream iss(line); // 创建一个字符串流，以便按空格分隔并解析当前行的数据

            // 定义变量以存储从文件中读取的各个字段
            string number,depart,dest,departTime,arriveTime,aircraft;
            double price;

            // 尝试从字符串流中解析每个字段
            if (!(iss>>number>>depart>>dest>>departTime>>arriveTime>>aircraft>>price)){
                cerr<<"Error parsing line in file."<<endl;
                continue; // 跳过解析错误的行，继续处理下一行
            }

            // 创建一个 Flight 对象并将其添加到 flights 向量中
            flights.emplace_back(number, depart, dest, departTime, arriveTime, aircraft, price);
        }

        inputFile.close();
    }

    void swap(Flight& a, Flight& b) {
        Flight temp = a;
        a = b;
        b = temp;
    }

    // 快速排序的辅助函数
    int partition(vector<Flight>& flights,int low,int high){
        // 选择枢纽元
        Flight pivot=flights[high];
        int i=low-1;

        for(int j=low;j<high;j++){
            // 如果当前元素小于枢纽元，则交换它和分区索引后移一位的元素
            if(flights[j].flightNumber<pivot.flightNumber){
                i++;
                swap(flights[i],flights[j]);
            }
        }
        // 将枢纽元放置到正确的位置，即分区索引后移一位的位置
        swap(flights[i+1],flights[high]);
        // 返回枢纽元最终的位置
        return i+1;
    }

    // 快速排序算法
    void quickSort(vector<Flight>& flights,int low,int high){
        if(low<high){
            int partitionIndex=partition(flights,low,high);
            // 递归对分区索引的子数组进行排序
            quickSort(flights,low,partitionIndex-1);
            quickSort(flights,partitionIndex+1,high);
        }
    }

    // 按航班号排序
    void sortFlightsByNumber() {
        int size=flights.size();
        quickSort(flights,0,size-1);
    }

    bool binarySearch(const vector<Flight>& flights, const Flight& target) {
        int low = 0;
        int high = flights.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (flights[mid].compareByNumber(target)) {
                low = mid + 1;
            } else if (target.compareByNumber(flights[mid])) {
                high = mid - 1;
            } else {
                return true;  // 找到了目标
            }
        }

        return false;  // 没有找到目标
    }

    // 通过二分查找快速查询航班信息
    bool searchFlightByNumber(const std::string& number) {
        Flight targetFlight{number, "", "", "", "", "", 0};
        return binarySearch(flights, targetFlight);
    }

    // 根据起飞地点查找
    bool searchFlightByDeparture(const std::string& departure) {
        for (const auto& flight : flights) {
            if (flight.departure == departure) {
                return true;  // 找到了目标
            }
        }
        return false;  // 没有找到目标
    }

    // 根据目的地查找
    bool searchFlightByDestination(const std::string& destination) {
        for (const auto& flight : flights) {
            if (flight.destination == destination) {
                return true;  // 找到了目标
            }
        }
        return false;  // 没有找到目标
    }

    // 根据起飞时间查找
    bool searchFlightByDepartureTime(const std::string& departureTime) {
        for (const auto& flight : flights) {
            if (flight.departureTime == departureTime) {
                return true;  // 找到了目标
            }
        }
        return false;  // 没有找到目标
    }

    // 根据到达时间查找
    bool searchFlightByArrivalTime(const std::string& arrivalTime) {
        for (const auto& flight : flights) {
            if (flight.arrivalTime == arrivalTime) {
                return true;  // 找到了目标
            }
        }
        return false;  // 没有找到目标
    }

    // 根据飞机类型查找
    bool searchFlightByAircraftType(const std::string& aircraftType) {
        for (const auto& flight : flights) {
            if (flight.aircraftType == aircraftType) {
                return true;  // 找到了目标
            }
        }
        return false;  // 没有找到目标
    }

    // 根据票价查找
    bool searchFlightByTicketPrice(double ticketPrice) {
        for (const auto& flight : flights) {
            if (flight.ticketPrice == ticketPrice) {
                return true;  // 找到了目标
            }
        }
        return false;  // 没有找到目标
    }

    // // 在 FlightManager 类中添加以下函数
    // void displayFlightDetails(const std::string& flightNumber) const {
    // // 在 flights 向量中查找航班号为 flightNumber 的航班
    //     auto it = std::find_if(flights.begin(), flights.end(), [&flightNumber](const Flight& flight) {
    //         return flight.flightNumber == flightNumber;
    //     });

    //     if (it != flights.end()) {
    //         // 找到了航班，显示详细信息
    //         cout << "Flight Details:\n";
    //         cout << "Flight Number: " << it->flightNumber << "\n";
    //         cout << "Departure: " << it->departure << "\n";
    //         cout << "Destination: " << it->destination << "\n";
    //         cout << "Departure Time: " << it->departureTime << "\n";
    //         cout << "Arrival Time: " << it->arrivalTime << "\n";
    //         cout << "Aircraft Type: " << it->aircraftType << "\n";
    //         cout << "Ticket Price: " << it->ticketPrice << "¥\n";
    //     } else {
    //         // 没有找到航班
    //         cout << "Flight not found.\n";
    //     }
    // }

    // 在 FlightManager 类中添加以下函数
    void displayFlightDetailsByDeparture(const std::string& departure) const {
        // 在 flights 向量中查找起飞地点为 departure 的航班
        auto matchingFlights = findFlightsByDeparture(departure);

        if (!matchingFlights.empty()) {
            // 找到了航班，显示详细信息
            cout << "Flight Details (Departure: " << departure << "):\n";
            for (const auto& flight : matchingFlights) {
                displaySingleFlightDetails(flight);
            }
        } else {
            // 没有找到航班
            cout << "No flights found for departure: " << departure << "\n";
        }
    }

    void displayFlightDetailsByDestination(const std::string& destination) const {
        // 在 flights 向量中查找目的地为 destination 的航班
        auto matchingFlights = findFlightsByDestination(destination);

        if (!matchingFlights.empty()) {
            // 找到了航班，显示详细信息
            cout << "Flight Details (Destination: " << destination << "):\n";
            for (const auto& flight : matchingFlights) {
                displaySingleFlightDetails(flight);
            }
        } else {
            // 没有找到航班
            cout << "No flights found for destination: " << destination << "\n";
        }
    }

    // 在 FlightManager 类中添加其他按属性查找的函数，类似上述函数的实现

    // 辅助函数：在 flights 中查找起飞地点为 departure 的航班
    std::vector<Flight> findFlightsByDeparture(const std::string& departure) const {
        std::vector<Flight> matchingFlights;
        for (const auto& flight : flights) {
            if (flight.departure == departure) {
                matchingFlights.push_back(flight);
            }
        }
        return matchingFlights;
    }

    // 辅助函数：在 flights 中查找目的地为 destination 的航班
    std::vector<Flight> findFlightsByDestination(const std::string& destination) const {
        std::vector<Flight> matchingFlights;
        for (const auto& flight : flights) {
            if (flight.destination == destination) {
                matchingFlights.push_back(flight);
            }
        }
        return matchingFlights;
    }

    // 辅助函数：显示单个航班的详细信息
    void displaySingleFlightDetails(const Flight& flight) const {
        cout << "Flight Number: " << flight.flightNumber << "\n";
        cout << "Departure: " << flight.departure << "\n";
        cout << "Destination: " << flight.destination << "\n";
        cout << "Departure Time: " << flight.departureTime << "\n";
        cout << "Arrival Time: " << flight.arrivalTime << "\n";
        cout << "Aircraft Type: " << flight.aircraftType << "\n";
        cout << "Ticket Price: " << flight.ticketPrice << "¥\n";
        cout << "--------------------------\n";
    }

    


    // 显示航班信息
    void displayFlights(){
        for(const auto& flight : flights){
            cout<<flight.flightNumber<<" "<<flight.departure<<" to "<<flight.destination
                <<" Departure: "<<flight.departureTime<<" Arrival: "<< flight.arrivalTime
                <<" Aircraft: "<<flight.aircraftType<<" Price: "<< flight.ticketPrice<<"¥"<< "\n";
        }
    }
};


int main() {
    FlightManager flightManager;

    // 读取航班信息从文件flights.txt
    flightManager.readFlightsFromFile("FIS_Info.txt");

    flightManager.sortFlightsByNumber();

    cout << "All Flights:\n";
    flightManager.displayFlights();

    // 用户手动输入航班号进行搜索
    cout << "Enter the flight number to search: ";
    string searchFlightNumber;
    cin >> searchFlightNumber;

    // 快速查询航班信息11
    if(flightManager.searchFlightByNumber(searchFlightNumber)){
        cout<<"Flight "<<searchFlightNumber<<" found."<<endl;
    }else{
        cout<<"Flight "<<searchFlightNumber<<" not found."<<endl;
    }

    // 用户手动选择要搜索的属性
    cout << "Choose search criteria:\n"
         << "1. Departure\n"
         << "2. Destination\n"
         << "3. Departure Time\n"
         << "4. Arrival Time\n"
         << "5. Aircraft Type\n"
         << "6. Ticket Price\n";

    int choice;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    // 根据用户的选择进行搜索
    switch (choice) {
        case 1: {
            // 根据起飞地点查找
            string departure;
            cout << "Enter Departure: ";
            cin >> departure;
            if (flightManager.searchFlightByDeparture(departure)) {
                cout << "Flight found!\n";
            } else {
                cout << "Flight not found.\n";
            }
            break;
        }
        case 2: {
            // 根据目的地查找
            string destination;
            cout << "Enter Destination: ";
            cin >> destination;
            if (flightManager.searchFlightByDestination(destination)) {
                cout << "Flight found!\n";
            } else {
                cout << "Flight not found.\n";
            }
            break;
        }
        case 3: {
            // 根据起飞时间查找
            string departureTime;
            cout << "Enter Departure Time: ";
            cin >> departureTime;
            if (flightManager.searchFlightByDepartureTime(departureTime)) {
                cout << "Flight found!\n";
            } else {
                cout << "Flight not found.\n";
            }
            break;
        }
        case 4: {
            // 根据到达时间查找
            string arrivalTime;
            cout << "Enter Arrival Time: ";
            cin >> arrivalTime;
            if (flightManager.searchFlightByArrivalTime(arrivalTime)) {
                cout << "Flight found!\n";
            } else {
                cout << "Flight not found.\n";
            }
            break;
        }
        case 5: {
            // 根据飞机类型查找
            string aircraftType;
            cout << "Enter Aircraft Type: ";
            cin >> aircraftType;
            if (flightManager.searchFlightByAircraftType(aircraftType)) {
                cout << "Flight found!\n";
            } else {
                cout << "Flight not found.\n";
            }
            break;
        }
        case 6: {
            // 根据票价查找
            double ticketPrice;
            cout << "Enter Ticket Price: ";
            cin >> ticketPrice;
            if (flightManager.searchFlightByTicketPrice(ticketPrice)) {
                cout << "Flight found!\n";
            } else {
                cout << "Flight not found.\n";
            }
            break;
        }
        default:
            cout << "Invalid choice.\n";
            break;
    }

    system("pause");
    return 0;
}
