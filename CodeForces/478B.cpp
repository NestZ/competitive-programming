#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n, m;cin >> n >> m;
	ll permn = n / m;
	ll permx = (n + m - 1) / m;
	ll ntmn = m - (n % m);
	ll ntmx = n % m;
	ll mint = permx * (permx - 1) / 2 * ntmx + permn * (permn - 1) / 2 * ntmn;
	ll maxx = (n - m + 1) * (n - m) / 2;
	cout << mint << ' ' << maxx;
}
