#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool in(vector<int> a, int x) {
    for(int y : a) {
        if (y == x) return true;
    }
    return false;
}

int score(vector<int> a, vector<int> b) {
    int score = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] > b[i]) score++;
    } 
    return score;
}

int invalidPermutations(vector<int> princess, vector<int>& prince, int pos, int unvalidPermutations) {
    if(pos == prince.size()-1 && score(prince, princess) < 2) {
        return unvalidPermutations + 1;
    }
    else {
        for(int i = pos; i < prince.size(); ++i) {
            swap(prince[pos], prince[i]);
            unvalidPermutations = invalidPermutations(princess, prince, pos + 1, unvalidPermutations);
            swap(prince[pos], prince[i]);
        }
        return unvalidPermutations;
    }
}

int main() {
    int a, b, c, x, y, p;
    int princessP = 0;
    vector<int> princess(3);
    vector<int> prince(3);
    
    while(cin >> princess[0] >> princess[1] >> princess[2] >> prince[0] >> prince[1] && prince[0] != 0) {
        // Para cada carta possível
        bool find = false;
        for(int c = 1; c < 53 && !find; c++) {
            prince[2] = c;
            // Para cada permutação de Prince com a Carta atual
            for(int j = 0; j < 6; ++j) {
                vector<int> prince2 = {prince[0], prince[1]};
                if(invalidPermutations(princess, prince, 0, 0) == 0 && !in(princess, c) && !in(prince2, c)) {
                    cout << c << '\n';
                    find = true;
                    break;
                }
            }
        }
        if(!find) {
            cout << "-1" << '\n';
        }
    }

    return 0;
}