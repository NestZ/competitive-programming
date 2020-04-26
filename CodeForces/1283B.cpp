#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b;cin >> a >> b;
		if(a % b > b / 2)cout << a - (a % b) + b / 2;
		else cout << a;
		cout << endl;
	}
}
