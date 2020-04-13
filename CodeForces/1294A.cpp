#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		bool flag = false;
		int a, b, c, n;cin >> a >> b >> c >> n;
		int mx = max({a, b, c});
		n -= mx * 3 - (a + b + c);
		if(n % 3 == 0 && n >= 0)flag = true;
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
