#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		vector<int> arr(3);
		int ans = 0;
		for(int i = 0;i < 3;i++)cin >> arr[i];
		for(int i = 0;i < 3;i++){
			if(arr[i]){
				arr[i]--;
				ans++;
			}
		}
		sort(arr.rbegin(), arr.rend());
		for(int i = 0;i < 3;i++){
			if(arr[i] && arr[(i + 1) % 3]){
				arr[i]--; arr[(i + 1) % 3]--;
				ans++;
			}
		}
		if(arr[0] && arr[1] && arr[2])ans++;
		cout << ans << endl;
	}
}
