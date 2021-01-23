#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k;cin >> n >> k;
	ll ans = 0;
	if(k == 0)cout << n * n;
	else{
		for(ll i = k + 1;i <= n;i++){
			ans += (n / i) * (i - k);
			ans += max(0ll, (n % i) - k + 1);
		}
		cout << ans;
	}
	cout << endl;
}
