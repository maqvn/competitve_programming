#include <iostream>
#include <vector>
#include <string>
using namespace std;

void calcP(bool white, vector<vector<char>>& occupied, int row, int col) {
    if(!white) {
        if(row <= 6) {
            if(col < 7) {
                if(occupied[row+1][col+1] == ' ') occupied[row+1][col+1] = 'x';
            }
            if(col > 0) {
                if(occupied[row+1][col-1] == ' ') occupied[row+1][col-1] = 'x';
            }
        }
    }
    else {
        if(row > 0) {
            if(col < 7) {
                if(occupied[row-1][col+1] == ' ') occupied[row-1][col+1] = 'x';
            }
            if(col > 0) {
                if(occupied[row-1][col-1] == ' ') occupied[row-1][col-1] = 'x';
            }
        }
    }
}

void calcN(vector<vector<char>>& occupied, int row, int col) {
    if(row + 2 <= 7) {
        if(col - 1 >= 0) {
            if(occupied[row+2][col-1] == ' ') occupied[row+2][col-1] = 'x';
        }
        
        if(col + 1 <= 7) {
            if(occupied[row+2][col+1] == ' ') occupied[row+2][col+1] = 'x';
        }    
    }
    if(col + 2 <= 7) {
        if(row + 1 <= 7) {
            if(occupied[row+1][col+2] == ' ') occupied[row+1][col+2] = 'x';
        }    
        
        if(row - 1 >= 0) {
            if(occupied[row-1][col+2] == ' ') occupied[row-1][col+2] = 'x';
        }    
    }
    if(row - 2 >= 0) {
        if(col + 1 <= 7) {
            if(occupied[row-2][col+1] == ' ') occupied[row-2][col+1] = 'x';
        }    
        
        if(col - 1 >= 0) {
            if(occupied[row-2][col-1] == ' ') occupied[row-2][col-1] = 'x';
        }
    }
    if(col - 2 >= 0) {
        if(row + 1 <= 7) {
            if(occupied[row+1][col-2] == ' ') occupied[row+1][col-2] = 'x';
        }    
        
        if(row - 1 >= 0) {
            if(occupied[row-1][col-2] == ' ') occupied[row-1][col-2] = 'x';
        }    
    }
    
}

void calcB(vector<vector<char>>& occupied, int row, int col) {
    // cima direita
    int cCol = col + 1;
    for(int i = row + 1; i <= 7; ++i) {
        if(cCol <= 7) {
            if(occupied[i][cCol] != ' ' && occupied[i][cCol] != 'x') {
                break;
            }
            else {
                occupied[i][cCol] = 'x';
            }
        }
        cCol++;
    }
    
    // cima esquerda
    cCol = col - 1;
    for(int i = row + 1; i <= 7; ++i) {
        if(cCol >= 0) {
            if(occupied[i][cCol] != ' ' && occupied[i][cCol] != 'x') {
                break;
            }
            else {
                occupied[i][cCol] = 'x';
            }
        }
        cCol--;
    }

    // baixo direita
    cCol = col + 1;
    for(int i = row - 1; i >= 0; --i) {
        if(cCol <= 7) {
            if(occupied[i][cCol] != ' ' && occupied[i][cCol] != 'x') {
                break;
            }
            else {
                occupied[i][cCol] = 'x';
            }
        }
        cCol++;
    }

    cCol = col - 1;
    for(int i = row - 1; i >= 0; --i) {
        if(cCol >= 0) {
            if(occupied[i][cCol] != ' ' && occupied[i][cCol] != 'x') {
                break;
            }
            else {
                occupied[i][cCol] = 'x';
            }
        }
        cCol--;
    }
}

void calcR(vector<vector<char>>& occupied, int row, int col) {
    int cRow, cCol;
    cRow = row;
    cCol = col;

    // cima
    for(int i = row + 1; i <= 7; ++i) {
        if(occupied[i][col] != ' ' && occupied[i][col] != 'x') {
            break;
        }
        else {
            occupied[i][col] = 'x';
        }
    }

    // baixo
    for(int i = row - 1; i >= 0; --i) {
        if(occupied[i][col] != ' ' && occupied[i][col] != 'x') {
            break;
        }
        else {
            occupied[i][col] = 'x';
        }
    }

    // direita
    for(int i = col + 1; i <= 7; ++i) {
        if(occupied[row][i] != ' ' && occupied[row][i] != 'x') {
            break;
        }
        else {
            occupied[row][i] = 'x';
        }
    }

    // esquerda
    for(int i = col - 1; i >= 0; --i) {
        if(occupied[row][i] != ' ' && occupied[row][i] != 'x') {
            break;
        }
        else {
            occupied[row][i] = 'x';
        }
    }
}

void calcK(vector<vector<char>>& occupied, int row, int col) {
    if(row < 7) {
        if(occupied[row+1][col] == ' ') occupied[row+1][col] = 'x';

        if(col > 0) {
            if(occupied[row+1][col-1] == ' ') occupied[row+1][col-1] = 'x';
        }
        if(col < 7) {
            if(occupied[row+1][col+1] == ' ') occupied[row+1][col+1] = 'x';
        }
    }
    if(row > 0) {
        if(occupied[row-1][col] == ' ') occupied[row-1][col] = 'x';

        if(col > 0) {
            if(occupied[row-1][col-1] == ' ') occupied[row-1][col-1] = 'x';
        }
        if(col < 7) {
            if(occupied[row-1][col+1] == ' ') occupied[row-1][col+1] = 'x';
        }
    }
    if(col > 0) {
        if(occupied[row][col-1] == ' ') occupied[row][col-1] = 'x';
    }
    if(col < 7) {
        if(occupied[row][col+1] == ' ') occupied[row][col+1] = 'x';
    }
}

int main() {
    string board;
    while(getline(cin, board)) {
        vector<vector<char>> occupied(8);
        int row = 0;
        int num;
        for(char c : board) {
            if(c == '/') {
                row++;
            }
            else {
                if(c >= '0' && c <= '8') {
                    num = c - '0';
                    for(int i = 0; i < num; ++i) {
                        occupied[row].push_back(' ');
                    }
                }
                else {
                    occupied[row].push_back(c);
                }
            }
        }

        for(int row = 0; row <= 7; row++) {
            for(int col = 0; col <= 7; col++) {
                char c = occupied[row][col];
                if(c != ' ') {
                    if(c == 'P') {
                        calcP(true, occupied, row, col);
                    }
                    else if(c == 'p') {
                        calcP(false, occupied, row, col);
                    }
                    else if(c == 'N' || c == 'n') {
                        calcN(occupied, row, col);
                    }
                    else if(c == 'B' || c == 'b') {
                        calcB(occupied, row, col);
                    }
                    else if(c == 'R' || c == 'r') {
                        calcR(occupied, row, col);
                    }
                    else if(c == 'Q' || c == 'q') {
                        calcB(occupied, row, col);
                        calcR(occupied, row, col);
                    }
                    else if(c == 'K' || c == 'k') {
                        calcK(occupied, row, col);
                    }
                }
            }
        }
        int counter = 0;
        for(auto x : occupied) {
            for(char c : x) {
                if(c == ' ') counter++;
            }
        }
        cout << counter << '\n';
    }

    return 0;
}