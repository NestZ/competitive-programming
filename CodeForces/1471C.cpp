#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		ll n, m;cin >> n >> m;
		ll ans = 0;
		vector<ll> f(n);
		vector<ll> c(m);
		vector<ll> as(n);
		for(int i = 0;i < n;i++)cin >> f[i];
		for(int i = 0;i < m;i++)cin >> c[i];
		sort(f.begin(), f.end());
		ll ptr = 0;
		for(int i = n - 1;i >= 0;i--){
			if(ptr < m && c[f[i] - 1] > c[ptr]){
				as[i] = c[ptr];
				ptr++;
			}
			else as[i] = c[f[i] - 1];
		}
		for(ll i : as)ans += i;
		cout << ans << endl;
	}
}
