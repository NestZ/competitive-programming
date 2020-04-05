#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n, m;cin >> n >> m;
	ll ans = 0;
	ll last = 1;
	while(m--){
		ll t;cin >> t;
		if(t > last)ans += t - last;
		else if(t < last)ans += n - last + t;
		last = t;
	}
	cout << ans;
}
