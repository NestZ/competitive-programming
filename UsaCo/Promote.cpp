/*
ID: nestz
LANG: C++14
TASK: promote
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("promote.out", "w", stdout);
	freopen("promote.in", "r", stdin);

	int b, bb;cin >> b >> bb;
	int s, ss;cin >> s >> ss;
	int g, gg;cin >> g >> gg;
	int p, pp;cin >> p >> pp;
	int tp = pp - p;
	int tg = tp + (gg - g);
	int ts = tg + (ss - s);
	cout << ts << endl << tg << endl << tp << endl;
}
