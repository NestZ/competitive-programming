#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	for(ll i = 1;i <= 3500;i++){
		for(ll j = i;j <= 3500;j++){
			ll up = n * i * j;
			ll down = (4 * i * j - n * j - n * i);
			if(down != 0 && up % down == 0 && up / down > 0){
				cout << i << ' ' << j << ' ' << up / down << endl;
				return 0;
			}
		}
	}
}
