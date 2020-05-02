#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll a, b, c;cin >> a >> b >> c;
		if(a > b + c + 1 || b > a + c + 1 || c > a + b + 1)cout << "No";
		else cout << "Yes";
		cout << endl;
	}
}
