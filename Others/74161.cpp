#include <iostream>
#include <windows.h>

using namespace std;

class Counter606024 {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Counter606024() : hours(0), minutes(0), seconds(0) {}

    void increment() {
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
            if (minutes == 60) {
                minutes = 0;
                hours++;
                if (hours == 24) {
                    hours = 0;
                }
            }
        }
    }

    int getHours() const {
        return hours;
    }

    int getMinutes() const {
        return minutes;
    }

    int getSeconds() const {
        return seconds;
    }
};

class Display {
public:
    void show(int hours, int minutes, int seconds) {
        cout << "Display: " << hours << " hours " << minutes << " minutes " << seconds << " seconds" << endl;
    }
};

int main() {
    Counter606024 counter;

    Display display;

    for (int i = 0; i < 86400; i++) {  // 86400 seconds in a day
        // Update counter
        counter.increment();

        // Display time
        display.show(counter.getHours(), counter.getMinutes(), counter.getSeconds());

        // Simulate clock input by sleeping for 1 second using Windows API
        Sleep(1000);
    }

    return 0;
}
