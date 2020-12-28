#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 998244353;

ll mod_pow(ll n, ll e){
	ll ans = n;
	for(int i = 1;i < e;i++){
		ans = ans * n % MOD;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(n);
	vector<ll> cnt(n, 0);
	ll mx = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		mx = max(mx, arr[i]);
		cnt[arr[i]]++;
	}
	bool valid = true;
	ll ans = 1;
	if(cnt[0] != 1 || arr[0] != 0)valid = false;
	for(int i = mx;i > 1;i--){
		if(cnt[i - 1] == 0)valid = false;
		ans = ans * mod_pow(cnt[i - 1], cnt[i]) % MOD;
	}
	if(valid)cout << ans;
	else cout << 0;
	cout << endl;
}
