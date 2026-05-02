#include <iostream>
using namespace std;

int main() {
    int m, n;

    while(cin >> m >> n && m != 0) {
        if(m < 3 || n < 3 ) {
            if(m == 1 || n == 1) {
                cout << m*n;
            }
            else {  
                int k = max(m, n);
                int groups = k / 4;
                int rem = k % 4;

                int res = groups * 4;
                if (rem == 1) res += 2;
                else if (rem > 1) res += 4;

                cout << res;

            }
        }
        else {
            cout << ((m*n+1) / 2);
        }
        cout << " knights may be placed on a " << m << " row " << n << " column board.\n";
    }

    return 0;
}