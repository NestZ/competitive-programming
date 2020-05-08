#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	const ll m = 1e9 + 7;
	vector<ll> t(4);
	vector<ll> curr(4);
	t[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 4;j++){
			for(int k = 0;k < 4;k++){
				if(j == k)continue;
				curr[j] = (curr[j] + t[k]) % m;
			}
		}
		for(int j = 0;j < 4;j++){
			t[j] = curr[j];
			curr[j] = 0;
		}
	}
	cout << t[0];
}
