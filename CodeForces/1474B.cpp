#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<bool> p(100001, true);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(ll i = 2;i <= 100000;i++){
		if(p[i]){
			for(ll j = i * i;j <= 100000;j += i)
				p[j] = false;
		}
	}

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll find = 1 + n;
		ll x = 1, y, z;
		while(!p[find])find++;
		y = find;
		find += n;
		while(!p[find])find++;
		z = find;
		cout << (ll)y * (ll)z << endl;
	}
}
