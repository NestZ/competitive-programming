#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int L, v, l, r;cin >> L >> v >> l >> r;
		int s = L / v;
		s -= (r / v) - ((l - 1) / v);
		cout << s << endl;
	}
}
