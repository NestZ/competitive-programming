#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;cin >> t;
	while(t--){
		ll n;cin >> n;
		if(n == 2){
			ll x, y;cin >> x >> y;
			cout << x << ' ' << y << endl;
		}
		else{
			ll x, y;cin >> x >> y;
			ll diff = y - x;
			ll wide = 0;
			vector<ll> arr;
			arr.push_back(x);
			arr.push_back(y);
			for(ll j = 1;j <= diff;j++){
				if(diff % j != 0)continue;
				if(diff / j + 1 > n)continue;
				wide = j;
				break;
			}
			ll w = n - 2ll;
			for(ll j = x + 1;j < y && w > 0ll;j++){
				if((j - x) % wide == 0){
					w--;
					arr.push_back(j);
				}
			}
			while(w > 0 && (x - wide) > 0){
				x -= wide;
				arr.push_back(x);
				w--;
			}
			while(w > 0){
				y += wide;
				w--;
				arr.push_back(y);
			}
			for(ll j : arr)cout << j << ' ';
			cout << endl;
		}
	}
}
