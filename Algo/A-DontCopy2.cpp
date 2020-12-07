#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<bool> vis(1010, false);
vector<int> g(1010);

int dfs(int n){
	if(vis[n])return n;
	vis[n] = true;
	return dfs(g[n]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int p;cin >> p;
		p--;
		g[i] = p;
	}
	for(int i = 0;i < n;i++){
		cout << dfs(i) + 1 << ' ';
		vis = vector<bool>(1010, false);
	}
	cout << endl;
}
