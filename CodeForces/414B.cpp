#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	const ll m = 1e9 + 7;
	ll n, k;cin >> n >> k;
	vector<vector<ll>> dp(2001, vector<ll>(2001));
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){
			if(i == 1)dp[j][i] = 1;
			else{
				for(int l = j;l <= n;l+=j){
					dp[l][i] = (dp[j][i - 1] + dp[l][i]) % m;
				}
			}
		}
	}
	ll sum = 0;
	for(int i = 1;i <= n;i++)sum = (sum + dp[i][k]) % m;
	cout << sum;
}
