#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d, l, v1, v2;cin >> d >> l >> v1 >> v2;
	int v = v1 + v2;
	l -= d;
	printf("%.15f", (double)l / v);
}
