#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 3;
const int INF = (int)1e8;
int prime = 31;
vector<int> parent;
vector<int> sz;
int comp;
int find(int node) {
	if(parent[node]) return node;
	return parent[node] = node;
}
void unite(int n1, int n2) {
	int u = find(n1);
	int v = find(n2);
	if(u == v) return;
	if(sz[u] > sz[v]) swap(sz[u], sz[v]);
	parent[u] = v;
	sz[v] += sz[u];
	comp--;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin>>n>>m;
	comp = n;
	parent.resize(n + 1);
	sz.resize(n + 1, 1);
	for(int i = 1; i <= n; i++) parent[i] = i;
	int p, q;
	for(int i = 0; i < m; i++) {
		cin>>p>>q;
		unite(p, q);
	}
	cout<<comp<<'\n';
	return 0;
}
