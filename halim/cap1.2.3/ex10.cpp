#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int v = 0;

    for(int i = 0; i < s.length(); ++i) {        
        if(v == 0) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                v = 1;
            }
            else {
                v = -1;
            }
        }
        else if(v == 1) {
            if(s[i] >= '0' && s[i] <= '9') {
                v = 2;
            }
            else {
                v = -1;
            }
        }
        else if(v == 2) {
            if(s[i] >= '0' && s[i] <= '9') {
                v = 3;
            }
            else {
                v = -1;
            }
        }
        else if(v == 3) {
            if(s[i] == ' ') {
                for(int j = i-3; j < i; ++j) {
                    s[j] = '*';
                }
            }
            else {
                v = -1;
            }  
        }
        else if(s[i] == ' ') {
            v = 0;
        }
    }
    if(v == 3) {
        for(int j = s.length() - 3; j < s.length(); ++j) {
            s[j] = '*';
        }
    }

    cout << s << '\n';

    return 0;
}