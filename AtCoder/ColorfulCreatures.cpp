#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll cur = 0;
	ll cnt = 0;
	ll cut = 0;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i < n - 1;i++){
		cur += arr[i];
		cnt++;
		if(arr[i + 1] > 2 * cur)cut = cnt;
	}
	cout << n - cut << endl;
}
