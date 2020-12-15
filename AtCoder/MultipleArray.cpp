#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	ll ans = 0;
	vector<ll> a(n);
	vector<ll> b(n);
	for(int i = 0;i < n;i++)cin >> a[i] >> b[i];
	for(int i = n - 1;i >= 0;i--){
		a[i] += ans;
		if(a[i] % b[i] == 0)continue;
		ll cur = b[i] - a[i] % b[i];
		ans += cur;
	}
	cout << ans << endl;
}
