#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;cin >> h >> w;
	int ans = 0;
	vector<vector<int>> cost(10, vector<int>(10));
	vector<vector<int>> dp(10, vector<int>(10));
	vector<vector<int>> wall(h, vector<int>(w));
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 10;j++){
			cin >> cost[i][j];
			dp[i][j] = cost[i][j];
		}
	}
	for(int i = 0;i < h;i++)
		for(int j = 0;j < w;j++)
			cin >> wall[i][j];
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 10;j++){
			if(i == j)continue;
			for(int k = 0;k < 10;k++){
				if(k == i || k == j)continue;
				dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
			}
		}
	}
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(wall[i][j] == -1)continue;
			ans += dp[wall[i][j]][1];
		}
	}
	cout << ans << endl;
}
