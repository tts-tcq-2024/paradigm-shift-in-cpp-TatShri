#include <assert.h>
#include <iostream>
#include <map>
#include "LanguageTranslate.h"
using namespace std;

void printMessage(const string& range, const string& message ) {
    std::cout << languagetranslate(range) << ": " << languagetranslate(message) << std::endl;
}

bool checkInRange(float value, float min, float max, const string& rangeType) {
  // Use ternary operator to determine the message and print it
    string message = (value < min || value > max) ? "out" : "in";
    printMessage(rangeType, message);

    return true;
}

bool TemperatureIsOk(float temperature) {
    return checkInRange(temperature, 0, 45, "Temp");
}

bool socIsOk(float soc) {
    return checkInRange(soc, 20, 80, "SOC");
}

bool chargeRateIsOk(float chargeRate) {
    return checkInRange(chargeRate, 0, 0.8, "CR");
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool tempIsOk = TemperatureIsOk(temperature);
    bool stcIsOk = socIsOk(soc);
    bool crIsOk = chargeRateIsOk(chargeRate);
    return (tempIsOk && stcIsOk && crIsOk);
}

int main() {
    setoutputlanguage("german");
    assert(batteryIsOk(25, 70, 0.7) == true);  // All values within range
    assert(batteryIsOk(50, 85, 0) == false);   // Temperature and SOC out of range
    assert(batteryIsOk(0, 20, 0.8) == true);   // All values at the boundary of their range
    assert(batteryIsOk(-1, 70, 0.5) == false); // Temperature out of range
    assert(batteryIsOk(25, 10, 0.5) == false); // SOC out of range
    assert(batteryIsOk(25, 70, 0.9) == false); // Charge Rate out of range
    assert(batteryIsOk(45, 80, 0.8) == true);  // All values at the upper boundary of their range
    assert(batteryIsOk(0, 20, 0) == true);     // All values at the lower boundary of their range
}
