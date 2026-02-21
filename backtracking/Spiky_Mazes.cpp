#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkPath(vector<vector<char>>& matrix, vector<vector<bool>>& visited, int source, int target, int row, int column, int spikeSkips) {
    bool down = false;
    bool right = false;
    bool up = false;
    bool left = false;
    
    int n = matrix.size();
    int m = matrix[0].size();

    visited[row][column] = true;

    if(matrix[row][column] == 'x') {
        return true;
    }

    if(matrix[row][column] == '#') {
        return false;
    }
    if(matrix[row][column] == 's') {
        if(spikeSkips > 0) {
            spikeSkips --;
        }
        else {
            visited[row][column] = false;
            return false;
        }
    }

    if(row < n - 1 && !visited[row + 1][column]) {
        down = checkPath(matrix, visited, source, target, row + 1, column, spikeSkips);
    }
    if(column < m - 1 && !visited[row][column + 1]) {
        right = checkPath(matrix, visited, source, target, row, column + 1, spikeSkips);
    }
    if(row > 0 && !visited[row - 1][column]) {
        up = checkPath(matrix, visited, source, target, row - 1, column, spikeSkips);
    }
    if(column > 0 && !visited[row][column - 1]) {
        left = checkPath(matrix, visited, source, target, row, column - 1, spikeSkips);
    }

    if(down || right || up || left) {
        return true;
    }
    
    visited[row][column] = false;
    return false;
}

int main() {
    int n, m, j;
    cin >> n >> m >> j;

    string matrixRow;
    int source, target;
    vector<vector<char>> matrix(n);
    vector<vector<bool>> visited(n, vector<bool> (m, false));

    for(int i = 0; i < n; i++) {
        cin >> matrixRow;
        
        for(int j = 0; j < m; j++) {
            matrix[i].push_back(matrixRow[j]);
            
            if(matrixRow[j] == '@') {
                source = (n * i) + j;
            }
            if(matrixRow[j] == 'x') {
                target = (n * i) + j;
            }
        }
    }

    if(checkPath(matrix, visited, source, target, source / n, source % n, j / 2)) {
        cout << "SUCCESS\n";
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}
