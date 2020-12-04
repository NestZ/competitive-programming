#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;cin >> n >> a >> b;
	if(a > b || (n == 1 && a != b))return cout << 0 << endl, 0;
	if(a == b)return cout << 1 << endl, 0;
	cout << (b - a) * (n - 2) + 1 << endl;
}
