#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int ans = 8;
	bool x = false;
	bool y = false;
	if(s[0] == 'a' || s[0] == 'h')x = true;
	if(s[1] == '1' || s[1] == '8')y = true;
	if(x && y)ans -= 5;
	else if(x || y)ans -= 3;
	cout << ans;
}
