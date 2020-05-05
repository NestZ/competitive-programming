#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll s, a, b, c;cin >> s >> a >> b >> c;
		cout << (s / c) + (s / c) / a * b << endl;
	}
}
