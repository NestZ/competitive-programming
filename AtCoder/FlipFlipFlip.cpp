#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	ll ans = n * m;
	if(n == 1 && m == 1){
		cout << 1 << endl;
	}
	else if(n == 1 || m == 1){
		cout << max(n, m) - 2 << endl;
	}
	else{
		cout << ans - (2 * (n + m) - 4) << endl;
	}
}
