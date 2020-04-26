#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	vector<vector<int>> dp(n, vector<int>(3));
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n;i++){
		if(i == 0){
			if(arr[i] == 1)dp[i][1]++;
			else if(arr[i] == 2)dp[i][2]++;
			else if(arr[i] == 3){
				dp[i][1]++;
				dp[i][2]++;
			}
		}
		else{
			if(arr[i] == 1){
				dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1);
			}
			else if(arr[i] == 2){
				dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
			}
			else if(arr[i] == 3){
				dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1);
				dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
			}	
			dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
		}
	}
	int ans = max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
	cout << n - ans;
}
