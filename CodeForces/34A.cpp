#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int mn = INT_MAX;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(abs(arr[i] - arr[(i + 1) % n]) < mn){
			ans = i;
			mn = abs(arr[i] - arr[(i + 1) % n]);
		}
	}
	cout << ans + 1 << ' ';
	if(ans + 2 == n + 1)cout << 1;
	else cout << ans + 2;
}
