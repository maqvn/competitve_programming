#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

// compliance = numberOfRequirementsMet / numberOfRequirements
void addTuple(pair<pair<string, float>, int>& trio, string a, float b, int c) {
    trio.first.first = a;
    trio.first.second = b;
    trio.second = c;
}
 

int main() {
    int numRequirements, numProposals;
    string requirement;
    int c = 1;

    while(cin >> numRequirements >> numProposals) {
        if(numRequirements != 0 && numProposals != 0) {
            cin.ignore();
            for(int i = 0; i < numRequirements; ++i) {
                getline(cin, requirement);
            }
            
            string proposalName, metRequirement;
            float price;
            int numMetRequirements;
            
            //prop   price   numMetRequirements
            pair<pair<string, float>, int> trio;
            addTuple(trio, "", 0.0, 0);
            
            for(int i = 0; i < numProposals; ++i) {
                getline(cin, proposalName);
    
                cin >> price >> numMetRequirements;
                cin.ignore();
                
                for(int j = 0; j < numMetRequirements; j++) {
                    getline(cin, metRequirement);
                }
                
                if(numMetRequirements > trio.second) {
                    addTuple(trio, proposalName, price, numMetRequirements);
                }
                else if(numMetRequirements == trio.second && price < trio.first.second) {
                    addTuple(trio, proposalName, price, numMetRequirements);
                }
            }
            if(c > 1) {
                cout << '\n';
            }
            cout << "RFP #" << c << '\n';
            cout << trio.first.first << "\n";
            c++;
        }
    }

    
    return 0;
}