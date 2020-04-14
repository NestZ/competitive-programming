#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n;cin >> n;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	ll mx = *max_element(arr.begin(), arr.end());
	ll mn = *min_element(arr.begin(), arr.end());
	ll cntmx = 0;
	ll cntmn = 0;
	for(ll i = 0;i < n;i++){
		if(arr[i] == mx)cntmx++;
		if(arr[i] == mn)cntmn++;
	}
	ll w = 0;
	if(mx != mn)w = cntmx * cntmn;
	else w = n * (n - 1) / 2;
	cout << mx - mn << ' ' << w;
}
