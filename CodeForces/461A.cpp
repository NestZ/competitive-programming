#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		ans += arr[i - 1] * (i + 1);
	}
	ans -= arr[n - 1];
	cout << ans;
}
