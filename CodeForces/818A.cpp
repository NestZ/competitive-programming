#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;cin >> n >> k;
	ll win = n / 2;
	ll a = win / (k + 1);
	ll b = a * k;
	ll c = n - (a + b);
	cout << a << ' ' << b << ' ' << c;
}
