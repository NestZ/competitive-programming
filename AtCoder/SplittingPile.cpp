#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<ll> arr(n);
	ll sum = 0;
	ll cur = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	ll ans = INT_MAX;
	for(int i = 0;i < n - 1;i++){
		cur += arr[i];
		ans = min(ans, abs(sum - 2 * cur));	
	}
	cout << ans << endl;
}
