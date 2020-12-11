#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, c, d;cin >> n >> a >> b >> c >> d;
	a--;b--;c--;d--;
	string s;cin >> s;
	bool ans = true;
	for(int i = min(a, b);i < max(c, d);i++){
		if(i - 1 < 0)continue;
		if(s[i] == '#' && s[i - 1] == '#')ans = false;
	}
	if(c > d){
		int mx = 0;
		int cur = 0;
		for(int i = b - 1;i <= d + 1;i++){
			if(s[i] == '.')cur++;
			else cur = 0;
			mx = max(mx, cur);
		}
		if(mx < 3)ans = false;
	}
	if(ans)cout << "Yes";
	else cout << "No";
	cout << endl;
}
