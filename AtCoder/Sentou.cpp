#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, t;cin >> n >> t;
	ll start = 0;
	ll cur_e = 0;
	ll ans = 0;
	for(int i = 0;i < n;i++){
		ll num;cin >> num;
		if(num > cur_e){
			ans += cur_e - start;
			start = num;
			cur_e = num + t;
		}
		else cur_e = num + t;
	}
	ans += cur_e - start;
	cout << ans << endl;
}
