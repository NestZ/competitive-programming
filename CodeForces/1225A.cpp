#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	if(abs(a - b) > 1 && (a != 9 || b != 1))return cout << -1, 0;
	if(a > b && (a != 9 || b != 1))return cout << -1, 0;
	if(a == 9 && b == 1){
		b *= 10;
	}
	else if(a - b != 0){
		a = a * 10 + 9;
		b *= 10;
	}
	else{
		a *= 10;
		b = b * 10 + 1;
	}
	cout << a << ' ' << b;
}
