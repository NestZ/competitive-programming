#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll l = 1;
	ll r = n;
	ll mid = 0;
	ll ans = INT_MAX;
	while(l <= r){
		mid = l + (r - l) / 2;
		ll cur = mid * (mid + 1) / 2;
		if(cur == n){
			ans = mid;
			break;
		}
		else if(cur < n)l = mid + 1;
		else{
			ans = min(ans, mid);
			r = mid - 1;
		}
	}
	ll ig = ans * (ans + 1) / 2 - n;
	for(int i = 1;i <= ans;i++){
		if(i != ig)
			cout << i << endl;
	}
}
