#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a;

    for(int i = 0; i < a; ++i) {
        cin >> b >> c;

        if(b > c) {
            cout << ">\n";
        }
        else if(b < c) {
            cout << "<\n";
        }
        else {
            cout << "=\n";
        }
    }

    return 0;
}