#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(3 * n);
	for(int i = 0;i < 3 * n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	ll ans = 0;
	int cnt = 0;
	for(int i = 3 * n - 2;cnt < n;i -= 2, cnt++){
		ans += arr[i];
	}
	cout << ans << endl;
}
