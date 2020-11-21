#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<int>> g(1001);
vector<bool> vis(1001, false);

bool dfs(int n){
	if(vis[n])return false;
	vis[n] = true;
	bool valid = true;
	for(int adj : g[n])
		if(!dfs(adj))valid = false;
	return valid;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int cnt;cin >> cnt;
		for(int j = 0;j < cnt;j++){
			int adj;cin >> adj;
			g[i].push_back(adj - 1);
		}
	}
	for(int i = 0;i < n;i++){
		if(dfs(i))cout << "NO";
		else cout << "YES";
		cout << endl;
		for(int j = 0;j < n;j++)
			vis[j] = false;
	}
}
