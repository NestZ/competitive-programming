#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	ll ans = 0;
	for(ll i = 1;i <= n;i++){
		ans += abs(i - arr[i - 1]);
	}
	cout << ans;
}
