#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, x;cin >> n >> x;
		if(n <= 2)cout << 1;
		else{
			n -= 2;
			cout << 1 + ((n + x - 1) / x);
		}
		cout << endl;
	}
}
