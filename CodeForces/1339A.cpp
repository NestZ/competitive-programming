#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll t;cin >> t;
	while(t--){
		ll n;cin >> n;
		if(n & 1)cout << 2LL * (n / 2LL) + 1 << endl;
		else cout << 2LL * (n / 2LL) << endl;
	}
}
