#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		ll w = 5 - (i % 5);
		if(w == 0)w = 5;
		if(m - w >= 0)ans += (m - w) / 5 + 1;
	}
	cout << ans;
}
