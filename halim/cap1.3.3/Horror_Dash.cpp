#include <iostream>
using namespace std;

int main() {
    int t, n, s, fs;
    cin >> t;
    
    for(int i = 0; i < t; ++i) {
        fs = 0;
        cin >> n;
        for(int j = 0; j < n; ++j) {
            cin >> s;
            if(s > fs) {
                fs = s;
            }
        }

        cout << "Case " << i+1 << ": " << fs << '\n';
    }

    return 0;
}