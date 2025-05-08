#include <iostream>
using namespace std;

int decreaseByAConstantFactor(int base, int exponent) {
    if(exponent == 0) {
        return 1;
    }
    else if(exponent % 2 == 0) {
        return decreaseByAConstantFactor(base, exponent / 2) * decreaseByAConstantFactor(base, exponent / 2);
    }
    else {
        return decreaseByAConstantFactor(base, (exponent - 1) / 2) * decreaseByAConstantFactor(base, (exponent - 1) / 2) * base;
    }
    
}

int main() {

    int result = decreaseByAConstantFactor(5, 2);

    cout << result << endl;

    return 0;
}