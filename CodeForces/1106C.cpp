#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	ll sum = 0;
	vector<ll> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i < n / 2;i++)sum += pow(arr[i] + arr[n - i - 1], 2);
	cout << sum;
}
