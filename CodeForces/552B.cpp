#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll sum = 0;
	ll curr = 0;
	for(ll i = 1;i <= 1e10;i *= 10, curr++){
		if(n >= i)sum += (i - (i / 10)) * curr;
		else{
			sum += (n - (i / 10) + 1) * curr;
			break;
		}
	}
	cout << sum;
}
