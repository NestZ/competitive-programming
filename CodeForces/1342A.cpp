#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll ans = 0;
		ll x, y;cin >> x >> y;
		ll a, b;cin >> a >> b;
		if(x < 0 && y > 0 || x > 0 && y < 0){
			ans += a * abs(x) + a * abs(y);
		}
		else{
			x = abs(x);
			y = abs(y);
			if(a * 2LL < b){
				ans = a * x + a * y;
			}
			else{
				ans += min(x, y) * b + a * (max(x, y) - min(x, y));
			}
		}
		cout << ans << endl;
	}
}
