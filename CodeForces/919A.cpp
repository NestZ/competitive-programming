#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	double ans = 1e9;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		double p = (double)a / b;
		ans = min(ans, p * m);
	}
	printf("%.9f", ans);
}
