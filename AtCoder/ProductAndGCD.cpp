#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, p;cin >> n >> p;
	if(n == 1)cout << p;
	else if(p == 1)cout << 1;
	else{
		ll ans = 0;
		for(ll i = 1;;i++){
			if(pow(i, n) > p)break;	
			if(p % (ll)pow(i, n) == 0)ans = i;
		}
		cout << ans;
	}
	cout << endl;
}
