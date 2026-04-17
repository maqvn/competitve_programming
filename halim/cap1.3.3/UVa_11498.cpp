#include <iostream>
using namespace std;

int main() {
    int a, xx, yy, x, y;
    a = 1;
    
    while(a != 0) {
        cin >> a; 
        if(a != 0) {
            cin >> xx >> yy;
            
            for(int i = 0; i < a; ++i) {
                cin >> x >> y;
                
                if(x == xx || y == yy) {
                    cout << "divisa\n";
                }
                // E
                else if(x > xx) {
                    // NE
                    if(y > yy) {
                        cout << "NE\n";
                    }
                    // SE
                    else {
                        cout << "SE\n";
                    }
                }
                // W
                else {
                    // NW
                    if(y > yy) {
                        cout << "NO\n";
                    }
                    // SW
                    else {
                        cout << "SO\n";
                    }
                }
            }
        }
    }
    
    return 0;
}