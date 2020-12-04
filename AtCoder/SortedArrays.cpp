#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int last = 0;
	int ans = 0;
	for(int i = 1;i < n;i++){
		int cur = arr[i] - arr[i - 1];
		if(cur == 0)continue;
		if((last < 0 && cur > 0) || (last > 0 && cur < 0)){
			ans++;
			last = 0;
		}
		else last = cur;
	}
	cout << ans + 1 << endl;
}
