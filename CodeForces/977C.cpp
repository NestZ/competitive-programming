#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	if(k == n)return cout << arr[n - 1], 0;
	if(k == 0 && arr[0] == 1)return cout << -1, 0;
	if(arr[k] == arr[k - 1])return cout << -1, 0;
	cout << arr[k] - 1;
}
