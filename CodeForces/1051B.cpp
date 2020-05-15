#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll l, r;cin >> l >> r;
	cout << "YES" << endl;
	for(ll i = l;i <= r;i += 2LL){
		cout << i << ' ' << i + 1LL << endl;
	}
}
