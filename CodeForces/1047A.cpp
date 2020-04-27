#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int b;
	int c;
	int a = b = c = n / 3;
	int sum = a + b + c;
	a += n - sum;
	if(a % 3 == 0){
		a--;
		b++;
	}
	if(b % 3 == 0){
		b--;
		c++;
	}
	if(c % 3 == 0){
		c++;
		a--;
	}
	cout << a << ' ' << b << ' ' << c;
}
