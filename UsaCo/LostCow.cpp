/*
ID: nestz
LANG: C++14
TASK: lostcow
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("lostcow.out", "w", stdout);
	freopen("lostcow.in", "r", stdin);

	int x, y;cin >> x >> y;
	int cur = 1;
	int op = 1;
	int ans = 0;
	int lst = x;
	while(true){
		int nx = x + op * cur;
		if(x < y && nx > y)nx = y;
		else if(x > y && nx < y)nx = y;
		ans += abs(lst - nx);
		if(nx == y)break;
		cur <<= 1;
		op *= -1;
		lst = nx;
	}
	cout << ans << endl;
}
