#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		vector<vector<int>> dp(n + 1, vector<int>(2, 1e9 + 5));
		for(int i = 0;i < n;i++)cin >> arr[i];
		dp[0][1] = 0;
		for(int i = 0;i < n;i++){
			for(int w = 0;w < 2;w++){
				for(int f = 1;f <= min(2, n - i);f++){
					int h = arr[i] + (f > 1 ? arr[i + 1] : 0);
					dp[i + f][!w] = min(dp[i + f][!w], dp[i][w] + w * h);
				}
			}
		}
		cout << min(dp[n][0], dp[n][1]) << endl;
	}
}
