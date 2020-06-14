#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll sum = 0;
	for(ll i = 0;i < n - 1;i++){
		ll t;cin >> t;
		sum += t;
	}
	cout << n * (n + 1) / 2 - sum;
}
