#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		string u, d;cin >> u >> d;
		//row, col, dir
		bool dp[2][n + 1][3];
		for(int i = 0;i < 2;i++)
			for(int j = 0;j <= n;j++)
				for(int k = 0;k < 3;k++)
					dp[i][j][k] = false;
		//0: u 1: d 2: r
		dp[0][0][2] = true;
		for(int i = 1;i <= n;i++){
			if(u[i - 1] > '2'){
				dp[0][i][1] = dp[0][i - 1][2];
			}
			if(d[i - 1] > '2'){
				dp[1][i][0] = dp[1][i - 1][2];
			}
			if(u[i - 1] <= '2'){
				dp[0][i][2] = dp[0][i - 1][2];
			}
			else{
				dp[0][i][2] = dp[1][i][0];
			}
			if(d[i - 1] <= '2'){
				dp[1][i][2] = dp[1][i - 1][2];
			}
			else{
				dp[1][i][2] = dp[0][i][1];
			}
		}
		if(dp[1][n][2])cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
