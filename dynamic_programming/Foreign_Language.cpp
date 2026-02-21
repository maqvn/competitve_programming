#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long minCost(string source, string target, int n, int m, long long insert, long long remove, long long modify) { 
    vector<vector<long long>> tableDP(n+1, vector<long long> (m+1, 0));

    for (int i = 1; i <= n; i++) {
        tableDP[i][0] = tableDP[i-1][0] + remove;
    }

    for (int i = 1; i <= m; i++) {
        tableDP[0][i] = tableDP[0][i-1] + insert;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (source[i-1] == target[j-1]) {
                tableDP[i][j] = tableDP[i-1][j-1];
            }
            else {
                tableDP[i][j] = min(
                    min(tableDP[i-1][j-1] + modify, tableDP[i-1][j] + remove),
                    tableDP[i][j-1] + insert
                    );
            }
        }
    }

    return tableDP[n][m];
}

int main() {
    int n, m;
    long long a, b, c;
    string source, target;
    
    cin >> n >> m >> a >> b >> c;
    cin >> source >> target;

    cout << minCost(source, target, n, m, a, b, c);
    
    return 0;
}
