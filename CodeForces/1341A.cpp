#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, a, b, c, d;cin >> n >> a >> b >> c >> d;
		int mng = (a - b) * n;
		int mxg = (a + b) * n;
		int mnp = (c - d);
		int mxp = (c + d);
		if(mxg >= mnp && mxp >= mng)cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}
