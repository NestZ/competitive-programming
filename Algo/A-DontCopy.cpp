#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
	
vector<vector<int>> g(2010);
vector<bool> vis(2010, false);

int dfs(int n){
	vis[n] = true;
	int mxH = 1;
	for(int adj : g[n]){
		if(!vis[adj])
			mxH = max(mxH, 1 + dfs(adj));
	}
	return mxH;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int pi;cin >> pi;
		if(pi != -1){
			pi--;
			g[i].push_back(pi);
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		vis = vector<bool>(2010, false);
		ans = max(ans, dfs(i));
	}
	cout << ans << endl;
}
