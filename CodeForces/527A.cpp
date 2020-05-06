#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;cin >> a >> b;
	ll ans = 0;
	while(a > 0 && b > 0){
		if(a >= b){
			ans += a / b;
			a = a % b;
		}
		else{
			ans += b / a;
			b = b % a;
		}
	}
	cout << ans;
}
