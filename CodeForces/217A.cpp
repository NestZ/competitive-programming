#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<int>> g(101);
vector<bool> v(101, false);
int ans = 0;

void dfs(int n){
	v[n] = true;
	for(int a : g[n]){
		if(!v[a])dfs(a);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int x, y;cin >> x >> y;
		arr.push_back({x, y});
	}
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[i].first == arr[j].first || arr[i].second == arr[j].second){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for(int i = 0;i < n;i++){
		if(!v[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans - 1;
}
