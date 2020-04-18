#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	ll ans = 0;
	ll m = 0;
	ll z = 0;
	for(int i = 0;i < n;i++){
		ll t;cin >> t;
		if(t < 0)m++;
		if(t == 0)z++;
		ans += abs(1 - t);
	}
	if(m & 1 && z > 0){
		ans -= 2;
		m--;
	}
	ans -= m * 2;
	if(m & 1)ans += 2;
	cout << ans;
}
