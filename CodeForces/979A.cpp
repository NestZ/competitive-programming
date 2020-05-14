#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	n++;
	if(n - 1 == 0)cout << 0;
	else if(n & 1 ^ 1)cout << n / 2LL;
	else cout << n;
}
