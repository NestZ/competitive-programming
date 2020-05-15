#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	for(ll i = n - 2;i >= 0;i--){
		arr[i] = min(arr[i], max(0LL, arr[i + 1] - 1));
	}
	ll ans = 0;
	for(ll i = 0;i < n;i++)ans += arr[i];
	cout << ans;
}
