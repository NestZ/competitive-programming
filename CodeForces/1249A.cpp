#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		int ans = 1;
		for(int i = 0;i < n - 1;i++){
			if(arr[i + 1] - arr[i] <= 1)ans = 2;
		}
		cout << ans << endl;
	}
}
