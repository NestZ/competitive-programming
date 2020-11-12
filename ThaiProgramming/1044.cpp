#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	ll sum = 0;
	ll ans = 0;
	vector<vector<ll>> init_cost(n, vector<ll>(m));
	vector<vector<ll>> dif_cost(n, vector<ll>(m));
	vector<ll> sum_row(n, 0);
	vector<ll> sum_col(m, 0);
	vector<ll> dif_row(n, 0);
	vector<ll> dif_col(m, 0);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> init_cost[i][j];
			sum += init_cost[i][j];
			sum_row[i] += init_cost[i][j];
			sum_col[j] += init_cost[i][j];
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> dif_cost[i][j];
			dif_row[i] += dif_cost[i][j];
			dif_col[j] += dif_cost[i][j];
		}
	}
	for(int i = 0;i < n;i++){
		ll cur_cost = sum - sum_row[i];
		if(i - 1 >= 0)cur_cost += dif_row[i - 1];
		if(i + 1 < n)cur_cost += dif_row[i + 1];
		ans = max(ans, cur_cost);
	}
	for(int i = 0;i < m;i++){
		ll cur_cost = sum - sum_col[i];
		if(i - 1 >= 0)cur_cost += dif_col[i - 1];
		if(i + 1 < m)cur_cost += dif_col[i + 1];
		ans = max(ans, cur_cost);
	}
	cout << ans;
}
