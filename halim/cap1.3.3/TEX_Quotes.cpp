#include <iostream>
#include <vector>
using namespace std;

int main() {
    char l = ' ';
    int a = 0;

    while(cin.get(l)) {
        if(l == '"') {
            if(a == 0) {
                cout << "``";
                a = 1;
            }
            else if(a == 1) {
                cout << "''";
                a = 0;
            }
        }
        else {
            cout << l;
        }
    }

    return 0;
}
