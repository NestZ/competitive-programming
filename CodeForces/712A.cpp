#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	vector<int> ans(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	ans[n - 1] = arr[n - 1];
	for(int i = n - 2;i >= 0;i--){
		ans[i] = arr[i] + arr[i + 1];
	}
	for(int i : ans)cout << i << ' ';
}
