#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;cin >> t;
	while(t--){
		ll n, k;cin >> n >> k;
		ll ans = 0;
		if(n % 2 == 0)ans = n + (2 * k);
		else{
			for(ll j = 2;j * j <= n;j++){
				if(n % j == 0){
					ans = j;
					break;
				}
			}
			if(ans == 0)ans = n;
			n += ans;
			k--;
			n += 2 * k;
			ans = n;
		}
		cout << ans << endl;
	}
}
