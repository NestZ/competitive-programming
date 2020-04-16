#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<int> g[2005];
int ans = 0;

void dfs(int n, int d){
	ans = max(ans, d);
	for(int a : g[n]){
		dfs(a, d + 1);
	}
}

int main(){
	int n;cin >> n;
	for(int i = 1;i <= n;i++){
		int t;cin >> t;
		if(t == -1)continue;
		g[i].push_back(t);
	}
	for(int i = 1;i <= n;i++)dfs(i, 0);
	cout << ans + 1;
}
