#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int currd = arr[n - 1] - arr[0];
	int mx = max(arr[n - 1] - arr[n - 2], arr[1] - arr[0]);
	cout << currd - mx;
}
