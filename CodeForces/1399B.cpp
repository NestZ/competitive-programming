#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<ll> candy(n);
		vector<ll> orange(n);
		vector<ll> dca(n);
		vector<ll> dor(n);
		for(int i = 0;i < n;i++)cin >> candy[i];
		for(int i = 0;i < n;i++)cin >> orange[i];
		ll mnc = *min_element(candy.begin(), candy.end());
		ll mno = *min_element(orange.begin(), orange.end());
		for(ll i = 0;i < n;i++){
			dca[i] = candy[i] - mnc;
			dor[i] = orange[i] - mno;
		}
		ll ans = 0;
		for(ll i = 0;i < n;i++){
			ans += max(dca[i], dor[i]);
		}
		cout << ans << endl;
	}
}
