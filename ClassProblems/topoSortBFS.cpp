#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<pair<int,int>> &edges) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    // Build graph
    for (auto &e : edges) {
        adj[e.first].push_back(e.second);
        indegree[e.second]++;
    }

    queue<int> q;

    // Push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check for cycle
    if (topo.size() != n) {
        cout << "Cycle detected, no topo sort possible\n";
        return {};
    }

    return topo;
}

int main() {
    int n = 6;
    vector<pair<int,int>> edges = {
        {5, 2}, {5, 0}, {4, 0},
        {4, 1}, {2, 3}, {3, 1}
    };

    vector<int> result = topoSort(n, edges);

    for (int x : result) {
        cout << x << " ";
    }
}
