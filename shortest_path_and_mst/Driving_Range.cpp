#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int first(const vector<vector<pair<int, int>>>& graph, int node) {
    if(!graph[node].empty()) {
        return 0;
    }
    return graph[node].size();
}

int next(const vector<vector<pair<int, int>>>& graph, int node, int index) {
    if (index + 1 < graph[node].size()) {
        return index + 1;
    }
    return graph[node].size();
}

void prim(vector<vector<pair <int, int>>>& graph, int n, int s) {
    vector <bool> visited(n);
    vector <int> distance(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    for(int i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = 2147483647;
    }

    heap.push({0, s});
    distance[s] = 0;

    int biggestRoad = 0;

    int current = s;
    int parent;
    int weight;

    while(!heap.empty()) {

        current = heap.top().second;
        weight = heap.top().first;

        heap.pop();

        
        if(!visited[current]) {
            if(weight > biggestRoad) {
                biggestRoad = weight;
            }
            visited[current] = true;
            
            int neighbourPos = first(graph, current);
            int neighbourVal;
            
            while(neighbourPos < graph[current].size()) {
                weight = graph[current][neighbourPos].first;
                neighbourVal = graph[current][neighbourPos].second;
                
                if(!visited[neighbourVal] && distance[neighbourVal] > weight) {
                    distance[neighbourVal] = weight;
                    heap.push({distance[neighbourVal], neighbourVal});
                }
                
                neighbourPos = next(graph, current, neighbourPos);
            }
        }
    }


    int impossible = false;
    
    for(int i = 0; i < n; i++) {
        if(distance[i] == 2147483647) {
            impossible = true;
        }
    }
    if (impossible){
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << biggestRoad << '\n';
    }
}

int main() {
    int n;
    int m;
    
    while(n != 0 && m != 0) {
        cin >> n >> m;
        
        vector<vector<pair<int, int>>> graph(n);

        int source, target, weight;

        if(n != 0 && m != 0) {
            for(int i = 0; i < m; i++) {
                cin >> source >> target >> weight;
                
                graph[source].push_back({weight, target});
                graph[target].push_back({weight, source});
            }
            
            prim(graph, graph.size(), 0);   
        }
    }

    return 0;
}
