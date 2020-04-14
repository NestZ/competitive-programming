#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int h, m;cin >> h >> m;
		int ans = 0;
		ans += 60 - m;
		h++;
		ans += 60 * (24 - h);
		cout << ans << endl;
	}
}
