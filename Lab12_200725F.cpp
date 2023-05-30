#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int numVertices = 6;

int findMinDistance(const vector<int>& distances, const vector<bool>& visited) {
    int minDistance = numeric_limits<int>::max();
    int minIndex = -1;

    for (int v = 0; v < numVertices; ++v) {
        if (!visited[v] && distances[v] <= minDistance) {
            minDistance = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printSolution(const vector<int>& distances, int source) {

    for (int i = 0; i < numVertices; ++i) {
        cout << "From city " << source << " to city " << i << " = " << distances[i] << endl;
    }
}

void dijkstra(const vector<vector<int>>& graph, int source) {
    vector<int> distances(numVertices, numeric_limits<int>::max());
    vector<bool> visited(numVertices, false);

    distances[source] = 0;

    for (int count = 0; count < numVertices - 1; ++count) {
        int u = findMinDistance(distances, visited);
        visited[u] = true;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && graph[u][v] && distances[u] != numeric_limits<int>::max() &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }

    printSolution(distances, source);
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    dijkstra(graph, 5);

    return 0;
}