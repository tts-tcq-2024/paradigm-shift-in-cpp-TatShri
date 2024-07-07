#include <assert.h>
#include <iostream>
using namespace std;

void printMessage(const string& message) {
    cout << message << endl;
}

bool checkInRange(float value, float min, float max, const string& rangeType) {
    if (value < min || value > max) {
        printMessage(rangeType + " out of range!");
        return false;
    } else {
        printMessage(rangeType + " in range.");
    }
    return true;
}

bool TemperatureIsOk(float temperature) {
    return checkInRange(temperature, 0, 45, "Temperature");
}

bool socIsOk(float soc) {
    return checkInRange(soc, 20, 80, "State of Charge");
}

bool chargeRateIsOk(float chargeRate) {
    return checkInRange(chargeRate, 0, 0.8, "Charge Rate");
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool tempIsOk = TemperatureIsOk(temperature);
    bool stcIsOk = socIsOk(soc);
    bool crIsOk = chargeRateIsOk(chargeRate);
    return (tempIsOk && stcIsOk && crIsOk);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);  // All values within range
    assert(batteryIsOk(50, 85, 0) == false);   // Temperature and SOC out of range
    assert(batteryIsOk(0, 20, 0.8) == true);   // All values at the boundary of their range
    assert(batteryIsOk(-1, 70, 0.5) == false); // Temperature out of range
    assert(batteryIsOk(25, 10, 0.5) == false); // SOC out of range
    assert(batteryIsOk(25, 70, 0.9) == false); // Charge Rate out of range
    assert(batteryIsOk(45, 80, 0.8) == true);  // All values at the upper boundary of their range
    assert(batteryIsOk(0, 20, 0) == true);     // All values at the lower boundary of their range
}
