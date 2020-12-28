#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll ans = 0;
	ll cur = 10;
	if(n & 1)cout << 0;
	else{
		while(cur <= n){
			ans += n / cur;
			cur *= 5;
		}
		cout << ans;
	}
	cout << endl;
}
