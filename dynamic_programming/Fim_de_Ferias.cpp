#include <iostream>
#include <vector>
#include <string>

using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, vector<int>& usedToys, int weight , int n) {

    vector<vector<int>> table(n + 1, vector<int>(weight + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= weight; ++j) {
            table[i][j] = table[i - 1][j];
            
            if (weights[i - 1] <= j) {
                table[i][j] = max(
                    values[i - 1] + table[i - 1][j - weights[i - 1]],
                    table[i - 1][j]
                );
            } 
        }
    }

    int column = weight;

    for (int i = weights.size(); i >= 1; i--) {
        if(table[i][column] != table[i-1][column]) {
            usedToys.push_back(i);
            column -= weights[i-1];
        }
    }

    return table[n][weight];
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<string> names(n);
    vector<int> weights (n);
    vector<int> values (n);
    vector<int> usedToys (0);

    for (int i = 0 ; i < n; i++) {
        cin >> names[i] >> weights[i] >> values[i];
    }
    
    int result = knapsack(weights, values, usedToys, w , n);

    cout << result << ':';
    for (int i = usedToys.size() - 1; i >= 0; i--) {
        cout << ' ' << names[usedToys[i] - 1];
        if(i >= 1) {
            cout << ',';
        }
    }

    return 0;
}

