#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll ans = 3;
	vector<ll> cnt(100010, 0);
	cnt[0] = 1;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	bool valid = true;
	if(arr[0] != 0)valid = false;
	for(ll i = 1;i < n;i++){
		if(arr[i] == 0)
			ans = ans * (3 - cnt[0]) % MOD;
		else{
			ll rem = cnt[arr[i] - 1] - cnt[arr[i]];
			if(rem <= 0)valid = false;
			ans = ans * rem % MOD;
		}
		cnt[arr[i]]++;
		if(cnt[arr[i]] > 3)valid = false;
	}
	if(!valid)cout << 0 << endl;
	else cout << ans << endl;
}
