#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll h, w;cin >> h >> w;
	ll ans = h * w;
	if(h == 1 || w == 1)cout << 1;
	else cout << (ans + 1) / 2;
}
