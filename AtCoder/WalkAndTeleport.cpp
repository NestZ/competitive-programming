#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, a, b;cin >> n >> a >> b;
	vector<ll> arr(n);
	ll ans = 0;
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n - 1;i++){
		ll diff = arr[i + 1] - arr[i];
		ans += min(diff * a, b);
	}
	cout << ans << endl;
}
