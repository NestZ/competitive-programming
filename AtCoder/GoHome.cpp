#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll h = n;
	ll l = 0;
	ll ans = INT_MAX;
	while(l <= h){
		ll mid = l + (h - l) / 2;
		ll cur = mid * (mid + 1) / 2;
		if(cur == n){
			ans = mid;
			break;
		}
		else if(cur < n)l = mid + 1;	
		else{
			h = mid - 1;
			ans = min(ans, mid);
		}
	}
	cout << ans << endl;
}
