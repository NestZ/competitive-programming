#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;cin >> n >> k;
	ll ans = 0;
	vector<ll> arr(n);
	vector<ll> pre(n + 1);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 1;i <= n;i++){
		pre[i] = arr[i - 1] + pre[i - 1];
	}
	for(int i = 0;i < n;i++){
		ll r = n;
		ll l = i + 1;
		ll mid = 0;
		ll mn = INT_MAX;
		while(l <= r){
			mid = l + (r - l) / 2;
			if(pre[mid] - pre[i] >= k){
				mn = min(mid, mn);
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if(mn != INT_MAX)ans += n - mn + 1;
	}
	cout << ans << endl;
}
