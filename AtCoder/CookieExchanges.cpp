#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;cin >> a >> b >> c;
	set<tuple<int, int, int>> s;
	int ans = 0;
	bool inf = true;
	while(!s.count(make_tuple(a, b, c))){
		if((a & 1) || (b & 1) || (c & 1)){
			inf = false;
			break;
		}
		s.insert(make_tuple(a, b, c));
		int na, nb, nc;
		na = b / 2 + c / 2;
		nb = a / 2 + c / 2;
		nc = b / 2 + a / 2;
		a = na;b = nb;c = nc;
		ans++;
	}
	if(!inf)
		cout << ans << endl;
	else cout << -1 << endl;
}
