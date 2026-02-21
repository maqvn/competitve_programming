#include <iostream>
#include <vector>
#include <string>

using namespace std;

int searchWord(vector<string>& listWords, string word, int r) {
    int l = 0;
    int m;

    while(l <= r) {
        m = (l + r) / 2;
        if(listWords[m] == word) {
            return 1;
        }
        else if(word < listWords[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numOfWords;
    cin >> numOfWords;

    vector<string> listWords(numOfWords);

    for(int i = 0; i < numOfWords; i++) {
        cin >> listWords[i];
    }

    int numOfCorrectAttempts = 0;
    int numOfAttempts;
    cin >> numOfAttempts;

    string attempt;
    for(int i = 0; i < numOfAttempts; i++) {
        cin >> attempt;
        numOfCorrectAttempts += searchWord(listWords, attempt, numOfWords - 1);
    }
    cout << numOfCorrectAttempts;
    
    return 0;
}