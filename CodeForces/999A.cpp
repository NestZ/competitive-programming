#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = 0;
	int l = 0;
	for(int i = 0;i < n;i++){
		if(arr[i] <= k)ans++;
		else break;
		l = i;
	}
	for(int i = n - 1;i >= 0 && i > l;i--){
		if(arr[i] <= k)ans++;
		else break;
	}
	cout << ans;
}
