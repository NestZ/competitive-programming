#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	int n = s.length();
	int k;cin >> k;
	int dp[n + 10][k + 10][2];
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= k;j++){
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
		}
	}
	dp[0][0][0] = 1;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= k;j++){
			for(int l = 0;l < 2;l++){
				int lim;
				if(l == 0)lim = s[i] - '0';
				else lim = 9;
				for(int num = 0;num <= lim;num++){
					int ni = i + 1, nl = l, nj = j;
					if(num != 0)nj++;
					if(num < lim)nl = 1;
					dp[ni][nj][nl] += dp[i][j][l];
				}
			}
		}
	}
	cout << dp[n][k][0] + dp[n][k][1] << endl;
}
