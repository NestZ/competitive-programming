#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;cin >> n >> k;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	ll sin_inv = 0;
	ll dou_inv = 0;
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[j] < arr[i])sin_inv++;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(arr[j] > arr[i])dou_inv++;
		}
	}
	ll dou_cnt = k * (k - 1) / 2 % MOD;
	ll ans = dou_cnt * dou_inv % MOD + sin_inv * k % MOD;
	cout << ans % MOD << endl;
}
