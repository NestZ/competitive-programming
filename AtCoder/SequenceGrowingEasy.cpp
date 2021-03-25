#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	ll ans = 0;
	bool valid = true;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(i > 0 && arr[i] - arr[i - 1] > 1)
			valid = false;
	}
	if(arr[0] != 0)valid = false;
	arr.push_back(0);
	for(int i = 1;i <= n;i++){
		if(arr[i] <= arr[i - 1]){
			ans += arr[i - 1];
		}
	}
	if(valid)cout << ans;
	else cout << -1;
	cout << endl;
}
