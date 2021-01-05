#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		ll n, x;cin >> n >> x;
		vector<ll> arr(n);
		ll mn = 0, mx = 0;
		ll sum = 0;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			mx += (arr[i] + x - 1) / x;
			sum += arr[i];
		}
		mn = (sum + x - 1) / x;
		cout << mn << ' ' << mx << endl;
	}
}
