#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int x, y, z;cin >> x >> y >> z;
		int x1, y1, z1;cin >> x1 >> y1 >> z1;
		int mn = min(z, y1);
		int ans = mn * 2;
		z -= mn;y1 -= mn;
		z1 -= z + x;
		ans -= 2 * max(0, z1);
		cout << ans << endl;
	}
}
