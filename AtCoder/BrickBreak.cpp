#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int cur = 1;
	for(int i = 0;i < n;i++){
		if(arr[i] == cur)cur++;
	}
	int ans = n - (cur - 1);
	if(ans == n)cout << -1;
	else cout << ans;
	cout << endl;
}
