#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b){
	return (b ? gcd(b, a % b) : a);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll l, r;cin >> l >> r;
	for(ll i = l;i <= r - 2;i++){
		for(ll j = i + 1;j <= r - 1;j++){
			if(gcd(i, j) != 1)continue;
			for(ll k = j + 1;k <= r;k++){
				if(gcd(j, k) == 1 && gcd(i, k) != 1)
					return cout << i << ' ' << j << ' ' << k, 0;
			}
		}
	}
	cout << -1;
}
