#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, x, y, a, b;cin >> r >> x >> y >> a >> b;
	double d = sqrt(pow(a - x, 2) + pow(b - y, 2));
	cout << ceil(d / (2 * r));
}
