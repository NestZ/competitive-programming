#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int last_t = 0;
	int last_x = 0;
	int last_y = 0;
	bool ans = true;
	for(int i = 0;i < n;i++){
		int t, x, y;cin >> t >> x >> y;
		int cur_dif = abs(x - last_x) + abs(y - last_y);
		int cur_t = t - last_t;
		if(cur_t < cur_dif)ans = false;
		if((cur_t - cur_dif) % 2 != 0)ans = false;
		last_t = t;
		last_x = x;
		last_y = y;
	}
	if(ans)cout << "Yes";
	else cout << "No";
	cout << endl;
}
