#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll s;cin >> s;
	ll x2 = 1e9;
	ll x3 = (x2 - s % x2) % x2;
	ll y3 = (s + x3) / x2;
	printf("0 0 1000000000 1 %lld %lld \n", x3, y3);
}
