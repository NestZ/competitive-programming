#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	int c, d;cin >> c >> d;
	int x = abs(a - c);
	int y = abs(b - d);
	cout << min(x, y) + (max(x, y) - min(x, y));
}
