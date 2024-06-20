#include <assert.h>
#include <iostream>
using namespace std;

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
     bool retIsOk = true;

    if (temperature < 0 || temperature > 45) {
        cout << "Temperature out of range!\n";
        retIsOk = false;
    }

    if (soc < 20 || soc > 80) {
        cout << "State of Charge out of range!\n";
        retIsOk = false;
    }

    if (chargeRate > 0.8) {
        cout << "Charge Rate out of range!\n";
        retIsOk = false;
    }

    return retIsOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
