#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int a, b, c, d;cin >> a >> b >> c >> d;
		if(a == d)a++;
		cout << a << ' ' << d << endl;
	}
}
