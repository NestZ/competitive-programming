#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int ans = 0;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		for(int i = 1;i <= n;i++){
			if(arr[i - 1] <= i)ans = i;
		}
		cout << ans + 1 << endl;
	}
}
