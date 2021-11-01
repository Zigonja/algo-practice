#include <iostream>
#define N 9

using namespace std;

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    
    for (int i = 0; i < N; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}

// s = start node
void dijkstra(int nodes[][N], int s) {
    int distances[N];
    bool visited[N];

    for (int i = 0; i < N; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    int curr_node = s;
    distances[s] = 0;

    // find shortest distances for nodes connected to curr_node
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[curr_node]) {
                continue;
            }

            if (nodes[curr_node][j] > 0 && distances[j] > distances[curr_node] + nodes[curr_node][j] && distances[curr_node] != INT_MAX) {
                distances[j] = distances[curr_node] + nodes[curr_node][j];
            }
        }

        visited[curr_node] = true;

        // find closest unvisited node of current_node
        int min = INT_MAX;

        for (int j = 0; j < N; j++) {
            if (!visited[j] && distances[j] <= min) {
                min = distances[j];
                curr_node = j;
            }
        }
    }

    printSolution(distances);
}

int main() {
    int graph[N][N] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
    };

    dijkstra(graph, 0);
}