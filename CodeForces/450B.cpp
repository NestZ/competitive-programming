#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll x, y;cin >> x >> y;
	const ll m = 1e9 + 7;
	ll n;cin >> n;
	n--;
	ll ans = 0;
	if(n % 6 == 0)ans = x;
	else if(n % 6 == 1)ans = y;
	else if(n % 6 == 2)ans = y - x;
	else if(n % 6 == 3)ans = -x;
	else if(n % 6 == 4)ans = -y;
	else if(n % 6 == 5)ans = x - y;
	cout << (ans + 3 * m) % m;
}
