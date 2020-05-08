#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	const ll m = 998244353;
	ll sum = 0;
	ll p = -1;
	ll ans = 1;
	for(int i = 0;i < n;i++){
		ll a;cin >> a;
		if(a >= n - k + 1){
			sum += a;
			if(p != -1)ans = 1LL * ans * (i - p) % m;
			p = i;
		}
	}
	cout << sum << ' ' << ans;
}
