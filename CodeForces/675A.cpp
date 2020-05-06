#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;cin >> a >> b >> c;
	if(c == 0 && a == b)cout << "YES";
	else if((b - a) % c == 0){
		if(c < 0 && a >= b || c > 0 && a <= b)
			cout << "YES";
		else cout << "NO";
	}
	else cout << "NO";
}
