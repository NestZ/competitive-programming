#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll x1 = 1LL;
	ll y1 = 1LL;
	ll x2 = n;
	ll y2 = n;
	ll a, b;cin >> a >> b;
	ll dx1 = abs(x1 - a);
	ll dy1 = abs(y1 - b);
	ll dx2 = abs(x2 - a);
	ll dy2 = abs(y2 - b);
	ll d1 = dx1 + dy1 - min(dx1, dy1);
	ll d2 = dx2 + dy2 - min(dx2, dy2);
	if(d1 <= d2)cout << "White";
	else cout << "Black";
}
