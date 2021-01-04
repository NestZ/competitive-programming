#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		ll a, b;cin >> a >> b;
		ll ans = INT64_MAX;
		if(a == b)ans = 0;
		for(ll i = 1;;i++){
			ll cur = i * (i + 1) / 2;
			if((cur + a + b) % 2 == 0 && (cur + a + b) / 2 >= max(a, b)){
				ans = min(ans, i);
				break;
			}
		}
		cout << ans << endl;
	}
}
