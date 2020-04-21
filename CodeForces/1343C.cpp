#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool par(ll n){
	return n < 0;
}

int main(){
	ll t;cin >> t;
	while(t--){
		ll n;cin >> n;
		vector<ll> arr(n);
		for(ll i = 0;i < n;i++)cin >> arr[i];
		ll mx = arr[0];
		ll sum = 0;
		for(ll i = 1;i < n;i++){
			if(par(arr[i]) == par(arr[i - 1])){
				mx = max(arr[i], mx);
			}
			else{
				sum += mx;
				mx = arr[i];
			}
		}
		sum += mx;
		cout << sum << endl;
	}
}
