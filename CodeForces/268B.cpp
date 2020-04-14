#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n;cin >> n;
	ll ans = 0;
	for(ll i = 1;i <= n;i++){
		ans += (n - i) * i;
	}
	cout << ans + n;
}
