#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h, k;cin >> w >> h >> k;
	int ans = 0;
	for(int i = 0;i < k;i++){
		int currw = w - (4 * i);
		int currh = h - (4 * i);
		ans += currw * 2 + currh * 2 - 4;
	}
	cout << ans;
}
