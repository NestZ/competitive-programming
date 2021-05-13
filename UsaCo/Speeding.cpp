/*
ID: nestz
LANG: C++14
TASK: speeding
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("speeding.out", "w", stdout);
	freopen("speeding.in", "r", stdin);

	int n, m;cin >> n >> m;
	vector<pair<int, int>> lim;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		lim.push_back({a, b});
	}
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		arr.push_back({a, b});
	}
	vector<int> sim_lim(101), sim_arr(101);
	int cur = 1;
	for(auto p : lim){
		for(int i = 0;i < p.first;i++){
			sim_lim[cur] = p.second;
			cur++;
		}
	}
	cur = 1;
	for(auto p : arr){
		for(int i = 0;i < p.first;i++){
			sim_arr[cur] = p.second;
			cur++;
		}
	}
	int ans = 0;
	for(int i = 1;i <= 100;i++){
		ans = max(ans, sim_arr[i] - sim_lim[i]);
	}
	cout << ans << endl;
}
