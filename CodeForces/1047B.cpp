#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll mx = 0;
	int n;cin >> n;
	while(n--){
		ll a, b;cin >> a >> b;
		mx = max(mx, a + b);
	}
	cout << mx;
}
