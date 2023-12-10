#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class Flight {
public:
    std::string flightNumber;
    std::string departure;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    std::string aircraftType;
    double ticketPrice;

    // 构造函数
    Flight(std::string number, std::string depart, std::string dest, std::string departTime, std::string arriveTime, std::string aircraft, double price)
        : flightNumber(number), departure(depart), destination(dest), departureTime(departTime), arrivalTime(arriveTime), aircraftType(aircraft), ticketPrice(price) {}
};

// 函数声明
void sortFlights(std::vector<Flight>& flights);
int binarySearch(const std::vector<Flight>& flights, const std::string& key);

int main() {
    // 示例数据
    std::vector<Flight> flights = {
        {"AB123", "CityA", "CityB", "08:00", "10:00", "Boeing 737", 300.0},
        {"CD456", "CityB", "CityC", "12:00", "14:00", "Airbus A320", 250.0},
        {"EF789", "CityC", "CityD", "16:00", "18:00", "Boeing 747", 400.0},
        // 添加更多航班信息...
    };

    // 排序航班信息
    sortFlights(flights);

    // 显示排序后的航班信息
    std::cout << "Sorted Flights:\n";
    for (const auto& flight : flights) {
        std::cout << flight.flightNumber << " " << flight.departure << " to " << flight.destination << " Departure: " << flight.departureTime << " Arrival: " << flight.arrivalTime << " Price: $" << flight.ticketPrice << "\n";
    }

    // 查询航班信息
    std::string searchKey = "CD456";  // 要查询的航班号
    int index = binarySearch(flights, searchKey);

    // 显示查询结果
    if (index != -1) {
        std::cout << "Flight found:\n";
        std::cout << flights[index].flightNumber << " " << flights[index].departure << " to " << flights[index].destination << " Departure: " << flights[index].departureTime << " Arrival: " << flights[index].arrivalTime << " Price: $" << flights[index].ticketPrice << "\n";
    } else {
        std::cout << "Flight not found.\n";
    }

    return 0;
}

// 排序航班信息
void sortFlights(std::vector<Flight>& flights) {
    std::sort(flights.begin(), flights.end(), [](const Flight& a, const Flight& b) {
        return a.flightNumber < b.flightNumber;
    });
}

// 二分查找航班信息
int binarySearch(const std::vector<Flight>& flights, const std::string& key) {
    int left = 0;
    int right = flights.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (flights[mid].flightNumber == key) {
            return mid;  // 找到航班，返回索引
        } else if (flights[mid].flightNumber < key) {
            left = mid + 1;  // 在右半边继续查找
        } else {
            right = mid - 1;  // 在左半边继续查找
        }
    }

    return -1;  // 未找到航班
}
