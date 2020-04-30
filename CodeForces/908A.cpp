#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	int ans = 0;
	string t = "aeiou13579";
	for(int i = 0;i < n;i++){
		if(t.find(s[i]) != string::npos)ans++;
	}
	cout << ans;
}
