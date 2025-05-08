#include <iostream>
using namespace std;

int decreaseByAConstant(int base, int exponent) {
    if(exponent > 0) {
        return decreaseByAConstant(base, exponent - 1) * base;
    }
    return 1;
}

int main() {
    int result = decreaseByAConstant(5, 3);

    cout << result;

    return 0;
}