#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a, b, c, d;cin >> a >> b >> c >> d;
	int mx = min({a, c, d});
	a -= mx;
	c -= mx;
	d -= mx;
	int ans = mx * 256;
	mx += min(a, b);
	ans += 32 * min(a, b);
	cout << ans;
}
