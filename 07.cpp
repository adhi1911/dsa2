#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < key.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(vector<int>& parent, vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primMST(vector<vector<int>>& graph) {
    vector<int> parent(graph.size());
    vector<int> key(graph.size(), INT_MAX);
    vector<bool> mstSet(graph.size(), false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph.size() - 1; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < graph.size(); v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    int V;
    cout << "Enter the number of offices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the cost matrix:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph);

    return 0;
}