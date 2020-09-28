#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll fac = 1;
	ll pw = 1;
	for(ll i = 1;i < n;i++){
		pw *= 2;
		pw %= mod;
		fac *= i;
		fac %= mod;
	}
	fac *= n;
	fac %= mod;
	fac += mod;
	fac -= pw;
	cout << fac % mod;
}
