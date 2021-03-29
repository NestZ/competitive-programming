#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	map<pair<int, int>, int> tmp;
	vector<vector<pair<int, int>>> g(n + 10);
	for(int i = 0;i < m;i++){
		int a, b, c;cin >> a >> b >> c;
		auto p = make_pair(a, b);
		if(!tmp.count(p) || tmp[p] > c)
			tmp[p] = c;
	}
	for(auto e : tmp){
		auto p = e.first;
		int c = e.second;
		g[p.first].push_back(make_pair(p.second, c));
	}
	for(int i = 1;i <= n;i++){
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		vector<int> dist(n + 10, INT_MAX);
		dist[i] = 0;
		q.push({0, i});
		int ans = INT_MAX;
		while(!q.empty()){
			auto cur = q.top(); q.pop();
			int v = cur.second;
			int c = cur.first;
			for(auto adj : g[v]){
				if(c + adj.second < dist[adj.first]){
					dist[adj.first] = c + adj.second;
					q.push({dist[adj.first], adj.first});
				}
			}
		}
		for(int j = 1;j <= n;j++){
			auto p = make_pair(j, i);
			if(!tmp.count(p) || dist[j] == INT_MAX)continue;
			ans = min(ans, dist[j] + tmp[p]);
		}
		if(ans == INT_MAX)cout << -1;
		else cout << ans;
		cout << endl;
	}
}
