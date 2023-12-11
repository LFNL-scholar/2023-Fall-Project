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

    // 自定义二分查找函数
    bool binarySearch(const vector<Flight>& flights,const Flight& target,bool(*compareFunction)(const Flight&, const Flight&)) {
        int low = 0;
        int high = flights.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (compareFunction(flights[mid], target)) {
                low = mid + 1;
            } else if (compareFunction(target, flights[mid])) {
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
        return binarySearch(flights, targetFlight, &Flight::compareByNumber);
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

    // 按航班号排序
    flightManager.sortFlightsByNumber();

    // 显示排序后的航班信息
    cout<<"Sorted Flights: "<<endl;
    flightManager.displayFlights();

    // 快速查询航班信息
    string searchFlightNumber="TK777";
    if(flightManager.searchFlightByNumber(searchFlightNumber)){
        cout<<"Flight "<<searchFlightNumber<<" found."<<endl;
    }else{
        cout<<"Flight "<<searchFlightNumber<<" not found."<<ednl;;
    }

    system("pause");
    return 0;
}
