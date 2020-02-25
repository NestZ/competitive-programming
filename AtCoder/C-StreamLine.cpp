#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n,m;cin >> n >> m;
	if(n >= m)return cout << 0, 0;
	vector<int> arr(m);
	int ans = 0;
	for(int i = 0;i < m;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	vector<int> diff;
	for(int i = 1;i < m;i++)diff.push_back(abs(arr[i] - arr[i - 1]));
	sort(diff.begin(), diff.end());
	for(int i = 0;i < m - n;i++)ans += diff[i];
	cout << ans;
}
