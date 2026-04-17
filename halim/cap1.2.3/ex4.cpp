#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a;
    vector<int> inteirosUnicos;

    unordered_map<int, int> dicionarioHash;

    for(int i = 0; i < a; i++) {
        cin >> b;
        dicionarioHash[b]++;
    }

    for(auto &x : dicionarioHash) {
        if(x.second == 1) {
            inteirosUnicos.push_back(x.first);
        }
    }


    sort(inteirosUnicos.begin(), inteirosUnicos.end());
    for(int x : inteirosUnicos) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
