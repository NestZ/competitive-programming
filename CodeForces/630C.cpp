#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		ans += pow(2LL, i);
	}
	cout << ans;
}
