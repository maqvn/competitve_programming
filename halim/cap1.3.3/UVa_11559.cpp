#include <iostream>
using namespace std;

int main() {
    int numPessoas, budget, numHotels, numWeeks; 
    int price, availableBeds;
    int min = 500001;
        
    while(cin >> numPessoas >> budget >> numHotels >> numWeeks) {
        for(int i = 0; i < numHotels; ++i) {
            cin >> price;
            for(int j = 0; j < numWeeks; ++j) {
                cin >> availableBeds;
    
                if((availableBeds >= numPessoas) && 
                ((price * numPessoas) <= budget) &&
                ((price * numPessoas) < min)) {
                    min = price * numPessoas;
                };
            }
        } 

        if(min == 500001) {
            cout << "stay home\n";
        }
        else {
            cout << min << '\n';
        }
        min = 500001;
    }


    return 0;
}