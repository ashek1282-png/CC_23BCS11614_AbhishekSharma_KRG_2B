#include <bits/stdc++.h>
using namespace std;

int prims(int n, vector<vector<pair<int,int>>> &adj) {
    // {weight, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<bool> visited(n, false);
    pq.push({0, 0}); // start from node 0

    int mstWeight = 0;

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        mstWeight += weight;

        for (auto &neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int nextWeight = neighbor.second;

            if (!visited[nextNode]) {
                pq.push({nextWeight, nextNode});
            }
        }
    }

    return mstWeight;
}

int main() {
    int n = 4;
    vector<vector<pair<int,int>>> adj(n);

    // u - v (weight)
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({2, 6});
    adj[2].push_back({0, 6});

    adj[0].push_back({3, 5});
    adj[3].push_back({0, 5});

    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});

    adj[1].push_back({3, 15});
    adj[3].push_back({1, 15});

    cout << prims(n, adj);
} 
