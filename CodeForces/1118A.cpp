#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n, a, b;cin >> n >> a >> b;
		if(a * 2 < b)cout << n * a << endl;
		else cout << n / 2 * b + n % 2 * a << endl;
	}
}
