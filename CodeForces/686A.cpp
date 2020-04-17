#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n, x;cin >> n >> x;
	ll d = 0;
	ll p = 0;
	for(int i = 0;i < n;i++){
		char c;cin >> c;
		ll num;cin >> num;
		if(c == '-'){
			if(num <= x)x -= num;
			else d++;
		}
		else{
			p += num;
			x += num;
		}
	}
	cout << x << ' ' << d;
}
