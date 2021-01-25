#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c;cin >> n >> c;
	vector<int> a(n - 1);
	vector<int> b(n - 1);
	vector<vector<int>> dp(2, vector<int>(n + 1, INT_MAX));
	for(int i = 1;i < n;i++)cin >> a[i];
	for(int i = 1;i < n;i++)cin >> b[i];
	//last used, floor
	//0: stair 1: elevator
	dp[0][0] = 0;
	dp[1][0] = c;
	for(int i = 0;i < n;i++){
		//last stair
		//go stair
		dp[0][i + 1] = min(dp[0][i + 1], dp[0][i] + a[i]);
		//go elevator
		dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + b[i] + c);	
		//last elevator
		//go stair
		dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + a[i]);	
		//go elevator
		dp[1][i + 1] = min(dp[1][i + 1], dp[1][i] + b[i]);
	}
	for(int i = 1;i <= n;i++)
		cout << min(dp[0][i], dp[1][i]) << ' ';
	cout << endl;
}
