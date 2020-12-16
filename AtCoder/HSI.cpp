#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int each = 1900 * m + 100 * (n - m);
	int round = pow(2, m);
	cout << each * round << endl;
}
