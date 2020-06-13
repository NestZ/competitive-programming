#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b;cin >> a >> b;
		int mn = min(a, b) * 2;
		int mx = max(a, b);
		if(mn < mx)cout << mx * mx;
		else cout << mn * mn;
		cout << endl;
	}
}
