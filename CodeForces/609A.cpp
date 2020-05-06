#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = 0;
	int curr = 0;
	for(int i = n - 1;i >= 0;i--){
		curr += arr[i];
		ans++;
		if(curr >= m)break;
	}
	cout << ans;
}
