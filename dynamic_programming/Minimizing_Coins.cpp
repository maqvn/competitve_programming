#include <iostream>
#include <vector>

using namespace std;

int int_max = 10*10*10*10*10*10 + 5;

int minCoin(vector<int> values, int target) {
    int n = values.size();
    vector<int> table(target + 1, int_max);
    table[0] = 0;

    for (int i = 0; i < n; i++) {
        int coin = values[i];
        for (int j = coin; j <= target; j++) {
            if (table[j - coin] != int_max) {
                table[j] = min(table[j], table[j - coin] + 1);
            }
        }
    }

    return table[target];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> values(n);

    for(int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    int result = minCoin(values, x);
    
    if(result == int_max) {
        result = -1;
    }
    
    cout << result;
    
    return 0;
}
