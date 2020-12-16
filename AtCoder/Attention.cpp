#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	int cnt_w = 0;
	int cnt_e = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 'W')cnt_w++;
		else cnt_e++;
	}
	int ans = INT_MAX;
	int cur_w = 0;
	int cur_e = 0;
	for(int i = 0;i < n;i++){
		int change_l = cur_w;
		int change_r = cnt_e - cur_e;
		if(s[i] == 'E')change_r--;
		if(s[i] == 'W')cur_w++;
		else cur_e++;
		ans = min(ans, change_l + change_r);
	}
	cout << ans << endl;
}
