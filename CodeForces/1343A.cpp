#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		ll k = 4;
		ll curr = 3;
		while(n % curr != 0LL){
			curr += k;
			k <<= 1;
		}
		cout << n / curr << endl;
	}
}
