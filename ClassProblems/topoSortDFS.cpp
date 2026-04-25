#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> topoSortDFS(int n, vector<pair<int,int>> &edges) {
    vector<vector<int>> adj(n);

    for (auto &e : edges) {
        adj[e.first].push_back(e.second);
    }

    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> topo;

    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main() {
    int n = 6;
    vector<pair<int,int>> edges = {
        {5, 2}, {5, 0}, {4, 0},
        {4, 1}, {2, 3}, {3, 1}
    };

    vector<int> result = topoSortDFS(n, edges);

    for (int x : result) {
        cout << x << " ";
    }
} 
