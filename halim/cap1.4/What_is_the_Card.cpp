#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    
    for(int i = 0; i < n; ++i) {
        //          value suits
        vector<pair<char, char>> hand(25);
        vector<pair<char, char>> deck(27);

        string card;
        
        for(int j = 0; j < 27; ++j) {
            cin >> card;
            deck[j].first = card[0];
            deck[j].second = card[1];
        }
        for(int j = 0; j < 25; j++) {
            cin >> card;
            hand[j].first = card[0];
            hand[j].second = card[1];
        }
        
        int Y = 0;
        int r = 26;
        
        for(int j = 0; j < 3; ++j) {
            int X;
            char cardValue = deck[r].first;
            
            // Step 1
            if(cardValue >= '2' && cardValue <= '9') {
                X = cardValue - '0';
            } 
            else {
                X = 10;
            }

            // Step 2
            Y += X;

            // Step 3
            r -= 1 + (10 - X);
        }
        Y -= 1;

        if(Y <= r) {
            cout << "Case " << i+1 << ": " << deck[Y].first << deck[Y].second << '\n';
        }
        else {
            Y -= r+1;
            cout << "Case " << i+1 << ": " << hand[Y].first << hand[Y].second << '\n';
        }
    }


    return 0;
}