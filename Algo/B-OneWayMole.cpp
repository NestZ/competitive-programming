#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, t;
vector<int> g(30010);
vector<bool> vis(30010, false);

bool dfs(int cur){
	if(cur == t)return true;
	if(cur > t)return false;
	return dfs(g[cur]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> t;
	for(int i = 1;i < n;i++){
		int a;cin >> a;
		g[i] = i + a;
	}
	if(dfs(1))cout << "YES";
	else cout << "NO";
	cout << endl;
}
