#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	for(int i = 0;i < n;i++)arr[i] = a[i] - b[i];
	sort(arr.begin(), arr.end());
	ll ans = 0;
	for(int i = 0;i < n;i++){
		int w = 1 - arr[i];
		auto it = lower_bound(arr.begin() + i + 1, arr.end(), w);
		ans += arr.end() - it;
	}
	cout << ans;
}
