#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        // union by size
        if (sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    int getSize(int x) {
        return sz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    int components = n;
    int maxSize = 1;

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (dsu.unite(a, b)) {
            components--;
            maxSize = max(maxSize, dsu.getSize(a));
        }

        cout << components << " " << maxSize << "\n";
    }
}
