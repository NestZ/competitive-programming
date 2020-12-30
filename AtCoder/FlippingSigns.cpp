#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(n);
	bool z = false;
	ll mn_abs = INT64_MAX;
	ll sum = 0;
	ll minus_cnt = 0;
	for(ll i = 0;i < n;i++){
		cin >> arr[i];
		sum += abs(arr[i]);
		mn_abs = min(mn_abs, abs(arr[i]));
		if(arr[i] < 0)minus_cnt++;
		if(arr[i] == 0)z = true;
	}
	if(z || minus_cnt % 2 == 0)cout << sum;
	else cout << sum - 2 * mn_abs;
	cout << endl;
}
