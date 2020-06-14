#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll a, b, c, d;cin >> a >> b >> c >> d;
		if(b >= a)cout << b;
		else{
			if(c <= d)cout << -1;
			else{
				ll w = a - b;
				ll r = (w + (c - d - 1)) / (c - d);
				cout << b + (r * c);
			}
		}
		cout << endl;
	}
}
