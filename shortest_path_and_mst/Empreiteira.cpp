#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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

int prim(vector<vector<pair <int, int>>>& graph, int n) {
    vector <bool> marked(n);
    vector <int> cost(n);

    for(int i = 0; i < n; i++) {
        marked[i] = false;
        cost[i] = INT_MAX;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    heap.push({0, 0});
    cost[0] = 0;

    int current = 0;
    int parent;
    
    while(!heap.empty()) {

        current = heap.top().second;
        heap.pop();   

        if(!marked[current]) {
          
            marked[current] = true;
    
            int neighbourPosition = first(graph, current);
            int neighbourValue;
            int weight;
    
            while(neighbourPosition < graph[current].size()) {
                   
                    weight = graph[current][neighbourPosition].first;
                    neighbourValue = graph[current][neighbourPosition].second;
    
                    if(!marked[neighbourValue] && cost[neighbourValue] > weight) {
                        cost[neighbourValue] = weight;
                        heap.push({cost[neighbourValue], neighbourValue});
                    }
    
                    neighbourPosition = next(graph, current, neighbourPosition);
            }

        }

    }

    int minCost = 0;
    for(int i = 0; i < n; i++) {
        minCost += cost[i];
    }

    return minCost;
}


int main(){
    int nodes, egdes;
    cin >> nodes >> egdes;

    vector<vector<pair<int, int>>> graph(nodes);

    int source, target, weight;
    for(int i = 0; i < egdes; i++) {
        cin >> source >> target >> weight;

        graph[source].push_back({weight, target});
        graph[target].push_back({weight, source});
    }

    int cost = prim(graph, graph.size());

    cout << cost;

    return 0;
}
