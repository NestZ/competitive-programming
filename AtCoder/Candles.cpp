#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;cin >> n >> k;
	ll neg_cnt = 0;
	ll ans = INT64_MAX;
	vector<ll> arr;
	for(int i = 0;i < n;i++){
		ll num;cin >> num;
		if(num == 0)k--;
		else arr.push_back(num);
		if(num < 0)neg_cnt++;
	}
	if(k == 0)ans = 0;
	else{
		ll start = max(0ll, neg_cnt - k);
		for(int i = start;i + k - 1 < n && i <= neg_cnt;i++){
			ll lc = abs(arr[i]);
			ll rc = abs(arr[i + k - 1]);
			if(arr[i] > 0 && arr[i + k - 1] > 0)
				ans = min(ans, rc);
			else if(arr[i] < 0 && arr[i + k - 1] < 0)
				ans = min(ans, lc);
			else ans = min({ans, 2 * lc + rc, 2 * rc + lc});
		}
	}
	cout << ans << endl;
}
