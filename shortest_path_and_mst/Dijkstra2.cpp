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

void dijkstra(vector<vector<pair <int, int>>>& graph, int n, int source, int target) {
    vector <bool> visited(n);
    vector <int> distance(n);
    vector <int> previous(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    for(int i = 1; i < n; i++) {
        visited[i] = false;
        distance[i] = 2147483646;
        previous[i] = -1;
    }

    heap.push({0, source});
    distance[source] = 0;

    int pathStep = source;
    int parent;

    while(!heap.empty() && !visited[target]) {

        while(!heap.empty() && visited[pathStep]) {
            pathStep = heap.top().second;
            heap.pop();
        }

        visited[pathStep] = true;

        int neighbourPosition = first(graph, pathStep);
        int neighbour;
        int weight;

        while(neighbourPosition < graph[pathStep].size()) {
                weight = graph[pathStep][neighbourPosition].first;
                neighbour = graph[pathStep][neighbourPosition].second;

                if(!visited[neighbour] && distance[neighbour] > distance[pathStep] + weight) {
                    distance[neighbour] = distance[pathStep] + weight;
                    previous[neighbour] = pathStep;
                    heap.push({distance[neighbour], neighbour});
                }

                neighbourPosition = next(graph, pathStep, neighbourPosition);
        }
    }
   
    if(previous[target] == -1) {
        cout << -1;
    }
    else {
        vector<int> path(0);
        pathStep = target;

        while(pathStep != 1) {
            path.push_back(pathStep);
            pathStep = previous[pathStep];
        }
        path.push_back(pathStep);

        for(int i = path.size() - 1; i > 0; i--) {
            cout << path[i] << ' ';
        }
        cout << path[0];
    }
}

int main() {

    int numOfNodes;
    cin >> numOfNodes;

    vector<vector<pair<int, int>>> graph(numOfNodes + 1);

    int numOfEdges;
    cin >> numOfEdges;

    int source;
    int target;
    int weight;
    int distance;

    for(int i = 0; i < numOfEdges; i++) {
        cin >> source >> target >> weight;
        
        graph[source].push_back({weight, target});
        graph[target].push_back({weight, source});
    }
    
    dijkstra(graph, graph.size(), 1, numOfNodes);

    return 0;
}
