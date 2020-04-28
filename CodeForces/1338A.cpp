#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int mx = -1e9;
		int ans = 0;
		for(int i = 0;i < n;i++){
			int k;cin >> k;
			mx = max(mx, k);
			int temp = mx - k;
			if(temp > 0){
				ans = max(ans, 32 - __builtin_clz(temp));
			}
		}
		cout << ans << endl;
	}
}
