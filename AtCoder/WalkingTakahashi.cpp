#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll x, k, d;cin >> x >> k >> d;
	ll w = abs(x) / d;
	ll cur = abs(x) - min(k, w) * d;
	if(k <= w)cout << cur;
	else{
		k -= w;
		if(k & 1)cout << abs(cur - d);
		else cout << cur;
	}
	cout << endl;
}
