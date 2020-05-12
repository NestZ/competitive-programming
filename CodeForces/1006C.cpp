#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	ll l = 0;
	ll r = n - 1;
	ll suml = 0;
	ll sumr = 0;
	ll ans = 0;
	while(l <= r){
		if(suml <= sumr)suml += arr[l++];
		else sumr += arr[r--];
		if(suml == sumr)ans = suml;
	}
	cout << ans;
}
