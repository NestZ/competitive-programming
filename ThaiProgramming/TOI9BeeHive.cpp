#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	int ans = 0;
	int ans_cnt = 0;
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
	vector<vector<int>> cnt(n, vector<int>(m, 0));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	for(int i = 0;i < m;i++){
		dp[0][i] = arr[0][i];
		cnt[0][i] = 1;
	}
	for(int i = 1;i < n;i++){
		for(int j = 0;j < m;j++){
			if(i & 1){
				if(j == m - 1){
					dp[i][j] = arr[i][j] + dp[i - 1][j];
					cnt[i][j] = cnt[i - 1][j];
				}
				else{
					dp[i][j] = arr[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j]);
					if(dp[i - 1][j + 1] == dp[i - 1][j]){
						cnt[i][j] += cnt[i - 1][j + 1] + cnt[i - 1][j];
					}
					else if(dp[i - 1][j + 1] > dp[i - 1][j]){
						cnt[i][j] = cnt[i - 1][j + 1];
					}
					else cnt[i][j] = cnt[i - 1][j];
				}
			}
			else{
				if(j == 0){
					dp[i][j] = arr[i][j] + dp[i - 1][j];
					cnt[i][j] = cnt[i - 1][j];
				}
				else{
					dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
					if(dp[i - 1][j - 1] == dp[i - 1][j]){
						cnt[i][j] += cnt[i - 1][j - 1] + cnt[i - 1][j];
					}
					else if(dp[i - 1][j - 1] > dp[i - 1][j]){
						cnt[i][j] = cnt[i - 1][j - 1];
					}
					else cnt[i][j] = cnt[i - 1][j];
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	for(int i = 0;i < m;i++){
		if(dp[n - 1][i] == ans)ans_cnt += cnt[n - 1][i];
	}
	cout << ans << ' ' << ans_cnt << endl;
}
