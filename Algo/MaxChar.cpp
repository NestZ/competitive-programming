#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<vector<int>> g(300010);
vector<vector<int>> dp(300010, vector<int>(26, 0));
vector<int> vis(300010, 0);
stack<int> st;

bool dfs(int n){
	vis[n] = 1;
	bool ncycle = true;
	for(auto adj : g[n]){
		if(vis[adj] == 2)continue;
		if(vis[adj] == 1)return false;
		else ncycle &= dfs(adj);
	}
	vis[n] = 2;
	st.emplace(n);
	return ncycle;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	bool inf = false;
	string s;cin >> s;
	set<pair<int, int>> edge;
	for(int i = 0;i < n;i++){
		dp[i + 1][s[i] - 'a'] = 1;
	}
	for(int i = 1;i <= m;i++){
		int a, b;cin >> a >> b;
		if(a == b)inf = true;
		if(!edge.count({a, b})){
			g[a].push_back(b);
			edge.emplace(a, b);
		}
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			bool ncycle = dfs(i);
			if(!ncycle)inf = true;
		}
	}
	if(inf)cout << -1;
	else{
		while(!st.empty()){
			int cur = st.top();
			st.pop();
			for(int adj : g[cur]){
				for(int i = 0;i < 26;i++){
					int nw = dp[cur][i];
					if(s[adj - 1] == char(i + 'a'))nw++;
					dp[adj][i] = max(dp[adj][i], nw);
				}
			}
		}
		int mx = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < 26;j++){
				mx = max(mx, dp[i][j]);
			}
		}
		cout << mx;
	}
	cout << endl;
}
