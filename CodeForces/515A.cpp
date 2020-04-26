#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, s;cin >> a >> b >> s;
	ll d = abs(a) + abs(b);
	if((s - d) % 2 == 0 && s >= d)cout << "Yes";
	else cout << "No";
}
