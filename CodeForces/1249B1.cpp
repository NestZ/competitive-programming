#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int dfs(vector<int> &cc, vector<vector<int>> g, vector<bool> &v, int s, int n){
	if(v[n])return s - 1;
	v[n] = true;
	for(int i : g[n])return cc[i] = dfs(cc, g, v, s + 1, i);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<bool> v(n + 1, false);
		vector<vector<int>> g(n + 1);
		vector<int> cc(n + 1, 0);
		for(int i = 1;i <= n;i++){
			int k;cin >> k;
			g[i].push_back(k);
		}
		for(int i = 1;i <= n;i++){
			if(!v[i])dfs(cc, g, v, 1, i);
		}
		for(int i = 1;i <= n;i++)cout << cc[i] << ' ';
		cout << endl;
	}
}
