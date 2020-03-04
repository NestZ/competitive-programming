#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int k, n, m;cin >> k >> n >> m;
	vector<int> g[n + 5];
	vector<bool> visited(n + 5, false);
	int ans = 1;
	for(int i = 0;i < m;i++){
		int v, w;cin >> v >> w;
		g[v].push_back(w);
	}
	vector<int> dis(n + 5, INT_MAX);
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	visited[1] = true;
	while(!q.empty()){
		int v = q.front();q.pop();
		if(dis[v] <= k)ans = max(ans, v);
		for(int w : g[v]){
			if(!visited[w]){
				visited[w] = true;
				q.push(w);
				dis[w] = dis[v] + 1;
			}
		}
	}
	cout << ans;
}
