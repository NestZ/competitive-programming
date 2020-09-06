#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll t;cin >> t;
	while(t--){
		ll n;cin >> n;
		vector<ll> arr(n);
		for(ll i = 0;i < n;i++)cin >> arr[i];
		ll ans = 0;
		for(ll i = 0;i < n;i++){
			ans += arr[i];
			ans = max(0ll, ans);
		}
		cout << ans << endl;
	}
}
