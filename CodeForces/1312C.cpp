#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;cin >> t;
	while(t--){
		ll n, k;cin >> n >> k;
		vector<ll> arr(100, 0);
		bool flag = true;
		for(ll i = 0;i < n;i++){
			ll temp;cin >> temp;
			ll cnt = 0;
			while(temp){
				arr[cnt] += temp % k;
				temp /= k;
				if(arr[cnt] >= 2)flag = false;
				cnt++;
			}
		}
		if(flag)cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}
