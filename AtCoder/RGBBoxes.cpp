#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, g, b, n;cin >> r >> g >> b >> n;
	int ans = 0;
	for(int i = 0;i <= n / r;i++){
		for(int j = 0;j <= n / g;j++){
			int cnt_r = r * i;
			int cnt_g = g * j;
			int cnt_b = n - cnt_r - cnt_g;
			if(cnt_b < 0 || cnt_b % b != 0)continue;
			if(cnt_r + cnt_g + cnt_b > n)continue;
			ans++;
		}
	}
	cout << ans << endl;
}
