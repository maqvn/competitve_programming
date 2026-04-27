#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
// 0       1       2         3
// Spades, Hearts, Diamonds, Clubs
// 0 1 2 3 4 5 6 7 8 9 10 11 12
// A 2 3 4 5 6 7 8 9 T J  Q  K

// Contagem de Pontos
    // Contar: Aces, Kings, Queens, Jacks
    // Contar: Quantidade de cartas de cada naipe
    // Contar: Kings de cada naipe
    // Contar: Queens de cada naipe
    // Contar: Jacks de cada naipe

void buildCv(map<char, int>& cv) {
    cv['A'] = 0; 
    cv['2'] = 1;
    cv['3'] = 2;
    cv['4'] = 3;
    cv['5'] = 4; 
    cv['6'] = 5;
    cv['7'] = 6;
    cv['8'] = 7;
    cv['9'] = 8; 
    cv['T'] = 9;
    cv['J'] = 10;
    cv['Q'] = 11;
    cv['K'] = 12;    
}

void buildCs(map<char, int>& cs) {
    cs['S'] = 0; 
    cs['H'] = 1;
    cs['D'] = 2;
    cs['C'] = 3;
}

void buildcsR(map<int, char>& csR) {
    csR[0] = 'S'; 
    csR[1] = 'H';
    csR[2] = 'D';
    csR[3] = 'C';
}

bool checkNoTrump(vector<vector<int>> cards, int pointsNT) {
    bool nt = false;
    bool AllStopped = true;
    
    for(auto suit : cards) {
        if(!suit[14]) AllStopped = false;
    }
    if(AllStopped && pointsNT >= 16) {
        nt = true;
    }

    return nt;
}

int main() {
    vector<vector<int>> cards(4, vector<int>(15, 0)); 
    vector<char> suits = {'S', 'H', 'D', 'C'};

    map<char, int> cs;    
    map<char, int> cv;
    map<int, char> csR;
    buildCs(cs);
    buildCv(cv);
    buildcsR(csR);

    string card;
    int points;
    int pointsNT;
    int c = 0;

    while(cin >> card) {
        cards[cs[card[1]]][cv[card[0]]]++;
        cards[cs[card[1]]][13]++;

        if(c >= 12) {
            // Counting Points

            points = 0;
            pointsNT = 0;
            for(auto& suit : cards) {
                
                // Rule 1
                // Aces
                points += 4*(suit[0]);
                pointsNT += 4*(suit[0]);
                // Kings
                points += 3*(suit[12]);
                pointsNT += 3*(suit[12]);
                // Queens
                points += 2*(suit[11]);
                pointsNT += 2*(suit[11]);
                // Jacks
                points += 1*(suit[10]);
                pointsNT += 1*(suit[10]);

                // Rule 2
                if(suit[12] && suit[13] == 1) points --;
                if(suit[12] && suit[13] == 1) pointsNT --;

                // Rule 3
                if(suit[11] && suit[13] <= 2) points --;
                if(suit[11] && suit[13] <= 2) pointsNT --;

                // Rule 4
                if(suit[10] && suit[13] <= 3) points --;
                if(suit[10] && suit[13] <= 3) pointsNT --;

                // Number of cards in the suit
                if(suit[13] == 2) points += 1;
                if(suit[13] == 1) points += 2;
                if(suit[13] == 0) points += 2;

                // Stopped
                if(suit[0]) suit[14] = 1;
                else if(suit[12] && suit[13] > 1) suit[14] = 1;
                else if(suit[11] && suit[13] > 2) suit[14] = 1; 
            }
            
            if(points < 14) {
                cout << "PASS\n";
            }
            // NO-TURMP evaluation
            else if(checkNoTrump(cards, pointsNT)) {
                cout << "BID NO-TRUMP\n";
            }
            else{
                char suit;
                int maxI = 0;
                int max = 0;
                for(int i = 0; i < 4; ++i) {
                    if(cards[i][13] > max) {
                        max = cards[i][13];
                        maxI = i;
                    }
                }

                cout << "BID " << csR[maxI] << '\n';
            }
            
            cards.assign(4, vector<int>(15, 0));
            c = 0;
        }
        else {
            c++;
        }
    }
    return 0;
}
