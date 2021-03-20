#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<vector<int>> g(n + 1);
	vector<int> c(n);
	vector<int> ans(n + 1);
	queue<int> q;
	vector<bool> vis(n + 1, false);
	for(int i = 0;i < n - 1;i++){
		int a, b;cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0;i < n;i++)cin >> c[i];
	sort(c.rbegin(), c.rend());
	vis[1] = true;	
	q.push(1);
	ans[1] = c[0];
	int res = 0;
	int ptr = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int adj : g[cur]){
			if(!vis[adj]){
				ans[adj] = c[ptr];
				res += c[ptr++];
				vis[adj] = true;
				q.push(adj);
			}
		}
	}
	cout << res << endl;
	for(int i = 1;i <= n;i++)cout << ans[i] << ' ';
	cout << endl;
}
