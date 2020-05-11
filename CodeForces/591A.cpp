#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l;cin >> l;
	int a, b;cin >> a >> b;
	double ans = (double)l / (a + b) * a;
	printf("%.9f", ans);
}
