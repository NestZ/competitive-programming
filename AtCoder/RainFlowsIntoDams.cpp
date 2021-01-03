#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll cur = 0;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++){
		cin >> arr[i];
		cur = arr[i] * 2 - cur;
	}
	ll fst = cur / 2;
	for(ll i = 0;i < n;i++){
		cout << fst << ' ';
		fst = arr[i] * 2 - fst;
	}
	cout << endl;
}
