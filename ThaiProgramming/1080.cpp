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
	int ans = 0;
	int cur = 1;
	for(int i = 0;i < n - 2 && i + cur < n;i++){
		int l = i;
		while(i + cur + 1 < n &&
				arr[l] + arr[l + 1] > arr[i + cur + 1]){
			cur++;
			ans = max(cur, ans);
		}
	}
	cout << ans + 1 << endl;
}
