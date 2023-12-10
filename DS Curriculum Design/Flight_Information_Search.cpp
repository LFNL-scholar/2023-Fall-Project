#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
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
};

class FlightManager{
private:
    vector<Flight> flights;

public:
    // 从文件中读取航班信息
    void readFlightsFromFile(const string& filename){
        // 打开指定文件以进行读取操作
        ifstream inputFile(filename);
        if(!inputFile.is_open()){
            cerr<<"Error opening file for reading."<<endl;
        }
        string line;
        // 逐行读取文件
        while(getline(inputFile,line)){
            // 创建一个字符串流，以便按空格分隔并解析当前行的数据
            istringstream iss(line);

            // 定义变量以存储从文件中读取的各个字段
            string number,depart,dest,departTime,arriveTime,aircraft;
            double price;

            // 尝试从字符串流中解析每个字段
            if (!(iss >> number >> depart >> dest >> departTime >> arriveTime >> aircraft >> price)) {
                cerr << "Error parsing line in file.\n";
                continue; // 跳过解析错误的行，继续处理下一行
            }

            // 创建一个 Flight 对象并将其添加到 flights 向量中
            flights.emplace_back(number, depart, dest, departTime, arriveTime, aircraft, price);
        }

        // 关闭文件
        inputFile.close();
    }

    // 按航班号排序
    void sortFlightsByNumber() {
        sort(flights.begin(), flights.end(), [](const Flight& a, const Flight& b) {
            return a.flightNumber < b.flightNumber;
        });
    }

    // 通过二分查找快速查询航班信息
    bool searchFlightByNumber(const std::string& number) {
        return std::binary_search(flights.begin(), flights.end(), Flight(number, "", "", "", "", "", 0),
                                   [](const Flight& a, const Flight& b) {
                                       return a.flightNumber < b.flightNumber;
                                   });
    }

    // 显示航班信息
    void displayFlights() {
        for (const auto& flight : flights) {
            std::cout << flight.flightNumber << " " << flight.departure << " to " << flight.destination
                      << " Departure: " << flight.departureTime << " Arrival: " << flight.arrivalTime
                      << " Aircraft: " << flight.aircraftType << " Price: $" << flight.ticketPrice << "\n";
        }
    }
};


int main() {
    FlightManager flightManager;

    // 读取航班信息从文件flights.txt
    flightManager.readFlightsFromFile("FIS_Info.txt");

    // 按航班号排序
    flightManager.sortFlightsByNumber();

    // 显示排序后的航班信息
    cout << "Sorted Flights:\n";
    flightManager.displayFlights();

    // 快速查询航班信息
    string searchFlightNumber = "TK777";
    if (flightManager.searchFlightByNumber(searchFlightNumber)) {
        cout << "Flight " << searchFlightNumber << " found.\n";
    } else {
        cout << "Flight " << searchFlightNumber << " not found.\n";
    }

    system("pause");
    return 0;
}