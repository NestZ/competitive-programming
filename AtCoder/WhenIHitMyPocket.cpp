#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll k, a, b;cin >> k >> a >> b;
	ll bis = 1;
	ll all = bis + k;
	if(a >= b)cout << all << endl;
	else if(a > k + 1)cout << all << endl;
	else{
		if(bis < a){
			k -= a - bis;
			bis = a;
			assert(k >= 0);
		}
		if(k & 1){
			bis++;
			k--;
		}
		bis += (b - a) * (k / 2);
		cout << max(bis, all) << endl;
	}
}
