#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, t;cin >> n >> t;
	vector<int> arr(n);
	vector<int> pre(n + 1, 0);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n;i++){
		pre[i + 1] = arr[i] + pre[i];
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		int b = i;
		for(int k = (n - i) / 2;k > 0;k /= 2){
			while(b + k < n && pre[b + k + 1] - pre[i] <= t)
				b += k;
		}
		if(pre[b + 1] - pre[i] <= t)ans = max(ans, b - i + 1);
	}
	cout << ans;
}
