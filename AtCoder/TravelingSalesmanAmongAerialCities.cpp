#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<vector<int>> dist(n, vector<int>(n));
	vector<tuple<int, int, int>> pos;
	vector<vector<int>> dp(n, vector<int>(1 << n, 2e9));
	dp[0][0] = 0;
	for(int i = 0;i < n;i++){
		int x, y, z;cin >> x >> y >> z;
		pos.emplace_back(x, y, z);
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i == j)continue;
			dist[i][j] = abs(get<0>(pos[i]) - get<0>(pos[j])) +
									abs(get<1>(pos[i]) - get<1>(pos[j])) +
									max(0, get<2>(pos[j]) - get<2>(pos[i]));
		}
	}
	for(int i = 0;i < (1 << n);i++){
		for(int j = 0;j < n;j++){
			for(int k = 0;k < n;k++){
				if(j != k && dp[j][i] != 2e9){
					dp[k][i | (1 << k)] = min(dp[k][i | (1 << k)], dp[j][i] + dist[j][k]);
				}
			}
		}
	}
	cout << dp[0][(1 << n) - 1] << endl;
}
