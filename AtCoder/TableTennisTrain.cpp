#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;cin >> n >> a >> b;
	ll gol = a - 1 + (b - a + 1) / 2;
	ll gor = n - b + (b - a + 1) / 2;
	ll mid = INT64_MAX;
	if((b - a) % 2 == 0){
		mid = (b - a) / 2;
	}
	cout << min({gor, gol, mid}) << endl;
}
