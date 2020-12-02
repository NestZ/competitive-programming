#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr(3);
	for(int i = 0;i < 3;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = arr[2] - arr[1];
	arr[1] += ans;
	arr[0] += ans;
	int diff = arr[2] - arr[0];
	ans += diff / 2;
	if(diff & 1)ans += 2;
	cout << ans << endl;
}
