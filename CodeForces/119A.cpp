#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a, b, n;cin >> a >> b >> n;
	bool s = true;
	while(n != 0){
		if(s)n -= __gcd(n, a);
		else n -= __gcd(n, b);
		s = !s;
	}
	if(s)cout << 1;
	else cout << 0;
}
