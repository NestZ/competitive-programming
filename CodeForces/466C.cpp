#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n;cin >> n;
	vector<ll> arr(n);
	ll sum = 0;
	for(ll i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	ll w = sum / 3;
	if(sum % 3 != 0)return cout << 0, 0;
	vector<ll> cnt(n, 0);
	ll curr = 0;
	for(int i = n - 1;i >= 0;i--){
		curr += arr[i];
		if(curr == w)cnt[i]++;
		if(i < n - 1)cnt[i] += cnt[i + 1];
	}
	curr = 0;
	ll ans = 0;
	for(int i = 0;i < n - 2;i++){
		curr += arr[i];
		if(curr == w)ans += cnt[i + 2];
	}
	cout << ans;
}
