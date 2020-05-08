#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d, e, f;cin >> a >> b >> c >> d >> e >> f;
	int ans = 0;
	for(int i = 0;i <= d;i++){
		int df = i;
		int ds = d - i;
		int fst = 0;
		int s = 0;
		fst = min(a, df) * e;
		s = min({ds, b, c}) * f;
		ans = max(ans, fst + s);
	}
	cout << ans;
}
