#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		vector<int> freq(2 * k + 1, 0);
		for(int i = 0;i < n / 2;i++){
			freq[arr[i] + arr[n - i - 1]]++;
		}
		vector<int> pre(2 * k + 2, 0);
		for(int i = 0;i < n / 2;i++){
			int l = min(arr[i], arr[n - i - 1]) + 1;
			int r = max(arr[i] + k, arr[n - i - 1] + k);
			pre[l]++;
			pre[r + 1]--;
		}
		for(int i = 1;i < 2 * k + 2;i++){
			pre[i] += pre[i - 1];
		}
		int ans = INT_MAX;
		for(int i = 2;i <= 2 * k;i++){
			ans = min(ans, pre[i] - freq[i] + (n / 2 - pre[i]) * 2);
		}
		cout << ans << endl;
	}
}
