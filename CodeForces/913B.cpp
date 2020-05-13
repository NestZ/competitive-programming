#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<int>> g(1005);
bool flag = true;

void dfs(int n, int f){
	int cntL = 0;
	bool l = true;
	for(int a : g[n]){
		if(a != f){
			l = false;
			if(g[a].size() == 0)cntL++;
			dfs(a, n);
		}
	}
	if(cntL < 3 && !l)flag = false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n + 1, 0);
	for(int i = 1;i <= n - 1;i++){
		int t;cin >> t;
		g[t].push_back(i + 1);
	}
	dfs(1, 0);
	if(flag)cout << "Yes";
	else cout << "No";
}
