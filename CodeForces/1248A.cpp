#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll no = 0;
		ll ne = 0;
		for(int i = 0;i < n;i++){
			ll k;cin >> k;
			if(k & 1)no++;
			else ne++;
		}
		ll m;cin >> m;
		ll mo = 0;
		ll me = 0;
		for(ll i = 0;i < m;i++){
			ll k;cin >> k;
			if(k & 1)mo++;
			else me++;
		}
		cout << no * mo + ne * me << endl;
	}
}
