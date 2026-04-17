#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int m, n, currentM, c;
    double dp, total, currentOwe, currentCarValue, dep;
    m = 1;

    while(m >= 0) {
        cin >> m >> dp >> total >> n;
        
        if(m >= 0) {
            vector<pair<int, double>> monthDep;
            currentCarValue = total + dp;
            currentOwe = total;
            double monthPayment = total / m;
        
            for(int i = 0; i < n; ++i) {
                cin >> currentM >> dep;
                monthDep.push_back({currentM, dep});
            }
    
            int currentMonth, pos;
            double currentMdep;
            currentMonth = 0; 
            currentMdep = 0;
            pos = 0;


            currentMdep = monthDep[pos].second;
            currentCarValue -= (currentCarValue * currentMdep);
            pos++;
    

            while(currentCarValue <= currentOwe) {
                currentMonth++;
                if(monthDep[pos].first == currentMonth) {
                    currentMdep = monthDep[pos].second;
                    currentCarValue -= (currentCarValue * currentMdep);
                    currentOwe -= monthPayment;            
    
                    pos++;
                }
                else {
                    currentCarValue -= (currentCarValue * currentMdep);
                    currentOwe -= monthPayment;
                }
            }
            
            if(currentMonth != 1) {
                cout << currentMonth << " months\n";
            }
            else {
                cout << currentMonth << " month\n";
            }
        }
    }


    return 0;
}