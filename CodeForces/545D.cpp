#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n;cin >> n;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	ll sum = 0;
	ll ans = 0;
	for(ll i = 0;i < n;i++){
		if(arr[i] >= sum){
			ans++;
			sum += arr[i];
		}
	}
	cout << ans;
}
