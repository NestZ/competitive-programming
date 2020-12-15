#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll lcm(ll a, ll b){
	return b / __gcd(a, b) * a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	ll ans = arr[0];
	for(int i = 1;i < n;i++){
		ans = lcm(ans, arr[i]);
	}
	cout << ans << endl;
}
