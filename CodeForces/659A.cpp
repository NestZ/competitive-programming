#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;cin >> n >> a >> b;
	while(b < 0)b += n;
	b %= n;
	int d = a + b;
	d %= n;
	if(d == 0)d = n;
	cout << d;
}
