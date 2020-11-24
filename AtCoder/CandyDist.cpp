#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;cin >> n >> x;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(x < arr[i])break;
		x -= arr[i];
		ans++;
		if(i == n - 1 && x > 0)ans--;
	}
	cout << ans << endl;
}
