#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	ll ans = 0;
	ll cnt = 0;
	for(int i = n - 1;i >= 0;i--){
		if(s[i] == 'W')cnt++;
		else ans += cnt;
	}
	cout << ans << endl;
}
