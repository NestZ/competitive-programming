#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n, g, b;cin >> n >> g >> b;
		ll needG = (n + 1) / 2LL;
		ll totalG = needG / g * (b + g);
		if(needG % g == 0)totalG -= b;
		else totalG += needG % g;
		cout << max(n, totalG) << endl;
	}
}
