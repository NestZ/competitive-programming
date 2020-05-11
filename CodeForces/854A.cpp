#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int gcd(int a, int b){
	return (b ? gcd(b, a % b) : a);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int a = 0;
	int b = n;
	int aa = 0;
	int ab = 0;
	while(a < b){
		if(gcd(a, b) == 1){
			aa = a;
			ab = b;
		}
		a++;
		b--;
	}
	cout << aa << ' ' << ab;
}
