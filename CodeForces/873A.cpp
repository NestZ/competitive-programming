#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, x;cin >> n >> k >> x;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = n - 1;i >= 0;i--){
		if(arr[i] > x && k > 0){
			arr[i] = x;
			k--;
		}
		else break;
	}
	int ans = 0;
	for(int i = 0;i < n;i++)ans += arr[i];
	cout << ans;
}
