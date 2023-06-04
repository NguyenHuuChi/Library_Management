#include <ctime>
#include <iostream>

using namespace std;

int main() {
    // Get the current time
    time_t currentTime = time(nullptr);
    
    // Convert the time to a local time string
    string currentTimeString = ctime(&currentTime);
    
    // Print the current time
    cout << "Current time: " << currentTimeString;

    return 0;
}
