#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    private: 
        vector<vector <char>> graph;
        vector<vector <bool>> visited;
        vector< vector <pair <int, int>>> predecessor;

        int n;
        int m;

    public:
        Graph(vector<vector<char>>& matrix, int rows, int columns) 
            :   n(rows),
                m(columns),
                graph(matrix),
                visited(rows, vector<bool>(columns, false)),
                predecessor(rows, vector<pair<int, int>>(columns, {-1, -1}))
            {

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (matrix[i][j] != '.') {
                        if (matrix[i][j] == '<') {
                            int k = j - 1;
                            while(k >= 0 && matrix[i][k] == '.') {
                                graph[i][k] = 'x';
                                k --;
                            }
                        }
                        else if (matrix[i][j] == '>') {
                            int k = j + 1;
                            while(k < m && matrix[i][k] == '.') {
                                graph[i][k] = 'x';
                                k ++;
                            }
                        }
                        else if (matrix[i][j] == '^') {
                            int k = i - 1;
                            while(k >= 0 && matrix[k][j] == '.') {
                                graph[k][j] = 'x';
                                k --;
                            }                            
                        } 
                        else if (matrix[i][j] == 'v') {
                            int k = i + 1;
                            while(k < n && matrix[k][j] == '.') {
                                graph[k][j] = 'x';
                                k ++;
                            }
                        }
                    }
                }
            }
        }

        bool isReachable(int row, int column) {
            return visited[row][column];
        }

        void BFS(int row, int column) {
            if(graph[0][0] == '.') {
                
                queue <pair<int, int>> visitsQueue;
    
                visitsQueue.push({row, column});
                visited[row][column] = 1;
    
                while(!visitsQueue.empty()) {
                    row = visitsQueue.front().first;
                    column = visitsQueue.front().second;
                    visitsQueue.pop();
                    
                    if(row > 0) {
                        if(!visited[row - 1][column] && graph[row - 1][column] == '.') {
                            visited[row - 1][column] = true;
                            visitsQueue.push({row - 1, column});
    
                            predecessor[row - 1][column] = {row, column};
                        }
                    }
                    if(row < graph.size() - 1) {
                        if(!visited[row + 1][column] && graph[row + 1][column] == '.') {
                            visited[row + 1][column] = true;
                            visitsQueue.push({row + 1, column});
    
                            predecessor[row + 1][column] = {row, column};
                        }
                    }
                    if(column > 0) {
                        if(!visited[row][column - 1] && graph[row][column - 1] == '.') {
                            visited[row][column - 1] = true;
                            visitsQueue.push({row, column - 1});
    
                            predecessor[row][column - 1] = {row, column};
                        }
                    }
                    if(column < graph[0].size() - 1) {
                        if(!visited[row][column + 1] && graph[row][column + 1] == '.') {
                            visited[row][column + 1] = true;
                            visitsQueue.push({row, column + 1});
    
                            predecessor[row][column + 1] = {row, column};
                        }
                    }
                }
            }
        }

        void printResult(vector<vector<char>>& matrix) {
            pair<int, int> current = {n - 1, m - 1};
            while (current.first != -1 && current.second != -1) {
                if (graph[current.first][current.second] == '.') {
                    graph[current.first][current.second] = 'X';
                }
                current = predecessor[current.first][current.second];
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if(graph[i][j] == 'X') {
                        cout << graph[i][j];
                    }
                    else {
                        cout << matrix[i][j];
                    }
                }
                cout << '\n';
            }
        }
};

int main() {
    int rows, columns;
    cin >> rows >> columns;
    
    vector<vector<char>> matrix(rows, vector<char>(columns));

    for (int i = 0; i < rows; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = row[j];
        }
    }

    Graph graph(matrix, matrix.size(), matrix[0].size());

    graph.BFS(0, 0);

    if (!graph.isReachable(rows - 1, columns - 1)) {
        cout << "-1\n";
    } else {
        graph.printResult(matrix);
    }

    return 0;
}
