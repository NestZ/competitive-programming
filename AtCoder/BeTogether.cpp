#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = INT_MAX;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = -100;i <= 100;i++){
		int cur = 0;
		for(int j = 0;j < n;j++){
			cur += pow(arr[j] - i, 2);
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
}
