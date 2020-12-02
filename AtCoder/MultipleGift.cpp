#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll x, y;cin >> x >> y;
	ll diff = x;
	ll ans = 1;
	ll cur = x;
	while(cur + diff <= y){
		cur += diff;
		diff <<= 1;
		ans++;
	}
	cout << ans << endl;
}
