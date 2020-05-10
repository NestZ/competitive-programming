#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll lcm(ll a, ll b){
	return a * b / __gcd(a, b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll mn = INT64_MAX;
	ll ansa = 0;
	ll ansb = 0;
	for(ll i = 1;i * i <= n;i++){
		ll a = i;
		ll b = n / a;
		if(lcm(a, b) != n)continue;
		if(max(a, b) < mn){
			mn = max(a, b);
			ansa = a;
			ansb = b;
		}
	}
	cout << ansa << ' ' << ansb;
}
