#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int mxN = 100010;
int n, m, k;
int cur_g_num = 0;
vector<vector<int>> gf(mxN);
vector<bool> vis(mxN, false);
vector<int> adj_f_cnt(mxN, 0);
vector<int> g_b_cnt(mxN, 0);
vector<int> g_num(mxN, -1);
vector<int> in_g(mxN, 0);

int dfs(int cur){
	vis[cur] = true;
	g_num[cur] = cur_g_num;
	int cnt = 1;
	for(auto adj : gf[cur]){
		if(!vis[adj])
			cnt += dfs(adj);
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		gf[a].push_back(b);
		gf[b].push_back(a);
		adj_f_cnt[a]++;
		adj_f_cnt[b]++;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i])
			in_g[cur_g_num] = dfs(i);
		cur_g_num++;
	}
	for(int i = 0;i < k;i++){
		int a, b;cin >> a >> b;
		if(g_num[a] == g_num[b]){
			g_b_cnt[a]++;
			g_b_cnt[b]++;
		}
	}
	for(int i = 1;i <= n;i++){
		cout << in_g[g_num[i]] - adj_f_cnt[i] - g_b_cnt[i] - 1 << ' ';
	}
	cout << endl;
}
