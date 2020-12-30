#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<vector<int>> g(200010);
vector<int> inc(200010);
vector<int> ans(200010, 0);

void dfs(int n, int &sum, int p){
	sum += inc[n];
	ans[n] += sum;
	for(int adj : g[n]){
		if(adj != p)
			dfs(adj, sum, n);
	}
	sum -= inc[n];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;cin >> n >> q;
	for(int i = 0;i < n - 1;i++){
		int a, b;cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0;i < q;i++){
		int p, x;cin >> p >> x;
		inc[p] += x;
	}
	int sum = 0;
	dfs(1, sum, 0);
	for(int i = 1;i <= n;i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
}
