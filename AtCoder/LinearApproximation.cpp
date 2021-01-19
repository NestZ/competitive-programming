#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int med = 0;
	ll ans = 0;
	vector<int> arr(n);
	vector<int> diff(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 1;i <= n;i++){
		diff[i - 1] = arr[i - 1] - i;
	}
	sort(diff.begin(), diff.end());
	med = diff[n / 2];
	for(int i = 0;i < n;i++){
		ans += abs(arr[i] - (med + i + 1));
	}
	cout << ans << endl;
}
