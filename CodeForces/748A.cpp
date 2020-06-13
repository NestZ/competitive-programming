#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;cin >> n >> m >> k;
	int lane = (k + (2 * m - 1)) / (2 * m);
	int w = k - (m * 2) * (k / (m * 2));
	int desk = (w + 1) / 2;
	if(w == 0)desk = m;
	cout << lane << ' ' << desk << ' ' << ((k & 1) ? 'L':'R');
}
