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
		for(int i = 0;i < n;i++)cin >> arr[i];
		ll x = 1;
		while(x < 1000000000)x <<= 1;
		ll all = 0;
		while(x > 0){
			ll cnt = 0;
			for(int i = 0;i < n;i++){
				if((arr[i] & x) > 0 && arr[i] != -1){
					cnt++;
					arr[i] = -1;
				}
			}
			if(cnt > 0)all += cnt * (cnt - 1) / 2;
			x >>= 1;
		}
		cout << all << endl;
	}
}
