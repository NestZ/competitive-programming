#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	int curr = 0;
	int ans = 0;
	while(t--){
		int a,b;cin >> a >> b;
		curr += b;
		curr -= a;
		ans = max(ans, curr);
	}
	cout << ans;
}
