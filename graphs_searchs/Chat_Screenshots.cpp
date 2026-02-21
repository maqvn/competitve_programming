#include <iostream>
#include <vector>

using namespace std;

class Graph {
    private: 
        vector<vector <int>> graph;
        vector<int> visited;
        
        int numNodes;
        int numEdges;

    public:
        Graph(int numOfNodes) : 
            graph(numOfNodes), 
            visited(numOfNodes),
            numNodes(numOfNodes), 
            numEdges(0) {}

        void setEdge(int node, int value) {
            graph[node].push_back(value);
            numEdges ++;
        }

        int first(int node) {
            if(graph[node].size() > 0) {
                return 0;
            }
            return numNodes;
        }

        int next(int node, int neighbour) {
            if(neighbour < graph[node].size() - 1){
                return neighbour + 1;
            }
            return numNodes;
        }
        
        void topologicalSort(int node) {
            for(int i = 0; i < visited.size(); i++) {
                visited[i] = 0;
            }

            bool hasLoop = false;
            
            while(node < graph.size() && !hasLoop) {
                if (visited[node] == 0) {
                    topologicalSortHelp(node, hasLoop);
                }
                node ++;
            }
            if(hasLoop) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        void topologicalSortHelp(int node, bool& hasLoop) {
            visited[node] = 1;

            int neighbour = first(node);
            int neighbourValue;

            while(neighbour < graph[node].size()) {
                neighbourValue = graph[node][neighbour];
                
                if(visited[neighbourValue] == 0) {
                    topologicalSortHelp(neighbourValue, hasLoop);
                }
                else if(visited[neighbourValue] == 1) {
                    hasLoop = true;
                }
                neighbour = next(node, neighbour);
            }
            visited[node] = 2;
        }
};

int main() {
    int numOfCases;
    cin >> numOfCases;

    int numOfParticipants;
    int numOfShots;
    for(int i = 0; i < numOfCases; i++) {
        
        cin >> numOfParticipants;
        cin >> numOfShots;
        
        Graph graph(numOfParticipants + 1);
        vector<int> screenShot(numOfParticipants);
        
        for(int j = 0; j < numOfShots; j++) {
            for(int k = 0; k < numOfParticipants; k++) {
                cin >> screenShot[k];
            }

            for(int k = 1; k < numOfParticipants - 1; k++) {
                graph.setEdge(screenShot[k], screenShot[k+1]);
            }
        }

        graph.topologicalSort(0);
    }
    
    return 0;
}
