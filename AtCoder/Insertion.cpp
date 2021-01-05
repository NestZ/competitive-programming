#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int cur = 0;
	string s;cin >> s;
	string ans = "";
	for(int i = 0;i < n;i++){
		if(s[i] == ')'){
			if(cur == 0)ans += '(';
			else cur--;
		}
		else cur++;
	}
	ans += s;
	for(int i = 0;i < cur;i++)ans += ')';
	cout << ans << endl;
}
