#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;cin >> a >> b;
	int al = a.length();
	int bl = b.length();
	vector<vector<int>> dp(al + 1, vector<int>(bl + 1, 0));
	string ans;
	int mx = 0;
	for(int i = 1;i <= al;i++){
		for(int j = 1;j <= bl;j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if(dp[i][j] > mx){
					mx = dp[i][j];
					ans = a.substr(i - mx, mx);
				}
			}
		}
	}
	cout << ans;
}
