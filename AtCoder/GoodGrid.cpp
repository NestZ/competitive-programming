#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c;cin >> n >> c;
	int ans = INT_MAX;
	vector<vector<int>> cost(c + 1, vector<int>(c + 1));
	vector<vector<int>> arr(n + 1, vector<int>(n + 1));
	vector<vector<int>> cnt(3, vector<int>(c + 1));
	vector<vector<int>> cost_change(3, vector<int>(c + 1));
	for(int i = 1;i <= c;i++)
		for(int j = 1;j <= c;j++)
			cin >> cost[i][j];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> arr[i][j];
			cnt[(i + j) % 3][arr[i][j]]++;
		}
	}
	for(int i = 0;i < 3;i++){
		for(int j = 1;j <= c;j++){
			int sum = 0;
			for(int k = 1;k <= c;k++){
				sum += cnt[i][k] * cost[k][j];
			}
			cost_change[i][j] = sum;
		}
	}
	for(int i = 1;i <= c;i++){
		for(int j = 1;j <= c;j++){
			if(i == j)continue;
			for(int k = 1;k <= c;k++){
				if(k == j || k == i)continue;
				ans = min(ans, cost_change[0][i] + cost_change[1][j] + cost_change[2][k]);
			}
		}
	}
	cout << ans << endl;
}
