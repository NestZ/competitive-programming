#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(n);
	ll sum = 0;
	vector<ll> odd;
	for(ll i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
		if(arr[i] & 1LL)odd.push_back(arr[i]);
	}	
	if(odd.size() & 1LL)sum -= *min_element(odd.begin(), odd.end());
	cout << sum;
}
