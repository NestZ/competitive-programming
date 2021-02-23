#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
int n, m;
int cnt = 0;
vector<vector<int>> g(200010);
vector<int> scc(200010);
vector<bool> vis(200010, false);
stack<int> s;

void dfs2(int cur){
	vis[cur] = true;
	scc[cur] = cnt;
	for(auto adj : g[cur])
		if(!vis[adj])
			dfs2(adj);
}

void transpose(){
	vector<vector<int>> new_g(200010);
	for(int i = 1;i <= m;i++){
		for(auto adj : g[i]){
			new_g[adj].push_back(i);
		}
	}
	g = new_g;
}

void dfs(int cur){
	vis[cur] = true;
	for(auto adj : g[cur]){
		if(!vis[adj])
			dfs(adj);
	}
	s.push(cur);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int q = 0;q < 5;q++){
		cin >> n >> m;
		vector<pair<int, int>> arr;
		vector<int> op(m + 1);
		for(int i = 0;i < n;i++){
			int a, b;cin >> a >> b;
			arr.emplace_back(a, b);
		}
		for(int i = 0;i < m / 2;i++){
			int a, b;cin >> a >> b;
			op[a] = b;
			op[b] = a;
		}
		for(auto p : arr){
			g[op[p.first]].push_back(p.second);
			g[op[p.second]].push_back(p.first);
		}
		for(int i = 1;i <= m;i++){
			if(!vis[i])
				dfs(i);
		}
		transpose();
		fill(vis.begin(), vis.end(), false);
		while(!s.empty()){
			int cur = s.top();
			s.pop();
			if(!vis[cur])
				dfs2(cur);
			cnt++;
		}
		bool valid = true;
		for(int i = 1;i <= m;i++){
			if(scc[i] == scc[op[i]])
				valid = false;
		}
		if(valid)cout << 'Y';
		else cout << 'N';
		g = vector<vector<int>>(200010);
		vis = vector<bool>(200010);
		scc = vector<int>(200010);
	}
	cout << endl;
}
