#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;cin >> t;
	while(t--){
		ll n;cin >> n;
		vector<ll> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		vector<ll> pre(n + 1);
		vector<ll> suf(n + 1);
		for(int i = 1;i < n;i++){
			pre[i] = pre[i - 1] + (abs(arr[i] - arr[i - 1]));
		}
		for(int i = n - 2;i >= 0;i--){
			suf[i] = suf[i + 1] + (abs(arr[i] - arr[i + 1]));
		}
		ll ans = INT64_MAX;
		for(int i = 0;i < n;i++){
			if(i == 0)ans = min(ans, suf[i + 1]);
			else if(i == n - 1)ans = min(ans, pre[n - 2]);
			else{
				ans = min(ans, pre[i - 1] + suf[i + 1] + (abs(arr[i - 1] - arr[i + 1])));
			}
		}
		cout << ans << endl;
	}
}
