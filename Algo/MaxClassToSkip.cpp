#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int inf = 1e9;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;cin >> n >> m >> k;
	vector<vector<int>> mn_hr(n + 1, vector<int>(k + 1, inf));
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf));
	for(int i = 0;i <= k;i++)dp[0][i] = 0;
	for(int i = 1;i <= n;i++){
		string s;cin >> s;
		int cnt = 0;
		vector<int> ind;
		for(int j = 0;j < m;j++){
			if(s[j] == '1'){
				ind.push_back(j);
				cnt++;
			}
		}
		if(cnt != 0)mn_hr[i][0] = ind[cnt - 1] - ind[0] + 1;
		else mn_hr[i][0] = 0;
		for(int j = 1;j <= k;j++){
			if(cnt == 0)mn_hr[i][j] = 0;
			else{
				for(int l = 0;l <= j;l++){
					int ptr_l = l;
					int ptr_r = cnt - (j - l) - 1;
					if(ptr_r >= ptr_l)mn_hr[i][j] = min(mn_hr[i][j], ind[ptr_r] - ind[ptr_l] + 1);
					else mn_hr[i][j] = 0;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= k;j++){
			for(int td = 0;td <= j;td++){
				dp[i][j] = min(mn_hr[i][td] + dp[i - 1][j - td], dp[i][j]);
			}
		}
	}
	cout << dp[n][k] << endl;
}
