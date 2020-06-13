#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, t;cin >> n >> k >> t;
	if(t <= k)cout << t;
	else if(t > n)cout << k - (t - n);
	else cout << k;
}
