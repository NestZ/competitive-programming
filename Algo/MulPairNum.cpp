#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	ll p = 0;
	ll m = 0;
	//0 plus
	//1 minus
	vector<vector<ll>> dp(2, vector<ll>(n + 1));
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 1;i <= n;i++){
		if(arr[i - 1] < 0){
			dp[0][i] = dp[1][i - 1];
			dp[1][i] = dp[0][i - 1] + 1;
		}
		else{
			dp[0][i] = dp[0][i - 1] + 1;
			dp[1][i] = dp[1][i - 1];
		}
		p += dp[0][i];
		m += dp[1][i];
	}
	cout << m << ' ' << p << endl;	
}
