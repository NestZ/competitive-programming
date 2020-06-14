#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, z, t1, t2, t3;cin >> x >> y >> z >> t1 >> t2 >> t3;
	int gotoM = 2 * t3 + (t2 * abs(z - x));
	int useE = gotoM + (t2 * abs(x - y)) + t3;
	int useS = abs(x - y) * t1;
	if(useS < useE)cout << "NO";
	else cout << "YES";
}
