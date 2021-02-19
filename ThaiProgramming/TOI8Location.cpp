#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	int k;cin >> k;
	int ans = 0;
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
			if(i > 0)dp[i][j] += dp[i - 1][j];
			if(j > 0)dp[i][j] += dp[i][j - 1];
			if(i > 0 && j > 0)dp[i][j] -= dp[i - 1][j - 1];
		}
	}
	for(int i = 0;i <= n - k;i++){
		for(int j = 0;j <= m - k;j++){
			int cur_sum = dp[i + k - 1][j + k - 1];
			if(i > 0)cur_sum -= dp[i - 1][j + k - 1];
			if(j > 0)cur_sum -= dp[i + k - 1][j - 1];
			if(i > 0 && j > 0)cur_sum += dp[i - 1][j - 1];
			ans = max(ans, cur_sum);
		}
	}
	cout << ans << endl;
}
