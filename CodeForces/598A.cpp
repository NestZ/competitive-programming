#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll sum = n * (n + 1) / 2;
		ll curr = 1;
		while(curr <= n){
			sum -= 2 * curr;
			curr <<= 1;
		}
		cout << sum << endl;
	}
}
