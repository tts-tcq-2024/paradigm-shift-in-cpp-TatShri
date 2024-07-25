#include <assert.h>
#include <iostream>
#include "LanguageTranslate.h"
using namespace std;


void printMessage(const string& range, const string& message) {
    std::cout << languagetranslate(range, messageLanguage) << ": " << languagetranslate(message, messageLanguage) << std::endl;
}

// Function to check if a value is within a specified range
bool checkInRange(float value, float min, float max) {
    if(min!=-1000.0f){
        return (value >= min && value <= max);
    }
    else{
        return (value <= max);
    }
}

bool TemperatureIsOk(float temperature) {
    return checkInRange(temperature, 0, 45);
}

bool socIsOk(float soc) {
    return checkInRange(soc, 20, 80);
}

bool chargeRateIsOk(float chargeRate) {
    return checkInRange(chargeRate, -1000.0f, 0.8);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool tempIsOk = TemperatureIsOk(temperature);
    printMessage("Temp", tempIsOk ? "in" : "out");

    bool socIsOk = socIsOk(soc);
    printMessage("SOC", socIsOk ? "in" : "out");

    bool crIsOk = chargeRateIsOk(chargeRate);
    printMessage("CR", crIsOk ? "in" : "out");

    return (tempIsOk && socIsOk && crIsOk);
}

int main() {
    messageLanguage = Language::German;
    
    assert(batteryIsOk(25, 70, 0.7) == true);  // All values within range
    assert(batteryIsOk(50, 85, 0) == false);   // Temperature and SOC out of range
    assert(batteryIsOk(0, 20, 0.8) == true);   // All values at the boundary of their range
    assert(batteryIsOk(-1, 70, 0.5) == false); // Temperature out of range
    assert(batteryIsOk(25, 10, 0.5) == false); // SOC out of range
    assert(batteryIsOk(25, 70, 0.9) == false); // Charge Rate out of range
    assert(batteryIsOk(45, 80, 0.8) == true);  // All values at the upper boundary of their range
    assert(batteryIsOk(0, 20, 0) == true);     // All values at the lower boundary of their range

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
