#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int N = 101;
vector<vector<int>> g(N);
vector<bool> v(N, false);

void dfs(int n){
	v[n] = true;
	for(int i : g[n]){
		if(!v[i])dfs(i);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<set<int>> s(n);
	vector<vector<int>> arr(n);
	bool flag = false;
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		for(int j = 0;j < num;j++){
			int t;cin >> t;
			s[i].insert(t);
			arr[i].push_back(t);
			flag = true;
		}
	}
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			for(int k : arr[i]){
				if(s[j].count(k) > 0){
					g[i].push_back(j);
					g[j].push_back(i);
					break;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(!v[i]){
			ans++;
			dfs(i);
		}
	}
	if(!flag)ans++;
	cout << ans - 1;
}
