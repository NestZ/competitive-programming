#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		if(n == 1)cout << 0;
		else if(n == 2)cout << m;
		else cout << 2 * m;
		cout << endl;
	}
}
