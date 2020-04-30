#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll h, l;cin >> h >> l;
	auto ans = double(l * l - h * h) / (2.0 * h);
	printf("%.9f", ans);
}
