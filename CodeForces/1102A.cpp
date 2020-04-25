#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	if((n * (n + 1) / 2) & 1)cout << 1;
	else cout << 0;
}
