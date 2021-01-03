#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	string s;cin >> s;
	int cnt_b = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == '#')cnt_b++;
	}
	int ans = cnt_b;
	int cur_w = 0;
	int cur_b = 0;
	for(int i = n - 1;i >= 0;i--){
		if(s[i] == '.')cur_w++;
		else cur_b++;
		int cost = cur_w + (cnt_b - cur_b);
		ans = min(ans, cost);
	}
	cout << ans << endl;
}
