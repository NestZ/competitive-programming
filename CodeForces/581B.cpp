#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	vector<int> ans(n, 0);
	int curr = arr[n - 1];
	for(int i = n - 2;i >= 0;i--){
		if(arr[i] <= curr)ans[i] = curr - arr[i] + 1;
		else curr = arr[i];
	}
	for(int i : ans)cout << i << ' ';
}
