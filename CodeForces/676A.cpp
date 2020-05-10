#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int mn = (min_element(arr.begin(), arr.end()) - arr.begin());
	int mx = (max_element(arr.begin(), arr.end()) - arr.begin());
	if(mx < mn)cout << max(mn, n - mx - 1);
	else cout << max(mx, n - mn - 1);
}
