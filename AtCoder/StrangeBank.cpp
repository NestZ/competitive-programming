#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<int> dp(n + 1, 1e9);
	vector<int> cnt;
	for(int i = 1;pow(6, i) <= 100010;i++){
		cnt.push_back(pow(6, i));
	}
	for(int i = 1;pow(9, i) <= 100010;i++){
		cnt.push_back(pow(9, i));
	}
	for(int i = 0;i <= n;i++)dp[i] = i;
	for(int i = 1;i <= n;i++){
		for(int j : cnt){
			if(i - j < 0)continue;
			dp[i] = min(dp[i], dp[i - j] + 1);
		}
	}
	cout << dp[n] << endl;
}
