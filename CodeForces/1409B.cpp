#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	for(ll t = 0;t < n;t++){
		ll a, b, x, y, num;cin >> a >> b >> x >> y >> num;
		if(num >= (a - x) + (b - y))cout << x * y << endl;
		else{
			ll ma = max(a - num, x);
			ll mb = max(b - num, y);
			if(ma < mb){
				ll d1 = min(num, a - x);
				num -= d1;
				a -= d1;
				ll d2 = min(num, b - y);
				b -= d2;
			}
			else{
				ll d1 = min(num, b - y);
				num -= d1;
				b -= d1;
				ll d2 = min(num, a - x);
				a -= d2;
			}
			cout << a * b << endl;
		}
	}
}
