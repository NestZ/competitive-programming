#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b, c;cin >> a >> b >> c;
		int curr = min(a, b);
		int ans = curr;
		if(c < curr){
			a -= c; b -= c;
			if(a >= 2 * b || b >= 2 * a)ans = c + min(a, b);
			else ans = c + (a + b) / 3;
		}
		cout << ans << endl;
	}
}
