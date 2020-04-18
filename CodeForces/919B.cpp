#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool c(ll n){
	ll sum = 0;
	while(n > 0){
		sum += n % 10;
		n /= 10;
	}
	return sum == 10;
}

int main(){
	ll n;cin >> n;
	ll cnt = 0;
	for(ll i = 0;;i++){
		if(c(i)){
			cnt++;
			if(cnt == n)return cout << i, 0;
		}
	}
}
