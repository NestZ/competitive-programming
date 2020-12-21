#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int l, r, d, u;cin >> l >> r >> d >> u;
		int x, y, x1, y1, x2, y2;cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int diff_left = abs(x - x1);
		int diff_right = abs(x - x2);
		int diff_down = abs(y - y1);
		int diff_up = abs(y - y2);
		int want_x = r - l;
		int want_y = u - d;
		bool ans = true;
		if(x1 == x2 && (l > 0 || r > 0))ans = false;
		if(y1 == y2 && (u > 0 || d > 0))ans = false;
		if(want_x >= 0){
			if(diff_right < want_x)ans = false;
		}
		else if(want_x < 0){
			if(diff_left < -want_x)ans = false;
		}
		if(want_y >= 0){
			if(diff_up < want_y)ans = false;
		}
		else if(want_y < 0){
			if(diff_down < -want_y)ans = false;
		}
		if(ans)cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}
