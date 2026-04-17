#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a;
    int b[3];
    cin >> a;

    for(int i = 0; i < a; ++i) {
        cin >> b[0] >> b[1] >> b[2];
        sort(b, b+3);
        cout << "Case " << i+1 << ": " << b[1] << '\n';
    }

    return 0;
}