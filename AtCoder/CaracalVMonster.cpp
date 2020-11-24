#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll h;cin >> h;
	ll ans = 0;
	for(int i = 0;;i++){
		if(h > 0){
			ans += pow(2, i);
			h >>= 1;
		}
		else break;
	}
	cout << ans << endl;
}
