#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fuck(ll a, ll b){
	ll cnta = 0;
	ll cntb = 0;
	while(a > 0){
		cnta++;
		a /= 10;
	}
	while(b > 0){
		cntb++;
		b /= 10;
	}
	return max(cnta, cntb);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll ans = INT64_MAX;
	for(ll i = 1;i * i <= n;i++){
		if(n % i == 0){
			ans = min(ans, fuck(i, n / i));
		}
	}
	cout << ans << endl;
}
