#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;cin >> a >> b;
	ll gcd = __gcd(a, b);
	vector<ll> ans;
	ans.push_back(1);
	for(ll i = 2;i * i <= gcd;i++){
		if(gcd % i == 0)ans.push_back(i);
		while(gcd % i == 0)gcd /= i;
	}
	if(gcd > 1)ans.push_back(gcd);
	cout << ans.size() << endl;
}
