#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll ans = 1;
	ll lst = -1;
	bool flag = false;
	for(ll i = 0;i < n;i++){
		ll t;cin >> t;
		if(t == 1){
			flag = true;
			if(lst != -1){
				ans *= i - lst;
				lst = i;
			}
			else lst = i;
		}
	}
	if(!flag)ans = 0;
	cout << ans;
}
