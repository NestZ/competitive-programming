#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	if(n == 1)cout << 9 << ' ' << 8;
	else cout << n * 10 + n << ' ' << n * 10;
}
