#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int a, b, c;cin >> a >> b >> c;
		while(a > c * 10 && b > 0){
			a >>= 1;
			a += 10;
			b--;
		}
		if(a <= c * 10)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
