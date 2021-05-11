/*
ID: nestz
LANG: C++14
TASK: square
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("square.out", "w", stdout);
	freopen("square.in", "r", stdin);

	int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;cin >> x3 >> y3 >> x4 >> y4;
	int w = max(x2, x4) - min(x1, x3);
	int h = max(y2, y4) - min(y1, y3);
	cout << max(w, h) * max(w, h) << endl;
}
