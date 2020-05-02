#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	for(int j = 0;j < t;j++){
		int x, y;cin >> x >> y;
		string s;cin >> s;
		int n = s.length();
		int ans = INT_MAX;
		for(int i = 1;i <= n;i++){
			if(s[i - 1] == 'N')y++;
			else if(s[i - 1] == 'S')y--;
			else if(s[i - 1] == 'W')x--;
			else x++;
			if(abs(x) + abs(y) <= i)ans = min(ans, i);
		}
		cout << "Case #" << j + 1 << ": ";
		if(ans == INT_MAX)cout << "IMPOSSIBLE";
		else cout << ans;
		cout << endl;
	}
}
