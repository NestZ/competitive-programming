#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll sum(ll n){
	ll ans = 0;
	while(n > 0){
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	ll cur = 0;
	ll exp = 0;
	while(cur * 10 + 9 <= n){
		cur = cur * 10 + 9;
		exp++;
	}
	for(int i = 1;i <= 9;i++){
		if(cur + pow(10, exp) <= n){
			cur += pow(10, exp);
		}
		else break;
	}
	cout << sum(cur) << endl;
}
