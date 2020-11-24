#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, m;cin >> a >> b >> m;
	vector<int> arra(a);
	vector<int> arrb(b);
	int mina = INT_MAX;
	int minb = INT_MAX;
	for(int i = 0;i < a;i++){
		cin >> arra[i];
		mina = min(arra[i], mina);
	}
	for(int i = 0;i < b;i++){
		cin >> arrb[i];
		minb = min(arrb[i], minb);
	}
	int ans = mina + minb;
	for(int i = 0;i < m;i++){
		int x, y, c;cin >> x >> y >> c;
		x--;y--;
		ans = min(ans, arra[x] + arrb[y] - c);
	}
	cout << ans << endl;
}
