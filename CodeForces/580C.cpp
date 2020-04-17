#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100005;
vector<int> g[N];
vector<int> v(N, false);
vector<int> cat(N, false);
int k;
int ans = 0;

void dfs(int n, int con){
	v[n] = true;
	if(cat[n])con++;
	else con = 0;
	if(con > k)return;
	if(g[n].size() == 1 && n != 1)ans++;
	for(int a : g[n]){
		if(!v[a])dfs(a, con);
	}
}

int main(){
	int t;cin >> t >> k;
	for(int i = 0;i < t;i++){
		int num;cin >> num;
		if(num == 1)cat[i + 1] = true;
	}
	for(int i = 0;i < t - 1;i++){
		int a, b;cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	cout << ans;
}
