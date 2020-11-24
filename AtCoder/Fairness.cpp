#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;cin >> a >> b >> c;
	ll k;cin >> k;
	if(k & 1)cout << b - a << endl;
	else cout << a - b << endl;
}
