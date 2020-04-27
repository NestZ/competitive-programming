#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<pair<ll ,ll>> arr;
	for(ll i = 0;i < n;i++){
		ll a, b;cin >> a >> b;
		arr.push_back({a, b});
	}
	ll lst = arr[0].first;
	ll ans = 2;
	if(n == 1)ans = 1;
	for(ll i = 1;i < n - 1;i++){
		if(arr[i].first - arr[i].second <= lst){
			if(arr[i].first + arr[i].second < arr[i + 1].first){
				ans++;
				lst = arr[i].first + arr[i].second;
				continue;
			}
		}
		else ans++;
		lst = arr[i].first;
	}
	cout << ans;
}
