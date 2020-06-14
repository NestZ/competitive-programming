#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, n, s, p;cin >> k >> n >> s >> p;
	int e = (n + (s - 1)) / s;
	int all = e * k;
	cout << (all + (p - 1)) / p;
}
