#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll ans = 0;
		vector<ll> arr(n);
		vector<ll> mx(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = n - 1;i >= 0;i--){
			mx[i] = arr[i];
			if(i + arr[i] < n)mx[i] += mx[i + arr[i]];
			ans = max(ans, mx[i]);
		}
		cout << ans << endl;
	}
}
