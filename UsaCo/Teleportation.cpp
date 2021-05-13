/*
ID: nestz
LANG: C++14
TASK: teleport
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("teleport.out", "w", stdout);
	freopen("teleport.in", "r", stdin);

	int a, b, c, d;cin >> a >> b >> c >> d;
	int not_use = abs(b - a);
	int use_c = abs(a - c) + abs(d - b);
	int use_d = abs(a - d) + abs(c - b);
	cout << min({not_use, use_d, use_c}) << endl;
}
