/*
ID: nestz
LANG: C++17
TASK: billboard
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool covered(int x, int y, int x1, int y1, int x2, int y2) {
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("billboard.out", "w", stdout);
	freopen("billboard.in", "r", stdin);

	int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;cin >> x3 >> y3 >> x4 >> y4;

	int cornerCover = 0;
	if(covered(x1, y1, x3, y3, x4, y4)) ++cornerCover;
	if(covered(x1, y2, x3, y3, x4, y4)) ++cornerCover;
	if(covered(x2, y1, x3, y3, x4, y4)) ++cornerCover;
	if(covered(x2, y2, x3, y3, x4, y4)) ++cornerCover;

	int iw = max(0, min(x2, x4) - max(x1, x3));
	int ih = max(0, min(y2, y4) - max(y1, y3));
	int w = x2 - x1;
	int h = y2 - y1;
	if(cornerCover < 2)cout << w * h;
	else if(cornerCover == 4)cout << 0;
	else cout << w * h - iw * ih;
	cout << endl;
}
