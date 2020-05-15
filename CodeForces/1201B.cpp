#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> arr(n);
	ll sum = 0;
	for(ll i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr.begin(), arr.end());
	if(sum % 2 == 0 && arr[n - 1] <= sum - arr[n - 1])cout << "YES";
	else cout << "NO";
}
