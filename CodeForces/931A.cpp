#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	int d = abs(a - b);
	int f = d / 2;
	int s = (d + 1) / 2;
	int ans = f * (f + 1) / 2 + s * (s + 1) / 2;
	cout << ans;
}
