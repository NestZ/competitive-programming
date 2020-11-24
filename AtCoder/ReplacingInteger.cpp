#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;cin >> n >> k;
	if(n > k)n -= n / k * k;
	assert(n <= k);
	cout << min(n, k - n) << endl;
}
