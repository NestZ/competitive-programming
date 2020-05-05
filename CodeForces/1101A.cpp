#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll l, r, d;cin >> l >> r >> d;
		ll curr = r;
		if(l > d)curr = d;
		else if(r >= d){
			int k = (curr + d - 1) / d;
			curr = d * k;
			if(curr == r)curr += d;
		}
		else if(d > r)curr = d;
		cout << curr << endl;
	}
}
