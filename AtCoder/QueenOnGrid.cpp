#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m));
	vector<vector<int>> u(n, vector<int>(m));
	vector<vector<int>> l(n, vector<int>(m));
	vector<vector<int>> ul(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(arr[i][j] == '#')continue;
			if(i == 0 && j == 0){
				dp[i][j] = 1;
				u[i][j] = 1;
				l[i][j] = 1;
				ul[i][j] = 1;
			}
			else if(i == 0){
				dp[i][j] = (dp[i][j] + l[i][j - 1]) % MOD;
				l[i][j] = (l[i][j - 1] + dp[i][j]) % MOD;
				ul[i][j] = u[i][j] = dp[i][j];
			}
			else if(j == 0){
				dp[i][j] = (dp[i][j] + u[i - 1][j]) % MOD;
				u[i][j] = (u[i - 1][j] + dp[i][j]) % MOD;
				ul[i][j] = l[i][j] = dp[i][j];
			}
			else{
				dp[i][j] = ((dp[i][j] + u[i - 1][j]) % MOD + (ul[i - 1][j - 1] + l[i][j - 1]) % MOD) % MOD;
				u[i][j] = (u[i - 1][j] + dp[i][j]) % MOD;
				l[i][j] = (l[i][j - 1] + dp[i][j]) % MOD;
				ul[i][j] = (ul[i - 1][j - 1] + dp[i][j]) % MOD;
			}
		}
	}
	cout << dp[n - 1][m - 1] << endl;
}
