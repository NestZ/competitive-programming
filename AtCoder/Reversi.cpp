#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<int> arr;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(i == 0 || t != arr.back())
			arr.push_back(t);
	}
	int l = arr.size();
	vector<vector<int>> dp(2, vector<int>(l + 1, 0));
	vector<int> lst(200010, -1);
	dp[0][0] = 1;
	for(int i = 1;i <= l;i++){
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
		int last = lst[arr[i - 1]];
		if(last != -1)
			dp[1][i] = (dp[0][last] + dp[1][last]) % MOD;
		lst[arr[i - 1]] = i;
	}
	cout << (dp[0][l] + dp[1][l]) % MOD << endl;
}
