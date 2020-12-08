#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	map<ll, ll> m;
	vector<pair<ll, ll>> arr;
	for(ll i = 0;i < n;i++){
		ll t;cin >> t;
		m[t]++;
	}
	for(auto p : m){
		if(p.second >= 2)arr.push_back(p);	
	}
	reverse(arr.begin(), arr.end());
	if(arr.size() >= 1 && arr[0].second >= 4)cout << arr[0].first * arr[0].first;
	else if(arr.size() >= 2)cout << arr[0].first * arr[1].first;
	else cout << 0;
	cout << endl;
}
