#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q;cin >> n >> m >> q;
	vector<vector<int>> dp(n + 2, vector<int>(n + 2));
	for(int i = 0;i < m;i++){
		int l, r;cin >> l >> r;
		dp[l][r]++;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(j <= i)continue;
			dp[i][j] += dp[i][j - 1];
		}
	}
	for(int i = n;i > 0;i--){
		for(int j = n;j > 0;j--){
			if(j <= i)continue;
			dp[i][j] += dp[i + 1][j];
		}
	}
	for(int i = 0;i < q;i++){
		int l, r;cin >> l >> r;
		cout << dp[l][r] << endl;
	}
}
