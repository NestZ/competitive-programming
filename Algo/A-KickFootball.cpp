#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		ll n, x;cin >> n >> x;
		ll mx = 0;
		bool valid = false;
		for(int i = 0;i < n;i++){
			ll num;cin >> num;
			mx = max(mx, num);
			if(num == x)valid = true;
		}
		if(valid)cout << 1;
		else if(mx <= x)cout << (x + mx - 1) / mx;
		else cout << 2;
		cout << endl;
	}
}
