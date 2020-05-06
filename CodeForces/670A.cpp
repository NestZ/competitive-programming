#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int mx = (n / 7 * 2) + min(2, n % 7);
	int mn = (n / 7 * 2) + max(0, n % 7 - 5);
	cout << mn << ' ' << mx;
}
