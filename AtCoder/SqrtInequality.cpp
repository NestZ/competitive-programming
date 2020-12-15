#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;cin >> a >> b >> c;
	ll d = c - a - b;
	if(d > 0 && d * d > 4 * a * b)cout << "Yes";
	else cout << "No";
	cout << endl;
}
