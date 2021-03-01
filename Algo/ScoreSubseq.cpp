#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll mx = 0;
	ll mxi = 0;
	vector<ll> arr(n);
	vector<ll> dp(n);
	map<ll, ll> len;
	for(ll i = 0;i < n;i++)cin >> arr[i];
	for(ll i = 0;i < n;i++){
		if(len.count(arr[i] - 1))len[arr[i]] = len[arr[i] - 1] + 1;
		else len[arr[i]] = 1;
		ll temp = len[arr[i]];
		if(temp > mx){
			mx = temp;
			mxi = i;
		}
	}
	ll cur = arr[mxi] - mx + 1;
	cout << mx << endl;
	for(ll i = 0;i < n;i++){
		if(arr[i] == cur){
			cout << i + 1 << ' ';
			cur++;
		}
	}
	cout << endl;
}
