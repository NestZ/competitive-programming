#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, r;cin >> l >> r;
	if(r - l <= 1)cout << r;
	else{
		if(l % 3 == 0 && r % 3 == 0 && r - l == 3)cout << 3;
		else cout << 2;
	}
}
