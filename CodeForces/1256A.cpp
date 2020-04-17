#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		ll a, b, n, s;cin >> a >> b >> n >> s;
		if(a * n >= s)s %= n;
		else s -= n * a;
		if(s <= b)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
