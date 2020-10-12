#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll x, y, k;cin >> x >> y >> k;
		ll gainpertrade = x - 1;
		ll wantstick = k + (y * k) - 1;
		cout << (gainpertrade + wantstick - 1) / gainpertrade + k;
		cout << endl;
	}
}
