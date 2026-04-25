#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 3;
const int INF = (int)1e8;
int prime = 31;
int solve(vector<int>& tokens, int power) {
	sort(tokens.begin(), tokens.end());
	int score = 0;
	int left = 0, right = tokens.size() - 1;
	while(left<=right){
			if(tokens[left] <= power)
			{
					power-=tokens[left];
					score++;
					left++;
			}else if(left<right && score > 0){
					power+=tokens[right];
					score--;
					right--;
			}else{
					return score;
			}
	}
	return score;
}

int solve2(vector<int> &v) {
	vector<int> bit(32, 0);
	for(int i = 0; i < 32; i++) {
		for(int num : v) {
			if(num &(1 << i)) bit[i]++;
		}
	}
	int mask = 0;
	for(int i = 0; i < 32; i++) {
		if(bit[i] % 3 != 0) {
			mask = (mask | (1 << i));
		}
	}
	return mask;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//clock_t tStart = clock();
	int t = 1; //cin>>t;
	//while(t--)
	//vector<int> v = {200, 100};
	//cout<<solve(v, 150)<<'\n';

	vector<int> v2 = {1,1,1,2,2,2,3,3,3,10};
	cout<<solve2(v2)<<'\n';
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
