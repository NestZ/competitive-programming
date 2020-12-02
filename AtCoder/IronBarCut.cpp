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
	ll ans = sum;
	for(int i = 0;i < n;i++){
		cur += arr[i];
		ans = min(ans, abs(cur - (sum - cur)));
	}
	cout << ans << endl;
}
