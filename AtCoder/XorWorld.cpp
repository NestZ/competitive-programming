#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<ll> a_cnt(64, 0);
vector<ll> b_cnt(64, 0);
vector<ll> offset(64, 0);
vector<ll> lookup(64, 0);
vector<ll> ans(64, 0);

void cnt(ll n, vector<ll> &arr){
	ll mul = 0;
	for(int i = 63;i >= 0;i--){
		ll f = 1;
		ll nf = 1;
		for(int j = i - 1;j >= 0;j--){
			f += (1ll << j);
			if((1ll << j) & n)
				nf += (1ll << j);
		}
		if((1ll << i) & n)arr[i] = nf + f * mul;
		else arr[i] = f * mul;
		mul = (mul << 1);
		if((1ll << i) & n)mul++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b;cin >> a >> b;
	lookup[0] = lookup[1] = 1;
	for(int i = 2;i < 64;i++)
		lookup[i] = lookup[i - 1] * 2;
	for(int i = 0;i < 64;i++){
		if((1ll << i) & a)
			offset[i]++;
	}
	cnt(a, a_cnt);
	cnt(b, b_cnt);
	ll res = 0;
	for(int i = 0;i < 64;i++){
		ans[i] = b_cnt[i] - a_cnt[i] + offset[i];
		if(ans[i] & 1ll)
			res += (1ll << i);
	}
	cout << res << endl;
}
