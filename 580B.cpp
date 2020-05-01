#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, d;cin >> n >> d;
	vector<pair<ll, ll>> arr;
	for(int i = 0;i < n;i++){
		ll a, b;cin >> a >> b;
		arr.push_back({a, b});
	}
	sort(arr.begin(), arr.end());
	ll ans = 0;
	ll sum = 0;
	int l = 0;
	int r = 0;
	while(r < n && l < n){
		if(arr[r].first - arr[l].first < d){
			sum += arr[r].second;
			ans = max(ans, sum);
			r++;
		}
		if(r >= n)break;
		if(arr[r].first - arr[l].first >= d){
			sum -= arr[l].second;
			l++;
		}
	}
	cout << ans;
}
