#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;cin >> n >> k;
	int ans = 0;
	vector<int> pre_wake(n + 1);
	vector<int> pre_all(n + 1);
	vector<int> arr(n);
	vector<bool> wake(n);
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t)wake[i] = true;
		else wake[i] = false;
	}
	for(int i = 1;i <= n;i++){
		pre_all[i] = arr[i - 1] + pre_all[i - 1];
		pre_wake[i] = pre_wake[i - 1];
		if(wake[i - 1])pre_wake[i] += arr[i - 1];
	}
	int cur_sum = 0;
	for(int i = 0;i < n - k + 1;i++){
		int all = pre_all[i + k] - pre_all[i];
		int lst = pre_wake[n] - pre_wake[i + k];
		ans = max(cur_sum + all + lst, ans);
		if(wake[i])cur_sum += arr[i];
	}
	cout << ans << endl;
}
