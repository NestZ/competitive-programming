#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll ans = 0;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	for(ll i = 0;i < n - 1;i++){
		ans += (arr[i] + arr[i + 1]) / 2;
		if((arr[i] + arr[i + 1]) & 1){
			if(arr[i + 1] != 0)
				arr[i + 1] = 1;
		}
		else arr[i + 1] = 0;
	}
	if(n == 1)ans = arr[0] / 2;
	cout << ans << endl;
}
