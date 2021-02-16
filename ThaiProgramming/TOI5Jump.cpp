#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = 0;
	for(int i = 0;i < n - 1;i++){
		int cur = arr[i] + k;
		int l = i;
		int r = n - 1;
		int mx = 0;
		while(l <= r){
			int mid = l + (r - l) / 2;
			if(arr[mid] <= cur){
				l = mid + 1;
				mx = max(mx, mid);
			}
			else r = mid - 1;
		}
		ans = max(ans, mx - i);
	}
	cout << ans << endl;
}
