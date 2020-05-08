#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b, c, r;cin >> a >> b >> c >> r;
		int t1 = a;
		int t2 = b;
		a = min(t1, t2);
		b = max(t1, t2);
		int s = c - r;
		int e = c + r;
		if(s >= b || e <= a)cout << b - a;
		else cout << max(0, s - a) + max(0, b - e);
		cout << endl;
	}
}
