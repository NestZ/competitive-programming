#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	string nn, mm;cin >> nn >> mm;
	for(int i = 0;i < n;i++){
		if((i * m) % n != 0)continue;
		if(i * m / n < m && nn[i] != mm[i * m / n]){
			return cout << -1, 0;
		}
	}
	cout << n * m / __gcd(n, m) << endl;
}
