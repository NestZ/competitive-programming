#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int a = k * l / nl;
	int b = c * d;
	int t = p / np;
	cout << min({a, b, t}) / n;
}
