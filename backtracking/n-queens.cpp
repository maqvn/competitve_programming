#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<int>& queenPos) {
    for(int i = 0; i < row; i++) {
        if(queenPos[i] == col) {
            return false;
        }
        if(abs(queenPos[i] - col) == abs(row - i)){
            return false;
        }
    }
    
    return true;
}

void nQueens(int row, vector<int>& queenPos, int& numOfSolutions, int n) {
    if (row == n) {
        numOfSolutions++;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, queenPos)) {
            queenPos[row] = col;
            nQueens(row + 1, queenPos, numOfSolutions, n);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> queenPos(n);
    int numOfSolutions = 0;

    nQueens(0, queenPos, numOfSolutions, n);

    cout << numOfSolutions;
    
    return 0;
}
