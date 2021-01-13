#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;cin >> n >> m;
	ll ans = 0;
	set<ll> s;
	for(ll i = 1;i * i <= m;i++){
		if(m % i == 0){
			s.insert(i);
			s.insert(m / i);
		}
	}
	for(ll i : s){
		if(m / i >= n)ans = i;
	}
	cout << ans << endl;
}
