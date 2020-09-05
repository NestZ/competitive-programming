#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 300;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
	string s, t;cin >> s >> t;
	//n ck cnt0
	dp[0][0][0] = 0;
	for(int i = 0;i < n;i++){
		for(int ck = 0;ck <= k;ck++){
			for(int cnt0 = 0;cnt0 <= n;cnt0++){
				int e0 = s[i] == t[0];
				int e1 = s[i] == t[1];
				int e01 = t[0] == t[1];
				//not change i's char
				dp[i + 1][ck][cnt0 + e0] = max(dp[i + 1][ck][cnt0 + e0], dp[i][ck][cnt0] + (e1 ? cnt0 : 0));
				//can change char
				if(ck < k){
					//change i's char to t0
					dp[i + 1][ck + 1][cnt0 + 1] = max(dp[i + 1][ck + 1][cnt0 + 1], dp[i][ck][cnt0] + (e01 ? cnt0 : 0));
					//change i's char to t1
					dp[i + 1][ck + 1][cnt0 + e01] = max(dp[i + 1][ck + 1][cnt0 + e01], dp[i][ck][cnt0] + cnt0);
				}
			}
		}
	}
	int ans = 0;
	for(int ck = 0;ck <= k;ck++){
		for(int cnt0 = 0;cnt0 <= n;cnt0++){
			ans = max(ans, dp[n][ck][cnt0]);
		}
	}
	cout << ans;
}
