#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	for(int q = 0;q < t;q++){
		int n;cin >> n;
		vector<int> arr(n);
		vector<int> diff(n - 1);
		for(int i = 0;i < n;i++)cin >> arr[i];
		int ans = 0;
		int curr = 1;
		for(int i = 0;i < n - 1;i++)diff[i] = arr[i] - arr[i + 1];
		for(int i = 1;i < n - 1;i++){
			if(diff[i] == diff[i - 1])curr++;
			else {
				ans = max(curr, ans);
				curr = 1;
			}
		}
		ans = max(curr, ans);
		cout << "Case #" << q + 1 << ": " << ans + 1 << endl;
	}
}
