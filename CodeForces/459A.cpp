#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
	int x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	if(x1 == x2){
		x3 += x1 + abs(y1 - y2);
		x4 = x3;
		y3 = y1;
		y4 = y2;
	}
	else if(y1 == y2){
		y3 += y1 + abs(x1 - x2);
		y4 = y3;
		x3 = x1;
		x4 = x2;
	}
	else if(abs(x1 - x2) == abs(y1 - y2)){
		x3 = x1;
		x4 = x2;
		y3 = y2;
		y4 = y1;
	}
	else return cout << -1, 0;
	cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4;
}
