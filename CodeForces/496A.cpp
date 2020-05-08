#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = INT_MAX;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 1;i < n - 1;i++){
		int curr = INT_MIN;
		for(int j = 0;j < n - 1;j++){
			if(j == i)continue;
			if(j + 1 == i)curr = max(curr, abs(arr[j] - arr[j + 2]));
			else curr = max(curr, abs(arr[j] - arr[j + 1]));
		}
		ans = min(curr, ans);
	}
	cout << ans;
}
