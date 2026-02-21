#include <iostream>
#include <vector>

using namespace std;

int nextValid(vector<vector<int>>& sudoku, int row, int column) {
    bool validValue = true;
    int value = sudoku[row][column] + 1;
    
    while(value <= 9) {
        for(int i = 0; i < 9; i++) {
            if(i != column && sudoku[row][i] == value) {
                validValue = false;
            }
        }

        for(int i = 0; i < 9; i++) {
            if(i != row && sudoku[i][column] == value) {
                validValue = false;
            }
        }

        for(int i = 3 * (row / 3); i < (3 + (3 *(row / 3))); i++) {
            for(int j = 3 * (column / 3); j < (3 + (3 *(column / 3))); j++) {
                if((i != row || j != column) && sudoku[i][j] == value) {
                    validValue = false;
                }
            }
        }

        if(!validValue) {
            value ++;
            validValue = true;
        }
        else {
            return value;
        }
    }

    return value;
}

bool isBase(vector<vector<int>>& baseSudoku, int position) {
    int row = position / 9;
    int column = position % 9;

    return baseSudoku[row][column];
}

bool solveSudoku(vector<vector<int>>& baseSudoku, vector<vector<int>>& sudoku, int position) {
    int row = position / 9;
    int column = position % 9;

    if(0 <= position && position <= 80 ) {
        if(!isBase(baseSudoku, position)) {
            int nextValidValue = nextValid(sudoku, row, column);
            
            if(nextValidValue <= 9) {
                sudoku[row][column] = nextValidValue;
                position ++;
                return solveSudoku(baseSudoku, sudoku, position);
            }
    
            sudoku[row][column] = 0;
            
            position --;
            while(isBase(baseSudoku, position)) {
                position --;
            }
            
            return solveSudoku(baseSudoku, sudoku, position);
        }

        position ++;
        return solveSudoku(baseSudoku, sudoku, position);

    }
    
    else if (position < 0) {
        return false;
    }

    else {
        return true;
    }
}

int main() {
    
    int numOfCases;
    cin >> numOfCases;

    
    int value;
    
    for(int i = 0; i < numOfCases; i++) {
        vector<vector<int>> baseSudoku(9);
        vector<vector<int>> sudoku(9);
        
        for(int row = 0; row < 9; row++) {
            for(int column = 0; column < 9; column ++) {
                cin >> value;
                baseSudoku[row].push_back(value);
                sudoku[row].push_back(value);  
            }
        }

        if(solveSudoku(baseSudoku, sudoku, 0)) {
            for(int row = 0; row < 9; row++) {
                for(int column = 0; column < 9; column ++) {
                    cout << sudoku[row][column];
                    if(column < 8 ){
                        cout << ' ';
                    }
                }
                cout << "\n";
            }
        }
        else {
            cout << "No solution\n";
        }
    }

    return 0;
}
