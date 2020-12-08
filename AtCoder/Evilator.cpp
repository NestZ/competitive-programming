#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	ll ans = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 'D')ans += i + (n - i - 1) * 2;
		else ans += 2 * i + n - i - 1;
	}
	cout << ans << endl;
}
