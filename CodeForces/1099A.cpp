#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h;cin >> w >> h;
	int u1, d1;cin >> u1 >> d1;
	int u2, d2;cin >> u2 >> d2;
	while(h >= 0){
		w += h;
		if(h == d1)w = max(0, w - u1);
		if(h == d2)w = max(0, w - u2);
		h--;
	}
	cout << w;
}
