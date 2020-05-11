#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, x;cin >> n >> x;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	ll ans = 0;
	for(int i = 0;i < n;i++){
		ans += max(1LL, x - i) * arr[i];
	}
	cout << ans;
}
