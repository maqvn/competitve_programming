#include <iostream>
#include <queue>
#include <vector>

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

unsigned int dijkstra(vector<vector<pair <int, int>>>& graph, int n, int sourceServer, int targetServer) {
    vector <bool> visited(n);
    vector <unsigned int> distance(n);
    vector <int> previous(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    for(int i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = 4294967295;
        previous[i] = -1;
    }

    heap.push({0, sourceServer});
    distance[sourceServer] = 0;

    int current = sourceServer;
    int parent;

    while(!heap.empty() && !visited[targetServer]) {

        while(!heap.empty() && visited[current]) {
            current = heap.top().second;
            heap.pop();
        }

        visited[current] = true;

        int neighbourPos = first(graph, current);
        int neighbourVal;
        int weight;

        while(neighbourPos < graph[current].size()) {
                weight = graph[current][neighbourPos].first;
                neighbourVal = graph[current][neighbourPos].second;

                if(!visited[neighbourVal] && distance[neighbourVal] > distance[current] + weight) {
                    distance[neighbourVal] = distance[current] + weight;
                    previous[neighbourVal] = current;
                    heap.push({distance[neighbourVal], neighbourVal});
                }

                neighbourPos = next(graph, current, neighbourPos);
        }
    }

    return distance[targetServer];
}


int main() {
    
    int numOfCases;
    cin >> numOfCases;
    
    int numServers;
    int numCables;
    int sourceServer;
    int targetServer;
    
    int server1;
    int server2;
    int latency;

    unsigned int distance;
    
    for(int i = 0; i < numOfCases; i++) {
        cin >> numServers >> numCables >> sourceServer >> targetServer;
        
        vector<vector<pair <int, int>>> graph(numServers);

        for(int j = 0; j < numCables; j++) {
            cin >> server1 >> server2 >> latency;

            graph[server1].push_back({latency, server2});
            graph[server2].push_back({latency, server1});
        }

        distance = dijkstra(graph, graph.size(), sourceServer, targetServer);

        cout << "Case #" << i + 1 << ": ";
        
        if (distance >= 4294967295)
            cout << "unreachable\n";
        else
            cout << distance << '\n';
    }
    
    return 0;
}
