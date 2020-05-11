#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<ll> arr(n);
	ll x = 0;
	ll y = 0;
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.rbegin(), arr.rend());
	for(int i = 0;i < (n + 1) / 2;i++)x += arr[i];
	for(int i = (n + 1) / 2;i < n;i++)y += arr[i];
	cout << x * x + y * y;
}
