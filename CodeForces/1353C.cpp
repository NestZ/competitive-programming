#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll curr = n / 2;
		ll w = n;
		ll ans = 0;
		for(int i = 0;i < n / 2;i++){
			ans += curr * (w * 4 - 4);
			w -= 2;
			curr--;
		}
		cout << ans << endl;
	}
}
