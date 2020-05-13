#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;cin >> n >> m >> k;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = INT_MAX;
	for(int i = m;i < n;i++){
		if(arr[i] <= k && arr[i] > 0)ans = min(ans, i - m + 1);
	}
	for(int i = m - 2;i >= 0;i--){
		if(arr[i] <= k && arr[i] > 0)ans = min(ans, abs(i - m + 1));
	}
	cout << ans * 10;			
}
