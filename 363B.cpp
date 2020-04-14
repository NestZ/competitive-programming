#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, k;cin >> n >> k;
	vector<int> arr(n);
	vector<int> pre(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(i == 0)pre[i] = arr[i];
		else pre[i] = arr[i] + pre[i - 1];
	}
	int mn = pre[k - 1];
	int ans = 1;
	for(int i = 1;i + k - 1 < n;i++){
		if(pre[i + k - 1] - pre[i - 1] < mn){
			mn = pre[i + k - 1] - pre[i - 1];
			ans = i + 1;
		}
	}
	cout << ans;
}
