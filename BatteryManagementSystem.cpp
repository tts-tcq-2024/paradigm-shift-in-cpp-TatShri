#include <assert.h>
#include <iostream>
#include <vector>
#include <tuple>
#include "messageTranslate.h"

using namespace std;

preferredLanguage  messageLanguage;

// Print the status of whether a parameter is in range
void printRangeStatus(const string& parameter, bool isInRange) {
    std::string rangeStatus = isInRange ? "in" : "out";
    std::cout << messageTranslate(parameter, messageLanguage) << ": " << messageTranslate(rangeStatus, messageLanguage) << std::endl;
}

// Check if a value is within a specified range
bool isValueInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

// Check if temperature is within range
bool isTemperatureInRange(float temperature) {
    return isValueInRange(temperature, 0, 45);
}

// Check if State of Charge (SOC) is within range
bool isSocInRange(float soc) {
    return isValueInRange(soc, 20, 80);
}

// Check if charge rate is within range
bool isChargeRateInRange(float chargeRate) {
    return (chargeRate <= 0.8);
}

// Check if all battery parameters are within range
bool isBatteryOk(float temperature, float soc, float chargeRate) {
    // Vector of tuples to hold the parameter name and check result
    std::vector<std::tuple<std::string, bool>> checks = {
        {"Temperature", isTemperatureInRange(temperature)},
        {"State of Charge", isSocInRange(soc)},
        {"Charge Rate", isChargeRateInRange(chargeRate)}
    };

    bool allChecksPassed = true;

    // Iterate through each check, print message and update the overall status
    for (const auto& check : checks) {
        const std::string& parameter = std::get<0>(check); // Get parameter name
        bool isInRange = std::get<1>(check); // Get check result
        printRangeStatus(parameter, isInRange);
        allChecksPassed = allChecksPassed && isInRange;
    }

    return allChecksPassed;
}

int main() {
    messageLanguage = Language::German;

    assert(isBatteryOk(25, 70, 0.7) == true);
    assert(isBatteryOk(50, 85, 0) == false);
    assert(isBatteryOk(0, 20, 0.8) == true);
    assert(isBatteryOk(-1, 70, 0.5) == false);
    assert(isBatteryOk(25, 10, 0.5) == false);
    assert(isBatteryOk(25, 70, 0.9) == false);
    assert(isBatteryOk(45, 80, 0.8) == true);
    assert(isBatteryOk(0, 20, 0) == true);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
