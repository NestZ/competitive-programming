#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll ans = INT_MAX;
		for(int i = 1;i * i <= 1e9;i++){
			ans = min(ans, i - 1 + ((n - i) + i - 1) / i);  
		}
		cout << ans << endl;
	}
}
