#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		int cnt1 = 0;
		int cnt2 = 0;
		int ans = 0;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(arr[i] % 3 == 1)cnt1++;
			else if(arr[i] % 3 == 2)cnt2++;
			else ans++;
		}
		int temp = min(cnt1, cnt2);
		cnt1 -= temp;
		cnt2 -= temp;
		ans += temp;
		ans += cnt1 / 3;
		ans += cnt2 / 3;
		cout << ans << endl;
	}
}
