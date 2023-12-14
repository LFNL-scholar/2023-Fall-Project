#include <iostream>
#include <vector>
using namespace std;

struct Car {
    int licensePlate;
    int arrivalTime;
};

class Stack {
private:
    vector<Car> stack;

public:
    bool isEmpty() {
        return stack.empty();
    }

    void push(const Car& car) {
        stack.push_back(car);
    }

    Car pop() {
        Car car = stack.back();
        stack.pop_back();
        return car;
    }

    Car top() {
        return stack.back();
    }

    int size() {
        return stack.size();
    }

    vector<Car> getStack() {
        return stack;
    }
};

class Queue {
private:
    vector<Car> queue;

public:
    bool isEmpty() {
        return queue.empty();
    }

    void enqueue(const Car& car) {
        queue.push_back(car);
    }

    Car dequeue() {
        Car car = queue.front();
        queue.erase(queue.begin());
        return car;
    }

    int size() {
        return queue.size();
    }

    vector<Car> getQueue() {
        return queue;
    }
};

int main() {
    Stack parkingLot;  // 停车场
    Stack tempStack;   // 临时栈，用于给要离去的汽车让路
    Queue waitingQueue;  // 便道

    char action;
    int licensePlate, arrivalTime;

    while (true) {
        cin >> action;

        if (action == 'E') {
            break;  // 输入结束
        }
    

        cin >> licensePlate >> arrivalTime;

        if (action == 'A') {  // 车辆到达
            Car car = {licensePlate, arrivalTime};

            if (parkingLot.isEmpty()) {
                parkingLot.push(car);
                cout << "Car " << licensePlate << " parks at position 1." << endl;
            } else if (parkingLot.size() < 5) {
                parkingLot.push(car);
                cout << "Car " << licensePlate << " parks at position " << parkingLot.size() << "." << endl;
            } else {
                waitingQueue.enqueue(car);
                cout << "Car " << licensePlate << " waits in the queue." << endl;
            }
        } else if (action == 'D') {  // 车辆离去
            int departureTime;
            departureTime=arrivalTime;

            while (!parkingLot.isEmpty() && parkingLot.top().licensePlate != licensePlate) {
                tempStack.push(parkingLot.pop());
            }

            if (!parkingLot.isEmpty()) {
                Car departingCar = parkingLot.pop();
                int parkingTime = departureTime - departingCar.arrivalTime;
                int fee = parkingTime * 10;  // 停车费用计算规则，假设每小时10元

                cout << "Car " << departingCar.licensePlate << " stays " << parkingTime << " hours and pays " << fee << " yuan." << endl;

                // 更新停车场的顺序
                vector<Car> remainingCars;
                while (!tempStack.isEmpty()) {
                    remainingCars.push_back(tempStack.pop());
                }

                for (int i = remainingCars.size() - 1; i >= 0; --i) {
                    parkingLot.push(remainingCars[i]);
                }

                // 如果便道上有等待的车辆，将其加入停车场
                if (!waitingQueue.isEmpty() && parkingLot.size() < 5) {
                    parkingLot.push(waitingQueue.dequeue());
                    cout << "Car " << parkingLot.top().licensePlate << " moves from the queue to the parking lot." << endl;
                }
            }
        }
    }

    // 输出停车场和便道的状态
    cout << "Parking Lot Status:" << endl;
    vector<Car> parkingLotStatus = parkingLot.getStack();
    for (int i = parkingLotStatus.size() - 1; i >= 0; --i) {
        cout << "Position " << parkingLot.size() - i << ": Car " << parkingLotStatus[i].licensePlate << endl;
    }

    cout << "Waiting Queue Status:" << endl;
    vector<Car> waitingQueueStatus = waitingQueue.getQueue();
    for (int i = 0; i < waitingQueueStatus.size(); ++i) {
        cout << "Car " << waitingQueueStatus[i].licensePlate << endl;
    }

    return 0;
}
