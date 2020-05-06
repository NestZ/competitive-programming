#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;cin >> x >> y;
	int n;cin >> n;
	double ans = 1e9;
	for(int i = 0;i < n;i++){
		int xi, yi, d;cin >> xi >> yi >> d;
		double dis = sqrt(pow(xi - x, 2) + pow(yi - y, 2));
		ans = min(ans, dis / (double)d);
	}
	printf("%.9f", ans);
}
