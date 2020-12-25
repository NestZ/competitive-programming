#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w;cin >> h >> w;
	vector<vector<char>> arr(h, vector<char>(w));
	vector<vector<int>> dp(h, vector<int>(w, INT_MAX));
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			cin >> arr[i][j];
		}
	}
	if(arr[0][0] == '#')dp[0][0] = 1;
	else dp[0][0] = 0;
	for(int i = 1;i < h;i++){
		if(arr[i][0] == '#' && arr[i - 1][0] != '#'){
			dp[i][0] = dp[i - 1][0] + 1;
		}
		else dp[i][0] = dp[i - 1][0];
	}
	for(int i = 1;i < w;i++){
		if(arr[0][i] == '#' && arr[0][i - 1] != '#'){
			dp[0][i] = dp[0][i - 1] + 1;
		}
		else dp[0][i] = dp[0][i - 1];
	}
	for(int i = 1;i < h;i++){
		for(int j = 1;j < w;j++){
			int up = dp[i - 1][j];
			int left = dp[i][j - 1];
			if(arr[i][j] == '#' && arr[i - 1][j] != '#')
				up++;
			if(arr[i][j] == '#' && arr[i][j - 1] != '#')
				left++;
			dp[i][j] = min(up, left);
		}
	}
	cout << dp[h - 1][w - 1] << endl;
}
