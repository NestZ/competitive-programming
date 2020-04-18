#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll t;cin >> t;
	while(t--){
		ll n, x;cin >> n >> x;
		vector<ll> arr(n);
		for(ll i = 0;i < n;i++)cin >> arr[i];
		sort(arr.rbegin(), arr.rend());
		ll sum = 0;
		ll i = 0;
		for(i = 0;i < n;i++){
			sum += arr[i];
			if(sum / (i + 1) < x)break;
		}
		cout << i << endl;
	}
}
