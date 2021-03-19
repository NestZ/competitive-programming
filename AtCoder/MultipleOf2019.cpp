#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int MOD = 2019;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	ll n = s.length();
	ll p = 1;
	ll rem = 0;
	ll ans = 0;
	vector<int> cnt(2019);
	cnt[0] = 1;
	for(int i = n - 1;i >= 0;i--){
		ll d = s[i] - '0';
		rem = (rem + (p * d % MOD)) % MOD;
		ans += cnt[rem];
		cnt[rem]++;
		p = p * 10 % MOD;
	}
	cout << ans << endl;
}
