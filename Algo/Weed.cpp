#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll ans = 0;
	vector<ll> a(n);
	vector<ll> b(n);
	vector<ll> suf_col(n + 1, 0);
	vector<ll> pre_col(n, 0);
	vector<ll> suf_c_cir(n + 1);
	vector<ll> suf_cc_cir(n + 1);
	vector<vector<ll>> c_cir(2, vector<ll>(n));
	vector<vector<ll>> cc_cir(2, vector<ll>(n));
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	ll c_cnt = 0;
	ll cc_cnt = 2;
	for(int i = 0;i < n;i++){
		c_cir[0][i] = c_cnt * a[i];
		c_cnt++;
		if(i > 0){
			cc_cir[1][i] = cc_cnt * b[i];
			cc_cnt++;
		}
	}
	for(int i = n - 1;i >= 0;i--){
		c_cir[1][i] = c_cnt * b[i];
		c_cnt++;
		if(i > 0){
			cc_cir[0][i] = cc_cnt * a[i];
			cc_cnt++;
		}
	}
	for(int i = n - 1;i >= 0;i--){
		suf_c_cir[i] = suf_c_cir[i + 1] + c_cir[0][i] + c_cir[1][i];
		suf_cc_cir[i] = suf_cc_cir[i + 1] + cc_cir[0][i] + cc_cir[1][i];
	}
	for(int i = n - 1;i >= 0;i--){
		suf_col[i] = suf_col[i + 1] + a[i] + b[i];
	}
	for(ll i = 0;i < n;i++){
		if(i & 1)pre_col[i] += (2 * i + 1) * a[i] + (2 * i) * b[i];
		else pre_col[i] += (2 * i) * a[i] + (2 * i + 1) * b[i];
		if(i > 0)pre_col[i] += pre_col[i - 1];
	}
	for(ll i = 0;i < n;i++){
		ll cur = 0;
		if(i & 1){
			cur = suf_cc_cir[i] + (i - 1) * suf_col[i];
		}
		else{
			cur = suf_c_cir[i] + i * suf_col[i];
		}
		if(i > 0)cur += pre_col[i - 1];
		ans = max(ans, cur);
	}
	cout << ans << endl;
}
