#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s = "";
	for(int i = 0;i < n;i++){
		char c;cin >> c;
		s += c;
	}
	s += s;
	int cnt = 0;
	int ans = 0;
	n = s.length();
	for(int i = 0;i < n;i++){
		if(s[i] == '1'){
			cnt++;
			ans = max(ans, cnt);
		}
		else cnt = 0;
	}
	cout << ans;
}
