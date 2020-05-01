#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		int ans = 0;
		for(int i = n - 1;i >= 0;i--){
			if(arr[i] >= n - i)ans = max(ans, n - i);
		}
		cout << ans << endl;
	}
}
