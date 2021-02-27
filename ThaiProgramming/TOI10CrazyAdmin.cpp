#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;cin >> m >> n;
	int mx = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	int l = mx;
	int r = 1e7;
	int ans = 1e7;
	while(l <= r){
		int mid = l + (r - l) / 2;
		int cur_sum = 0;
		int cnt = 1;
		for(int i = 0;i < n;i++){
			if(cur_sum + arr[i] <= mid)cur_sum += arr[i];
			else{
				cur_sum = arr[i];
				cnt++;
			}
		}
		if(cnt <= m){
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << endl;
}
