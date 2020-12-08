#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, p;cin >> n >> p;
	ll odd = 0;
	ll even = 0;
	for(ll i = 0;i < n;i++){
		ll t;cin >> t;
		if(t & 1)odd++;
		else even++;
	}
	if(odd > 0){
		printf("%lld\n", (ll)pow(2ll, n - 1));
	}
	else{
		if(p & 1 ^ 1)
			printf("%lld\n", (ll)pow(2ll, n));
		else printf("0\n");
	}
}
