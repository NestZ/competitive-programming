#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	vector<ll> v(n + 1, 0);
	vector<ll> w(n + 1, 0);
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			ll t;cin >> t;
			v[j] += t;
		}
		ll mx = *max_element(v.begin(), v.end());
		for(int j = 0;j < n;j++){
			if(v[j] == mx){
				w[j]++;
				break;
			}
		}
		v = vector<ll>(n + 1, 0);
	}
	ll mx = *max_element(w.begin(), w.end());
	for(int i = 0;i < n;i++){
		if(w[i] == mx)return cout << i + 1, 0;
	}
}
