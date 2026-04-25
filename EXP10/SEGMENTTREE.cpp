#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 3;
const int INF = (int)1e8;
class SegmentTree {
private:
	vector<int> tree;
	int n;
public:
	SegmentTree(vector<int> &v) {
		n = v.size();
		tree.resize(2*n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = v[i];
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = max(tree[2*i], tree[2*i + 1]);
		}
	}
	int query(int l, int r) {
		l += n;
		r += n;
		int ret = INT_MIN;
		while(l < r) {
			if(l&1) ret = max(ret, tree[l--]);
			if(r&1) ret = max(ret, tree[--r]);
			l /= 2;
			r /= 2;
		}
		return ret;
	}
	void update(int idx, int val) {
		idx += n;
		tree[idx] = val;
		while(idx > 1) {
			idx /= 2;
			tree[idx] = max(tree[2*idx + 1], tree[2*idx]);
		}
	}
};

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	int n = v.size();
	SegmentTree seg(v);
	cout<<seg.query(0,5);
}
