#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<int> dp(1 << k, 1e9);
	dp[0] = 0;
	for(int i = 0;i < n;i++){
		int w;cin >> w;
		int cur = 0;
		for(int j = 0;j < k;j++){
			int b;cin >> b;
			cur |= (b << j);
		}
		for(int j = 0;j < (1 << k);j++){
			dp[j | cur] = min(dp[j] + w, dp[j | cur]);
		}
	}
	cout << dp[(1 << k) - 1] << endl;
}
