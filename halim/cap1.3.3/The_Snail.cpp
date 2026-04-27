#include <iostream>
using namespace std;

int main() {
    double wellHight, dayDistance, nigthDistance, fatigue, dayCurrentDistance;    
    bool fim;
    wellHight = 1;
    
    while(wellHight != 0) {
        cin >> wellHight >> dayDistance >> nigthDistance >> fatigue;

        if(wellHight != 0) {
            int c = 1;
            double h = 0;
            fatigue = (fatigue / 100.0) * dayDistance;
            fim = false;

            dayCurrentDistance = dayDistance;

            while(!fim) {
                
                if(dayCurrentDistance > 0) {
                    h += dayCurrentDistance;
                }
                
                if(h > wellHight) {
                    cout << "success on day " << c << '\n';
                    break;
                }

                h -= nigthDistance;
    
                if(h < 0) {
                    cout << "failure on day " << c << '\n';
                    break;
                }
                
                dayCurrentDistance -= fatigue;
                c++;
            }
        }
        
    }

    return 0;
}