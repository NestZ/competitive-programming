#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll x;cin >> x;
		ll s = 1;
		ll ans = 0;
		while(x >= s * ((s + 1) / 2)){
			ans++;
			x -= s * ((s + 1) / 2);
			s = s * 2 + 1;
		}
		cout << ans << endl;
	}
}
