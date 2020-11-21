#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	ll mx = 0;
	ll mn = 0;
	for(int i = 0;i < n / 2;i++)mn += arr[i];
	for(int i = n / 2;i < n;i++)mx += arr[i];
	cout << mx - mn << endl;
}
