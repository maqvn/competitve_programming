#include <iostream>
#include <vector>
using namespace std;

int rook(int rows, int columns) {
    if(rows < columns)  {
        return rows;
    }
    return columns;
}
int knight(int rows, int columns) {
    return (rows * columns) / 2;
}
int queen(int rows, int columns) {
    if(rows < columns) {
        return rows;
    }
    return columns;
}
int king(int rows, int columns) {
    return ((rows + 1) / 2) * ((columns + 1) / 2);
}


int main() {
    char p;
    int n, rows, columns;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> p >> rows >> columns;
        vector<vector<int>> table(rows, vector<int> (0));
        int result;

        if(p == 'r') {
            result = rook(rows, columns);
        }
        else if(p == 'k') { 
            result = knight(rows, columns);
        }
        else if(p == 'Q') {
            result = queen(rows, columns);
        }
        else if(p == 'K') {
            result = king(rows, columns);
        }
        
        cout << result << '\n';
    }
    return 0;
}