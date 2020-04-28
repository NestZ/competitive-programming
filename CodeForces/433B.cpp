#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	vector<ll> pre(n + 1, 0);
	for(int i = 1;i <= n;i++){
		if(i == 1)pre[i] = arr[i - 1];
		else pre[i] = pre[i - 1] + arr[i - 1];
	}
	sort(arr.begin(), arr.end());
	vector<ll> prem(n + 1, 0);
	for(int i = 1;i <= n;i++){
		if(i == 1)prem[i] = arr[i - 1];
		else prem[i] = prem[i - 1] + arr[i - 1];
	}
	ll k;cin >> k;
	while(k--){
		ll o;cin >> o;
		ll l, r;cin >> l >> r;
		if(o == 1)cout << pre[r] - pre[l - 1];
		else cout << prem[r] - prem[l - 1];
		cout << endl;
	}
}
