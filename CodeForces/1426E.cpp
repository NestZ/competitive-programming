#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int r1, s1, p1;cin >> r1 >> s1 >> p1;
	int r2, s2, p2;cin >> r2 >> s2 >> p2;
	int mn = max(0, r1 - (r2 + p2)) + max(0, s1 - (s2 + r2)) + max(0, p1 - (p2 + s2));
	int mx = min(r1, s2) + min(s1, p2) + min(p1, r2);
	cout << mn << ' ' << mx;
}
