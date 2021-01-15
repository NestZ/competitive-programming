#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll ans = 0;
	for(ll i = 1;i * i < n;i++){
		if((n - i) % i == 0){
			if(i % ((n - i) / i) != 0)
				ans += (n - i) / i;
		}
	}
	cout << ans << endl;
}
