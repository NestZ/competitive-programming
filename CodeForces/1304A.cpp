#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		ll x, y, a, b;cin >> x >> y >> a >> b;
		ll dis = y - x;
		int bi = 0;
		for(int k = dis / max(a, b);k > 0;k /= 2){
			while((bi + k) * a + (bi + k) * b < dis)bi += k;
		}
		bi++;
		if(bi * a + bi * b == dis)cout << bi;
		else cout << -1;
		cout << endl;
	}
}
