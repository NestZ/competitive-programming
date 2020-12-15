#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll sum = 0;
		vector<ll> arr(n);
		vector<ll> pre(n);
		set<ll> factor;
		map<ll, int> m;
		//find sum and prefix sum arr
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			sum += arr[i];
		}
		for(int i = 0;i < n;i++){
			pre[i] = arr[i];
			if(i > 0)pre[i] += pre[i - 1];
			m[pre[i]]++;
		}
		//interger factoring
		for(ll i = 1;i * i <= sum;i++){
			if(sum % i == 0){
				factor.insert(i);
				factor.insert(sum / i);
			}
		}
		//calculate answer
		ll ans = INT64_MAX;
		for(ll f : factor){
			ll div = sum / f; 
			if(f > n)break;
			bool valid = true;
			for(ll i = 1;i <= f;i++){
				if(m.count(i * div) == 0)valid = false;
			}
			if(valid)ans = min(ans, n - f);
		}
		if(ans == INT64_MAX)cout << n - 1;
		else cout << ans;
		cout << endl;
	}
}
