#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b, x, y;cin >> a >> b >> x >> y;
		int ans = 0;
		ans = max(ans, x * b);
		ans = max(ans, (a - x - 1) * b);
		ans = max(ans, y * a);
		ans = max(ans, (b - y - 1) * a);
		cout << ans << endl;
	}
}
