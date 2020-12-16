#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	string s;cin >> s;
	map<char, ll> cnt;
	for(char c = 'a';c <= 'z';c++)cnt[c]++;
	for(ll i = 0;i < n;i++){
		cnt[s[i]]++;
	}
	ll ans = cnt['a'];
	for(char c = 'b';c <= 'z';c++){
		ans = ans * cnt[c] % MOD;
	}
	cout << ans - 1 << endl;
}
