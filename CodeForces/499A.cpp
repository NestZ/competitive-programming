#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;cin >> n >> x;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		arr.push_back({a, b});
	}
	sort(arr.begin(), arr.end());
	int ans = 0;
	int curr = 1;
	for(int i = 0;i < n;i++){
		while(curr + x <= arr[i].first)curr += x;
		ans += arr[i].second - curr + 1;
		curr = arr[i].second + 1;
	}
	cout << ans;
}
