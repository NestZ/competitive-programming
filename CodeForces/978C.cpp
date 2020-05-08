#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	vector<ll> d(n);
	for(int i = 0;i < n;i++)cin >> d[i];
	vector<ll> f(n + 1, 0);
	for(int i = 1;i < n + 1;i++){
		f[i] = f[i - 1] + d[i - 1];
	}
	for(int i = 0;i < m;i++){
		ll t;cin >> t;
		ll l = 0;
		ll r = n;
		ll mid = (l + r) / 2;
		while(l <= r){
			mid = (l + r) / 2;
			if(f[mid] < t)l = mid + 1;
			else r = mid - 1;
		}
		cout << l << ' ' << t - f[l - 1] << endl;
	}
}
