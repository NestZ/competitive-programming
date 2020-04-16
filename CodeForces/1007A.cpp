#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll t;cin >> t;
	while(t--){
		ll a, b, n;cin >> a >> b >> n;
		ll ans = 0;
		if(n & 1LL)ans += (a - b) * (n / 2LL)  + a;
		else ans += (a - b) * n / 2LL;
		cout << ans << endl;
	}
}
