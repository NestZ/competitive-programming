#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, d;cin >> n >> d;
		vector<int> arr(n);
		int ans = 0;
		for(int i = 0;i < n;i++)cin >> arr[i];
		ans += arr[0];
		for(int i = 1;i < n;i++){
			if(arr[i] > 0){
				if(i * arr[i] <= d){
					d -= i * arr[i];
					ans += arr[i];
				}
				else{
					ans += d / i;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}
