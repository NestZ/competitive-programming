#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d;cin >> a >> b >> c >> d;
	int m = max(3 * a / 10, a - a / 250 * c);
	int v = max(3 * b / 10, b - b / 250 * d);
	if(m < v)cout << "Vasya";
	else if(m == v)cout << "Tie";
	else cout << "Misha";
}
