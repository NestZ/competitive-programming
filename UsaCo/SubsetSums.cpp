/*
ID: nestz
LANG: C++14
TASK: subset
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subset.out", "w", stdout);
	freopen("subset.in", "r", stdin);
	
	ll n;cin >> n;
	if((n * (n + 1) / 2) & 1)return cout << 0 << endl, 0;
	ll sum = n * (n + 1) / 2 / 2;
	//dp[i][j] = first i elements with sum j
	vector<vector<ll>> dp(n + 1, vector<ll>(n * (n + 1), 0));
	//only way to choose i element with sum of 0 is dont choose any
	for(int i = 0;i <= n;i++)dp[i][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < n * (n + 1);j++){
			if(j - i >= 0)
				//dp[i - 1][j]
				//dont choose cur element
				//dp[i - 1][j - i]
				//choose cur element (cur element value is i)
				dp[i][j] += dp[i - 1][j] + dp[i - 1][j - i];
			//cur element is too big so dont choose it
			else dp[i][j] += dp[i - 1][j];
		}
	}
	cout << dp[n][sum] / 2 << endl;
}
