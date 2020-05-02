#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		vector<ll> arr(n);
		ll sum = 0;
		for(int i = 1;i <= n;i++){
			arr[i - 1] = pow(2, i);
			sum += arr[i - 1];
		}
		ll ans = arr[n - 1];
		ll w = n / 2 - 1;
		for(ll i = 0;i < w;i++){
			ans += arr[i];
		}
		ll r = ans - (sum - ans);
		cout << r << endl;
	}
}
