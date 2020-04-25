#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		int mn = arr[n - 1];
		int ans = 0;
		for(int i = n - 2;i >= 0;i--){
			if(arr[i] > mn)ans++;
			else if(arr[i] < mn)mn = arr[i];
		}
		cout << ans << endl;
	}
}
