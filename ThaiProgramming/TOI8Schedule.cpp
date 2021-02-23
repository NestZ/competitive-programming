#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;cin >> m >> n;
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1));
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
		cin >> b[i];
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			if(i == 0 && j == 0)dp[i][j] = make_pair(0, 0);
			else if(i == 0){
				dp[i][j] = dp[i][j - 1];
				if(dp[i][j - 1].second + b[j] > m){
					dp[i][j] = make_pair(dp[i][j].first + 1, b[j]);
				}
				else dp[i][j].second = dp[i][j].second + b[j];
			}
			else if(j == 0){
				dp[i][j] = dp[i - 1][j];
				if(dp[i - 1][j].second + a[i] > m){
					dp[i][j] = make_pair(dp[i][j].first + 1, a[i]);
				}
				else dp[i][j].second = dp[i][j].second + a[i];
			}
			else{
				int da = dp[i - 1][j].first;
				int db = dp[i][j - 1].first;
				int lsta = dp[i - 1][j].second;
				int lstb = dp[i][j - 1].second;
				if(dp[i - 1][j].second + a[i] > m){
					da++;
					lsta = a[i];
				}
				else lsta += a[i];
				if(dp[i][j - 1].second + b[j] > m){
					db++;
					lstb = b[j];
				}
				else lstb += b[j];
				if(da > db)dp[i][j] = make_pair(db, lstb);
				else if(db > da)dp[i][j] = make_pair(da, lsta);
				else dp[i][j] = make_pair(da, min(lsta, lstb));
			}
		}
	}
	cout << dp[n][n].first + 1 << endl;
	cout << dp[n][n].second << endl;
}
