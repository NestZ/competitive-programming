#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int ans = 0;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 0;i <= 100;i++){
			vector<bool> u(n, false);
			int cnt = 0;
			for(int j = 0;j < n - 1;j++){
				for(int k = j + 1;k < n;k++){
					if(u[j] || u[k])continue;
					if(arr[j] + arr[k] == i){
						cnt++;
						u[j] = true;
						u[k] = true;
					}
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
}
