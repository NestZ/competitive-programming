#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll ans = n / 11 * 2;
	ll rem = n % 11;
	if(rem > 0 && rem > 6)ans += 2;
	else if(rem > 0)ans++;
	cout << ans << endl;
}
