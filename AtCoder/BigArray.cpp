#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;cin >> n >> k;
	map<ll, ll> m;
	for(int i = 0;i < n;i++){
		ll a, b;cin >> a >> b;
		m[a] += b;
	}
	ll ans = 0;
	for(auto p : m){
		k -= p.second;
		if(k <= 0){
			ans = p.first;
			break;
		}
	}
	cout << ans << endl;
}
