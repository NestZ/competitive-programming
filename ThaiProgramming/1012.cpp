#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for(int i = 0;i < n;i++){
		int a1, b1, c1, d1, e1;cin >> a1 >> b1 >> c1 >> d1 >> e1;
		a += a1;
		b += b1;
		c += c1;
		d += d1;
		e += e1;
	}
	int ans = a + b + (c + 1) / 2;
	d -= b + (c & 1) * 2;
	if(d > 0){
		ans += (d + 3) / 4;
		e -= d % 4 * 2;
	}
	else if(d < 0){
		e -= abs(d * 2);
	}
	if(e > 0){
		ans += (e + 7) / 8;
	}
	cout << ans;
}
