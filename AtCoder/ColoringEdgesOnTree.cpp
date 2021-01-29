#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<vector<pair<int, int>>> g(100010);
vector<bool> vis(100010, false);
vector<int> deg(100010, 0);
vector<int> ans(100010, -1);
vector<set<int>> used(100010);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int mxDeg = 0;
	for(int i = 0;i < n - 1;i++){
		int a, b;cin >> a >> b;
		deg[a]++;
		deg[b]++;
		mxDeg = max({mxDeg, deg[a], deg[b]});
		g[a].emplace_back(b, i);
		g[b].emplace_back(a, i);
	}
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		int fst = 1;
		for(auto adj : g[cur]){
			if(vis[adj.first])continue;
			int edge_index = adj.second;
			while(used[cur].count(fst))fst++;
			ans[edge_index] = fst;
			used[cur].insert(fst);
			used[adj.first].insert(fst);
			vis[adj.first] = true;
			q.push(adj.first);
		}
	}
	cout << mxDeg << endl;
	for(int i = 0;i < n - 1;i++){
		cout << ans[i] << endl;
	}
}
