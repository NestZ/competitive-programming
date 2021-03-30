#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	ll ans = 0;
	ll sum = 0;
	ll cur = 0;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr.begin(), arr.end());
	for(int i = 0;i < n - 1;i++){
		cur += arr[i];
		ll more = sum - cur;
		ans += abs(arr[i] * (n - i - 1) - more);
	}
	cout << ans << endl;
}
