#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n, k;cin >> n >> k;
	ll m = k;
	int ans = 0;
	if(n < k)return cout << n, 0;
	while(k <= n){
		k *= m;
		ans++;
	}
	cout << ans + 1;
}
