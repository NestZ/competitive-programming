#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int cnt = 0;
	int cnto = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t == 5)cnt++;
		else cnto++;
	}
	string ans = string(9 * (cnt / 9), '5');
	if(cnto == 0)ans = "-1";
	else if(ans.length() > 0)ans += string(cnto, '0');
	else ans += '0';
	cout << ans;
}
